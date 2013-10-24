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

#include <CodeSet.hpp>
#include <fstream>
#include <iostream>

namespace CS
{

	// Constructor/destructor
	CodeSet::CodeSet( Syntax * p_pSyntax, Fractal * p_pFractal ) :
		m_pSyntax( p_pSyntax ),
		m_pFractal( p_pFractal )
	{
	}

	CodeSet::~CodeSet( )
	{
	}

	// Public general function
	/*bool CodeSet::OpenFile( const char * p_pFilePath, int p_MaxLength )
	{
		// Open the file
		std::ifstream fin( p_pFilePath, std::fstream::binary );
		if( !fin.is_open( ) )
		{
			return false;
		}

		// Read the file size and set the read size
		fin.seekg( 0, fin.end );
		int fileSize = fin.tellg( );
		fin.seekg( 0, fin.beg );
		int ReadSize = fileSize < p_MaxLength ? fileSize : p_MaxLength;

		// Read the file
		char * pBuffer = new char[ ReadSize + 1 ];
		pBuffer[ ReadSize ] = 0;
		fin.read( pBuffer, ReadSize );

		// Set the string and remove the buffer.
		m_String = pBuffer;
		delete [ ] pBuffer;

		// Close the file
		fin.close( );

		return true;
	}*/

	/*void CodeSet::ProcessString( )
	{
		// Ugly way of removing characters that we do not want.
		for( int i = 0; i < m_String.size( ); i++ )
		{
			if( m_String[ i ] == '\n' ||
				m_String[ i ] == '\r' ||
				m_String[ i ] == '\t')
			{
				m_String[ i ] = ' ';
			}
		}
	}*/

	bool CodeSet::WriteToFile( const char * p_pFilePath )
	{
		// Open the file
		std::ofstream fout( p_pFilePath );
		if( !fout.is_open( ) )
		{
			return false;
		}

		// Loop through the fractal size
		int CurrChar = 0;
		bool KeepLooping = true;

		for( int y = 0; y < m_pFractal->GetHeight( ); y++ )
		{
			for( int x = 0; x < m_pFractal->GetWidth( ); x++ )
			{
				// Iterate the fractal
				int n = m_pFractal->Iterate( x, y );

				// Print a character if the iteration == the precision
				if( n == m_pFractal->GetPrecision( ) )
				{
					// Write the current character
					fout << "#";
					//fout << m_String[ CurrChar ];
					CurrChar++;

					// Are we out of characters?
					/*if( CurrChar == m_String.size( ) )
					{
						KeepLooping = false;
						break;
					}*/
				}
				// Write a space if the current pixel is outside the mandelbrot set.
				else
				{
					fout << " ";
				}
			}

			if( !KeepLooping )
			{
				break;
			}

			// Finish the file with a new line
			fout << "\n";
		}

		// Close the file 
		fout.close( );

		return true;
	}

	char * CodeSet::WriteToString( )
	{
		return NULL;
	}

}