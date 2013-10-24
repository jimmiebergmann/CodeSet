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
#include <MandelbrotSet.hpp>
#include <iostream>

using namespace CS;

int CloseApplication( )
{
	std::cin.get( );
	return 0;
}

int main( )
{
	// Settings
	const int width = 100;
	const int height = 30;

	// Create the codeset, use a mandelbrot set
	Fractal * pFractal = new MandelbrotSet( width, height, 3.5, 2, -2.5, -1 );
	CodeSet codeSet( pFractal, 5000, 1.3f );

	// Open the file we want
	if( !codeSet.OpenFile( "CodeSet.cpp", width * height * 4 ) )
	{
		std::cout << "Can not open the file." << std::endl;
		return CloseApplication( );
	}

	// Process the file data
	codeSet.ProcessString( );

	// Write the file
	if( !codeSet.WriteToFile( "CodeSet_CodeSet.cpp" ) )
	{
		std::cout << "Can not write to file." << std::endl;
		return CloseApplication( );
	}



	// Clean up
	delete pFractal;

	/*const int width = 80;
	const int height = 22;
	const int precision = 10000;

	MandelbrotSet ms( width, height, 3.5, 2, -2.5, -1 );
	
	for( int y = 0 ; y < height; y++ )
	{
		for( int x = 0 ; x < width; x++ )
		{
			if( ms.Iterate( x, y, precision, 1.3 ) == precision )
			{
				std::cout << "#";
			}
			else
			{
				std::cout << " ";
			}
		}
	}*/


	return 0;
}