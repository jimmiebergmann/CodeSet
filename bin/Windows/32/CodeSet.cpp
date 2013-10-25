
namespace CS
{

	// Constructor/destructor
	SyntaxCPP::SyntaxCPP( ) :
		Syntax( )
	{

	}

	SyntaxCPP::~SyntaxCPP( )
	{

	}

	// Public general function
	void SyntaxCPP::MakeCompact( )
	{
		// Loop through all the lines
		bool IsMultiLineComment = false;

		for( int l = 0; l < m_Lines.size( ); l++ )
		{
			std::string word = "";
			bool IsAString = false;

			// Loop through all the characters in the line
			for( int c = 0; c < m_Lines[ l ].size( ); c++ )
			{
				char currChar = m_Lines[ l ][ c ];


				// Are we collecting a string?
				if( IsAString && currChar != '\"')
				{
 					word += currChar;
					continue;
				}

				// Remove comments
				

				if( ( l + 1 ) < m_Lines.size( ) )
				{
					// Single line comments
					if( currChar == '/' &&
						m_Lines[ l ][ c + 1 ] == '/' )
					{
						// Finish the word
						if( word.size( ) )
						{
							m_Words.push_back( word );
							word = "";
						}
						break;
					}
				}


				if( word.size( ) )
				{

					// Check for new lines, the word is done
					if( currChar == '\n' ||
						currChar== '\r' )
					{
						// Finish the word
						if( word.size( ) )
						{
							m_Words.push_back( word );
							word = "";
						}
						continue;
					}

					// Check for spaces and preriods, the word is done
					if( currChar == ' ' )
					{
						// Finish the word
						if( word.size( ) )
						{
							m_Words.push_back( word );
							word = "";
						}
						continue;
					}

					// Check for special characters
					if( currChar == ';' ||
						currChar == ',' ||
						currChar == '.' ||
						currChar == '(' ||
						currChar == ')' ||
						currChar == '{' ||
						currChar == '}' ||
						currChar == '[' ||
						currChar == ']' ||
						currChar == '<' ||
						currChar == '>' ||
						currChar == '=' ||
						currChar == '+' ||
						currChar == '-' ||
						currChar == '*' ||
						currChar == '/' )
					{
						// Finish the word
						if( word.size( ) )
						{
							m_Words.push_back( word );
							word = "";
						}

						// Add the chracter
						word += currChar;

						// Special case for operators
						if( ( l + 1 ) < m_Lines.size( ) )
						{
							char nextChar = m_Lines[ l ][ c + 1 ];
							
							if( nextChar != '\r' && nextChar != '\n' &&
								nextChar == '=' ||
								nextChar == '+' ||
								nextChar == '-' ||
								nextChar == '>' ||
								nextChar == '<' )
							{
								// Push back the sign to the word vector
								word += nextChar;

								// Move to the next character
								c++;
							}
								
						}

						m_Words.push_back( word );
						word = "";
						continue;
					}

					// This is the end of a string
					if( IsAString )
					{
						if( currChar == '\"' )
						{
							// Push back the old word
							if( word.size( ) )
							{
								word += currChar;
								m_Words.push_back( word );
								word = "";
							}

							IsAString = false;
							continue;
						}
					}

					// Add the character to the word
					word += currChar;
					continue;					
				}
				// Not started on a word yet
				else
				{
					// Ignore spaces
					if( currChar == ' ' )
					{
						continue;
					}

					// Skrip newline, tab and space
					if( currChar == '\n' ||
						currChar== '\r' ||
						currChar== '\t' )
					{
						// Push back the old word
						if( word.size( ) )
						{
							m_Words.push_back( word );
							word = "";
						}

						continue;
					}

					// Preprocessor?
					if(	currChar == '#' )
					{
						// Push back the old word
						if( word.size( ) )
						{
							m_Words.push_back( word );
							word = "";
						}

						// Puch back the rest of the line
						word +=  m_Lines[ l ].substr( c );

						// Remove newlines in the word
						for( int i = 0; i < word.size( ); i++ )
						{
							if( word[ i ] == '\r' ||
								word[ i ] == '\n' )
							{
								word.erase( i, 1 );
							}
						}

						m_Words.push_back( word );
						word = "";

						// We are done with this line
						break; 
					}

					// Is this a string?
					if( currChar == '\"' )
					{
						// This is a new string
						word += currChar;
						IsAString = true;
						continue;
					}

					// Add single character words
					if(	currChar == ';' ||
						currChar == ',' ||
						currChar == '(' ||
						currChar == ')' ||
						currChar == '{' ||
						currChar == '}' ||
						currChar == '[' ||
						currChar == ']' ||
						currChar == '<' ||
						currChar == '>' ||
						currChar == '=' ||
						currChar == '+' ||
						currChar == '-' ||
						currChar == '*' ||
						currChar == '/' ||
						currChar == '!' )
					{
						// Push back the old word
						if( word.size( ) )
						{
							m_Words.push_back( word );
							word = "";
						}

						// Push back the sign to the word vector
						word += currChar;

						// Special case for operators
						if( ( l + 1 ) < m_Lines.size( ) )
						{
							char nextChar = m_Lines[ l ][ c + 1 ];
							
							if( nextChar != '\r' && nextChar != '\n' &&
								nextChar == '=' ||
								nextChar == '+' ||
								nextChar == '-' ||
								nextChar == '>' ||
								nextChar == '<' )
							{
								// Push back the sign to the word vector
								word += nextChar;

								// Move to the next character
								c++;
							}
								
						}

						m_Words.push_back( word );
						word = "";
						continue;
					}

					// Ok so, we found a character that is the beginning of a word
					word += currChar;
				}
			}
		}

		for( int i = 0; i < 80; i++ )
		{
			std::cout << i << ": " << m_Words[ i ] << std::endl;
		}


	}

}