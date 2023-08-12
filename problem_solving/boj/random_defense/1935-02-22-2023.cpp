#include <bits/stdc++.h>
using namespace std;

double val[26];

stack<double> st;

int ctoi(char a) { return a - 'A'; }

bool is_al(char a) { return (a >= 'A' && a <= 'Z'); }

void calc(char op) {
  double y = st.top(); st.pop();
  double x = st.top(); st.pop();
  
  if(op == '*') st.push(x * y);
  else if(op == '/') st.push(x / y);
  else if(op == '+') st.push(x + y);
  else st.push(x - y);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string eq; cin >> eq;

  for(int i = 0; i < n; i++)
    cin >> val[i];

  for(char a : eq) {
    if(is_al(a)) st.push(val[ctoi(a)]);
    else calc(a);
  }
  cout.precision(2);
  cout << fixed;
  cout << st.top();
}