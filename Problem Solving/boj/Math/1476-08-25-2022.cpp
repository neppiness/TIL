#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int E, S, M; cin >> E >> S >> M;
    E--; S--; M--;
    
    int limit = 15 * 28 * 19;
    for(int i = 0; i <= limit; i++)
        if(i % 15 == E && i % 28 == S && i % 19 == M)
            {cout << i + 1; return 0;}
}