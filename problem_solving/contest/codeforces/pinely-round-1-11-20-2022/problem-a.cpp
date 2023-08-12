#include <bits/stdc++.h>
using namespace std;

string solve() {
  int n, a, b;
  cin >> n >> a >> b;

  if(a + b < n - 1) return "Yes";
  else if(a == n && b == n) return "Yes";
  return "No"; 
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--)
    cout << solve() << '\n';
}