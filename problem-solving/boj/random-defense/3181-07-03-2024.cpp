#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> useless;
string ul[] = {"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (string u : ul) {
    useless[u] = 1;
  }
  
  string s;
  int cnt = 0;
  while (cin >> s) {
    cnt++;
    if (cnt != 1 && useless[s]) {
      continue;
    }
    cout << (char)toupper(s[0]);
  }
}
