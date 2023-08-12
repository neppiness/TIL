#include <bits/stdc++.h>
using namespace std;

int a[1002], len[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  for (int i = 0; i < n; i++) {
    len[i] = 1;
    for (int j = 0; j < i; j++)
      if (a[j] < a[i])
        len[i] = max(len[i], len[j] + 1);
  }
  cout << *max_element(len, len + n);
}