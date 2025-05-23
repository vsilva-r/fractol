#include <stdio.h>
#include "libft/libft.h"
#include "libftprintf.h"

/* Flags in order */

/*	
	#	means 	adds 0 for octal and 0x(0X) for hexadecimal.
	-	means	align to the left rather than the right; overrides 0.
	Field width	is given by a int (base-10) number before the specifier
	0 	means 	zero-padding (to fit field width).
	[space] means 	adds space before positive number or empty string.
	+	means	adds + before positive number; overrides [space]
	. 	means 	(Precision) minimum number of digits to print, or max number 
			of chars for strings; overrides 0
	NOTA A ORDEM QUE ELE PRINTA AS FLAGS QUANDO NAO TEM SPECIFIER
	#+-F.P
	# -F.P
	# 0F.P
*/


int main()
{
	/*
	char	*str = "idkman";
	printf(" %d \n", (ft_printf("FT: Quantas %s tem %d avioes? %X %x %% %p %u %o %c\n", "cordas", -13, -13, -13, str, -13, -13, 42)));
	printf(" %d \n", (printf("OG: Quantas %s tem %d avioes? %X %x %% %p %u %o %c\n", "cordas", -13, -13, -13, (void *)-13, -13, -13, 42)));
	*/
	printf("%ld, %ld\n", INT_MIN, (int)(unsigned)(INT_MIN));
	printf("%ld, %ld\n\n", LONG_MIN, (long)(unsigned long)(LONG_MIN));
	
	printf("%ld, %ld\n", (-1), (long)(unsigned)(-1));
	printf("%ld, %ld\n", (-14), (long)(unsigned long)(-1));
}
/*
	int -1 		as long
	unsigned -1 	as long

	int intmin	as long
	unsigned intmin	as long
	longmin		as long
	unsign longmin	as long
*/
/*
	ft_printf("FT %p\t\t%p \n", LONG_MIN, LONG_MAX);
	printf("OG %p\t\t%p \n", LONG_MIN, LONG_MAX);
	ft_printf("FT %p\t\t%p \n", INT_MIN, INT_MAX);
	printf("OG %p\t\t%p \n", INT_MIN, INT_MAX);
	ft_printf("FT %p\t\t%p \n", ULONG_MAX, -ULONG_MAX);
	printf("OG %p\t\t%p \n", ULONG_MAX, -ULONG_MAX);
	
}*/
