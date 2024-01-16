#include <bits/stdc++.h>
using namespace std;

int n, x; 
set<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
  }

  cin >> x;
  auto it = s.find(x);
  if (it != s.end()) {
    cout << 0; 
    return 0;
  }

  int a = x, b = x;
  int cnt_a = 0, cnt_b = 0;
  while (s.find(a) == s.end() && a > 0) {
    a--;
    cnt_a++;
  }
  while (s.find(b) == s.end()) {
    b++;
    cnt_b++;
  }
  cout << cnt_a * cnt_b - 1;
}
