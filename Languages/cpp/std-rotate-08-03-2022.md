[TIL on August 3rd, 2022](../../TIL/2022/08/08-03-2022.md)
# **std::rotate**
- In `<algorithm>` header

### Rotate left the elements in range
- Rotates the order of the elements in the range [first,last), in such a way that the element pointed by `middle` becomes the new first element.

```cpp
template <class ForwardIterator>
  void rotate (ForwardIterator first, ForwardIterator middle,
               ForwardIterator last)
{
  ForwardIterator next = middle;
  while (first!=next)
  {
    swap (*first++,*next++);
    if (next==last) next=middle;
    else if (first==middle) middle=next;
  }
```
### Parameters
`first, last`
- Forward iterators to the initial and final positions of the sequence to be rotated left
- The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last.
- Notice that in this function these are not consecutive parameters, but the first and the third.

`middle`
- Forward iterator pointing to the element within the range [first,last) that is moved to the first position in the range.

`ForwardIterator` shall point to a type for which swap is properly defined and which is both move-constructible and move-assignable.

### Example
```cpp
#include <iostream>     // std::cout
#include <algorithm>    // std::rotate
#include <vector>       // std::vector

int main () {
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  std::rotate(myvector.begin(),myvector.begin()+3,myvector.end()); // 4 5 6 7 8 9 1 2 3
  //   rotate(first           ,middle            ,last          );
  // middle is moved to the first position in the range
  return 0;
}
```
___

### References
1. [std::rotate](https://cplusplus.com/reference/algorithm/rotate/)