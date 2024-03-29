#include <bits/stdc++.h>
using namespace std;

const int M = 1000003;
const int a = 1000;

string key[M];
int val[M];

int my_hash(string& k) {
  int h = 0;
  for(auto c : k)
    h = (h*a + c)%M;
  return h;
}

int find(string k) {
  int idx = my_hash(k);

  while(key[idx].length()) {
    if(key[idx] == k) return idx;
    idx = (idx + 1)%M;
  }
  return -1;
}

void insert(string k, int v) {
  int idx = find(k);
  if(idx == -1) {idx = my_hash(k);}
  key[idx] = k;
  val[idx] = v;
}

void erase(string k) {
  int idx = find(k);
  if(idx != -1) key[idx] = "dummy";
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
  ios::sync_with_stdio(0);
  cin.tie(0);
  test();
}