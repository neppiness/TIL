#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;

int f[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string lck, key;
  cin >> lck >> key;
  for(int i = 1; i < key.length(); i++) {
    int j = f[i - 1];
    while(key[i] != key[j] && j > 0) j = f[j - 1];
    if(key[i] == key[j]) f[i] = ++j;
  }
  
  bool is_found = 0;
  int j = 0;
  for(int i = 0; i < lck.length(); i++) {
    while(lck[i] != key[j] && j > 0) j = f[j - 1];
    if(lck[i] == key[j]) j++;
    if(j == key.length()) { is_found = 1; break; }
  }
  cout << is_found;
}