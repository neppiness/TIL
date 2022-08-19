#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> conv[100002];
int N;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    int begin, end;
    for(int i = 0; i < N; i++) {
        cin >> begin >> end;
        conv[i] = {end,begin};
    }

    sort(conv, conv+N);

    int tmp = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
        end = conv[i].first;
        begin = conv[i].second;
        if(begin < tmp) continue;
        tmp = end; cnt++;
    }
    cout << cnt;
}