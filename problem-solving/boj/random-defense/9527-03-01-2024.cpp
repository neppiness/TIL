#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll count() {
  ll a, b;
  cin >> a >> b;
  
  stack<bool> st;
  while (a) {
    st.push(a % 2);
    a /= 2;
  }

  ll cnt_a = 0;
  ll tot_a = 0;
  while (!st.empty()) {
    bool cur = st.top();
    st.pop();
    if (!cur) continue;
    tot_a += ((ll)1 << st.size() - 1) * (st.size()) + cnt_a * ((ll)1 << (st.size()));
    cnt_a++;
  }

  while (b) {
    st.push(b % 2);
    b /= 2;
  }

  ll cnt_b = 0;
  ll tot_b = 0;
  while (!st.empty()) {
    bool cur = st.top();
    st.pop();
    if (!cur) continue;
    tot_b += ((ll)1 << st.size() - 1) * (st.size()) + cnt_b * ((ll)1 << (st.size()));
    cnt_b++;
  }
  tot_b += cnt_b;
  return tot_b - tot_a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << count();
}
