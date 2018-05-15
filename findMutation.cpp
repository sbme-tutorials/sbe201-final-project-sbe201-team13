#include "helpers.hpp"
#include "SuffixArray.hpp"

int main( int argc, char **argv )
{
    if( argc != 3 )
    {
        std::cout << "Invalid usage!" << '\n';
        return 1;
    }
    else
    {
        int size = 0;
        char *dna = getDNA( argv[1], 0, size );
        
        int *suffixArr = buildSuffixArray( dna, size );
        
        int patternsNum = 0;
        auto &patterns = *getPatterns( argv[2], 0, patternsNum );
        
        //Now the patterns are patterns[0], patterns[1],......,patterns[patternsNum-1] of type std::string
        //Complete the logic for searching the patterns
    }
}
