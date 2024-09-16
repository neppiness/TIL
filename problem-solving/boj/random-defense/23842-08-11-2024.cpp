#include <bits/stdc++.h>
using namespace std;

int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string get_string(int x) {
  string s = to_string(x);
  if (s.size() < 2) {
    s = "0" + s;
  }
  return s;
}

int count(string &s) {
  return cnt[s[0] - '0'] + cnt[s[1] - '0'];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < 100; i++) {
    string si = get_string(i);
    for (int j = 0; j < 100; j++) {
      int tot = i + j;
      if (tot >= 100) continue;
      string sj = get_string(j);
      string stot = get_string(tot);
      int cnt = count(si) + count(sj) + count(stot) + 4;
      if (cnt != n) continue;
      cout << si << "+" << sj << "=" << stot;
      return 0;
    }
  }
  cout << "impossible";
}
