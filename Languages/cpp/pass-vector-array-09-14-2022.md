[TIL on September 14th, 2022](../../TIL/2022/09/09-14-2022.md)
# **How to pass an array of vectors to a function**

### Syntax
- Use & for referencer to shallow copy vector array
- Parenthesis binds & and newly declared variable `ad`
- Then, use brakets to represent an array

### Example
```cpp
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> (&ad)[]) {
  cout << *(ad[0].begin());
}

int main(void){
  vector<int> adj[100];
  adj[0].push_back(2123123123);
  solve(adj);
}
```
___

### Reference
1. [How to pass an array of vectors to a function](https://stackoverflow.com/questions/37863775/how-to-pass-an-array-of-vectors-to-a-function)