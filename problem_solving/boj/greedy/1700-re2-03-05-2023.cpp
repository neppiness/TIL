#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
const int MX = 100;

int unused = 0;
int seq[MX + 2], cnt[MX + 2], mul[MX + 2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;

  for(int i = 0; i < k; i++)
    cin >> seq[i];

  int i = 0;
  for(; i < k; i++) {
    bool is_found = 0;
    for(int j = 0; j < unused; j++)
      if(seq[i] == mul[j]) { is_found = 1; break; }
    if(!is_found) mul[unused++] = seq[i];
    if(unused == n) break;
  }
  int mx, ans = 0;
  for(; i < k; i++) {
    mx = 0;
    memset(cnt, 0x7f, sizeof(cnt));
    bool is_plugged = 0;
    for(int j = 0; j < n; j++)
      if(seq[i] == mul[j]) is_plugged = 1;
    if(is_plugged) continue;

    for(int j = i + 1; j < k; j++) {
      cnt[seq[j]] = min(cnt[seq[j]], j);
      mx = max(mx, j);
    }
    for(int j = 0; j < n; j++) {
      if(cnt[mul[j]] != mx && cnt[mul[j]] != INF)
        continue;
      mul[j] = seq[i];
      ans++; break;
    }
  }
  cout << ans;
}