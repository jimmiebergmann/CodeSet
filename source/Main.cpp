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
#include <JuliaSet.hpp>
#include <SyntaxCPP.hpp>
#include <iostream>

using namespace CS;


// Settings
static const int width = 140;
static const int height = 30;

static Syntax * pSyntax = NULL;
static Fractal * pFractal = NULL;
static CodeSet * pCodeSet = NULL;

static int CloseApplication( );


int main( )
{
	// Create a syntax
	pSyntax = new SyntaxCPP( );
	
	// Read the file
	if( !pSyntax->ReadFile( "CodeSet.cpp", width * height * 4 ) )
	{
		std::cout << "Can not open the file." << std::endl;
		return CloseApplication( );
	}

	// Generate the words
	pSyntax->MakeCompact( );



	// Create a fractal
	pFractal = new MandelbrotSet( width, height, 5000, 1.3f, 3.5, 2, -2.5, -1 );
	//Fractal * pFractal = new JuliaSet( width, height, 5000, 1.2f, 3.5, 2, -2.5, -1 );



	// Create the codeset, use a mandelbrot set
	pCodeSet = new CodeSet( pSyntax, pFractal );

	// Write code set to a file
	if( !pCodeSet->WriteToFile( "CodeSet_CodeSet.cpp" ) )
	{
		std::cout << "Can not write to file." << std::endl;
		return CloseApplication( );
	}



	return CloseApplication( );
}

int CloseApplication( )
{
	if( pSyntax )
	{
		delete pSyntax;
		pSyntax = NULL;
	}

	if( pFractal )
	{
		delete pFractal;
		pFractal = NULL;
	}

	if( pCodeSet )
	{
		delete pCodeSet;
		pCodeSet = NULL;
	}

	return 0;
}