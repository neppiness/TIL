#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'005;
bool isPr[MX + 5];
vector<int> prs;

void setPr() {
  fill(isPr + 2, isPr + MX + 1, 1);

  for(int i = 2; i <= MX; i++) {
    if(!isPr[i]) continue;
    prs.push_back(i);
    if(i > 1000) continue;
    for(int j = i; i*j <= MX; j++)
      isPr[i*j] = 0;
  } 
}

void solve(int x) {
  for(int pr : prs) {
    if(!isPr[x - pr])
      continue;
    else {
      cout << x << " = " << pr << " + " << (x-pr) << '\n';
      return;
    }
  }
  cout << "Goldbach's conjecture is wrong." << '\n';
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setPr();

  while(1) {
    int x; cin >> x;
    if(!x) return 0;
    solve(x);
  }
}