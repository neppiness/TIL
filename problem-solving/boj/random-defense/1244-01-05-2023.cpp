#include <bits/stdc++.h>
using namespace std;

int n; 
bool a[102];

void boy(int x) {
  for (int i = x; i <= n; i += x)
    a[i] = !a[i];
}

void girl(int x) {
  int i = x, j = x;
  while (i >= 1 && j <= n) {
    if (a[i] != a[j]) break;
    i--; j++;
  }
  i++; j--;

  for (int k = i; k <= j; k++)
    a[k] = !a[k];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int m; cin >> m;
  while (m--) {
    int code, x;
    cin >> code >> x;
    if (code == 1) {
      boy(x);
    } else {
      girl(x);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
    cnt++;
    if (cnt % 20 == 0) cout << '\n';
  }
}
