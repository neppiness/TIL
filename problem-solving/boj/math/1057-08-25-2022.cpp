#include <iostream>
using namespace std;

int N, A, B;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> A >> B;
    int round = 0;

    while(A != B) {++A /= 2; ++B /= 2; round++;}
    cout << round;
}