#include <bits/stdc++.h>
using namespace std;

set<pair<string, string>> comb;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b, c, d;
  cin >> a >> b >> c >> d;
  set<string> colors;
  colors.insert(a);
  colors.insert(b);
  colors.insert(c);
  colors.insert(d);

  vector<string> col;
  for (string str : colors)
    col.push_back(str);

  for (int i = 0; i < col.size(); i++)
    for (int j = 0; j < col.size(); j++)
      comb.insert({col[i], col[j]});

  for (auto [bc, tc] : comb)
    cout << bc << ' ' << tc << '\n';
}
