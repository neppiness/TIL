#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int sz;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> sz >> n;
  while(n != -1) {
    if(n == 0) q.pop();
    else if(q.size() != sz) q.push(n);
    cin >> n;
  }

  if(q.empty()) {
    cout << "empty";
    return 0;
  }
  while(!q.empty()) {
    cout << q.front() << ' ';
    q.pop();
  }
}