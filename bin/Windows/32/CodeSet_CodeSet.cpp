                                                                #includ                             
                                                                e <Code                             
                                                                 Set.                               
                                                          h pp> #include <f s                       
                                                    tre am> #include <iostream   >                  
                                                      namespace CS {   // Constructo                
                                                   r/destructor  CodeSet::CodeSet(                  
                                                Fractal * p_pFractal, const int p_Pr                
                                                ecision, const double p_Zoom ) :   m_               
                                               pFractal( p_pFractal ),   m_Precision(               
                                  p           _Precision ),   m_Zoom( p_Zoom )  {  }                
                              CodeSet::~     CodeSet( )  {  }   // Public general funct             
                           ion  bool CodeS   et::OpenFile( const char * p_pFilePath, i              
                          nt p_MaxLength )   {   // Open the file   std::ifstream fin(              
                       p  _pFilePath );   if( !fin.is_open( ) )   {    return false;                
   }    // Read the file size and set the read size   fin.seekg( std::ios::end );                   
                           int fileSize = fin.tellg( );   fin.seekg( 0 );   int Read                
                          Size = fileSize <  p_MaxLength ? fileSize : p_MaxLength;                  
                           // Read the fil   e   char * pBuffer = new char[ ReadSize ]              
                             ;   fin.rea     d( pBuffer, ReadSize );   m_String = pBuff             
                             e    r           ;   delete [ ] pBuffer;    // Close the               
                                               file   fin.close( );    return true;                 
                                                }   void CodeSet::ProcessString( )  {               
                                                  }   char * CodeSet::WriteToString(                
                                                    )  {   return NULL;  }   bool C                 
                                                     odeSet::WriteToFile( const char                
                                                     *  p_pFilePath )  {   //    Op                 
                                                          e n the file   st d                       
                                                                 ::of                               
                                                                stream                              
