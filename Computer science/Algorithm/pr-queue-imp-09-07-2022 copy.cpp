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
  return heap[1];
}

void pop(){
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

void test(){
  push(10); push(2); push(5); push(9); // {10, 2, 5, 9}
  cout << top() << '\n'; // 2
  pop(); // {10, 5, 9}
  pop(); // {10, 9}
  cout << top() << '\n'; // 9
  push(5); push(15); // {10, 9, 5, 15}
  cout << top() << '\n'; // 5
  pop(); // {10, 9, 15}
  cout << top() << '\n'; // 9
}

int main(){
  test();
}