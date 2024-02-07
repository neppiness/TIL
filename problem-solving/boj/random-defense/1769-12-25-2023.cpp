#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  if (s.size() == 1) {
    int n = s[0] - '0';
    cout << 0 << '\n';
    if (n % 3) cout << "NO";
    else cout << "YES";
    return 0;
  }

  int n = 0;
  for (int i = 0; i < s.size(); i++)
    n += s[i] - '0';

  int cnt = 1;
  while (n / 10) {
    int tmp = n;
    int nxt = 0;
    while (tmp) {
      nxt += tmp % 10;
      tmp /= 10;
    } 
    n = nxt;
    cnt++;
  }
  cout << cnt << '\n';
  if (n % 3) cout << "NO";
  else cout << "YES";
}
