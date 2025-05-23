#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main()
{
	ft_printf("LONG_MIN: \t%b\nLONG_MAX: \t%b\n\t-1: \t%b\n\n", (long)LONG_MIN, (int)LONG_MAX, (long)-1);
}
