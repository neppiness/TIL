// #include <queue>
#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int n;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  int x;
  for(int i = 0; i < n; i++) {
    cin >> x;
    pq.push(x);
  }
  for(int i = 0; i < (n-1)*n; i++) {
    cin >> x;
    pq.push(x);
    pq.pop();
  }
  cout << pq.top();
}