#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const string UCPC = "UCPC";
  string s;
  getline(cin, s);
  int search_idx = 0;
  for (int i = 0; i < s.size(); i++) {
    if (UCPC[search_idx] == s[i]) {
      search_idx++;
      if (search_idx == 4) {
        cout << "I love UCPC";
        return 0;
      }
    }
  }
  cout << "I hate UCPC";
}
