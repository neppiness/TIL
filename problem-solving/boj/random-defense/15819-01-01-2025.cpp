#include <bits/stdc++.h>
using namespace std;

string a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  cout << a[x - 1];
}
