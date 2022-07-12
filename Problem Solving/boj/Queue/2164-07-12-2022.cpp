#include <queue>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    queue<int> q;

    int N; cin >> N;

    int i = 1;
    for(; i <= N; i++) {
        q.push(i);
    }

    while(--N) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}