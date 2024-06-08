#include <bits/stdc++.h>
using namespace std;

queue<pair<string, int>> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string s; int cnt;
    cin >> s >> cnt;
    q.push({s, cnt});
  }

  while (q.size() != 1) {
    auto [s, cnt] = q.front();
    q.pop();
    
    while (--cnt) {
      q.push(q.front());
      q.pop();
    }
    q.pop();
  }
  cout << q.front().first;
}
