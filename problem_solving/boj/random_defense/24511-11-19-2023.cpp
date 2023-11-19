#include <bits/stdc++.h>
using namespace std;

bool is_stack[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  deque<int> dq;
  for (int i = 0; i < n; i++)
    cin >> is_stack[i];

  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (is_stack[i]) continue;
    dq.push_back(x);
  }

  cin >> n;
  while (n--) {
    int x; cin >> x;
    dq.push_front(x);
    cout << dq.back() << ' ';
    dq.pop_back();
  }
}
