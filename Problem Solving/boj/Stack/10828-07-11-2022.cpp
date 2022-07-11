#include <iostream>
#include <string>

using namespace std;

const int MX = 10001;

int stk[MX];
int pos = 0;

void push(int num) {
    stk[pos++] = num;
}

void pop() {
    if (pos == 0) cout << -1;
    else cout << stk[--pos];
    cout << '\n';
}

void size() {
    cout << pos << '\n';
}

void empty() {
    if(pos == 0) cout << 1;
    else cout << 0;
    cout << '\n';
}

void top() {
    if(pos != 0) cout << stk[pos-1];
    else cout << -1;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int noCommands;
    string com;
    cin >> noCommands;
    int num;
    while(noCommands--) {
        cin >> com;

        if(com.length() == 5) {
            empty();
        } else if(com.length() == 4) {
            if(com[0] == 'p' && com[1] == 'u' && com[2] == 's' && com[3] == 'h') {
                cin >> num;
                push(num);
            } else {
                size();
            }
        } else {
            if(com[0] == 't' && com[1] == 'o' && com[2] == 'p') top();
            else pop();
        }
    }
}