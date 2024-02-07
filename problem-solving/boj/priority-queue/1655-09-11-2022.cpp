#include <bits/stdc++.h>
using namespace std;

int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  priority_queue<int> pq1;
  priority_queue<int, vector<int>, greater<int>> pq2;

  cin >> n;

  int a; cin >> a;
  pq1.push(a);
  cout << pq1.top() << '\n';

  for(int i = 1; i < n; i++) {
    cin >> a;
    if(i%2 == 1) {
      int b = pq1.top();
      if(b > a) {
        pq1.push(a);
        pq2.push(b);
        pq1.pop();
      } else pq2.push(a);
    } else {
      int b = pq2.top();
      if(b < a) {
        pq2.push(a);
        pq1.push(b);
        pq2.pop();
      } else pq1.push(a);
    }
    cout << pq1.top() << '\n';
  }
}