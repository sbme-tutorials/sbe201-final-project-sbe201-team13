# Introduction

It is important to know that the most cancers are what we call **sporadic cancers**, these are isolated cases of cancer that are caused by
   * age
   * lifestyle 
   * environment 
   
Not by genetic risk factors.

 People who have sporadic cancers and their families have an average chance of getting cancer themselves and can follow the usual recommendations for cancer prevention and monitoring.

 A smaller group of families have what we call **hereditary cancer** in these families there is a strong inherited risk factor for cancer and  this is stronger than lifestyle and environment although life style and environment are still important.

 Hereditary cancer is not common but it is important to find these families because some people in the family have a higher chance of getting cancer, their information we can use to offer people medical care that can help them prevent cancer or catch it early.

We have two tools to find families with hereditary cancer 
  * Family history 
  * Genetic testing 

 It is important to use both family history and genetic testing together because each of them gives us different kinds of information and by putting them together we can have the most accurate picture of someone chances of getting cancer.

 Let’s take a closure look at **family history** in families with **sporadic cancer** and those with **hereditary cancer**

|Sporadic                                   |Hereditary                                   |
|-------------------------------------------|---------------------------------------------|
|   Cancer at later ages.                   |   Cancer at young ages.                     |  
|   Few people in the family who had cancer.|   Multiple family members.                  |
|   Different types of cancer.              |   Same or related types of cancer.          |
|                                           |   Rare cancers                              |

**Genetic testing** can help us to get more information as you may know we inherit from our mother in an egg and our father in a sperm a complete set of genetic information for how our body will grow and develop there are thousands of different genes and each gene is a set of instructions for something specific.

 The genes we are look at in hereditary cancer are called **tumor suppressor genes** and it have a normal job in our body which is helping to control how our cells grow and protect us from developing cancer.

 We have two copies of each tumor suppressor gene one from our mother and one from our father e.g. **BRCA1** and **BRCA2** genes **involved in hereditary breast and ovarian cancer**.

In families with hereditary cancer one of these important tumor suppressor genes is not working properly the technical word that we use for this is a **mutation**.

 A good analogy is making a spelling mistake in a set of instructions, a spelling mistake in the instructions is the same as a mutation in a tumor suppressor gene the body can’t use that information any more to protect us from getting cancer.

 Someone who has a mutation in a tumor suppressor gene is not automatically develop cancer, in fact most of these people will not get cancer for many years or may be never at all that’s because we have two copies of each of these genes and the copy from other parent can still work to protect us from getting cancer.

 While we have been using the term hereditary cancer it’s more accurate to say people with a mutation in a tumor suppressor gene have a hereditary predisposition to cancer, this is a long way of saying they have a higher chance of developing cancer than other people.

 We don’t do genetic testing just to tell people that they have a higher chance of getting cancer, we do genetic testing to find people who have a higher chance of getting cancer, so that we can offer them options for cancer monitoring and cancer prevention that are specific to them.

# Suffix array

The problem of finding the occurrences of a pattern string in a given text is one of the most fundamental computational tasks in bioinformatics. In most bioinformatics applications, the text is a huge database onto which a large volume of pattern queries are thrown. In such cases, precomputing an indexed data structure of the text allows efficient processing of pattern searches.

One simple and effective data structure is a **suffix array**, which informally is a list of the starting positions of the suffixes of the text, sorted by their alphabetical order. Suffix arrays are easy to understand and implement and form the basis for a host of other sophisticated indexing techniques.

## Building suffix array

There are many algorithms that can be used to construct a suffix array we have used **Naive method** to build Suffix Array.

**Naive method** to build Suffix Array:

A simple method to construct suffix array is to make an array of all suffixes and then sort the array.

Example:

Let the given string be "banana".
```c++
0 banana                          5 a
1 anana     Sort the Suffixes     3 ana
2 nana      ---------------->     1 anana  
3 ana        alphabetically       0 banana  
4 na                              4 na   
5 a                               2 nana
```
So the suffix array for "banana" is {5, 3, 1, 0, 4, 2}

The time complexity for this method is about O(n2Logn) if we consider a O(nLogn) algorithm used for sorting. The sorting step itself takes O(n2Logn) time as every comparison is a comparison of two strings and the comparison takes O(n) time.

Suffix array is an efficient in space as it requires about (4n).

## Searching 

**Searching patterns**

To find how much of the  sequence we’re searching for have been located in the genome we have break down the long sequence into small pieces of 10 characters then searching for each piece in the genome and calculate how many word have been found.

**Searching method**

To search a pattern in a text, we preprocess the text and build a suffix array of the text. Since we have a sorted array of all suffixes, Binary Search can be used to search.

**Binary Search**

Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty, the time complexity of the  search function is O(nLogn).

### example 
We search for a pattern **na** in the previous suffix array {5, 3, 1, 0, 4, 2}. We jump to the middle of the suffix array (**array [2]**) which is index **1** 
```c++
is na == anana?
  false
else is na> anana?->true
  jump to middle of array {0,4,2}
```
Now we jump to the middle of the array which is **4**
```c++
is na == na?
  true
  na found at index 4
```
There are more efficient algorithms to search pattern once the suffix array is built.

# Finding Mutation
To find  mutations we use both searching patterns and dividing methods. We divide a mutated pattern into small patterns and searching for all patterns until found one in the sequance which is unmutated pattern. We can find mutations locations by more dividing and searching.
### example
assume a mutated **banmna** and the real pattern is **banana** as the pervious two examples.How can we find the mutation location?

**First** divide the pattern into two small patterns **ban** and **mna**.
second we search fo the pattern **ban** as pervious which will be found at location **0** and knowing that the pattern lenght is 3 characters we can estimate that no mutation happend before the index **2**. (1)

**Second** we searching for the second pattern **mna** which will not be found the pattern **banana**. so we divide it again into two halfs **m** and **na**.

**Third** we repeat first and second steps until we found the mutation. We search for **m** which will not be found.Then, We search for **na** which will be found at index **4** and knowing that it's length is **2**, we can estimate that no mutation have been happend between indexes: **2** and **5**. (2)

**Using** informations at (1) and (2), we can estimate that the mutation happend between the indexes **2** and **4** which is the index **3**.



 




## References

1. [Suffix array](https://en.wikipedia.org/wiki/Suffix_array), *Wikipedia*.
2. [Suffix array](https://www.geeksforgeeks.org/suffix-array-set-1-introduction/), *geeksforgeeks*. 
3. [Suffix array](https://academic.oup.com/bib/article/15/2/138/212729).
 