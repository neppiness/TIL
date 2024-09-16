#include <bits/stdc++.h>
using namespace std;

int reg;
stack<int> st;

string inst[1002];

vector<string> split(string &s) {
  vector<string> ret;
  int pos = s.find(" ");
  string s1 = s.substr(0, pos);
  string s2 = s.substr(pos + 1, s.size() - (pos + 1));
  ret.push_back(s1);
  ret.push_back(s2);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++)
    getline(cin, inst[i]);

  for (int i = 0; i < n; i++) {
    string ss = inst[i].substr(0, 4);
    if (ss == "PUSH") {
      vector<string> sp = split(inst[i]);
      st.push(stoi(sp[1]));
    } else if (ss == "STOR") {
      reg = st.top(); st.pop();
    } else if (ss == "LOAD") {
      st.push(reg);
    } else if (ss == "PLUS") {
      int x = st.top(); st.pop();
      int y = st.top(); st.pop();
      st.push(x + y);
    } else if (ss == "TIME") {
      int x = st.top(); st.pop();
      int y = st.top(); st.pop();
      st.push(x * y);
    } else if (ss == "IFZE") {
      vector<string> sp = split(inst[i]);
      int m = stoi(sp[1]);
      int x = st.top(); st.pop();
      if (x == 0) i = m - 1;
    } else {
      cout << st.top();
      return 0;
    }
  }
}
