#include <stdio.h>
int src[2048][2048];
int dst[2048][2048];
int main(int argc, char* argv[])
{
	int rep;
	int i, j;
	for ( rep = 0; rep < 10; rep++ )
	{
		for ( i = 0; i < 2048; i++ )
		{
			for ( j = 0; j < 2048; j++ )
			{
				dst[j][i] = src[j][i];
			}
		}
	}
	return 0;
}