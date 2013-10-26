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

	bool CodeSet::WriteToFile( const char * p_pFilePath )
	{
		// Make sure that we've loaded a syntax text
		if( !m_pSyntax->GetText( ).size( ) )
		{
			return false;
		}

		// Open the file
		std::ofstream fout( p_pFilePath );
		if( !fout.is_open( ) )
		{
			return false;
		}

		// Get the cool string
	/*	char * pBuffer = WriteToString( );

		// Errorcheck the buffer
		if( !pBuffer )
		{
			return false;
		}

		// write the buffer
		fout << pBuffer;
		*/
		// Test
		for( int i = 0; i < m_pSyntax->GetText( ).size( ); i++ )
		{
			std::string word = m_pSyntax->GetWord( i );
			i += word.size( );
			fout << word << "\n";
		}

		// Delete the buffer
		//delete [ ] pBuffer;

		//fout << m_pSyntax->GetText( );

		/*
		// Loop through the fractal
		for( int y = 0; y < m_pFractal->GetHeight( ); y++ )
		{
			for( int x = 0; x < m_pFractal->GetWidth( ); x++ )
			{
				// Iterate the fractal
				int n = m_pFractal->Iterate( x, y );

				// Print a character if the iteration == the precision
				if( n == m_pFractal->GetPrecision( ) )
				{
					// Write the current
					fout << "#";
				}
				// Write a space if the current pixel is outside the mandelbrot set.
				else
				{
					fout << " ";
				}
			}
			// Finish the file with a new line
			fout << "\n";
		}
		*/
		// Close the file 
		fout.close( );

		return true;
	}

	char * CodeSet::WriteToString( )
	{
		// Error check the fractal and syntax pointer
		if( !m_pFractal || !m_pSyntax )
		{
			return NULL;
		}

		// Create a buffer
		const int bufferSize =	( m_pFractal->GetWidth( ) * m_pFractal->GetHeight( ) ) +
								m_pFractal->GetHeight( ) + 1; // need this for newlines and end char
		char * pBuffer = new char[ bufferSize ];
		memset( pBuffer, ' ', bufferSize );
		
		// Clear and set the newlines
		memset( pBuffer, ' ', bufferSize );
		for( int y = 0; y < m_pFractal->GetHeight( ); y++ )
		{
			int i = ( ( m_pFractal->GetWidth( ) + 1 ) * y ) + m_pFractal->GetWidth( );
			pBuffer[ i ] = '\n';
		}

		// Start by getting a word
		unsigned int wordIndex = 0;
		std::string word = m_pSyntax->GetWord( wordIndex );
		if( !word.size( ) ) // Make sure that the word is at least something...
		{
			word = "#";
		}

		// The total number of found points in a row
		int foundPoints = 0; 

		for( int i = 0; i < m_pSyntax->GetText( ).size( ); i++ )
		{
			word = m_pSyntax->GetWord( i );

			i += word.size( );
			if( word.size( ) ) // We need to decrease the index to correct the location
			{
				i--;
			}

			std::cout << word << "\n";
		}


		// Go though the fractal
		/*for( int y = 0; y < m_pFractal->GetHeight( ); y++ )
		{
			for( int x = 0; x < m_pFractal->GetWidth( ); x++ )
			{
				// current index
				int ci = ( m_pFractal->GetWidth( ) * y ) + x + y; 

				// Iterate the fractal
				int n = m_pFractal->Iterate( x, y );

				// We found a point
				if( n == m_pFractal->GetPrecision( ) )
				{
					foundPoints++;

					if( foundPoints == word.size( ) )
					{
						// Loop throguh and set every single character in the buffer
						for( int i = 0; i < word.size( ); i++ )
						{
							int start = ci - word.size( ) + 1;
							pBuffer[ start + i ] = word[ i ];
						}

						// Resert the point counter
						foundPoints = 0;

						// Get a new word
						wordIndex += word.size( );
	
						word = m_pSyntax->GetWord( wordIndex );
						if( !word.size( ) ) // Make sure that the word is at least something...
						{
							word = " ";
						}
					}
				}
				// Reset the found points if we didn't find a point at this coord
				else
				{
					foundPoints = 0;
				}
			}
		}*/

		// Set end char
		pBuffer[ bufferSize - 1 ] = 0;

		return pBuffer;
	}

}