#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("\n\n%ld\n\n",
		ft_printf("%760.+0153dHello, %-+015.16dWorld!\n", -720, 15));
	printf("%d%d\n\n", 1, 2);
	printf("%-13.02s", "Hello");
	return 0;
}
