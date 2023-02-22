#include <bits/stdc++.h>
using namespace std;

vector<int> cidx[26];

int ctoi(char a) { return a - 'A'; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string key, lck;
  cin >> key >> lck;

  for(int i = 0; i < key.size(); i++)
    cidx[ctoi(key[i])].push_back(i);

  int ans = 0;
  for(int i = 0; i < lck.size(); i++) {
    int a = ctoi(lck[i]);    
    int mx, tmp;
    for(auto idx : cidx[a]) {
      tmp = i, mx = 0;
      while(idx < key.size() && tmp < lck.size()) {
        if(key[idx] != lck[tmp]) break;
        mx++; idx++; tmp++;
      }
      ans = max(mx, ans);
    }
  }
  cout << ans;
}