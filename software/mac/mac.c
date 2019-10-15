#include "system.h"
#include <stdio.h>

int main() {
	int a = -2;
	int b =  3;
	int rlo, rhi;
	int i;
	long long r;

	// test
	rlo = __builtin_custom_inii (15, a, b); // ALT_CI_MACCI_0(0, a, b);
    printf("Expect 0x0ECE4530: %8x\n", rlo);
	rlo = __builtin_custom_inii (14, a, b); // ALT_CI_MACCI_0(0, a, b);
    printf("Expect 0xDEADBEEF: %8x\n", rlo);

	// initialize: MAC = A * B
	rlo = __builtin_custom_inii (1, a, b); // ALT_CI_MACCI_0(0, a, b);
    
    for (i=0; i<20; i++) {
    	// read result
	    rlo = __builtin_custom_inii (3, a, b); // ALT_CI_MACCI_0(2, a, b);
    	rhi = __builtin_custom_inii (4, a, b); // ALT_CI_MACCI_0(3, a, b);
    	printf("%6d HI %6x LO %6x -> ", i, rhi, rlo);
    	*((int *) &r)     = rlo;
    	*((int *) &r + 1) = rhi;
    	printf("%lld\n", r);

    	// MAC: MAC = MAC + A * B
	    rlo = __builtin_custom_inii (2, a, b); // ALT_CI_MACCI_0(1, a, b);
	}


	return 0;
}