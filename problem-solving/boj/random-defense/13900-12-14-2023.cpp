#include <bits/stdc++.h>
using namespace std;

long long ans;
int n;
long long no[10'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--) {
    int x; cin >> x;
    no[x]++;
  }

  for (int i = 0; i <= 10000; i++)
    for (int j = i + 1; j <= 10000; j++)
      ans += (i * j) * (no[i] * no[j]);
  for (int i = 0; i <= 10000; i++) {
    if (no[i] < 2) continue;
    ans += (i * i) * (no[i] * (no[i] - 1)) / 2;
  }

  cout << ans;
}
