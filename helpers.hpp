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

std::vector<char*> getPatterns( const char *filepath, int lineNum, int &size, int &patternsNum )
{
    std::ifstream f( filepath );
    std::string line;
    std::vector < char* > patterns;
    
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
    
    patternsNum = (line.size()+1)/10 + (line.size()+1)%10;
    
    int counter = 1;
    for( int i = 0; counter <= patternsNum; i = i+10 )
    {
        char *buffer = new char[11];
        buffer[11] = '\0';
        if( !counter==patternsNum )  std::copy( line[i], line[i+9], &buffer[0] );
        else    std::copy( line[i], line[line.size()-1], &buffer[0] );
        patterns.push_back( buffer );
        ++counter;
    }
    
    return patterns;
}

#endif
