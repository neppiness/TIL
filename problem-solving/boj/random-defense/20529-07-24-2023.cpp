#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> id;
string types[] = {
  "ISTJ", "ISFJ", "INFJ", "INTJ",
  "ISTP", "ISFP", "INFP", "INTP",
  "ESTP", "ESFP", "ENFP", "ENTP",
  "ESTJ", "ESFJ", "ENFJ", "ENTJ"
};

int ans;
int cnt[16];
int is_picked[16];

int calc(int lidx, int ridx) {
  string lt = types[lidx];
  string rt = types[ridx];
  int pt = 0;
  for (int i = 0; i < 4; i++)
    if (lt[i] != rt[i]) pt++;
  return pt;
}

void calc() {
  vector<int> picked;
  for (int i = 0; i < 16; i++) {
    if (is_picked[i] > cnt[i]) return;
    int cyc = is_picked[i];
    while (cyc--) picked.push_back(i);
  }
  int tot = calc(picked[0], picked[1]);
  tot += calc(picked[0], picked[2]);
  tot += calc(picked[1], picked[2]);
  ans = min(ans, tot);
}

void bt(int to_pick, int type) {
  if (to_pick == 0) { calc(); return; }

  for (int i = 0; i < 16; i++) {
    is_picked[i]++;
    bt(to_pick - 1, i);
    is_picked[i]--;
  }
}

void solve() {
  memset(cnt, 0, sizeof(cnt));
  ans = 0x7f7f7f7f;

  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    cnt[id[s]]++;
  }

  bt(3, 0);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 16; i++)
    id[types[i]] = i;

  int t; cin >> t;
  while (t--) solve();
}