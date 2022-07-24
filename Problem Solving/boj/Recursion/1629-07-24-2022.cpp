#include <iostream>

using namespace std;

long long pow(long long A, long long B, long long C){
    if(B == 1) return (A % C);
    long long val = (pow(A, B/2, C) % C);
    val = val * val % C;
    if(B % 2 == 0) return val;
    else return (A % C) * val;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    long long A, B, C; cin >> A >> B >> C;

    cout << pow(A, B, C) % C;
}