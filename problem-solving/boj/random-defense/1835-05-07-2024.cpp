#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  deque<int> dq;
  dq.push_front(n);

  while (--n) {
    dq.push_front(n);
    for (int i = 0; i < n; i++) {
      int x = dq.back();
      dq.pop_back();
      dq.push_front(x);
    }
  }

  while (!dq.empty()) {
    int x = dq.front(); dq.pop_front();
    cout << x << ' ';
  }
}
