// #include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
string str[52];

bool cmp(string a, string b) {
    int la = a.length(), lb = b.length();
    if(la < lb) return true;
    else if(la > lb) return false;

    int suma = 0, sumb = 0;
    for(auto charA : a) {if(charA >= '0' && charA <= '9') suma += charA - '0';}
    for(auto charB : b) {if(charB >= '0' && charB <= '9') sumb += charB - '0';}

    if (suma < sumb) return true;
    else if(suma > sumb) return false;

    for(int i = 0; i < la; i++) {
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    for(int i = 0; i < N; i++) cin >> str[i];

    sort(str, str + N, cmp);
    for(int i = 0; i < N; i++) cout << str[i] << '\n';
}