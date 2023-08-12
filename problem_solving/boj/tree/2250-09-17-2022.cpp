#include <bits/stdc++.h>
using namespace std;

int l[10002], r[10002];
bool isroot[10002];

vector<int> coord[10002];
int seq = 1;
int lev = 1, maxw = 0;

void inorder(int cur, int d) {
  if(l[cur] != -1) inorder(l[cur], d + 1);
  coord[d].push_back(seq++);
  if(r[cur] != -1) inorder(r[cur], d + 1);
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int no, lc, rc;

  fill(isroot + 1, isroot + 10001, 1);
  for(int i = 1; i <= n; i++) {
    cin >> no >> lc >> rc;
    l[no] = lc;
    r[no] = rc;
    if(lc != -1) isroot[lc] = 0;
    if(rc != -1) isroot[rc] = 0;
  }

  int root;
  for(int i = 1; i <= n; i++)
    if(isroot[i]) root = i;

  inorder(root, 1);
  
  for(int i = 1; i <= n; i++) {
    if(coord[i].empty()) continue;
    auto it = coord[i].end(); it--;
    int w = (*it) + 1;
    w -= *(coord[i].begin());
    if(maxw < w) {
      maxw = w;
      lev = i;
    }
  }
  cout << lev << ' ' << maxw;
}