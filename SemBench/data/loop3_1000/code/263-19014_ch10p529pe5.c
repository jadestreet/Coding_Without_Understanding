#include <stdio.h>
#define ROWS 5
#define COLS 4
int main()
{
	float vals[ROWS][COLS] ={{90.3,	92.7,	90.3,	99.8}, {85.3,	90.5,	87.3,	90.8},{93.2,	88.4,	93.8,	75.6}, {82.4,	95.6,	78.2,	90.0}, {93.5,	80.2,	92.9,	94.4}};
	printf("\nGrades\n");
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			printf("%7.1f", vals[i][j]);
		}
		printf("\n");
	}
	printf("\nFile written to is grades.bin a binary file.\n");
	FILE *wrkFile;
	wrkFile = fopen("grades.bin", "wb");
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLS; ++j)
		{
			fprintf(wrkFile, "%7.1f", vals[i][j]);
		}
		fprintf(wrkFile, "\n");
	}
	fclose(wrkFile);
	return 0;
}