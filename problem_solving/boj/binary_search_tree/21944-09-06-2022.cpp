#include <bits/stdc++.h>
using namespace std;

int N, M;
int no, d, g, x;
set<int> group[102];
set<int> diff[102];
set<int> prob[102][102]; // diff, group
pair<int,int> diffandgr[100'002]; // diff, group

void recommend(){
  cin >> g >> x;
  if(x == -1) {
    int i = 1;
    for(; i <= 100; i++) {
      if(prob[i][g].empty()) continue;
      else break;
    }
    cout << *(prob[i][g].begin()) << '\n';
  } else {
    int i = 100;
    for(; i >= 1; i--) {
      if(prob[i][g].empty()) continue;
      else break;
    }
    cout << *prev(prob[i][g].end()) << '\n';
  }
}

void recommend2(){
  cin >> x;
  if(x == -1) {
    int i = 1;
    for(; i <= 100; i++) {
      if(diff[i].empty()) continue;
      else break;
    }
    if(i == 101) return;
    cout << *(diff[i].begin()) << '\n';
  } else {
    int i = 100;
    for(; i >= 1; i--) {
      if(diff[i].empty()) continue;
      else break;
    }
    if(i == 0) return;
    cout << *prev(diff[i].end()) << '\n';
  }
}

void recommend3(){
  cin >> x >> d;
  int i = d;
  if(x == -1){
    i--;
    for(; i >= 1; i--) {
      if(diff[i].empty()) continue;
      else break;
    }
    if(i) cout << *prev(diff[i].end()) << '\n';
    else cout << -1 << '\n';
  } else {
    for(; i <= 100; i++) {
      if(diff[i].empty()) continue;
      else break;
    }
    if(i != 101) cout << *(diff[i].begin()) << '\n';
    else cout << -1 << '\n';
  }
}

void add() {
  cin >> no >> d >> g;
  diff[d].insert(no);
  group[g].insert(no);
  prob[d][g].insert(no);
  diffandgr[no] = {d, g};
}

void solved(){
  cin >> no;
  auto cur = diffandgr[no];
  tie(d, g) = cur;
  group[g].erase(no);
  diff[d].erase(no);
  prob[d][g].erase(no);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) add();

  cin >> M;
  for(int i = 0; i < M; i++) {
    string cmd; cin >> cmd;
    if(cmd == "recommend") recommend();
    else if(cmd == "recommend2") recommend2();
    else if(cmd == "recommend3") recommend3();
    else if(cmd == "add") add();
    else solved();
  }
}