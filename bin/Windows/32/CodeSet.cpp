#include <CodeSet.hpp>
#include <fstream>
#include <iostream>

namespace CS
{

	// Constructor/destructor
	CodeSet::CodeSet( Fractal * p_pFractal, const int p_Precision, const double p_Zoom ) :
		m_pFractal( p_pFractal ),
		m_Precision( p_Precision ),
		m_Zoom( p_Zoom )
	{
	}

	CodeSet::~CodeSet( )
	{
	}

	// Public general function
	bool CodeSet::OpenFile( const char * p_pFilePath, int p_MaxLength )
	{
		// Open the file
		std::ifstream fin( p_pFilePath );
		if( !fin.is_open( ) )
		{
			return false;
		}

		// Read the file size and set the read size
		fin.seekg( std::ios::end );
		int fileSize = fin.tellg( );
		fin.seekg( 0 );
		int ReadSize = fileSize < p_MaxLength ? fileSize : p_MaxLength;

		// Read the file
		char * pBuffer = new char[ ReadSize + 1 ];
		pBuffer[ ReadSize ] = 0;
		fin.read( pBuffer, ReadSize );
		m_String = pBuffer;
		delete [ ] pBuffer;

		// Close the file
		fin.close( );

		return true;
	}

	void CodeSet::ProcessString( )
	{
	}

	char * CodeSet::WriteToString( )
	{
		return NULL;
	}

	bool CodeSet::WriteToFile( const char * p_pFilePath )
	{
		// Open the file
		std::ofstream fout( p_pFilePath );
		if( !fout.is_open( ) )
		{
			return false;
		}

		
		// Loop through the fractal size
		int CurrChar = 0;
		bool KeepLooping = true;

		for( int y = 0; y < m_pFractal->GetHeight( ); y++ )
		{
			for( int x = 0; x < m_pFractal->GetWidth( ); x++ )
			{
				int n = m_pFractal->Iterate( x, y, m_Precision, m_Zoom );

				if( n == m_Precision )
				{
					fout << "#";
					//fout << m_String[ CurrChar ];
					CurrChar++;

					if( CurrChar == m_String.size( ) )
					{
						KeepLooping = false;
						break;
					}

					std::cout << "#";
				}
				else
				{
					//fout << " ";
					std::cout << " ";
				}
			}

			if( !KeepLooping )
			{
				break;
			}

			//fout << "\n";
		}


		//fout.write( m_String.c_str( ), m_String.size( ) );

		// Close the file 
		fout.close( );

		return true;
	}

	// Set functions
	void CodeSet::SetString( const std::string & p_String )
	{
	}

	void CodeSet::SetPrecision( const int p_Precision )
	{
		m_Precision = p_Precision;
	}

	void CodeSet::SetZoom( const double p_Zoom )
	{
		m_Zoom = p_Zoom;
	}

	// Get functions
	int CodeSet::GetPrecision( ) const
	{
		return m_Precision;
	}