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

#ifndef __CS_CODESET_HPP__
#define __CS_CODESET_HPP__

#include <Fractal.hpp>
#include <string>

namespace CS
{

	class CodeSet
	{

	public:

		// Constructor/destructor
		CodeSet( Fractal * p_pFractal, const int p_Precision, const double p_Zoom );
		~CodeSet( );

		// Public general function
		bool OpenFile( const char * p_pFilePath, int p_MaxLength );
		void ProcessString( ); // Remove comments, gaps, ...
		char * WriteToString( );
		bool WriteToFile( const char * p_pFilePath );

		// Set functions
		void SetString( const std::string & p_String );
		void SetPrecision( const int p_Precision );
		void SetZoom( const double p_Zoom );

		// Get functions
		int GetPrecision( ) const;
		double GetZoom( ) const;

	private:

		Fractal * m_pFractal;
		int m_Precision;
		double m_Zoom;
		std::string m_String;

	};

}

#endif