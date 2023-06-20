#include <bits/stdc++.h>
using namespace std;

vector<char> c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  for (char a : s) c.push_back(a);
  sort(c.begin(), c.end());

  int ans = 0;
  do {
    bool is_diff = 1;
    for (int i = 1; i < c.size(); i++)
      if (c[i - 1] == c[i]) is_diff = 0;
    ans += is_diff;
  } while (next_permutation(c.begin(), c.end()));
  cout << ans;
}