#include <bits/stdc++.h>
using namespace std;

const string NO[] = {
  "zero", "one", "two", "three", "four",
  "five", "six", "seven", "eight", "nine"
};

set<pair<string, int>> memo;

void setup(int x) {
  int tmp = x;
  stack<int> st;
  while (x) {
    int digit = x % 10;
    st.push(digit);
    x /= 10;
  }
  string str = "";
  while (!st.empty()) {
    str += NO[st.top()] + " ";
    st.pop();
  }
  memo.insert({str, tmp});
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;

  for (int i = n; i <= m; i++) {
    setup(i);
  }
  
  int cnt = 0;
  for (auto [str, x] : memo) {
    cout << x;
    if (cnt == 9) {
      cnt = 0;
      cout << '\n';
    } else {
      cnt++;
      cout << ' ';
    }
  }
}
