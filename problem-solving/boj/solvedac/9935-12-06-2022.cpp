#include <bits/stdc++.h>
using namespace std;

int idx[256];
string s, tr;

void reset(stack<char> &ans, stack<char> &tmp) {
  while(!tmp.empty()) {
    ans.push(tmp.top());
    tmp.pop();
  }
}

void solve(stack<char> &ans) {
  stack<char> tmp;
  for(int i = tr.length(); i > 0; i--) {
    char c = ans.top();
    if(idx[c] != i) {
      reset(ans, tmp);
      return;
    }
    tmp.push(c);
    ans.pop();
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s >> tr;

  int trlen = tr.length();
  for(int i = 0; i < trlen; i++)
    idx[tr[i]] = i + 1;

  stack<char> ans;
  for(int i = 0; i < s.length(); i++) {
    char c = s[i];
    ans.push(c);
    if(idx[c] != trlen) continue;
    if(ans.size() < tr.length()) continue;
    solve(ans);
  }

  if(ans.empty()) {
    cout << "FRULA";
    return 0;
  }

  int idx = ans.size();
  char answer[idx + 1];
  fill(answer, answer + idx + 1, 0);

  while(!ans.empty()) {
    answer[--idx] = ans.top();
    ans.pop();
  }
  cout << answer;
}