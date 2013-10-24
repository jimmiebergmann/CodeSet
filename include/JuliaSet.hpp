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

#ifndef __CS_JULIASET_HPP__
#define __CS_JULIASET_HPP__

namespace CS
{

}

#endif

/*
static int IterateJulia( const double x, const double y, const int max, const double zoom )
{
	double t = zoom;
	ComplexNumber c;
	c.x = (sin(cos(t / 10) * 10) + cos(t * 2.0) / 4.0 + sin(t * 3.0) / 6.0) * 0.8;
	c.y = (cos(sin(t / 10) * 10) + sin(t * 2.0) / 4.0 + cos(t * 3.0) / 6.0) * 0.8;
	

	
	const double scalex = 3.0;
	const double scaley = 2.0;
	const double diffx = -1.5f;
	const double diffy = -1.0f;

	ComplexNumber z;
	z.x = ( scalex / ( (double)width / (double)x ) + diffx ) / zoom;
	z.y = ( scaley / ( (double)height / (double)y ) + diffy) / zoom;

	int n;

	for( n = 0; n < max; n++ )
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
	//while( (z.x*z.x + z.y*z.y) < 16.0f && n < max )
	//{
		// Multiply the complex number z with z, then add c
		//z = z.Square( ) + c;

		//n++;
	//}

	return n;
}

*/