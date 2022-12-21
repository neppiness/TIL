#include <bits/stdc++.h>
using namespace std;

int ans; 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<tuple<int, int, int>> hw;
  bool hwgiven;
  int dur, pro, sc;

  int n; cin >> n;
  while(n--) {
    cin >> hwgiven;
    if(hwgiven) {
      cin >> sc >> dur;
      hw.push({dur, 0, sc});
    }
    if(!hw.empty()) {
      tie(dur, pro, sc) = hw.top(); hw.pop();
      pro++;
      if(dur == pro) ans += sc;
      else hw.push({dur, pro, sc});
    }
  }
  cout << ans;
}