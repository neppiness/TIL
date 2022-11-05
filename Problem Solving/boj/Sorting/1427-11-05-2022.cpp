#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> v;

  int no; cin >> no;
  while(no != 0) {
    v.push_back(no % 10);
    no /= 10;
  }
  sort(v.rbegin(), v.rend());

  int ans = 0;
  for(int a : v) {
    ans *= 10;
    ans += a;
  }

  cout << ans;
}