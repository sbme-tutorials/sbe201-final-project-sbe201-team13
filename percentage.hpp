#ifndef PER_HPP
#define PER_HPP

namespace PER 
{
double Per(char *pat, char *txt, int *suffArr, int n,&z,&y)
{ 
  
    int m = strlen(pat);  
 
    
    int l = 0, r = n-1; 
    while (l <= r)
    {
        
        int mid = l + (r - l)/2;
        int res = strncmp(pat, txt+suffArr[mid], m);
 
        if (res == 0)
        {
            z=z+1;
        }
 
        if (res < 0) r = mid - 1;
 
        
        else l = mid + 1;
    }
 
    y=y+1;
 return (z/(z+y));
}
}

#endif