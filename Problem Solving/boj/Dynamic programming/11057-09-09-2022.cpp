#include <bits/stdc++.h>
using namespace std;

int n;
long long ans[1002][10];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int j = 0; j < 10; j++) ans[1][j] = 1;

  for(int i = 2; i <= n; i++)
    for(int j = 1; j < 10; j++)
      for(int k = j; k < 10; k++)
        ans[i][j] = (ans[i][j] + ans[i-1][k]) % 10007;

  long long ANS = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 0; j < 10; j++)
      ANS = (ANS + ans[i][j])%10007;
  cout << ANS;
}