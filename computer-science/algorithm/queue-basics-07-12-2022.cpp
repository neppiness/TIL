#include <iostream>

using namespace std;

int head = 0, tail = 0;
const int MX = 111111;
int queue[MX] = {0};

void push(int x) {
    queue[tail++] = x;
}

void pop() {
    head++;
}

int front() {
    return queue[head];
}

int back() {
    return queue[tail-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int x;
    
    push(x);
}