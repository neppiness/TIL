#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while (n--) {
    string s; cin >> s;
    vector<char> ch;
    ch.resize(s.size());
    for (int i = 0; i < s.size(); i++)
      ch[i] = s[i];
    if (next_permutation(ch.begin(), ch.end())) {
      for (int i = 0; i < s.size(); i++)
        cout << ch[i];
    } else {
      cout << "BIGGEST";
    }
    cout << '\n';
  }
}
