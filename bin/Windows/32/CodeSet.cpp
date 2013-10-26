#include <string>
#include <iostream>
#include <fstream>


namespace CS1
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

		// Get functions
		const std::string & GetText( ) const;

	protected:

		std::string m_Text;

	};

};



namespace CS1
{

	// Constructor/destructor
	Syntax::Syntax( ) :
		m_Text( "" )
	{
	}

	Syntax::~Syntax( )
	{
	}

	// Public general function
	bool Syntax::ReadFile( const char * p_pFilePath, const int p_MaxCharacters )
	{
		// Open the file
		std::ifstream fin( p_pFilePath, std::fstream::binary );
		if( !fin.is_open( ) )
		{
			return false;
		}

		// Read the file size
		fin.seekg( 0, fin.end );
		int fileSize = fin.tellg( );
		fin.seekg( 0, fin.beg );
		int readSize = ( fileSize < p_MaxCharacters ) ? fileSize : p_MaxCharacters;
		m_Text.reserve( readSize + 1 );

		// Read all the lines
		int currentSize = 0;
		std::string tempString;
		tempString.reserve( 128 );
		while( !fin.eof( ) )
		{
			// Get another 
			std::getline( fin, tempString );

			// Remove the newline(if any)
			if( tempString.size( ) > 1 )
			{
				tempString.erase( tempString.size( ) - 1, 1 );
			}

			// Cur the line if needed and then break( too many characters
			currentSize += tempString.size( );
			if( currentSize > readSize )
			{
				tempString[ currentSize - readSize ] = 0;
				m_Text += tempString + '\n';
				break;
			}

			m_Text += tempString + '\n';	 

		}

		// Close the file
		fin.close( );

		return true;
	}

	// Set functions
	void Syntax::SetText( const std::string & p_Text )
	{
		m_Text = p_Text;
	}

	// Get functions
	const std::string & Syntax::GetText( ) const
	{
		return m_Text;
	}


}