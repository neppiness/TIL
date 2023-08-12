#include <bits/stdc++.h>
using namespace std;

set<int> full_cand;
int given_clock_no;
int cnt = 1;

int getClockNo(int tot) {
  vector<int> no(4), cand;
  int cnt = 4;
  while (cnt--) {
    no[cnt] = tot % 10;
    tot /= 10;
  }

  for (int i = 0; i < 4; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      int k = i + j;
      if (k >= 4) k-= 4;
      sum *= 10; sum += no[k];
    }
    cand.push_back(sum);
  }
  sort(cand.begin(), cand.end());
  return cand[0];
}

void genAllClockNos(int di, int tot) {
  if (di == 4) {
    full_cand.insert(getClockNo(tot));
    return;
  }
  for (int i = 1; i <= 9; i++)
    genAllClockNos(di + 1, tot * 10 + i);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int tot = 0;
  for (int i = 0; i < 4; i++) {
    int x; cin >> x;
    tot *= 10; tot += x;
  }

  given_clock_no = getClockNo(tot);
  genAllClockNos(0, 0);
  auto it = full_cand.begin();
  int cnt = 1;
  while (it != full_cand.end()) {
    if (*it == given_clock_no) {
      cout << cnt;
      return 0;
    }
    it++; cnt++;
  }
}