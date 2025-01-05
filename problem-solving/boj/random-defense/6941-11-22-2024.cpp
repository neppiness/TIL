#include <bits/stdc++.h>
using namespace std;

string get_str(int i) {
  string s;
  string ret;
  if (i <= 0) s = " ";
  else s = to_string(i);
  for (int i = 0; i < 3 - s.size(); i++)
    ret += " ";
  return ret + s;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  cout << "Sun Mon Tue Wed Thr Fri Sat";
  int cnt = 0;
  for (int i = -n + 2; i <= m; i++) {
    if (!cnt++) cout << '\n';
    else cout << ' ';
    cout << get_str(i);
    cnt %= 7;
  }
}
