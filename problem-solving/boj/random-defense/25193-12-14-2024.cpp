#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;

  int div_cnt = 0;
  for (char c : s)
    div_cnt += (c != 'C');

  cout << n / (div_cnt + 1);
}
