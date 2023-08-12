#include <bits/stdc++.h>
using namespace std;

string s;
stack<char> st;

pair<int, int> solve(int st) {
  int len = 0, i = st;
  for (; i < s.size(); i++) {
    char c = s[i];
    if ('0' <= c && c <= '9') len++;
    if (c == '(') {
      len--;
      auto [dl, nxt] = solve(i + 1);
      len += dl * (s[i - 1] - '0');
      i = nxt; // nxt는 닫는 괄호 좌표
    }
    if (c == ')') {
      return pair<int, int>(len, i);
    }
  }
  return pair<int, int>(len, s.size());
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  cout << solve(0).first;
}
