#include <bits/stdc++.h>
using namespace std;

vector< pair<int,int> > e;
int p[1002];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool areindiffgr(int a, int b) {
  a = find(a); b = find(b);
  if(a == b) return 0;
  if(p[a] == p[b]) p[a]--;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;
  return 1;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--) {
    int n, m;
    cin >> n >> m;
    fill(p, p + n + 1, -1);

    int a, b;
    while(m--) {
      cin >> a >> b;
      e.push_back({a, b});
    }
    int cnt = 0;
    auto it = e.begin();
    while(cnt < n - 1) {
      tie(a, b) = (*it);
      it++;
      if(!areindiffgr(a, b)) continue;
      cnt++;
    }
    cout << cnt << '\n';
  }
}