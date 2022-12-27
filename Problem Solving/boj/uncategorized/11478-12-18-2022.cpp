#include <bits/stdc++.h>
using namespace std;

string s;
set<string> a;

void solve(int len) {
  for(int i = 0; i < s.length() - len + 1; i++)
    a.insert(s.substr(i, len));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  for(int len = 1; len <= s.length(); len++)
    solve(len);
  cout << a.size();
}