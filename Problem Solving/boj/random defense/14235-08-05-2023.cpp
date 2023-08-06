#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    int a; cin >> a;
    if (!a) {
      if (pq.empty()) {
        cout << -1 << '\n'; continue;
      }
      cout << pq.top() << '\n';
      pq.pop();
      continue;
    }
    while (a--) {
      int x; cin >> x;
      pq.push(x);
    }
  }
}