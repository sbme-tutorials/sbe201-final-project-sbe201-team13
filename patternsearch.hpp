#ifndef PATTERNSEARCH_HPP
#define PATTERNSEARCH_HPP
//#include "SuffixArray.hpp"
#include <cstring>

namespace pattern_search
{

      bool search(int arr[], char (&pattern)[10], int size)
      {
            int right = size-1;
            int left= 0;


            while ( left < right )
            {
                  int mid = ( left + right ) / 2;

                  if ( strcmp( text[arr[mid]], pattern ) == 0 )

                        return true;

                  else if ( strcmp( text[arr[mid]], pattern ) > 0 )

                        right = mid - 1;
                  else
                        left = mid + 1;

            }
        return false;
      }
}
#endif
