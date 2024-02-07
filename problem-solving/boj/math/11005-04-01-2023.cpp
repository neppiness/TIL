#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int no, n;
  cin >> no >> n;

  if(no == 0) { cout << 0; return 0; }
  while(no != 0) {
    int x = no % n;
    no /= n;
    if(x < 10) st.push('0' + x);
    else st.push(x - 10 + 'A');
  }

  while(!st.empty()) {
    cout << st.top();
    st.pop();
  }
}