// #include <queue>
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

int a[100'002];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int, vector<int>, greater<int>> pq;

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    pq.push(x);
  }

  int ans = 0;
  while(pq.size() >= 2) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    int c = a + b;
    ans += c;
    pq.push(c);
  }
  cout << ans;
}