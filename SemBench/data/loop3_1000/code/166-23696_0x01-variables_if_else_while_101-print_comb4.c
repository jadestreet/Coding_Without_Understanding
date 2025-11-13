#include <stdio.h>
int main(void)
{
	int a;
	int b;
	int c;
	for (a = 0 ; a <= 8; a++)
	{
		for (b = 1 ; b <= 9; b++)
		{
			for (c = 2 ; c <= 9; c++)
			{
				if (a < b)
				{
					if (b < c)
					{
						putchar('0' + a);
						putchar('0' + b);
						putchar('0' + c);
						if (a != 7 || b != 8 || c != 9)
						{
							putchar(',');
							putchar(' ');
						}
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}