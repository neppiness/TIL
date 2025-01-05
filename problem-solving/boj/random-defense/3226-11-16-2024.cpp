#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_time(string s) {
  return { stoi(s.substr(0, 2)), stoi(s.substr(3)) };
}

int get_cost(int h, int m, int d) {
  int st = h * 60 + m;
  int en = st + d;
  
  int ret = 0;
  for (int i = st; i < en; i++) {
    int t = i % 1440;
    if (420 <= t && 19 * 60 > t) {
      ret += 10;
    } else {
      ret += 5;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int ans = 0;
  while (n--) {
    string s; int d;
    cin >> s >> d;
    auto [h, m] = get_time(s);
    ans += get_cost(h, m, d);
  }
  cout << ans;
}
