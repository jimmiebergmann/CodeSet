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

#include <JuliaSet.hpp>
#include <ComplexNumber.hpp>
#include <cmath>

namespace CS
{


	// Constructor/destructor
	JuliaSet::JuliaSet(	const int p_Width, const int p_Height,
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

	JuliaSet::~JuliaSet( )
	{
	}

	// Public general function
	int JuliaSet::Iterate( const int p_X, const int p_Y )
	{
        ComplexNumber<double> c;
        c.x = (sin(cos(m_Zoom / 10) * 10) + cos(m_Zoom * 2.0) / 4.0 + sin(m_Zoom * 3.0) / 6.0) * 0.8;
        c.y = (cos(sin(m_Zoom / 10) * 10) + sin(m_Zoom * 2.0) / 4.0 + cos(m_Zoom * 3.0) / 6.0) * 0.8;
        
        const double scalex = 3.0;
        const double scaley = 2.0;
        const double diffx = -1.5f;
        const double diffy = -1.0f;

        ComplexNumber<double> z;
        z.x = ( scalex / ( (double)m_Width / (double)p_X ) + diffx ) / m_Zoom;
        z.y = ( scaley / ( (double)m_Height / (double)p_Y ) + diffy) / m_Zoom;

        int n;
		for( n = 0; n < m_Precision; n++ )
        {
            double newx = ( z.x * z.x - z.y * z.y ) + c.x;
            double newy = ( z.y * z.x + z.x * z.y ) + c.y;

            if( ( newx * newx + newy * newy ) > 4.0f )
            {
                    break;
            }

            z.x = newx;
            z.y = newy;
        }

        return n;

	}


}