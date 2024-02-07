#include <iostream>
using namespace std;

int N;
int RGB[1002][3]; // RGB[house][color]
int calc[1002][3]; // calc[house][current color]

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];

    for(int i = 0; i < N; i++) fill(calc[i], calc[i] + 3, 0x7f7f7f7f);
    calc[0][0] = RGB[0][0];
    calc[0][1] = RGB[0][1];
    calc[0][2] = RGB[0][2];

    for(int i = 1; i < N; i++)
        for(int curC = 0; curC < 3; curC++) 
            for(int preC = 0; preC < 3; preC++)
                if(curC != preC) calc[i][curC] = min(calc[i-1][preC] + RGB[i][curC], calc[i][curC]); 
    // The code could be simpler without using for loop 

    // min_element function can simplify the code below:
    // cout << *min_element(calc[N-1], calc[N-1] + 3);
    int MN = 0x7f7f7f7f;
    for(int col = 0; col < 3; col++) MN = min(MN, calc[N-1][col]);
    cout << MN;
} 