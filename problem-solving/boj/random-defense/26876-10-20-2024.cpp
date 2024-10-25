#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string t1, t2; cin >> t1 >> t2;
  int h1 = stoi(t1.substr(0, 2));
  int m1 = stoi(t1.substr(3, 2));
  int h2 = stoi(t2.substr(0, 2));
  int m2 = stoi(t2.substr(3, 2));

  int cnt = 0;
  while (m1 != m2) {
    m1++; cnt++;
    if (m1 >= 60) {
      m1 = 0;
      h1++;
    }
  }

  if (h1 >= 24) h1 %= 24;
  while (h1 != h2) {
    h1++; cnt++;
    h1 %= 24;
  }
  cout << cnt;
}
