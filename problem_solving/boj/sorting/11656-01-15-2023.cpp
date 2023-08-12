#include <bits/stdc++.h>
using namespace std;

vector<string> str;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for(int i = 0; i < s.length(); i++) {
    string ss = s.substr(i);
    str.push_back(ss);
  }
  sort(str.begin(), str.end());
  for(string s : str)
    cout << s << '\n';
}