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

#include <Fractal.hpp>

namespace CS
{


	// Constructor/destructor
	Fractal::Fractal(	const int p_Width, const int p_Height,
						const int p_Precision, const double p_Zoom,
						const double p_GridScaleX, const double p_GridScaleY,
						const double p_GridDiffX, const double p_GridDiffY ) :
		m_Width( p_Width ),
		m_Height( p_Height ),
		m_Precision( p_Precision ),
		m_Zoom( p_Zoom ),
		m_GridScaleX( p_GridScaleX ),
		m_GridScaleY( p_GridScaleY ),
		m_GridDiffX( p_GridDiffX ),
		m_GridDiffY( p_GridDiffY )
	{
	}

	Fractal::~Fractal( )
	{
	}


	// Set functions
	void Fractal::SetWidth( const int p_Width )
	{
		m_Width = p_Width;
	}

	void Fractal::SetHeight( const int p_Height )
	{
		m_Height = p_Height;
	}

	void Fractal::SetSize( const int p_Width, const int p_Height )
	{
		m_Width = p_Width;
		m_Height = p_Height;
	}

	void Fractal::SetPrecision( const int p_Precision )
	{
		m_Precision = p_Precision;
	}

	void Fractal::SetZoom( const double p_Zoom )
	{
		m_Zoom = p_Zoom;
	}

	// Get functions
	int Fractal::GetWidth( ) const
	{
		return m_Width;
	}

	int Fractal::GetHeight( ) const
	{
		return m_Height;
	}

	int Fractal::GetPrecision( ) const
	{
		return m_Precision;
	}

	double Fractal::GetZoom( ) const
	{
		return m_Zoom;
	}


}