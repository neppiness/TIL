[TIL on September 4th, 2022](../../TIL/2022/09/09-04-2022.md)
# **Hash: open addressing method implementation**

### Constants and variables
- `M` is a size of a hash table
- `a` is used to generate a hash value
```cpp
const int M = 1000003;
const int a = 1000;
```
- `status` int array represents a status of a node
```cpp
const int EMPTY = -1;
const int OCCUPY = 0;
const int DUMMY = 1;
int status[M]; // EMPTY / OCCUPY / DUMMY
```
- `key` and `val` arrays save the given data
```cpp
string key[M];
int val[M];
```

### hash function
```cpp
int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}
```

### find function
- The argument of find the data from given key `k`
- `find` function returns the index of an EMPTY or a DUMMY node
- For linear probing
```cpp
int find(string k){
  int idx = my_hash(k);
  while(status[idx] != EMPTY){
    if(status[idx] == OCCUPY && key[idx] == k) return idx;
    idx = (idx+1) % M;
  }
  return -1;  
}
```

### insert function
- `insert` gets an index from find function with the given key, `k`
- The first index is given from the return value of `my_hash(k)`
```cpp
void insert(string k, int v){
  int idx = find(k);
  if(idx != -1){
    val[idx] = v;
    return;
  }
  idx = my_hash(k);
```
- Use `while` loop to find the index of an EMPTY or a DUMMY node
- Also, the `idx` takes a remainder to prevent index being out of bound
```cpp
  while(status[idx] == OCCUPY)
    idx = (idx+1) % M;
  key[idx] = k;
  val[idx] = v;
  status[idx] = OCCUPY;
}
```
### erase function
- erase function makes the status of a found node DUMMY
```cpp
void erase(string k){
  int idx = find(k);
  if(idx != -1) status[idx] = DUMMY;
}
```
___

### Full source code
- [basic-algo-lecture/0x15/hash_open_addressing_test_ans.cpp](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x15/hash_open_addressing_test_ans.cpp)