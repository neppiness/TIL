#include <bits/stdc++.h>
using namespace std;

string ans(string &s) {
  if (s.size() == 7) {
    return "UNIQUE";
  }
  string ss = s.substr(0, 2);
  string ans;
  if (ss == "A#") ans = "Bb";
  if (ss == "Bb") ans = "A#";

  if (ss == "C#") ans = "Db";
  if (ss == "Db") ans = "C#";

  if (ss == "D#") ans = "Eb";
  if (ss == "Eb") ans = "D#";

  if (ss == "F#") ans = "Gb";
  if (ss == "Gb") ans = "F#";

  if (ss == "G#") ans = "Ab";
  if (ss == "Ab") ans = "G#";

  return ans + s.substr(2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int cnt = 1;
  while (getline(cin, s)) {
    cout << "Case " << cnt++ << ": " << ans(s) << '\n';
  }
}
