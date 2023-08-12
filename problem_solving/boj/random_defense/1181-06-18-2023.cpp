#include <bits/stdc++.h>
using namespace std;

struct word {
  string s;
  word(string s_): s(s_) {}

  bool operator < (const word &rt) const {
    if (s.length() == rt.s.length())
      return s < rt.s;
    return s.length() < rt.s.length();
  }
};

set<word> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string input;
  while (n--) {
    cin >> input;
    word w = word(input);
    ans.insert(w);
  }

  for (word w : ans)
    cout << w.s << '\n';
}