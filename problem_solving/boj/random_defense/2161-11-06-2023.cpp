#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  deque<int> dq;
  for (int i = 1; i <= n; i++)
    dq.push_back(i);

  while (!dq.empty()) {
    cout << dq.front() << ' ';
    dq.pop_front();
    dq.push_back(dq.front());
    dq.pop_front();
  }
}
