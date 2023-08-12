#include <bits/stdc++.h>
using namespace std;

string s[10002];
queue<int> q;
char cmd[] = {'D', 'S', 'L', 'R'};

string bfs(int st, int en) {
  q.push(st);
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    string str = s[cur];
    for(char c : cmd) {
      int nxt;
      if(c == 'D') nxt = (cur << 1) % 10000;
      else if(c == 'S') nxt = (cur + 9999) % 10000;
      else if(c == 'L') nxt = (cur % 1000)*10 + (cur / 1000);
      else nxt = (cur / 10) + (cur % 10)*1000;

      if(s[nxt] != "") continue;
      s[nxt] = str + c;
      if(nxt == en) return s[en];
      q.push(nxt);
    }
  }
  return "";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  int a, b;
  while(t--) {
    cin >> a >> b;
    fill(s, s + 10002, "");
    while(!q.empty()) q.pop();

    cout << bfs(a, b) << '\n';
  }
}