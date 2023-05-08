#include <bits/stdc++.h>
using namespace std;

string str;

bool solve(string s) {
  if (s.size() == 1) return 1;
  int half_len = s.size() / 2;

  for (int i = 0; i <= half_len; i++)
    if (s[i] != s[s.size() - i - 1]) return 0;

  if (!solve(s.substr(0, half_len))) return 0;
  if (!solve(s.substr(s.size() - half_len, half_len))) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  if (solve(str)) cout << "AKARAKA";
  else cout << "IPSELENTI";
}