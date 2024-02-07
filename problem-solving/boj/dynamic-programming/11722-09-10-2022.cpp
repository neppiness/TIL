#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
int a[1002];
int len[1002];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  fill(len, len + n, 1);
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[j] > a[i]) len[i] = max(len[i], len[j] + 1);
      ans = max(ans, len[i]);
    }
  }
  cout << ans;
}