#include <bits/stdc++.h>
using namespace std;

string input;

vector<int> FFn(string str) {
  vector<int> f(str.size());
  int j = 0;
  for (int i = 1; i < str.size(); i++) {
    while (j != 0 && str[i] != str[j]) j = f[j - 1];
    if (str[i] == str[j]) f[i] = ++j;
  }
  return f;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  vector<int> f = FFn(input);
  for (int x : f) cout << x << ' ';
  return 0;

  int ans = 0;
  for (int i = 0; i < input.size(); i++) {
    string s = input.substr(i);
    vector<int> f = FFn(s);
    for (int x : f) ans = max(ans, x);
  }
  cout << ans;
}