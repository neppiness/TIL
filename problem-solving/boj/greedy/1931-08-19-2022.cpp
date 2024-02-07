#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;

tuple<int,int,int> conv[100002];
int N;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    int begin, end, time;
    for(int i = 0; i < N; i++) {
        cin >> begin >> end;
        time = end - begin;
        conv[i] = {end,time,begin};
    }

    sort(conv, conv+N);

    int tmp = 0, cnt = 0;
    for(int i = 0; i < N; i++) {
        tie(end,time,begin) = conv[i];
        if(begin < tmp) continue;
        tmp = end;
        cnt++;
    }
    cout << cnt;
}