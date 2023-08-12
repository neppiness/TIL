#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;
const int di[] = {-1, 0, -1};
const int dj[] = {0, -1, -1};

string key, lck;
stack<char> st;
int cache[MX + 2][MX + 2];

void solve(int keyidx) {
  for(int lckidx = 0; lckidx < lck.length(); lckidx++) {
    int &ret = cache[keyidx + 1][lckidx + 1];
    bool ismatched = (key[keyidx] == lck[lckidx]);
    ret = max(cache[keyidx][lckidx + 1], cache[keyidx + 1][lckidx]);
    ret = max(ret, cache[keyidx][lckidx] + ismatched);
  }
}

void res(int ci, int cj) {
  if(ci == 0 || cj == 0) return;

  int pi = -1, pj = -1;
  for(int dir = 0; dir < 2; dir++) {
    int tmpi = ci + di[dir];
    int tmpj = cj + dj[dir];
    if(cache[tmpi][tmpj] != cache[ci][cj]) continue;
    pi = tmpi; pj = tmpj;
  }
  if(pi != -1 && pj != -1) {
    res(pi, pj);
    return;
  }
  st.push(key[ci - 1]);
  res(ci - 1, cj - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, 0, sizeof(cache));
  cin >> key >> lck;

  for(int keyidx = 0; keyidx < key.length(); keyidx++) 
    solve(keyidx);

  cout << cache[key.length()][lck.length()] << '\n';
  res(key.length(), lck.length());
  while(!st.empty()) {
    cout << st.top();
    st.pop();
  }
}