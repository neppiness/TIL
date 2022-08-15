#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int no, num[1002], freq[1002];
vector<int> freqV[1002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, C; cin >> N >> C;

    int idx = 0;
    for(int i = 0; i < N; i++) {
        cin >> no;
        bool isFound = 0;
        for(int j = 0; j < idx; j++) {
            if(no == num[j]) {
                freq[j]++;
                isFound = 1;
                break;
            }
        }
        if(!isFound) {
            num[idx] = no;
            freq[idx]++;
            idx++;
        }
    }

    for(int i = 0 ; i < N; i++) freqV[freq[i]].push_back(num[i]);

    for(int n = N; n > 0; n--)
        for(auto fr : freqV[n])
            for(int i = 0; i < n; i++) cout << fr << ' ';
}