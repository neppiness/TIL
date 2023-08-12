#include <iostream>

using namespace std;
int N, M;

int ans[10];
bool isUsed[10] = {false};

void print(){
    for(int i = 0; i < M; i++) cout << ans[i] << ' ';
    cout << '\n';
}

void findSequence(int k){
    if(M == k) print();
    else {
        for(int i = 1; i <= N; i++){
            if(isUsed[i]) continue;
            else {
                ans[k] = i;
                isUsed[i] = true;
                findSequence(k+1);
                isUsed[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;

    findSequence(0);
}