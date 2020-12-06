#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("\n\n%ld\n\n",
		ft_printf("%-+0*.*dHello, %-+015.16dWorld!\n", 60, 701,2147483648 ,15));
	return 0;
}
