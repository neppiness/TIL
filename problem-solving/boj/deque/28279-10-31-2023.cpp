#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> dq;
  int n; cin >> n;
  while (n--) {
    int code; cin >> code;
    if (code == 1) {
      int x; cin >> x;
      dq.push_front(x);
    } else if (code == 2) {
      int x; cin >> x;
      dq.push_back(x);
    } else if (code == 3) {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    } else if (code == 4) {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    } else if (code == 5) {
      cout << dq.size() << '\n';
    } else if (code == 6) {
      cout << dq.empty() << '\n';
    } else if (code == 7) {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.front() << '\n';
      }
    } else {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.back() << '\n';
      }
    }
  }
}
