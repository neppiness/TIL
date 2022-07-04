#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int m = 2*n -1;

    for (int i = 1; i <= m; i++) {
        int noStar = 0;
        if (i <= n) noStar = m - 2*(i - 1);
        else noStar = 1 + 2*(i - n);

        int noSpace = 0;
        if (i <= n) noSpace = i - 1;
        else noSpace = 2*n - i - 1;

        for (int j = 1; j <= noSpace; j++) {
            printf(" ");
        }
        for (int j = 1; j <= noStar; j++) {
            printf("*");
        }
        puts("");
    }
}