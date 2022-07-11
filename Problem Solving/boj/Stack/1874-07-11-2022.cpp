#include <iostream>
#include <string>

using namespace std;

const int MX = 100001;
int stk[MX], pos = 0;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string answer;

    int noComs;
    cin >> noComs;

    bool isFail = false;
    int i = 1, num;

    while(noComs--) {
        cin >> num;

        if (i <= num) {
            while(i <= num) {
                answer += '+';
                stk[pos++] = i;
                i++;
            }
            answer += '-';
            --pos;
        } else {
            int popEl = stk[--pos];
            if(popEl != num) {
                isFail = true;
                break;
            } answer += '-';
        }
    }

    if(isFail) {
        cout << "NO";
    } else {
        for (auto c : answer) {
            cout << c << '\n';
        }
    }
}