#ifndef suffixArr_HPP
#define suffixArr_HPP

#include <cstring>
#include <algorithm>

struct suffix
{
    int index;
    char *suff;
};

bool cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0;
}

int *buildSuffixArray(char *txt, int size)
{
    suffix suffixes[size];
    for (int i = 0; i < size; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = txt + i;
    }

    std::sort(suffixes, suffixes + size, cmp);

    int *suffixArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        suffixArray[i] = suffixes[i].index;
    }
    return suffixArray;
}
#endif