#include <iostream>
using namespace std;

int n;
int ans[32];

long long solve() {
  if(n%2 == 1) return 0;

  ans[0] = 1; ans[2] = 3;
  for(int i = 4; i <= n; i += 2) {
    ans[i] += ans[i-2] * ans[2];
    for(int j = i-4; j >= 0; j -= 2)
      ans[i] += ans[j]*2;
  }
  return ans[n];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cout << solve();
}