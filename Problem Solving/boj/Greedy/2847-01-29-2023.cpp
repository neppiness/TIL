#include <bits/stdc++.h>
using namespace std;

int a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  int cnt = 0;
  for(int i = n - 1; i > 0; i--) {
    if(a[i - 1] < a[i]) continue;
    int diff = a[i - 1] - a[i];
    cnt += diff + 1;
    a[i - 1] = a[i] - 1;
  }
  cout << cnt;
}