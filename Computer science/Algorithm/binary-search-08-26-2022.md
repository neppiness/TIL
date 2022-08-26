[TIL on August 26th, 2022](../../TIL/2022/08/08-26-2022.md)
# **Binary Search**

### What is a binary search?
- Binary search is an efficient algorithm for finding an item from *a sorted list of items*
   * It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one

#### Example
- The Tycho-2 star catalog contains information about the brightest 2,539,913 stars in our galaxy. Suppose that you want to search the catalog for a particular star, based on the star's name.
  * Linear search: If the program examined every star in the star catalog in order starting with the first, the computer might have to examine all *2,539,913* stars to find the star you were looking for, in the worst case
  * Binary search: If the catalog were sorted alphabetically by star names, this algorithm would not have to examine more than *22 stars*, even in the worst case

___


### References
1. [[실전 알고리즘] 0x13강 - 이분탐색](https://blog.encrypted.gg/985)
2. [Binary search: Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search#:~:text=Binary%20search%20is%20an%20efficient,possible%20locations%20to%20just%20one.)