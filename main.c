#include <stdio.h>
#include "ft_printf.h"

int main()
{
	/*printf("\n\n%ld\n\n",
		ft_printf("%-60.3s %5.*s Hello, %-+015.16dWorld!\n", "aaaa\0",-16, "bbbb\0", 15));
	printf("%d%d\n\n", 1, 2);
	printf("%-13.20s", "Hello\n\n\n");*/
	char  *u = "proverochka";
//  int j = -1;
//    printf("\n%d %d\n", i, j);
	char  *i = "nu eto finalnaya proverochka\0";
	printf("Длина 01 строки = %ld\n\n", ft_printf("!01__%15.40s___!\n", i));
	printf("Длина 02 строки = %d\n\n", printf("!02__%15.40s___!\n", i));
	ft_printf("!03__%-20.15s___!\n\n", i);
	printf("!04__%-20.15s___!\n\n", i);
	ft_printf("!05__%s___!\n\n", u);
	printf("!06__%s___!\n\n", u);
	ft_printf("!07__%10.2s___!\n\n", u);
	printf("!08__%10.2s___!\n\n", u);
	ft_printf("!09__%.s___!\n\n", u);
	printf("!10__%.s___!\n\n", u);
	ft_printf("!11__%-6.*s___!\n\n", -16, u);
	printf("!12__%-6.*s___!\n\n", -16, u);
	printf("Длина 13 строки = %ld\n\n", ft_printf("!13__%30.s___!\n", u));
	printf("Длина 14 строки = %d\n\n", printf("!14__%30.s___!\n", u));
	printf("Длина 15 строки = %ld\n\n", ft_printf("!15__%-6.*s___!\n", -1, u));
	printf("Длина 16 строки = %d\n\n", printf("!16__%-6.*s___!\n", -1, u));
	printf("Длина 17 строки = %ld\n\n", ft_printf("!17__%.6s___!\n", u));
	printf("Длина 18 строки = %d\n\n", printf("!18__%.6s___!\n", u));
	ft_printf("!19__%.*s___!\n\n", -12, u);
	printf("!20__%.*s___!\n\n", -12, u);
	return 0;
}
