#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

vector<int> split_numbers(string s) {
  vector<int> ret;
  int pos = 0;
  while (pos < s.size()) {
    int nxt = s.find(" ", pos);
    if (nxt == -1) nxt = s.size();
    string ss = s.substr(pos, nxt - pos);
    ret.push_back(stoi(ss));
    pos = nxt + 1;
  }
  return ret;
}

int solve() {
  vector<int> no;
  string s;
  getline(cin, s);
  no = split_numbers(s);

  int ans = 1;
  for (int i = 0; i < no.size(); i++)
    for (int j = i + 1; j < no.size(); j++)
      ans = max(ans, abs(gcd(no[i], no[j])));
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  cin.ignore();

  while (t--) cout << solve() << '\n';
}
