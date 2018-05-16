#ifndef patternsearch2_HPP
#define patternsearch2_HPP

#include <cstring>

int searchptn(char *pat, char *txt, int *suffArr, int n)
{ 
  
    int m = strlen(pat);  
 
    int l = 0, r = n-1; 
    while (l <= r)
    {
        
        int mid = l + (r - l)/2;
        int res = strncmp(pat, txt+suffArr[mid], m);
 
        if (res == 0)
        {
           return 1;
        }
 
        if (res < 0) r = mid - 1;
 
        
        else l = mid + 1;
    }

 return 0;
}

#endif