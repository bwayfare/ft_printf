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
	char  *ch = "nu eto finalnaya proverochka\0";
	printf("Длина 01 строки = %ld\n\n", ft_printf("!01__%15.40s___!\n", ch));
	printf("Длина 02 строки = %d\n\n", printf("!02__%15.40s___!\n", ch));
	ft_printf("!03__%-20.15s___!\n\n", ch);
	printf("!04__%-20.15s___!\n\n", ch);
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
	printf("Длина 21 строки = %ld\n\n", ft_printf("%s%s\n", "Hello,\0", " world!\0"));
	printf("Длина 22 строки = %d\n\n", printf("%s%s\n", "Hello,\0", " world!\0"));

	printf("%ld\n" ,ft_printf("\n%%-*c\n"));
	printf("%d\n" ,printf("\n%%-*c\n"));
	char k = 'H';
	ft_printf("%c", k);
	ft_printf("135416531\n\n");

	printf("%ld\n", ft_printf("01 = %d\n", 153));
	printf("%d\n\n", printf("02 = %d\n", 153));
	printf("%ld\n", ft_printf("03 = %+d\n", -153));
	printf("%d\n\n", printf("04 = %+d\n", -153));
	printf("%ld\n", ft_printf("05 = %+d\n", 153));
	printf("%d\n\n", printf("06 = %+d\n", 153));

	printf("%ld\n", ft_printf("07 = %060d\n", 153));
	printf("%d\n\n", printf("08 = %060d\n", 153));
	printf("%ld\n", ft_printf("09 = %+060d\n", -153));
	printf("%d\n\n", printf("10 = %+060d\n", -153));
	printf("%ld\n", ft_printf("11 = %+60.70d\n", -153));
	printf("%d\n\n", printf("12 = %+60.70d\n", -153));
	printf("%ld\n", ft_printf("13 = %60d\n", -153));
	printf("%d\n\n", printf("14 = %60d\n", -153));

	printf("%ld\n", ft_printf("15 = %-60d\n", 153));
	printf("%d\n\n", printf("16 = %-60d\n", 153));
	printf("%ld\n", ft_printf("17 = %+-60d\n", 153));
	printf("%d\n\n", printf("18 = %+-60d\n", 153));
	printf("%ld\n", ft_printf("19 = %-60d\n", -153));
	printf("%d\n\n", printf("20 = %-60d\n", -153));
	printf("%ld\n", ft_printf("21 = %+-60d\n", -153));
	printf("%d\n\n", printf("22 = %+-60d\n", -153));

	printf("%ld\n", ft_printf("23 = %+-60d\n", 2147483647));
	printf("%d\n\n", printf("24 = %+-60d\n", 2147483647));
	printf("%ld\n", ft_printf("25 = %+-60d\n", -2147483647));
	printf("%d\n\n", printf("26 = %+-60d\n", -2147483647));
	printf("%ld\n", ft_printf("27 = %+-60d\n", 0));
	printf("%d\n\n", printf("28 = %+-60d\n", 0));
	printf("%ld\n", ft_printf("29 = %+060d\n", 0));
	printf("%d\n\n", printf("30 = %+060d\n", 0));

	long int i = 0;
	int j = 0;
	int hui = 2147483647;
	int dvahuya = -2147483648;
	i = ft_printf("!___01 MY + = %.d___!\n   !___MY - = %.d___!\n", hui, dvahuya);
	j = printf("!___02 NO + = %.d___!\n   !___MY - = %.d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___03 MY + = %3.3d___!\n   !___MY - = %3.3d___!\n", hui, dvahuya);
	j = printf("!___04 NO + = %3.3d___!\n   !___NO - = %3.3d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___05 MY + = %-30.25d___!\n   !___MY - = %-30.25d___!\n", hui, dvahuya);
	j = printf("!___06 NO + = %-30.25d___!\n   !___NO - = %-30.25d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___07 MY + = %30.20d___!\n   !___MY - = %30.20d___!\n", hui, dvahuya);
	j = printf("!___08 NO + = %30.20d___!\n   !___NO - = %30.20d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___07a MY + = %30.30d___!\n   !___MY - = %30.30d___!\n", hui, dvahuya);
	j = printf("!___08b NO + = %30.30d___!\n   !___NO - = %30.30d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___09 MY + = %30.3d___!\n   !___MY - = %30.3d___!\n", hui, dvahuya);
	j = printf("!___10 NO + = %30.3d___!\n   !___NO - = %30.3d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___11 MY + = %3.30d___!\n   !___MY - = %3.30d___!\n", hui, dvahuya);
	j = printf("!___12 NO + = %3.30d___!\n   !___NO - = %3.30d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___13 MY + = %.30d___!\n   !___MY - = %.30d___!\n", hui, dvahuya);
	j = printf("!___14 NO + = %.30d___!\n   !___NO - = %.30d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___15 MY + = %0.0d___!\n   !___MY - = %0.0d___!\n", hui, dvahuya);
	j = printf("!___16 NO + = %0.0d___!\n   !___NO - = %0.0d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___19 MY + = %.d___!\n   !___MY - = %.d___!\n", hui, dvahuya);
	j = printf("!___20 NO + = %.d___!\n   !___NO - = %.d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___21 MY + = %d___!\n   !___MY - = %d___!\n", hui, dvahuya);
	j = printf("!___22 NO + = %d___!\n   !___NO - = %d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	hui = 0;
	dvahuya = 0;
	i = ft_printf("!___21 MY + = %.0d___!\n   !___MY - = %.0d___!\n", hui, dvahuya);
	j = printf("!___22 NO + = %.0d___!\n   !___NO - = %.0d___!\n", hui, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___21 MY + = %*d___!\n   !___MY - = %*d___!\n", -25, hui, -25, dvahuya);
	j = printf("!___22 NO + = %*d___!\n   !___NO - = %*d___!\n", -25, hui, -25, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);
	i = ft_printf("!___25 MY + = %*.*d___!\n   !___MY - = %*.*d___!\n", -25, -15, hui, -25, -15, dvahuya);
	j = printf("!___26 NO + = %*.*d___!\n   !___NO - = %*.*d___!\n", -25, -15, hui, -25, -15, dvahuya);
	printf("					мой = %ld, системный = %d\n\n", i, j);

	return 0;
}
