#include <bits/stdc++.h>
using namespace std;

string s;

bool isNotPlusMinus(char a) { return (a == '*' || a == '/'); }

bool isPlusMinus(char a) { return (a == '-' || a == '+'); }

bool isLetter(char a) { return (a >= 'A' && a <= 'Z'); }

void solve(int i) {
  queue<char> ch;
  stack<char> op;
  for(int i = 0; i < s.length(); i++) {
    if(isOperator(s[i])) op.push(s[i]);
    else if(isLetter(s[i])) ch.push(s[i]);
  }
  while(!ch.empty()) {
    cout << ch.front();
    ch.pop();
  }
  while(!op.empty()) {
    cout << op.top();
    op.pop();
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;
  solve(0);
}