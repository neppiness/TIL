#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MX = 600005;
int nxt[MX], pre[MX];
char dat[MX];
int cursor;
int unused;

void L() {if(cursor != 0) cursor -= 1;}
void D(int max) {if(cursor != max) cursor += 1;}

void B() {
    int idx = 0, cnt = 0;

    while(cnt != cursor) {
        idx = nxt[idx];
        cnt ++;
    }

    nxt[pre[idx]] = nxt[idx];
    if(nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
}

void P(char a) {
    dat[unused] = a;

    int idx = 0, cnt = 0;

    while(cnt != cursor) {
        idx = nxt[idx];
        cnt ++;
    }
    
    pre[unused] = idx;
    nxt[unused] = nxt[idx];

    if(nxt[idx] != -1) pre[nxt[idx]] = unused;
    nxt[idx] = unused;

    unused++;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    string str;
    cin >> str;

    int max = str.length();
    cursor = max;
    unused = max + 1;

    nxt[0] = 1;

    for (int i = 1; i < max; i++) {
        dat[i] = str[i-1];
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }

    dat[max] = str[max-1];
    pre[max] = max - 1;

    int noOfCommand = 0;
    cin >> noOfCommand;
    
    while(noOfCommand > 0) {
        char com;
        cin >> com;
        if (com == 'L') {
            L();
        } else if (com == 'D') {
            D(max);
        } else if (com == 'B') {
            if(cursor != 0) {
                B();
            }
        } else {
            char a;
            cin >> a;
            P(a);
        }
        noOfCommand--;
    }

    int idx = nxt[0];

    // traverse and print
    while(idx != -1) {
        cout << dat[idx];
        idx = nxt[idx];
    }

}