#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n-1; ++i) {
        int noStar = 2;
        int noSpaces1 = (n - i);
        int noSpaces2 = 2*(i - 1) - 1;

        for (int j = 1; j <= noSpaces1; ++j) {
            printf(" ");
        }
        printf("*");
        for (int j = 1; j <= noSpaces2; ++j) {
            printf(" ");
        }
        if(i != 1) printf("*");
        puts("");
    }
    for (int j = 1; j <= 2*n - 1; ++j) printf("*");
}