#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
int a[1002];
int len[1002][2];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 1002; i++)
    fill(len[i], len[i] + 2, 1);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(a[j] < a[i]) 
        len[i][0] = max(len[i][0], len[j][0] + 1); 
      else if (a[j] > a[i]) {
        len[i][1] = max(len[i][1], len[j][1] + 1);
        len[i][1] = max(len[i][1], len[j][0] + 1);
      }
    }
    int dmax = max(len[i][0], len[i][1]);
    ans = max(dmax, ans);
  }
  cout << ans;
}