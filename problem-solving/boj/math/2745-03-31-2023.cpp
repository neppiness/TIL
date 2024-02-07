#include <bits/stdc++.h>
using namespace std;

bool is_num(char c) { return (c >= '0' && c <= '9'); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string no; int n;
  cin >> no >> n;

  int ans = 0;
  for(char c : no) {
    ans *= n;
    if(is_num(c)) ans += c - '0';
    else ans += c - 'A' + 10;
  }
  cout << ans;
}