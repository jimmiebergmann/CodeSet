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

#ifndef __CS_SYNTAX_CPP_HPP__
#define __CS_SYNTAX_CPP_HPP__

#include <Syntax.hpp>

namespace CS
{

	class SyntaxCPP : public Syntax
	{

	public:

		// Constructor/destructor
		SyntaxCPP( );
		~SyntaxCPP( );

		// Public virtual functions
		virtual void MakeCompact( );
		virtual std::string GetWord( const unsigned int p_Index );

	private:

		void RemoveMultiLineComments( );
		void RemoveSingleLineComments( );
		void MakePreCode( );
		void MakePostCode( );
		void RemoveTabsNewlines( );

		
	};

}

#endif