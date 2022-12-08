#include <bits/stdc++.h>
using namespace std;

stack<int> pridx;
bool vis[102];
string s;

void makepf(int st, int en) {
  char tmp = s[st];
  for(int i = st; i < en; i++)
    s[i] = s[i + 1];
  s[en] = tmp;
}

void pfop(bool ispm) {

}

void solve(int st, int en) {
  stack<char> pridx;
  for(int i = st; i <= en; i++) {
    if(vis[i]) continue;
    if(s[i] == '(') pr.push(i);
    else if(s[i] == ')') {
      int idx = pridx.top(); 
      pridx.pop();
      vis[idx] = vis[i] = 1;
      solve(idx + 1, i - 1);
    }
  }
  for(int i = st; i <= en; i++) {
    if(s[i] == '*' || s[i] == '/') pfop(0);
    else if(s[i] == '+' || s[i] == '-') pfop(1);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  solve(0, s.length() - 1);
  
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '(' || s[i] == ')') continue;
    cout << s[i];
  }
}
