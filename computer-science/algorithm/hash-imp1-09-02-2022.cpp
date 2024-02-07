#include <bits/stdc++.h>
using namespace std;

// Load factor: about 0.5
const int M = 1000003;
const int a = 1000;
const int MX = 500005; // The maximum number of insertion

int head[M];

int pre[MX];
int nxt[MX];

string key[MX];
int val[MX];

int unused = 0; // cursor for data

int my_hash(string& s){
  int h = 0;
  for(auto x : s)
    h = (h * a + x) % M;
  return h;
}

// return idx such that key[idx] == k
// if k doesn't exist, return -1
int find(string k){
  int hash_head = head[my_hash(k)];
  int next_node = hash_head;
  if(hash_head != -1) {
    while(nxt[next_node] != -1 && key[next_node] != k)
      next_node = nxt[next_node];
  }
  return next_node;
}

void insert(string k, int v){
  int hash_head = head[my_hash(k)];
  if(hash_head == -1) head[my_hash(k)] = unused;
  else {
    int found_idx = find(k);
    if(found_idx == -1) {
      int last_node = hash_head;
      while(nxt[last_node] != -1) last_node = nxt[last_node];
      nxt[last_node] = unused;
      pre[unused] = last_node;
    } else {
      key[found_idx] = k;
      val[found_idx] = v;
      return;
    }
  }
  key[unused] = k;
  val[unused] = v;
  unused++;
}

void erase(string k){
  int found_idx = find(k);

  if(found_idx != -1) {
    if(pre[found_idx] != -1) nxt[pre[found_idx]] = nxt[found_idx];
    else head[my_hash(k)] = -1;
    if(nxt[found_idx] != -1) pre[nxt[found_idx]] = pre[found_idx];
  }
}

void test(){
  insert("orange", 724); // ("orange", 724)
  insert("melon", 20); // ("orange", 724), ("melon", 20)
  assert(val[find("melon")] == 20);
  insert("banana", 52); // ("orange", 724), ("melon", 20), ("banana", 52)
  insert("cherry", 27); // ("orange", 724), ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 100); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(val[find("banana")] == 52);
  assert(val[find("orange")] == 100);
  erase("wrong_fruit"); // ("orange", 100), ("melon", 20), ("banana", 52), ("cherry", 27)
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  assert(find("orange") == -1);
  erase("orange"); // ("melon", 20), ("banana", 52), ("cherry", 27)
  insert("orange", 15); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15)
  assert(val[find("orange")] == 15);
  insert("apple", 36); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36)
  insert("lemon", 6); // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 15), ("apple", 36), ("lemon", 6)
  insert("orange", 701);  // ("melon", 20), ("banana", 52), ("cherry", 27), ("orange", 701), ("apple", 36), ("lemon", 6)
  assert(val[find("cherry")] == 27);
  erase("xxxxxxx");
  assert(find("xxxxxxx") == -1);
  assert(val[find("apple")] == 36);
  assert(val[find("melon")] == 20);
  assert(val[find("banana")] == 52);
  assert(val[find("cherry")] == 27);
  assert(val[find("orange")] == 701);
  assert(val[find("lemon")] == 6);
  cout << "good!\n";
}

int main(){
  fill(head, head+M, -1);
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  test();
}