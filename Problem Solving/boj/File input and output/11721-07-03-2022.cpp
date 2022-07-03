#include <stdio.h>

int main() {
	char str[100];
	scanf("%s", &str);

	int index = -1;
	while (str[++index]) {
		printf("%c", str[index]);
		if (index % 10 == 9) puts("");
	}
	return 0;
}