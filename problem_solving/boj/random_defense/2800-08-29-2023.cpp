#include <bits/stdc++.h>
using namespace std;

int cnt;
string s;
pair<int, int> par[12];
set<string> ans;

int countPar() {
  int no = 0;
  stack<char> st;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      par[no].first = i;
      st.push(no); no++;
    }
    if (s[i] == ')') {
      int tmp = st.top(); st.pop();
      par[tmp].second = i;
    }
  }
  return no;
}

void addAnswer(int st) {
  bool chk[202] = {};
  int idx = 0;
  string tmp = "";
  while (st) {
    if (st % 2) {
      chk[par[idx].first] = 1;
      chk[par[idx].second] = 1;
    }
    st /= 2; idx++;
  }

  for (int i = 0; i < s.size(); i++)
    if (!chk[i]) tmp.push_back(s[i]);
  ans.insert(tmp);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  cnt = countPar();
  for (int i = 1; i < (1 << cnt); i++)
    addAnswer(i);
  for (auto a : ans)
    cout << a << '\n';
}
