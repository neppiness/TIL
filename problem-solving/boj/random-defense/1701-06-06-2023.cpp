#include <bits/stdc++.h>
using namespace std;

string input;
int ans = 0;

queue<int> GetIndexes(int st) {
  queue<int> ret;
  char c = input[st];
  int pos = input.find(c, st + 1);
  while (pos != -1) {
    ret.push(pos);
    pos = input.find(c, pos + 1);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  for (int i = 0; i < input.size(); i++) {
    queue<int> nxt_q = GetIndexes(i);
    queue<int> cur_q;
    int st = i;
    if (nxt_q.empty()) continue;
    int len = 0;
    while (!nxt_q.empty()) {
      st++; len++; ans = max(ans, len);
      cur_q = nxt_q;
      nxt_q = queue<int>();
      while (!cur_q.empty()) {
        int cur = cur_q.front(); cur_q.pop();
        if (cur + 1 >= input.size()) continue;
        if (input[st] != input[cur + 1]) continue;
        nxt_q.push(cur + 1);
      }
    }
  }

  cout << ans;
}