#include <stdio.h>

int main(void) {
    char str[101];
    while(fgets(str, 101, stdin)) printf("%s", str);
    return 0;
}

/*
- written by kimhunsu96

int main(){
    char a[100];
    while(scanf("%[^\n]\n", a)!=EOF) printf("%s\n", a);
}
*/