// ///////////////////////////////////////////////////////////////////////////
// Copyright (C) 2013 Jimmie Bergmann - jimmiebergmann@gmail.com
//
// This software is provided 'as-is', without any express or
// implied warranty. In no event will the authors be held
// liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute
// it freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but
//    is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any
//    source distribution.
// ///////////////////////////////////////////////////////////////////////////

#include <SyntaxCPP.hpp>
#include <iostream>

namespace CS
{

	static std::string GetOperator( const std::string & p_Text, unsigned int p_Index )
	{
		char c = p_Text[ p_Index ];
		std::string word;

		if( c == '=' ||
			c == '+' ||
			c == '-' ||
			c == '*' ||
			c == '/' ||
			c == '%' ||
			c == '&' ||
			c == '<' ||
			c == '>' ||
			c == '|' ||
			c == '^' ||
			c == '!' )
		{
			word += c;

			// Check if there's another operator sign.
			if( ( p_Index + 1 ) < p_Text.size( ) )
			{
				char nc = p_Text[ p_Index + 1 ];

				if( nc == '=' ||
					nc == '+' ||
					nc == '-' ||
					nc == '*' ||
					nc == '/' ||
					nc == '%' ||
					nc == '&' ||
					nc == '<' ||
					nc == '>' ||
					nc == '|' ||
					nc == '^' ||
					nc == '!' ||
					nc == '.' )
				{
					word += nc;
				}

			}
		}

		return word;
	}


	// Constructor/destructor
	SyntaxCPP::SyntaxCPP( ) :
		Syntax( )
	{

	}

	SyntaxCPP::~SyntaxCPP( )
	{

	}

	// Public general function
	void SyntaxCPP::MakeCompact( )
	{
		
		RemoveMultiLineComments( );
		RemoveSingleLineComments( );
		MakePreCode( );
		MakePostCode( );
		RemoveTabsNewlines( );

		std::cout << m_Text << std::endl;
	}

	std::string SyntaxCPP::GetWord( const unsigned int p_Index )
	{
		if( p_Index >= m_Text.size( ) )
		{
			return "";
		}

		// Get the first character
		char sc = m_Text[ p_Index ];

		// Special cases
		// String or character
		if( sc == '\"' || sc == '\'' )
		{
			// Find the end of the string
			for( int i = p_Index + 1; i < m_Text.size( ); i++ )
			{
				char c = m_Text[ i ];

				// We found the end, return the string
				if( c == sc )
				{
					std::string com = m_Text.substr( p_Index, ( i - p_Index)  + 1  );
					return com;
				}
			}

			// We did't find the end for some reson...
			return "";
		}

		// Is this an operator?
		std::string op = GetOperator( m_Text, p_Index );
		if( op.size( ) )
		{
			return op;
		}

		// Is comma?
		if( sc == ',' )
		{
			return ",";
		}

		// Just get a word
		std::string word;

		// Start by looping from the index to the end of the text
		for( int i = p_Index; i < m_Text.size( ); i++ )
		{
			char c = m_Text[ i ];

			// No characters yet?, check for single character "words"
			if( !word.size( ) )
			{
				if(	c == ',' ||
					c == '.' ||
					c == '(' ||
					c == ')' ||
					c == '[' ||
					c == ']' ||
					c == '{' ||
					c == '}' ||
					c == ';')
				{
					word = c;
					return word;
				}
			}

			// Break the word if it's ending by any following character
			if( c == ' ' ||
				c == ',' ||
				c == '.' ||
				c == '(' ||
				c == ')' ||
				c == '[' ||
				c == ']' ||
				c == '{' ||
				c == '}' ||
				c == ';')
			{
				break;
			}

			word += c;
		}

		return word;
	}

	void SyntaxCPP::RemoveMultiLineComments( )
	{
		bool foundComment = false;
		int commentStart = 0;

		for( int i = 0; i < m_Text.size( ); i++ )
		{
			// Current and next char
			char cc = m_Text[ i ];
			char nc = m_Text[ i + 1 ];

			// we've not found any comment yet
			if( !foundComment )
			{
				// We found a comment?
				if( cc == '/' && nc == '*' )
				{
					foundComment = true;
					commentStart = i;
				}
			}
			else
			{
				// Is this the end of the comment?
				if( cc == '*' && nc == '/' )
				{
					int commentLength = i - commentStart;
					m_Text.erase( commentStart, commentLength + 2 );
					foundComment = false;
					i -= commentLength;
				}
			}
		}
	}

	void SyntaxCPP::RemoveSingleLineComments( )
	{
		bool foundComment = false;
		int commentStart = 0;

		for( int i = 0; i < m_Text.size( ); i++ )
		{
			// Current and next char
			char cc = m_Text[ i ];
			char nc = m_Text[ i + 1 ];

			// we've not found any comment yet
			if( !foundComment )
			{
				// We found a comment?
				if( cc == '/' && nc == '/' )
				{
					foundComment = true;
					commentStart = i;
				}
			}
			// We've already found a comment
			else
			{
				// Is this the end of this line?
				if( cc == '\n' || cc == '\r' )
				{
					int commentLength = i - commentStart;
					m_Text.erase( commentStart, commentLength );
					foundComment = false;
					i -= commentLength;
				}
			}

		}
	}

	void SyntaxCPP::MakePreCode( )
	{
		static const std::string findString = "#include";
		std::string includeDirectives = "";
		std::size_t found = 0;

		// Find all the directives
		for( std::size_t i = 0; i < m_Text.size( ); i++ )
		{
			// Find an include directive
			if( ( found = m_Text.find( "#include", i ) ) != std::string::npos )
			{
				// Erase the line
				std::size_t newline = m_Text.find( "\n", found + findString.size( ) );
				if( newline != std::string::npos )
				{
					// Get the directive
					includeDirectives += m_Text.substr(  found, newline - found ) + "\n";
					m_Text.erase( found, newline - found );

					// Move the index
					i = found;
				}
			}
		}

		// Set the precode
		m_PreCode = includeDirectives;
	}

	void SyntaxCPP::MakePostCode( )
	{
		m_PostCode = "Happy coding ==(^..^)==";
	}

	void SyntaxCPP::RemoveTabsNewlines( )
	{
		for( int i = 0; i < m_Text.size( ); i++ )
		{
			// Current char
			char cc = m_Text[ i ];

			// Remove the tab or newline
			if( cc == '\t' ||
				cc == '\n' ||
				cc == '\r' )
			{
				m_Text.erase( i, 1 );
				i--;
			}
			
		}
	}

}
