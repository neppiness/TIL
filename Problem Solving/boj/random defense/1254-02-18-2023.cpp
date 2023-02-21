#include <bits/stdc++.h>
using namespace std;

string s;

bool solve(int x) {
  int en = (x - 1) / 2;
  int j = x - 1;
  for(int i = 0; i <= en; i++) {
    int cj = j--;
    if(cj >= s.size()) continue;
    if(s[i] != s[cj]) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;

  int x = s.size();
  while(1) {
    if(solve(x)) break;
    x++;
  }
  cout << x;
}