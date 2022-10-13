#include <bits/stdc++.h>
using namespace std;

vector<int> idx[26];
int cnt[26];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;

  int x;
  for(int i = 0; i < a.length(); i++) {
    x = a[i] - 'A';
    idx[x].push_back(i);
  }
  stack<int> st;
  int mx = 0;
  for(int j = 0; j < b.length(); j++) {
    for(int i = j; i < b.length(); i++) {
      x = b[i] - 'A';
      if(idx[x].empty()) continue;
      if(st.empty()) {
        st.push(idx[x][0]);
        cnt[x]++;
      } else {
        if(cnt[x] == idx[x].size()) continue;
        if(st.top() < idx[x][cnt[x]]) {
          st.push(idx[x][cnt[x]]);
          mx = max(mx, (int)st.size());
          cnt[x]++;
        } else {
          while(!st.empty() && st.top() > idx[x][cnt[x]]) st.pop();
          st.push(idx[x][cnt[x]]);
          cnt[x]--;
        }
      }
    }
    while(!st.empty()) st.pop();
  }
  cout << mx;
}