#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
const int INF = 0x3f3f3f3f;

string key, lck;
int len[MX + 2][MX + 2]; // len[keyidx][lckidx]
pair<int, int> idx[MX + 2][MX + 2]; // idx[curkeyidx][curlckidx] = {prvkeyidx, prvlckidx}`

void solve(int keyidx, int lckidx) {
  if(keyidx > key.length()) return;
  int &tmplen = len[keyidx][lckidx];
  auto &tmpidx = idx[keyidx][lckidx];
  // case i. 이전 keyidx와 동일한 경우: 단순 할당 처리
  tmplen = len[keyidx - 1][lckidx];
  tmpidx = idx[keyidx - 1][lckidx];

  // case ii. 이전 lckidx와 동일한 경우: 비교를 통한 값 할당
  tmplen = max(tmplen, len[keyidx][lckidx - 1]);
  if(idx[keyidx][lckidx - 1].second < tmpidx.second)
    tmpidx = idx[keyidx][lckidx - 1];

  // case iii. keyidx - 1과 lckidx에 이번에 매칭된 문자가 더해지는 경우
  bool ismatched = (key[keyidx] == lck[lckidx]);
  int l = len[keyidx - 1][lckidx - 1] + ismatched;
  if(l > tmplen) {
    tmplen = l;
    tmpidx = {keyidx - 1, lckidx - 1};
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> key >> lck;
  for(int i = 1; i <= lck.length(); i++)
    solve(i, 0);

  cout << len[key.length()][lck.length()] << '\n';
  auto p = idx[key.length()][lck.length()];
  while(p != {0, 0}) {
    
  }
}