#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if (s.size() == 1) {
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    return 0;
  }
  int d = s[1] - s[0];
  bool is_cute = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i - 1] + d) {
      is_cute = 0;
    }
  }
  if (is_cute) {
    cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
  } else {
    cout << "흥칫뿡!! <(￣ ﹌ ￣)>";
  }
}
