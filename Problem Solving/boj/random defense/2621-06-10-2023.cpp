#include <bits/stdc++.h>
using namespace std;

char col[5];
int no[5];

int ccnt[4];
int ncnt[10];

int ColToNum(char c) {
  if (c == 'R') return 0;
  if (c == 'B') return 1;
  if (c == 'Y') return 2;
  return 3;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    cin >> col[i] >> no[i];
    ccnt[ColToNum(col[i])]++;
    ncnt[no[i]]++;
  }

  bool is_all_same_col = 1;
  for (int i = 1; i < 5; i++)
    if (col[i] != col[0])
      is_all_same_col = 0;
  
  // sorted numbers
  int tmp[5];
  for (int i = 0; i < 5; i++)
    tmp[i] = no[i];
  sort(tmp, tmp + 5);

  bool is_sequence = 1;
  for (int i = 1; i < 5; i++)
    if (tmp[i] - tmp[i - 1] != 1)
      is_sequence = 0;
  
  if (is_all_same_col) {
    if (is_sequence) cout << 900 + tmp[4]; // case 1
    else cout << 600 + tmp[4]; // case 4
    return 0;
  }

  if (is_sequence) {
    cout << 500 + tmp[4]; // case 5
    return 0;
  }

  vector<pair<int, int>> ncntchk;
  for (int i = 1; i <= 9; i++)
    ncntchk.push_back({ncnt[i], i});
  sort(ncntchk.rbegin(), ncntchk.rend());

  auto [mxncnt, mxnum] = ncntchk[0];
  if (mxncnt == 4) {
    cout << 800 + mxnum; // case 2
    return 0;
  }

  auto [nxtcnt, nxtnum] = ncntchk[1];
  if (mxncnt == 3) {
    if (nxtcnt == 2) cout << 700 + mxnum*10 + nxtnum; // case 3
    else cout << 400 + mxnum; // case 6
    return 0;
  }

  if (mxncnt == 2) {
    if (nxtcnt == 2) cout << 300 + max(mxnum, nxtnum) * 10 + min(mxnum, nxtnum);
    else cout << 200 + mxnum;
    return 0;
  }
  
  cout << 100 + tmp[4];
}