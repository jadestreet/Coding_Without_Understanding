#include <stdio.h>
int main(void)
{
	int a;
	int b;
	int c;
	int d;
	int temp;
	for (a = 0; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = a; c <= 9; c++)
			{
				if (c == a)
				{
					temp = b + 1;
				}
				else
				{
					temp = 0;
				}
				for (d = temp; d <= 9; d++)
				{
					putchar('0' + a);
					putchar('0' + b);
					putchar(' ');
					putchar('0' + c);
					putchar('0' + d);
					if (!(a == 9 && b == 8 && c == 9 && d == 9))
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}
	putchar('\n');
	return (0);
}