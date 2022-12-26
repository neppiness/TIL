#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int L; cin >> L;
  if(L % 5) cout << L / 5 + 1;
  else cout << L / 5;
}