#include <iostream>

using namespace std;

int N, M;
int perm[10];

int caseCalc(int n, int m) {
    if(n == 0) return 1;
    return (m + 1) * caseCalc(n - 1, m);
}

void sthToSolve() {
    // Something to solve with generated permutations
    return;
}

void permu(int n){
    if(n == N) {sthToSolve();}
    for(int i = 0; i <= M; i++) {perm[n] = i; permu(n+1);}
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N >> M;
    int moves[N];

    int CASES = caseCalc(N, M);
    cout << CASES;

    // permutation using 0 to M
    // Need to use base M so that the numbers are less than (M + 1)^(N)
    for(int cases = 1; cases < CASES; cases++) {
        int temp = cases, idx = 0;
        do {moves[idx++] = temp % M;} while(temp /= M);

        sthToSolve(); // Some problems to solve with a generated case
    }

    permu(0);
}