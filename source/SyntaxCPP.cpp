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

namespace CS
{

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
		// Loop through all the lines
		//while( m_Lines.size( ) )
		for( int l = 0; l < m_Lines.size( ); l++ )
		{
			int wordSize = 0;
			std::string word = "";

			// Loop through all the characters in the line
			for( int c = 0; c < m_Lines[ l ].size( ); c++ )
			{
				char currChar = m_Lines[ l ][ c ];

				// Skip tabs and newlines
				if( currChar == '\n' ||
					currChar== '\r' ||
					currChar == '\t')
				{
					continue;
				}

				// Discard the rest of the line if it's a comment
				if( currChar == '/' && ( c+1 < m_Lines[ l ].size( ) ) && m_Lines[ l ][ c + 1] == '/'  )
				{
					break;
				}

				// Start on a new word
				if( wordSize == 0 )
				{
					// Ignore spaces
					if( currChar == ' ' )
					{
						continue;
					}
					else if(	currChar == '(' ||
								currChar == ')' ||
								currChar == '{' ||
								currChar == '}' ||
								currChar == '[' ||
								currChar == ']' ||
								currChar == '<' ||
								currChar == '>' ||
								currChar == '=' ||
								currChar == '+' ||
								currChar == '-' ||
								currChar == '*' )
					{

						int a = 5;
						int * b = &
							a;

						// Push back the sign to the word vector
						std::string tempString;
						tempString.push_back( currChar );
						m_Words.push_back( tempString );
						continue;
					}
					else 
					{
						word += currChar;
					}

				}
				else
				{
				}
			}
		}
		

	}

}