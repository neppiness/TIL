#include <bits/stdc++.h>
using namespace std;

bool vis[4000002];
vector<int> prime;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  if(n == 1) {cout << 0; return 0;}
  for(int pr = 2; pr <= n; pr++) {
    if(vis[pr]) continue;
    prime.push_back(pr);
    vis[pr] = 1;
    for(int mul = pr; mul <= n; mul += pr) vis[mul] = 1;
  }

  auto en = prime.begin();
  int tot = *en;
  int cnt = 0;
  for(auto st = prime.begin(); st != prime.end(); st++) {
    while(tot < n && ++en != prime.end()) tot += *en;
    if(en == prime.end()) break;
    if(tot == n) cnt++;
    tot -= *st;
  }
  cout << cnt;
}