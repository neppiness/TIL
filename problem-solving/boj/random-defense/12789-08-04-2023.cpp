#include <bits/stdc++.h>
using namespace std;

queue<int> q;
stack<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    q.push(x);
  }

  int seq = 1;
  while (!q.empty()) {
    if (!s.empty() && s.top() == seq) {
      s.pop(); seq++;
      continue;
    }
    if (q.front() == seq) {
      q.pop(); seq++;
    } else {
      s.push(q.front());
      q.pop();
    }
  }
  while (!s.empty()) {
    if (s.top() != seq) break;
    s.pop(); seq++;
  }

  if (seq == n + 1) cout << "Nice";
  else cout << "Sad";
}