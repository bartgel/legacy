#include <stdio.h>

void print(char val, int uppercase) {
	printf("%c",uppercase > 1 ? val + 'A' - 'a': val);
}
