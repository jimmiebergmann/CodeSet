                                                                                         #include <                                         
                                                                                         CodeSet.hp                                         
                                                                                           p>  #i                                           
                                                                                 nc lude <fstream>  #incl ud                                
                                                                        e <i  ostream>    namespace CS  {         // C                      
                                                                          onstructor/destructor   CodeSet::CodeSet( Fr                      
                                                                       actal * p_pFractal, const int p_Precision, c                         
                                                                   onst double p_Zoom ) :    m_pFractal( p_pFractal ),                      
                                                                       m_Precision( p_Precision ),    m_Zoom( p_Zoom )                      
                                                                  {   }     CodeSet::~CodeSet( )   {   }     // Public                      
                                        ge   n  e               ral function   bool CodeSet::OpenFile( const char * p_pF                    
                                         ilePath, int p_       MaxLength )   {    // Open the file    std::ifstream fin(                    
                                     p_pFilePath );    if(    !fin.is_open( ) )    {     return false;    }      // Read                    
                                      the file size and set t he read size    fin.seekg( std::ios::end );    int fileSiz                    
                              e =   fin.tellg( );    fin.seek g( 0 );    int ReadSize = fileSize < p_MaxLength ? file                       
Size : p_MaxLength;      // Read the file    char * pBuffer = new char[ ReadSize + 1 ];    pBuffer[ ReadSize ] = 0                          
                              ;      fin.read( pBuffer, ReadS ize );    m_String = pBuffer;    delete [ ] pBuffer;                          
                                        // Close the file     fin.close( );      return true;   }     void CodeSet::Proc                    
                                     essString( )   {   }        char * CodeSet::WriteToString( )   {    return NULL;                       
                                         }     bool Code       Set::WriteToFile( const char * p_pFilePath )   {    // Ope                   
                                        n    t  h               e file    std::ofstream fout( p_pFilePath );    if( !fou                    
                                                                 t.is_open( ) )    {     return false;    }          //                     
                                                                    Loop through the fractal size    int CurrChar = 0;                      
                                                                     bool KeepLooping = true;      for( int y = 0; y <                      
                                                                        m_pFractal->GetHeight( ); y++ )    {     fo                         
                                                                          r( int x = 0; x < m_pFractal->GetWidth( ); x                      
                                                                        ++ )       {      int n = m_pFractal-    >Iter                      
                                                                                 at e( x, y, m_Precision,  m                                
                                                                                           _Zoom                                            
                                                                                         );                                                 
