#include <bits/stdc++.h>
using namespace std;

const string CH = "Cheese";

unordered_map<string, bool> ch;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    if (s.size() < CH.size()) continue;
    string ss = s.substr(s.size() - CH.size(), CH.size());
    if (ss == CH) {
      ch[s] = 1;
    }
  }
  if (ch.size() >= 4) {
    cout << "yummy";
  } else {
    cout << "sad";
  }
}
