#include <iostream>
#include <array>
using namespace std;

const int MX = 1000005;
int dat[MX];

int pos = 0;

void push(int x) {
    dat[pos++] = x;
}

void pop() {
    --pos;
}

int top() {
    return dat[pos-1];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
}