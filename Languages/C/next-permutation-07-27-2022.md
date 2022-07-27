[TIL on July 27th, 2022](../../TIL/2022/07/07-27-2022.md)
# **std::next_permutation**

### Transform range to next permutation
- Rearranges the elements in the range [first,last) into the next lexicographically (in dictionary order) greater permutation
- A permutation is each one of the N! possible arrangements the elements can take (where N is the number of elements in the range)
- Different permutations can be ordered according to how they compare lexicographicaly to each other; The first such-sorted possible permutation (the one that would compare lexicographically smaller to all other permutations) is the one which has all its elements sorted in ascending order, and the largest has all its elements sorted in descending order
- The comparisons of individual elements are performed using either operator `<` for the first version, or `comp` for the second

#### Permutations and return value
- If the function can determine the next higher permutation, it rearranges the elements as such and returns true
- If that was not possible (because it is already at the largest possible permutation), it rearranges the elements according to the first permutation (sorted in ascending order) and returns false.

<br>

### Parameters
`first, last`
- Bidirectional iterators to the initial and final positions of the sequence
- The range used is [first,last), which contains all the elements between first and last, including the element pointed by first but not the element pointed by last
- BidirectionalIterator shall point to a type for which swap is properly defined.

`comp`
- Binary function that accepts two arguments of the type pointed by BidirectionalIterator, and returns a value convertible to bool
- The value returned indicates whether the first argument is considered to go before the second in the specific strict weak ordering it defines
- The function shall not modify any of its arguments
- This can either be a function pointer or a function object

<br>

### Return value
- `true` if the function could rearrange the object as a lexicographicaly greater permutation
- Otherwise, the function returns `false` to indicate that the arrangement is not greater than the previous, but the lowest possible (sorted in ascending order)

### Example
```cpp
// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort

int main () {
  int myints[] = {1,2,3};

  std::sort (myints,myints+3);

  std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
    std::cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
  } while ( std::next_permutation(myints,myints+3) );
  // it continues til the largest permutation is set as a argument of next_permutation

  std::cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';

  return 0;
}
```

```shell
The 3! possible permutations with 3 elements:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
After loop: 1 2 3
```

### Complexity
- Up to linear in half the distance between first and last (in terms of actual swaps)

<br>

### See also
- [prev_permutation](https://cplusplus.com/reference/algorithm/prev_permutation/): Transform range to previous permutation (function template)

___

### References
1. [std::next_permutation](https://cplusplus.com/reference/algorithm/next_permutation/)