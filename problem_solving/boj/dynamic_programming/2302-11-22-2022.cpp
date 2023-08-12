#include <bits/stdc++.h>
using namespace std;

int p[42];
bool vip[42];

vector<int> len;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  p[1] = 1; p[2] = 2;
  for(int i = 3; i <= 40; i++)
    p[i] = p[i - 1] + p[i - 2];
  
  int n, V;
  cin >> n >> V;

  int v;
  for(int i = 0; i < V; i++) {
    cin >> v; vip[v] = 1;
  }

  int L = 0;
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    if(vip[i] && L != 0) {
      len.push_back(L);
      L = 0;
    }
    if(!vip[i]) L++;
  }
  if(L != 0) len.push_back(L);

  for(int L : len)
    ans *= p[L];
    
  cout << ans;
}