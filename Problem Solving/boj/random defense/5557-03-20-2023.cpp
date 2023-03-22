#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100;

int n, tar;
ll cache[MX + 2][21];
int no[MX + 2];

// i번째 수까지 더해서 연산 결과가 tot인 경우의 수를 반환하는 함수
ll solve(int i, int tot) {
  if(tot > 20 || tot < 0) return 0;
  if(i == 1) return (tot == no[1]);

  ll &ret = cache[i][tot];
  if(ret != -1) return ret;

  int nxt1 = tot - no[i];
  int nxt2 = tot + no[i];
  return ret = solve(i - 1, nxt1) + solve(i - 1, nxt2);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n; n--;
  for(int i = 1; i <= n; i++)
    cin >> no[i];
  cin >> tar;

  cout << solve(n, tar);
}