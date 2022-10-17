#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  deque<int> dq;
  int n;
  int cur, head, cnt = 0;
  cin >> n;
  cin >> cur;
  dq.push_back(cur);
  while(--n) {
    cin >> cur;
    cnt = 0;

    if(dq.size() == 1)
      dq.push_back(cur);

    if(dq.back() > cur) {
      while(dq.size() != 1) {
        head = dq.front(); dq.pop_front();
        cnt += (int)dq.size();
      } else {
        dq.push_back(cur);
        break;
      }
    }
  }

}