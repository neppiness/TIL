[TIL on August 26th, 2022](../../TIL/2022/08/08-26-2022.md)
# **Binary Search**

### What is a binary search?
- Binary search is an efficient algorithm for finding an item from *a sorted list of items*
   * It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one

#### Example
- The Tycho-2 star catalog contains information about the brightest 2,539,913 stars in our galaxy. Suppose that you want to search the catalog for a particular star, based on the star's name.
  * Linear search: If the program examined every star in the star catalog in order starting with the first, the computer might have to examine all *2,539,913* stars to find the star you were looking for, in the worst case
  * Binary search: If the catalog were sorted alphabetically by star names, this algorithm would not have to examine more than *22 stars*, even in the worst case

### `binary search` in STL
- `binary_search` function is included in algorithm header
- Syntax: `binary_search(begin, end, value);`
- The parameters:
  * `begin`: The beginning point of the searching domain
  * `end`: The end of range, the next index of the last index for an array or a vector
  * `value`: a value to find

#### `upper_bound` and `lower_bound` functions in STL
- Returns an iterator indicates an upper_bound and a lower_bound for a given value
- Example
```cpp
// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=std::lower_bound (v.begin(), v.end(), 20); //          ^
  up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
```
```shell
lower_bound at position 3
upper_bound at position 6
```
- [boj.kr/10816](../../Problem%20Solving/boj/Binary%20search/10816-re-08-27-2022.cpp)


### Caution for using binary search
1. Given array should be sorted
2. `mid` value should be determined to avoid an infinite loop
  * Be careful for a case when `en - st == 1`
  * If a pointer is assigned without some calculation, (such as +1 or -1) the equation for `mid` value must differ to the pointer `assigned` mid value

- An example for pointers causing an infinite loop
```cpp
mid = (st + en + 1) / 2; // if en - st = 1, mid is always equal to en;

if(mid < val) st = mid + 1; // st pointer changes from mid value
else en = mid; // end pointer doesn't change from mid value
```


### boj.kr/18870 using lower_bound and unique
```cpp
// http://boj.kr/ee7936483d9848d9b6a7a14243656eed
#include <bits/stdc++.h>
using namespace std;

int n;
int x[1000005];
vector<int> uni; // unique
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x[i];
    uni.push_back(x[i]);
  }
  sort(uni.begin(), uni.end());
  uni.erase(unique(uni.begin(), uni.end()), uni.end());
  for(int i = 0; i < n; i++)
    cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
}
```

### Parametric search
- Search the minimum or maximum value satisfying the given conditions using binary search
- Note that the function representing relationship between variables should be monotonic decreasing/increaseing function
  * If it is not, binary search is not valid
- [boj.kr/1654](../../Problem%20Solving/boj/Binary%20search/1654-08-28-2022.cpp)

___


### References
1. [[실전 알고리즘] 0x13강 - 이분탐색](https://blog.encrypted.gg/985)
2. [Binary search: Khan Academy](https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search#:~:text=Binary%20search%20is%20an%20efficient,possible%20locations%20to%20just%20one.)
3. [std::upper_bound](https://cplusplus.com/reference/algorithm/upper_bound/)