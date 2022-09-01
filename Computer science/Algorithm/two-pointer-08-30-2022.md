[TIL on August 30th, 2022](../../TIL/2022/08/08-30-2022.md)
# **Binary Search**

### Two-pointer technique
- Basically, two-pointer technique simplifies 'two-for-loops' which has a time complexity of O(N^2)
  * Two-pointer technique has a time complexity of O(N)

### boj.kr/2230
- Could be solved by both the two-pointer technique and the binary search (parametric search): lower_bound gives direct solution

#### Source code using two-pointer technique
```cpp
// http://boj.kr/b2658483a12c47c9b0e54c64f8ac898f
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100005];
int mn = 0x7fffffff;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int en = 0;
  for(int st = 0; st < n; st++){
    while(en < n && a[en] - a[st] < m) en++;
    if(en == n) break; // if en is out of bound, break the for loop
    mn = min(mn, a[en] - a[st]);
  }
  cout << m
```
___


### References
1. [[실전 알고리즘] 0x14강 - 투 포인터](https://blog.encrypted.gg/1004)