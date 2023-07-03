#include <bits/stdc++.h>
using namespace std;

int main() {
  stack<int> st;
  st.push(1);
  st.push(st.top());
  
  while (!st.empty()) {cout << st.top() << ' '; st.pop();}
}