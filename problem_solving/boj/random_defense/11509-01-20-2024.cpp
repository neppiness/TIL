#include <bits/stdc++.h>
using namespace std;

int a[1'000'002];
int arr[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  for (int i = 0; i < n; i++) {
    int &h = a[i];
    if (arr[h] != 0) {
      arr[h]--;
    }
    arr[h - 1]++;
  }

  int ans = 0;
  for (int i = 0; i <= 1'000'000; i++)
    ans += arr[i];
  cout << ans;
}
