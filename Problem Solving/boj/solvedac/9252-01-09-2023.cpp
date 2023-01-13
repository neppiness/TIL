#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

int cache[MX + 2][MX + 2]; // cache[keyidx][lckidx]
string key, lck;

void solve() {
  for(int keyidx = 0; keyidx < key.length(); keyidx++) {
    for(int lckidx = 0; lckidx < lck.length(); lckidx++) {
      bool ismatched = (key[keyidx] == lck[lckidx]);
      int &c = cache[keyidx + 1][lckidx + 1];
      c = cache[keyidx][lckidx] + ismatched;

      int &pl = cache[keyidx + 1][lckidx];
      int &pk = cache[keyidx][lckidx + 1];
      c = max({c, pk, pl});
    }
  }
}

void print() {
  int len = cache[key.length()][lck.length()];
  cout << len << '\n';

  int x = idx[key.length()][lck.length()];
  stack<char> st;

  if(x == -1) return;
  while(len != 0) {
    st.push(lck[x]);
    x = idx[key.length()][x];
    len--;
  }
  while(!st.empty()) {
    cout << st.top();
    st.pop();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> key >> lck;

  memset(idx, -1, sizeof(idx));

  solve();
  print();
}