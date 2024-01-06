#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; string s;
  cin >> n >> s;

  vector<pair<int, bool>> a;
  int cnt = 1;
  char prv = s[0];
  for (int i = 1; i < n; i++) {
    if (prv == s[i]) {
      cnt++;
    } else {
      a.push_back({cnt, prv == 'B'});
      cnt = 1;
      prv = s[i];
    }
  }
  a.push_back({cnt, prv == 'B'});

  stack<pair<int, bool>> st1, st2;
  for (int i = 0; i < a.size(); i++) {
    st1.push(a[i]);
    st2.push(a[a.size() - 1 - i]);
  }

  int ans_blue_right = 0, ans_red_right = 0;
  st1.pop();
  while (st1.size() >= 2) {
    auto [x, x_is_blue] = st1.top(); st1.pop();
    auto [y, y_is_blue] = st1.top(); st1.pop();
    ans_blue_right += x * x_is_blue + y * y_is_blue;
    ans_red_right += x * !x_is_blue + y * !y_is_blue;
    if (st1.empty()) break;
    auto [z, z_is_blue] = st1.top(); st1.pop();
    st1.push({x + z, z_is_blue});
  }

  int ans_blue_left = 0, ans_red_left = 0;
  st2.pop();
  while (st2.size() >= 2) {
    auto [x, x_is_blue] = st2.top(); st2.pop();
    auto [y, y_is_blue] = st2.top(); st2.pop();
    ans_blue_left += x * x_is_blue + y * y_is_blue;
    ans_red_left += x * !x_is_blue + y * !y_is_blue;
    if (st2.empty()) break;
    auto [z, z_is_blue] = st2.top(); st2.pop();
    st2.push({x + z, z_is_blue});
  }

  cout << min(min(ans_blue_right, ans_red_right), min(ans_blue_left, ans_red_left));

}
