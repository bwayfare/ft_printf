#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("\n\n%ld\n\n",
		ft_printf("%+-#*.*dHello, %-+015.16dWorld!\n",170, 750, -720, 15));
	printf("%d%d", 1, 2);
	return 0;
}
