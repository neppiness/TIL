#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        string p, Xn;
        int n;

        cin >> p;
        cin >> n;
        cin >> Xn;

        // DQ initialization
        deque<int> DQ;
        for(int i = 0; i < n; i++) {
            DQ.push_back((int)(Xn[2*i + 1] - '0'));
        }

        int noComs = p.length();

        bool isFlipped = false, errorOccurred = false;

        for(int i = 0; i < noComs; i++) {
            if(p[i] == 'R') isFlipped = !isFlipped;
            else if(DQ.empty()) {
                cout << "error" << '\n';
                errorOccurred = true;
                i = noComs;
            } else {
                isFlipped ? (DQ.pop_back()) : (DQ.pop_front());
            }
        }

        if (!errorOccurred) {
            cout << '[';

            if(isFlipped) {
                for(auto idx = DQ.rbegin(); idx != DQ.rend(); ++idx) {
                    cout << *idx;
                    if(idx + 1 != DQ.rend()) cout << ',';
                }
            } else {
                for(auto idx = DQ.begin(); idx != DQ.end(); ++idx) {
                    cout << *idx;
                    if(idx + 1 != DQ.end()) cout << ',';
                }
            }
            cout << ']' << '\n';
        }
        DQ.clear();
    }
}