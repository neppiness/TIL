[TIL on July 27th, 2022](../../TIL/2022/07/07-27-2022.md)
# **Backtracking**

### What is Backtracking algorithm?
- Backtracking is an algorithmic technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point of time

#### Structure of backtracking
```shell
Backtrack(x)
    if x is not a solution
        return false
    if x is a new solution
        add to list of solutions
    backtrack(expand x)
```

### Typical structure (BOJ#15649)
```cpp
#include <iostream>
using namespace std;

int n, m;
int arr[10];
bool isUsed[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) cout << arr[i] << ' ';
    cout << '\n'; 
    return;
    }
    for(int i = 1; i <= n; i++) {
        if(!isUsed[i]){
            arr[k] = i;
            isUsed[i] = 1;
            func(k+1);
            isUsed[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    func(0);
}
```

___

### Reference
1. [[실전 알고리즘] 0x0C강 - 백트래킹](https://blog.encrypted.gg/945?category=773649)
2. [Backtracking Algorithms: GeeksforGeeks](https://www.geeksforgeeks.org/backtracking-algorithms/)
3. [Backtracking Algorithm: Programiz](https://www.programiz.com/dsa/backtracking-algorithm)