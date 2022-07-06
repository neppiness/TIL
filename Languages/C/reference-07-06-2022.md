[TIL on July 6th, 2022](../../TIL/2022/07/07-06-2022.md)
# **References in C++**

### Description
- When a variable is declared as a reference, it becomes an alternative name for an existing variable
- A variable can be declared as a reference by putting ‘&’ in the declaration

```cpp
#include <iostream>
using namespace std;
 
int main()
{
    int x = 10;
 
    // ref is a reference to x.
    int& ref = x;
 
    // Value of x is now changed to 20
    ref = 20;
    cout << "x = " << x << '\n';
 
    // Value of x is now changed to 30
    x = 30;
    cout << "ref = " << ref << '\n';
 
    return 0;
}
```

### Applications
1. Modify the passed parameters in a function
- If a function receives a reference to a variable, it can modify the value of the variable

2. Avoiding a copy of large structures: Imagine a function that has to receive a large object
- If we pass it without reference, a new copy of it is created which causes wastage of CPU time and memory

### An argument for a function
- `int`, `struct`: deep copying the value, independent to original variables
- `arr[]`, `reference (&)`: just copy the address of array, changes original value

___

### References
1. [Reference in C++](https://www.geeksforgeeks.org/references-in-c/)
2. [[실전 알고리즘] 0x02강 - 기초 코드 작성 요령 II](https://blog.encrypted.gg/923?category=773649)