#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int yr; 
    cin >> yr;

    if ((yr % 4 == 0) && (yr % 100 != 0) || (yr % 400 == 0)) {
        cout << 1;
    } else cout << 0;
}