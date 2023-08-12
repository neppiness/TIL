#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MX = 1111111;
int nxt[MX], pre[MX];
char dat[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);

    string str;
    cin >> str;

    // Init. of a list
    int max = str.length();

    nxt[0] = 1;
    for (int i = 1; i <= max; i++) {
        dat[i] = str[i-1];
        nxt[i] = i + 1;
        pre[i] = i - 1;
    }
    nxt[max] = -1;

    int cursor = max;
    int unused = max + 1;

    // Commands
    int noOfCommands;
    cin >> noOfCommands;

    while(noOfCommands--) {
        char com;
        cin >> com;
        if (com == 'L') {
            if(pre[cursor] != -1) cursor = pre[cursor];
        } else if (com == 'D') { 
            if(nxt[cursor] != -1) cursor = nxt[cursor];
        } else if (com == 'B') {
            if(pre[cursor] != -1) {
                nxt[pre[cursor]] = nxt[cursor];
                if(nxt[cursor] != -1) pre[nxt[cursor]] = pre[cursor];
                cursor = pre[cursor];
            }
        } else if (com == 'P') {
            char a;
            cin >> a;

            dat[unused] = a;
            pre[unused] = cursor;
            nxt[unused] = nxt[cursor];

            if(nxt[cursor] != -1) pre[nxt[cursor]] = unused;
            nxt[cursor] = unused;

            cursor = unused;
            unused++;
        }
    }

    int idx = nxt[0];

    // traverse and print
    while(idx != -1) {
        cout << dat[idx];
        idx = nxt[idx];
    }
}