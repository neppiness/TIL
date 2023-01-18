#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

string key, lck;

int mxlen;
pair<int, int> mxlenidx;

int len[MX + 2][MX + 2]; // len[keyidx][lckidx]
pair<int, int> idx[MX + 2][MX + 2]; // idx[curkeyidx][curlckidx] = {prvkeyidx, prvlckidx}`

void solve(int keyidx) {
  if(keyidx == key.length()) return;
  for(int lckidx = 0; lckidx < lck.length(); lckidx++) {
    int &tmplen = len[keyidx + 1][lckidx + 1];
    auto &tmpidx = idx[keyidx + 1][lckidx + 1];

    // case i. 이전 keyidx와 동일한 경우: 단순 할당 처리
    tmplen = len[keyidx][lckidx + 1];
    tmpidx = idx[keyidx][lckidx + 1];

    // case ii. 이전 lckidx와 동일한 경우: 비교를 통한 값 할당
    if(tmplen < len[keyidx + 1][lckidx]) {
      tmplen = len[keyidx + 1][lckidx];
      tmpidx = idx[keyidx + 1][lckidx];
    } else if(tmplen == len[keyidx + 1][lckidx]) {
      if(idx[keyidx + 1][lckidx].second < tmpidx.second)
        tmpidx = idx[keyidx + 1][lckidx];
    }

    // case iii. keyidx - 1과 lckidx에 이번에 매칭된 문자가 더해지는 경우
    bool ismatched = (key[keyidx] == lck[lckidx]);
    int l = len[keyidx][lckidx] + ismatched;
    if(l > tmplen) {
      tmplen = l;
      tmpidx = {keyidx, lckidx};
      if(l > mxlen) {
        mxlen = l;
        mxlenidx = {keyidx, lckidx};
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> key >> lck;
  for(int i = 0; i < lck.length(); i++)
    solve(i);

  cout << len[key.length()][lck.length()] << '\n';
  stack<char> st;
  auto p = mxlenidx;
  while(p.first != 0 || p.second != 0) {
    st.push(lck[p.second]);
    p = idx[p.first][p.second];
  }
  while(!st.empty()) {
    cout << st.top();
    st.pop();
  }
}