#include <stdio.h>

int main() {
	int n;
    scanf("%d", &n);
    
    int m = 2*n - 1;

    for (int i = 1; i <= m; ++i) {
        int noStar = 0;

        if(i <= n) noStar = i;
        else noStar = (n - (i%n));

        for (int j = 1; j <= n; ++j) {
            if(j <= n - noStar) printf(" ");
            else printf("*");
        }

        puts("");
    }
    return 0;
}