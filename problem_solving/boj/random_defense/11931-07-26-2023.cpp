#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.rbegin(), a.rend());
  for (int x : a) cout << x << '\n';
}