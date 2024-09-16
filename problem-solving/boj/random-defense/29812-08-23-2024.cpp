#include <bits/stdc++.h>
using namespace std;

const string HYU = "HYU";

int n, d, m;
int hyu_cnt[3];
string s;

vector<string> split() {
  vector<string> ret;
  int pos = 0;
  while (pos < n) {
    int nxt1 = s.find("H", pos);
    int nxt2 = s.find("Y", pos);
    int nxt3 = s.find("U", pos);
    if (nxt1 == -1) nxt1 = n;
    if (nxt2 == -1) nxt2 = n;
    if (nxt3 == -1) nxt3 = n;
    
    int nxt = min(nxt1, nxt2);
    nxt = min(nxt, nxt3);
    
    int len = nxt - pos;
    if (len != 0) {
      string ss = s.substr(pos, nxt - pos);
      ret.push_back(ss);
    }
    pos = nxt + 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s >> d >> m;

  for (char c : s) {
    int pos = HYU.find(c);
    if (pos != -1) hyu_cnt[pos]++;
  }

  vector<string> ret = split();
  int tot = 0;
  for (string ss : ret) {
    int sss = ss.size();
    tot += min(sss * d, m + d);
  }
  if (tot == 0) {
    cout << "Nalmeok" << '\n';
  } else {
    cout << tot << '\n';
  }

  int hyu = 0x7f7f7f7f;
  for (int i = 0; i < 3; i++) {
    hyu = min(hyu, hyu_cnt[i]);
  }
  if (hyu == 0) {
    cout << "I love HanYang University";
  } else {
    cout << hyu;
  }
}
