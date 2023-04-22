#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, sz;
ll ans = -0x7f7f7f7f7f7f;

string s;
vector<bool> comb;

ll calc(int st, int en) {

}

void solve(int no_of_par) {
  if(no_of_par != 0) {
    for(int i = 0; i < no_of_par*2; i++)
      comb[i] = 1;
  }
  
  do {
    
  } while(
      prev_permutation(comb.begin(), comb.end())
  );
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  int sz = n/2 + 1;
  comb.resize(sz);

  for(int i = 0; i <= sz/2; i++)
    solve(i);

  cout << ans;
}