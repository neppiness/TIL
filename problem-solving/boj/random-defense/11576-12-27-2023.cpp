#include <bits/stdc++.h>
using namespace std;

int a, b;
int x[30];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  int n; cin >> n;

  int no = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    no *= a;
    no += x;
  }

  stack<int> st;
  while (no) {
    st.push(no % b);
    no /= b;
  }

  while (!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
}
