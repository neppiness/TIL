#include <bits/stdc++.h>
using namespace std;

int n, k;
set<string> ans;
stack<int> st;

void setAnswer(stack<int> stk) {
  stack<int> temp;
  while (!stk.empty()) {
    temp.push(stk.top());
    stk.pop();
  }
  string s;
  while (!temp.empty()) {
    s.push_back('0' + temp.top());
    temp.pop();
    s.push_back('+');
  }
  s.pop_back();
  ans.insert(s);
}

void solve(int tot) {
  if (tot == n) {
    setAnswer(st);
    return;
  }
  for (int i : {1, 2, 3}) {
    if (tot + i > n) continue;
    st.push(i);
    solve(tot + i);
    st.pop();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  solve(0);
  
  if (k > ans.size()) {
    cout << -1;
  } else {
    auto it = ans.begin();
    while (--k) it++;
    cout << *it;
  }
}
