#include <iostream>

using namespace std;

const int MX = 100001;
int stk[MX];
int pos;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int total = 0;
    int noComs;
    cin >> noComs;

    while(noComs--) {
        int num;
        cin >> num;
        if(num == 0) {
            pos--;
        } else {
            stk[pos++] = num;
        }
    }

    while(pos--) {
        total += stk[pos];
    }

    cout << total;
}