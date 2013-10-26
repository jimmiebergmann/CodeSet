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

#ifndef __CS_SYNTAX_HPP__
#define __CS_SYNTAX_HPP__

#include <string>

namespace CS
{

	class Syntax
	{

	public:

		// Constructor/destructor
		Syntax( );
		virtual ~Syntax( );

		// Virtual functions
		virtual void MakeCompact( ) = 0;
		virtual std::string GetWord( const unsigned int p_Index ) = 0;

		// Public general function
		bool ReadFile( const char * p_FilePath, const int p_MaxCharacters );

		// Set functions
		void SetText( const std::string & p_Text );
		void SetPreCode( const std::string & p_PreCode );
		void SetPostCode( const std::string & p_PostCode );

		// Get functions
		const std::string & GetText( ) const;
		const std::string & GetPreCode( ) const;
		const std::string & GetPostCode( ) const;

	protected:

		std::string m_Text;
		std::string m_PreCode;
		std::string m_PostCode;

	};

};

#endif