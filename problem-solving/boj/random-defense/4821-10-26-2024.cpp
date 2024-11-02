#include <bits/stdc++.h>
using namespace std;

bool a[1002];
vector<string> ss;

vector<string> split(string &s) {
  vector<string> ret;
  int pos = 0;
  while (pos < s.size()) {
    int nxt = s.find(",", pos);
    if (nxt == -1) nxt = s.size();
    ret.push_back(s.substr(pos, nxt - pos));
    pos = nxt + 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n) {
    string str; cin >> str;
    ss = split(str);

    for (string s : ss) {
      int pos = s.find("-");
      if (pos != -1) {
        int p1 = stoi(s.substr(0, pos));
        int p2 = stoi(s.substr(pos + 1));
        for (int i = p1; i <= min(n, p2); i++)
          a[i] = 1;
      } else {
        int p = stoi(s);
        if (p <= n) a[p] = 1;
      }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
      ans += a[i];
    cout << ans << '\n';
    memset(a, 0, sizeof(a));
    cin >> n;
  }
  
}
