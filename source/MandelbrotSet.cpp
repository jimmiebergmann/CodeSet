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

#include <MandelbrotSet.hpp>
#include <ComplexNumber.hpp>

namespace CS
{


	// Constructor/destructor
	MandelbrotSet::MandelbrotSet(	const int p_Width, const int p_Height,
									const int p_Precision, const double p_Zoom,
									const double p_GridScaleX, const double p_GridScaleY,
									const double p_GridDiffX, const double p_GridDiffY ) :
	Fractal(	p_Width,
				p_Height,
				p_Precision,
				p_Zoom,
				p_GridScaleX,
				p_GridScaleY,
				p_GridDiffX,
				p_GridDiffY )
	{
	}

	MandelbrotSet::~MandelbrotSet( )
	{
	}

	// Public general function
	int MandelbrotSet::Iterate( const int p_X, const int p_Y )
	{
		double newx = ( m_GridScaleX / ( (double)m_Width / (double)p_X ) + m_GridDiffX ) / m_Zoom;
		double newy = ( m_GridScaleY / ( (double)m_Height / (double)p_Y ) + m_GridDiffY) / m_Zoom;

		ComplexNumber<double> c( newx, newy );
		ComplexNumber<double> z( c );
		int n = 0;

		while( (z.x*z.x + z.y*z.y) < 4.0f && n < m_Precision )
		{
			// Multiply the complex number z with z, then add c
			z = z.Square( ) + c;

			// Increment the iterator
			n++;
		}

		return n;
	}


}