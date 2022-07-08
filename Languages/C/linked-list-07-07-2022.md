[TIL on July 7th, 2022](../../TIL/2022/07/07-07-2022.md)
# **Linked List**

### Description
- In computer science, `a linked list` is a linear collection of data elements whose order is not given by their physical placement in memory
- Instead, each element points to the next
- It is a data structure consisting of a collection of nodes which together represent a sequence

### Formal declaration
```cpp
struct NODE {
    struct NODE *prev, *next;
    int data;
};
```
#### Explain
- `struct NODE` has two pointers to point `struct NODE` data type
- An integer data is restored in a variable `data`

<br>

### Easy construction of a linked list
- However, in PS, we don't have enough time to build a formal linked list
- We can make an array behaves as a formal one

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 1000005;
int pre[MX], nxt[MX], dat[MX];
int unused = 6;

void traverse() {
    int idx = nxt[0];

    while(nxt[idx] != -1) {
        cout << dat[idx] << ' ';
        idx = nxt[idx];
    }
    cout << "\n\n";
}

void insert(int addr, int num) {
    dat[unused] = num;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if(nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, pre+MX, -1);

    int addr, num;
    cin >> addr >> num;

    insert(addr, num);
    erase(addr);
}
```
- MX should be `const int`

<br>

### Linked list using "STL list"
```cpp
int main(void){
    list<int> L = {1, 2}; // 1 2
    list<int>::iterator t = L.begin();
    L.push_front(10); // 10 1 2
    cout << *L << '\n'; // 1, the value pointed by `t` is printed
    L.push_back(5); // 10 1 2 5
    L.insert(t, 6); // Insert 6 where the t indicates
    t++;
    t = L.erase(t); // Erase where the t indicates, and return the index for next element (5)

    cout << *t << '\n'; // 5
    for(auto i : L) cout << i << ' '; // For C++ not older than 11 version
    cout << '\n';

    for(list<int>::iterator it = L.begin(); it != L.end(); it++) cout << *it << ' ';
    // For C++ older than 11 version
}
```

<br>

### Appendix: `fill` function
- Defined in header `<algorithm>`
- Declared statement:
```cpp
void fill (ForwardIterator first, ForwardIterator last, const T& val);  
```
- The 'fill' function assigns the value 'val' to all the elements in the range [first, last), where 'first' is the initial position and 'last' is the last position.
- 'first' is included in the range but 'last' is *NOT* included

- Example:
```cpp
int main()
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
 
    std::fill(v.begin(), v.end(), -1);
 
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
```

___

### References
1. [Linked list in Wikipedia](https://en.wikipedia.org/wiki/Linked_list#:~:text=In%20computer%20science%2C%20a%20linked,which%20together%20represent%20a%20sequence.)
2. [[실전 알고리즘] 0x04강 - 연결 리스트](https://blog.encrypted.gg/932?category=773649)
3. [C++ Algorithm fill()](https://www.javatpoint.com/cpp-algorithm-fill-function)
4. [std::fill](https://en.cppreference.com/w/cpp/algorithm/fill)