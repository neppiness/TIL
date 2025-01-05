#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n) {
    int x = n % 2;
    q.push(x);
    n /= 2;
  }
  int sum = 0;
  while (!q.empty()) {
    sum *= 2;
    int x = q.front(); q.pop();
    sum += x;
  }
  cout << sum;
}
