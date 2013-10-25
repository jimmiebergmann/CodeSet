                                                                                                      namespaceCS                                               
                                                                                                      {                                               
                                                                                                                                                       
                                                                                                                                                  
                                                                                          SyntaxCPP::SyntaxCPP():Syntax(                                     
                                                                                   ){} SyntaxCPP::~SyntaxCPP(){}void                            
                                                                                     SyntaxCPP::MakeCompact(){boolIsMultiLineComment=                          
                                                                                 false;for(intl=0;l<m_Lines.size();l++){std::string                             
                                                                             word="";boolIsAString=false;for(intc=0;c<m_Lines[l].size                           
                                                                             ();c++){charcurrChar=m_Lines[l][c];if(IsAString&&currChar                         
                                                                          !='\"'){word+=currChar;continue;}if((l+1)<m_Lines.size()){if(                    
                                                                          currChar=='/'&&m_Lines[l][c+1]=='/'){if(word.size()){m_Words.                       
                                                                     push_back(word);word="";}break;}}if(word.size()){if(currChar==                       
                                               '\n'||currChar==         '\r'){if(word.size()){m_Words.push_back(word);word="";}continue;}if                     
                                             (currChar==''){if(      word.size()){m_Words.push_back(word);word="";}continue;}if(                       
                                           currChar==';'||currChar==   ','||currChar=='.'||currChar=='('||currChar==')'||currChar=='{'||                        
                                         currChar=='}'||currChar=='[' ||currChar==']'||currChar=='<'||currChar=='>'||currChar=='='||                         
                                     currChar=='+'||currChar=='-'||currChar=='*'||currChar=='/'){if(word.size()){m_Words.push_back                          
(word);word="";}word+=currChar;if((l+1)<m_Lines.size()){charnextChar=m_Lines[l][c+1];if(nextChar!='\r'&&nextChar!='\n'&&nextChar==                              
                                   '='  ||nextChar=='+'||nextChar=='-'||nextChar=='>'||nextChar=='<'){word+=nextChar;c++;}}m_Words.                          
                                         push_back(word);word=""; continue;}if(IsAString){if(currChar=='\"'){if(word.size()){word+=                         
                                           currChar;m_Words.   push_back(word);word="";}IsAString=false;continue;}}word+=                        
                                             currChar;continue;}      else{if(currChar==''){continue;}if(currChar=='\n'||currChar=='\r'                       
                                               ||currChar=='\t'         ){if(word.size()){m_Words.push_back(word);word="";}continue;}if(                     
                                                                     currChar=='#'){if(word.size()){m_Words.push_back(word);word="";}                       
                                                                          word+=m_Lines[l].substr(c);for(inti=0;i<word.size();i++){if(                       
                                                                          word[i]=='\r'||word[i]=='\n'){word.erase(i,1);}}m_Words.push_back(                    
                                                                             word);word="";break;}if(currChar=='\"'){word+=currChar;                         
                                                                             IsAString=true;continue;}if(currChar==';'||currChar==','                           
                                                                                 ||currChar=='('||currChar==')'||currChar=='{'||                             
                                                                                     currChar=='}'||currChar=='['||currChar==']'||                          
                                                                                    currChar=='<'||currChar=='>'||currChar  =='='                          
                                                                                   ||       currChar=='+'||currChar=='-'||                                     
                                                                                                    currChar=='*  '                                            
                                                                                                       ||                                                
                                                                                                      currChar=='                                               
