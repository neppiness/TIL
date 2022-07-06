# include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int no[10] = {0};

    int a = 0;
    int mlt = 1;

    for (int i = 0; i < 3; i++) {
        cin >> a;
        mlt *= a;
    }

    while(mlt != 0){
        no[mlt % 10] += 1;
        mlt /= 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << no[i] << '\n';
    }

}