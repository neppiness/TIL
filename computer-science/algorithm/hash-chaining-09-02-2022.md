[TIL on August 31st, 2022](../../TIL/2022/08/08-31-2022.md)
# **Hash: chaining method implementation**

### my_hash function
- Use char's number to generate hash values
```cpp
int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}
```

### find function
- A function to return found value's idx
  * `idx` such that key[idx] == k
- If k doesn't exist, return -1
```cpp
int find(string k){
  int h = my_hash(k);
  int idx = head[h];
  while(idx != -1){
    if(key[idx] == k) return idx;
    idx = nxt[idx];
  }
  return -1;
}
```

### insert function
- `insert` function of this solution inserts a data to a head
- `int idx = find(k);` code to find an index using key `k`
  * If `idx != -1`, `insert` updates the value
- If `idx == -1`, `insert` assign `k` and `v` to `key[unused]` and `val[unused]`, respectively
  * If `head` for `my_hash(k)` is already assigned, `nxt` and `pre` should be updated
  * If `head` for `my_hash(k)` is not assigned yet (which means that `head[h] == -1`), only `head[h]` value should be changed to `unused`

```cpp
void insert(string k, int v){
  int idx = find(k);
  if(idx != -1){
    val[idx] = v;
    return;
  }
  int h = my_hash(k);
  key[unused] = k;
  val[unused] = v;
  if(head[h] != -1){
    nxt[unused] = head[h];
    pre[head[h]] = unused;
  }
  head[h] = unused;
  unused++;
}
```

### erase function
- Assign `find(k)` to `idx` and use `idx` to re-arrange conections of the linked list
  * If `idx == -1`, nothing happens
  * Else, `pre[idx]` and `nxt[idx]` should be changed if their values are not -1
  * If `head[my_hash(k)] == idx`, then head value should also be changed
```cpp
void erase(string k){
  int idx = find(k);
  if(idx == -1) return;
  if(pre[idx] != -1) nxt[pre[idx]] = nxt[idx];
  if(nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
  int h = my_hash(k);
  if(head[h] == idx) head[h] = nxt[idx];
}
```
___

### Full source code
- [basic-algo-lecture/0x15/hash_chaining_test_ans.cpp](https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x15/hash_chaining_test_ans.cpp)