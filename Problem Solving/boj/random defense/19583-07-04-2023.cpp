#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> nicktoid;
int seq = 1, ans;
int mn[100'002], mx[100'002];

int s, e, q;

int timetomin(string s) {
  int idx = s.find(":"); 
  int hr = stoi(s.substr(0, idx));
  int m = stoi(s.substr(idx + 1));
  return hr * 60 + m;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(mn, 0x3f, sizeof(mn));
  memset(mx, -1, sizeof(mx));

  string time;
  cin >> time; s = timetomin(time);
  cin >> time; e = timetomin(time);
  cin >> time; q = timetomin(time);

  while (cin >> time) {
    string nick; cin >> nick;
    int id = nicktoid[nick];
    if (!id) {
      nicktoid[nick] = seq++;
      id = nicktoid[nick];
    }
    int t = timetomin(time);
    if (t > q) continue;
    mn[id] = min(mn[id], t);
    mx[id] = max(mx[id], t);
  }

  for (int id = 1; id < seq; id++)
    ans += (mn[id] <= s && e <= mx[id]);
  cout << ans;
}