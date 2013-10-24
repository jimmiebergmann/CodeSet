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

#ifndef __CS_FRACTAL_HPP__
#define __CS_FRACTAL_HPP__

namespace CS
{

	class Fractal
	{

	public:

		// Constructor/destructor
		Fractal(	const int p_Width, const int p_Height,
					const double p_GridScaleX, const double p_GridScaleY,
					const double p_GridDiffX, const double p_GridDiffY );
		virtual ~Fractal( );

		// Public general function
		virtual int Iterate( const int p_X, const int p_Y, const int p_Precision, const double p_Zoom ) = 0;
		
		// Set functions
		void SetWidth( const int p_Width );
		void SetHeight( const int p_Height );
		void SetSize( const int p_Width, const int p_Height );

		// Get functions
		int GetWidth( ) const;
		int GetHeight( ) const;

	protected:

		int m_Width;
		int m_Height;
		double m_GridScaleX;
		double m_GridScaleY;
		double m_GridDiffX;
		double m_GridDiffY;

	};

};

#endif