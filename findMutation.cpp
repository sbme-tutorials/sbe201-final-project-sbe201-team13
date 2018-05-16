#include "helpers.hpp"
#include "SuffixArray.hpp"
#include <cstring>
#include "patternsearch2.hpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Invalid usage!" << '\n';
        return 1;
    }
    else
    {
        int size = 0;
        char *dna = getDNA(argv[1], 0, size);

        int *suffixArr = buildSuffixArray(dna, size);

        int patternsNum = 0;

        float found = 0;
        //std::vector<std::string> &patterns = *getPatterns(argv[2], 0, patternsNum);
        auto patterns = getPatterns(argv[2], 0, patternsNum);
        //char char_array[num];
        for (int i = 0; i < patternsNum; i++)
        {
            // std::strcpy(char_array, patterns[i].c_str());

            found = found + searchptn(&patterns[i * num], dna, suffixArr, size, num);
        }

        float present = found / patternsNum * 100;
        std::cout << "mutation presentage ";
        std::cout << present << "%" << std::endl;
        if (present < 15)
        {
            std::cout << "congratulation you are safe" << std::endl;
        }
        //Now the patterns are patterns[0], patterns[1],......,patterns[patternsNum-1] of type std::string
        //Complete the logic for searching the patterns
    }
    return 0;
}
