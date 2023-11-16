#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
string card[12];
bool is_picked[12];
unordered_map<ll, bool> memo;

void solve(int picked, string str) {
  if (picked == k) {
    memo[stol(str)] = 1;
    return;
  }
  
  for (int i = 0; i < n; i++) {
    if (is_picked[i]) continue;
    is_picked[i] = 1;
    solve(picked + 1, str + card[i]);
    is_picked[i] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> card[i];

  solve(0, "");
  cout << memo.size();
}
