#ifndef PATTERNSEARCH_HPP
#define PATTERNSEARCH_HPP
//#include "SuffixArray.hpp"
#include <cstring>

namespace pattern_search
{

      bool search(int arr[], char (&pattern)[10], int size)
      {
        int m = strlen(pat);


        int l = 0, r = n-1;
        while (l <= r)
        {

            int mid = l + (r - l)/2;
            int res = strncmp(pat, txt+suffArr[mid], m);

            if (res == 0)
            {
                return true;
            }

            if (res < 0) r = mid - 1;


            else l = mid + 1;
        }


     return false;
    }
#endif
