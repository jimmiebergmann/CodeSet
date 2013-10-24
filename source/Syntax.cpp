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

#include <Syntax.hpp>
#include <iostream>
#include <fstream>

namespace CS
{

	// Constructor/destructor
	Syntax::Syntax( ) :
		m_Lines( ),
		m_Words( )
	{
	}

	Syntax::~Syntax( )
	{
	}

	// Public general function
	bool Syntax::ReadFile( const char * p_pFilePath, const int p_MaxCharacters )
	{
		// Open the file
		std::ifstream fin( p_pFilePath, std::fstream::binary );
		if( !fin.is_open( ) )
		{
			return false;
		}

		// Go through all the lines in the file
		int characterCount = 0;

		while( !fin.eof( ) )
		{
			// Read a line
			std::string temp;
			std::getline( fin, temp );

			// Check if we've reached the character count, then break.
			characterCount += temp.size( );
			if( characterCount >= p_MaxCharacters )
			{
				break;
			}

			// Push back the line to the line vector
			m_Lines.push_back( temp );
		}

		// Close the file
		fin.close( );

		return true;
	}

	void Syntax::ClearLines( )
	{
		m_Lines.clear( );
	}

	void Syntax::ClearWords( )
	{
		m_Words.clear( );
	}

	// Get functions
	unsigned int Syntax::GetWordCount( ) const
	{
		return static_cast<unsigned int>( m_Words.size( ) );
	}

	std::string Syntax::GetWord( const unsigned int p_Index ) const
	{
		return m_Words[ p_Index ];
	}


}