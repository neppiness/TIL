// based on https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x17/heap_test.cpp
#include <bits/stdc++.h>
using namespace std;

int heap[100005];
int sz = 0; // heap에 들어있는 원소의 수

void push(int x){
  heap[++sz] = x;
  int cur = sz;
  while(cur != 1) {
    if(heap[cur/2] > heap[cur])
      swap(heap[cur/2], heap[cur]);
    else break;
    cur /= 2;
  }
}

int top(){
  if(sz) return heap[1];
  else return 0;
}

void pop(){
  if(!sz) return;
  heap[1] = heap[sz--];
  int cur = 1;
  while(cur*2 <= sz) {
    int tmp = cur*2;
    if(cur*2 + 1 <= sz)
      if(heap[cur*2 + 1] < heap[cur*2])
        tmp = cur*2 + 1;
    if(heap[cur] > heap[tmp]) {
      swap(heap[tmp], heap[cur]);
      swap(tmp, cur);
    } else break;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  while(n--) {
    int cmd; cin >> cmd;
    if(cmd == 0) {
      cout << top() << '\n';
      pop();
    } else push(cmd);
  }
}