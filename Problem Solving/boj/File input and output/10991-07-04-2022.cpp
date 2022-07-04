#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        int noStar = i;
        int noSpaces = (n - i);
        for (int j = 1; j <= noSpaces; ++j) {
            printf(" ");
        }
        for (int j = 1;j <= 2*noStar - 1;++j) {
            if (j % 2 == 1) printf("*");
            else printf(" ");
        }
        puts("");
    }
}