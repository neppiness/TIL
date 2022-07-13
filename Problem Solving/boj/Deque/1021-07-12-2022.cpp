#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> DQ;

void lShift(int n){
    while(n--) {
        DQ.push_back(DQ.front());
        DQ.pop_front();
    }
}

void rShift(int n){
    while(n--) {
        DQ.push_front(DQ.back());
        DQ.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        DQ.push_back(i);
    }
    
    int result = 0;

    while(M--) {
        int num;
        cin >> num;

        int L = DQ.size();
        int idx = find(DQ.begin(), DQ.end(), num) - DQ.begin();

        if(idx < (L - idx)) {
            lShift(idx);
            DQ.pop_front();
            result += idx;
        } else {
            rShift(L - idx);
            DQ.pop_front();
            result += L - idx;
        }
    }

    cout << result;
}