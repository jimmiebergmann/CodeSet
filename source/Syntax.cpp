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
		m_Text( "" )
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

		// Read the file size
		fin.seekg( 0, fin.end );
		int fileSize = fin.tellg( );
		fin.seekg( 0, fin.beg );
		int readSize = ( fileSize < p_MaxCharacters ) ? fileSize : p_MaxCharacters;
		m_Text.reserve( readSize + 1 );

		// Read all the lines
		int currentSize = 0;
		std::string tempString;
		tempString.reserve( 128 );
		while( !fin.eof( ) )
		{
			// Get another 
			std::getline( fin, tempString );

			// Remove the newline(if any)
			if( tempString.size( ) > 1 )
			{
				tempString.erase( tempString.size( ) - 1, 1 );
			}

			// Cur the line if needed and then break( too many characters
			currentSize += tempString.size( );
			if( currentSize > readSize )
			{
				tempString[ currentSize - readSize ] = 0;
				m_Text += tempString + '\n';
				break;
			}

			m_Text += tempString + '\n';	 

		}

		// Close the file
		fin.close( );

		return true;
	}

	// Set functions
	void Syntax::SetText( const std::string & p_Text )
	{
		m_Text = p_Text;
	}

	// Get functions
	const std::string & Syntax::GetText( ) const
	{
		return m_Text;
	}


}