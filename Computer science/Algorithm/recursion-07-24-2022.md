[TIL on July 24th, 2022](../../TIL/2022/07/07-24-2022.md)
# **Recursion**

### What is recursion?
- A function calls itself to do a work

### Recursive thinking
To understand that `func1` prints n (n >= 1) to 1
- func1(1) prints 1
- If func1(k) prints k, k-1, k-2, ..., 1; then func1(k+1) prints k+1, k, k-1, k-2, ..., 1
- func1(k+1) prints k+1 and then calls func(k): thus, func1(k+1) prints k+1, k, k-1, k-2, ..., 1

### Base condition
- Correct recursive function should be terminated with specific input; which is called as a base condition or a base case
- All input should be converged to base condition

### Examples for recursive functions
```cpp
void func1(int n) {
    if(n==0) return;
    cout << n << ' ';
    func1(n-1);
}
```

### Recursion could be inefficient
```cpp
int fibo(int n) {
    if(n <= 1) return 1;
    return fibo(n-1) + fibo(n-2);
}
```
- The time complexity for this function above is O(1.618^n); n = 100 needs 20000 years to calculate

### Steps in recursive function
1. Codes for a base condition
2. Processing codes
3. Call a deeper function
4. Post-processing codes

#### Examples
- Factorial calculation
```cpp
int factorial(int n) {
  // 1. Base condition
  if(n == 1) return 1;
  // 2 & 3. Processing code and calling a deeper function
  return n * factorial(n-1);
  // 4. Post-processing omitted
}
```

- Backtracking example
```cpp
void backtracking(int m) {
    // 1. Base condition
    if (m == MAX) return;

    // 2. Processing code
    for(int i = 0; i < N; i++){
        vis[i] = true;
        // 3. Calling a deeper function
        backtracking(m + 1);
        // 4. Post processing
        vis[i] = false;
    }
}
```

___

### Reference
- [[실전 알고리즘] 0x0B강 - 재귀](https://blog.encrypted.gg/942?category=773649)