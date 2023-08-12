[TIL on August 2nd, 2022](../../TIL/2022/08/08-02-2022.md)
# **std::vector**
In header `<vector>`

### Introduction
- Vectors are sequence containers representing arrays that can *change* in size
- Just like arrays, vectors use contiguous storage locations for their elements, which means that their elements can also be accessed using offsets on regular pointers to its elements, and just as efficiently as in arrays
- But unlike arrays, their size can change dynamically, with their storage being handled automatically by the container

#### For efficient reallocation purpose
- Vector containers may allocate some extra storage to accommodate for possible growth, and thus the container may have an actual capacity greater than the storage strictly needed to contain its elements (i.e., its size)
- So that this array do not reallocate each time an element is added to the container
- Reallocations should only happen at logarithmically growing intervals of size so that the insertion of individual elements at the end of the vector can be provided with amortized constant time complexity
- Therefore, compared to arrays, vectors consume more memory in exchange for the ability to manage storage and grow dynamically in an efficient way

### Template parameters
`T`
- Type of the elements
- Only if T is guaranteed to not throw while moving, implementations can optimize to move elements instead of copying them during reallocations
- Aliased as member type vector::value_type

`Alloc`
- Type of the allocator object used to define the storage allocation model
- By default, the allocator class template is used, which defines the simplest memory allocation model and is value-independent
- Aliased as member type vector::allocator_type

### Member functions
| Iterators | Functions                                          |
| --------- | -------------------------------------------------- |
| begin	    | Return iterator to beginning                       |
| end       | Return iterator to end                             |
| rbegin    | Return reverse iterator to reverse beginning       |
| rend      | Return reverse iterator to reverse end             |
| cbegin    | Return const_iterator to beginning                 |
| cend      | Return const_iterator to end                       |
| crbegin   | Return const_reverse_iterator to reverse beginning |
| crend     | Return const_reverse_iterator to reverse end       |

| Capacity      | Functions                                 |
| --------------| ----------------------------------------- | 
| size          | Return size                               |
| max_size      | Return maximum size                       |
| resize        | Change size                               |
| capacity      | Return size of allocated storage capacity |
| empty         | Test whether vector is empty              |
| reserve       | Request a change in capacity              |
| shrink_to_fit | Shrink to fit                             |

| Element access | Functions            |
| -------------- | -------------------- |
| operator[]     | Access element       |
| at             | Access element       |
| front          | Access first element |
| back           | Access last element  |
| data           | Access data          |

| Modifiers   | Functions                               |
| ----------- | --------------------------------------- |
| assign      | Assign vector content                   |
| push_back   | Add element at the end                  |
| pop_back    | Delete last element                     |
| insert      | Insert elements                         |
| erase       | Erase elements                          |
| swap        | Swap content                            |
| clear       | Clear content                           |
| emplace     | Construct and insert element            |
| emplace_back| Construct and insert element at the end |

### Usage of a constructor
```cpp
// constructing vectors
#include <iostream>
#include <vector>

int main ()
{
  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```
Output:
```shell
The contents of fifth are: 16 2 77 29
```

### Usage of a insert
```cpp
// inserting into a vector
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector (3,100); // myvector: {100, 100, 100}
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert(it, 200);
  // myvector: {200, 100, 100, 100}
  // 'insert' function returns an iterator that points to
  // the first of the newly inserted elements

  myvector.insert(it,2,300); // myvector: {300, 300, 200, 100, 100, 100}
  //                                        ^
  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400); // anothervector: {400, 400}
  myvector.insert(it+2, anothervector.begin(), anothervector.end());
  // iterator 'it + 2' points the value 200
  // and insert function inserts anothervector to there
  // myvector: {300, 300, 400, 400, 200, 100, 100, 100}

  int myarray [] = {501,502,503};
  myvector.insert(myvector.begin(), myarray, myarray+3);
  // myvector: {501, 502, 503, 300, 300, 400, 400, 200, 100, 100, 100}

  std::cout << "myvector contains:";
  for(it = myvector.begin(); it < myvector.end(); it++)
    std::cout << ' ' << *it; // prints what it points
  std::cout << '\n';

  return 0;
}
```
Output:
```shell
myvector contains: 501 502 503 300 300 400 400 200 100 100 100
```

___

### References
1. [std::vector](https://m.cplusplus.com/reference/vector/vector/)