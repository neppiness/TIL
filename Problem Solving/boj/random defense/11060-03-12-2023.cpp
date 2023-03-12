#include <bits/stdc++.h>
using namespace std;

vector<int> a, d;
queue<int> q;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n; cin >> n;
  a.resize(n); d.resize(n);
  fill(d.begin(), d.end(), -1);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  d[0] = 0;
  q.push(0);
  while(!q.empty()) {
    int i = q.front(); q.pop();
    for(int j = i + 1; j <= i + a[i]; j++) {
      if(j >= n || d[j] != -1) continue;
      q.push(j);
      d[j] = d[i] + 1;
    }
  }
  cout << d[n - 1];
}