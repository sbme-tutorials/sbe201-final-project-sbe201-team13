#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

char *getDNA( const char *filepath, int lineNum, int &size)
{
    std::ifstream f( filepath );
    std::string line;
    
    if( f )
    {
        int i = 0;
        while( std::getline( f, line ) )
        {
            if( i == lineNum )  break;
            else ++i;
        }
    }
    else std::cout << "Failed to open file:" << filepath << '\n';
    
    char *buffer = new char[ line.size()+1 ];
    buffer[ line.size() ] = '\0';
    std::copy( line.begin(), line.end(), &buffer[0] );
    size = line.size();
    return buffer;
}

int remainderExist( int size )
{
    if( size%10 )  return 1;
    else    return 0;
}

std::vector<std::string> *getPatterns( const char *filepath, int lineNum, int &patternsNum )
{
    std::ifstream f( filepath );
    std::string line;
    //std::vector < std::string > patterns;
    
    if( f )
    {
        int i = 0;
        while( std::getline( f, line ) )
        {
            if( i == lineNum )  break;
            else ++i;
        }
    }
    else std::cout << "Failed to open file:" << filepath << '\n';
    
    patternsNum = line.size()/10 + remainderExist( line.size() );
    std::vector < std::string > *patterns = new std::vector < std::string >(patternsNum);
    
    int counter = 0;
    for( int i = 0; counter < patternsNum; i += 10 )
    {
        if( !counter==(patternsNum-1) ) patterns->push_back( line.substr(i,10) );
        else    patterns->push_back( line.substr(i) );
        ++counter;
    }
    
    return patterns;
}


#endif
