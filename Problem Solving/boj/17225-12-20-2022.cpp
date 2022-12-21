#include <bits/stdc++.h>
using namespace std;

// Index - 0 (false): sm, sangmin / 1 (true): js, jisoo
vector<int> ans[2];
queue<pair<int, int>> q[2]; // work queue

bool nowwrapping[2]; // sm or js is now wrapping

int com[2]; // time to completion, com
int N; // # of customers
int gift = 1, now = 0; // gift number, current time
int n[2]; // # of gift to wrap
int sttw[2]; // amount of spended time to wrap

void init() {
  cin >> com[0] >> com[1] >> N;
  while(N--) {
    int t, no; char color;
    cin >> t >> color >> no;
    q[(color == 'R')].push({t, no}); 
  }
}

void timeticks() {
  now++; // time is ticking
  for(int i = 0; i < 2; i++)
    sttw[i] += nowwrapping[i];
}

void assignwork() {
  // check work queue
  for(int i = 0; i < 2; i++) {
    if(!q[i].empty()) {
      auto [t, no] = q[i].front();
      if(now != t) continue;
      n[i] += no;
      q[i].pop();
    }
  }
}

void getgift(int i) {
  ans[i].push_back(gift++);
  nowwrapping[i] = 1;
  n[i]--;
  sttw[i] = 0;
}

bool isworkdone(int i) {
  if(sttw[i] != com[i]) return false;
  nowwrapping[i] = 0;
  return true;
}

bool hasworktodo(int i) { return n[i]; }

void wrapcheck(int i) {
  if(!nowwrapping[i]) getgift(i);
  if(isworkdone(i) && hasworktodo(i)) wrapcheck(i);
}

bool isover() { return !n[0] && !n[1] && q[0].empty() && q[1].empty(); }

void print() {
  for(int i = 0; i < 2; i++) {
    cout << ans[i].size() << '\n';
    for(auto x : ans[i])
      cout << x << ' ';
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();

  while(!isover()) {
    timeticks();
    assignwork();
    for(int i = 0; i < 2; i++)
      if(hasworktodo(i) || nowwrapping[i])
        wrapcheck(i);
  }
  print();
}
