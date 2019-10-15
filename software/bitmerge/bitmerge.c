#include "system.h"
#include <stdio.h>

int main() {
	int a = 0xAAAAAAAA;
	int b = 0x55555555;
	int r;	

	r = ALT_CI_BITMERGECI_0(a, b);
	printf("%x %x %x\n", a, b, r);

	return 0;
}