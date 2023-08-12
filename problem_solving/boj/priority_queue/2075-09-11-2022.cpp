#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0); cin.tie(0);

  int n, a;
  cin >> n;

  priority_queue<int> pq[n], tops;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> a;
      pq[j].push(a);
    }

  for(int i = 0; i < n; i++) tops.push(pq[i].top());

  int cnt = 1;
  while(cnt != n) {
    for(int i = 0; i < n; i++)
      if(pq[i].top() == tops.top()) {
        pq[i].pop();
        tops.pop();
        tops.push(pq[i].top());
        cnt++; break;
      }
  }
  cout << tops.top();
}