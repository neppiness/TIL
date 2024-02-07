#include <bits/stdc++.h>
using namespace std;

const int MX = 1000 + 2;

int a[MX], cache[MX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  fill(cache, cache + MX, 1);
  for(int i = 0; i < n; i++)
    for(int j = 0; j < i; j++) {
      if(a[j] >= a[i]) continue;
      cache[i] = max(cache[i], cache[j] + 1);
    }
  cout << (*max_element(cache, cache + n));
}