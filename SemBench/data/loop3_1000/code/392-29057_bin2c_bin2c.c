#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef WIN32
#define inline __inline
#pragma warning(disable:4996)
#endif
#define USER_NAME       "Ringsd"
static void help(void)
{
	puts("Using:");
	puts("	-i input file name");
	puts("	-o output file name");
	puts("	-s Var name, default is image_buffer");
	puts("	-r echo row has how many data, default is 16");
	puts("	Copyright (C) 2014-2016 " USER_NAME);
}
#define MAX_BUFFER_SIZE		1024
int bin2c(char* in_path, char* out_path, int length, char* var_name)
{
	int		ret = 0;
	unsigned char	buffer[MAX_BUFFER_SIZE];
	FILE	*fin = NULL;
	FILE	*fout = NULL;
	int		program_code_on = 0;
	int		start = 1;
	int		read_byte = 0;
	int		image_buffer_size = 0;
	fin = fopen(in_path, "rb");
	if( fin == NULL )
	{
		ret = -1;
		goto err1;
	}
	fout = fopen(out_path, "wb");
	if( fout == NULL )
	{
		ret = -2;
		goto err2;
	}
	fseek(fin, 0, SEEK_END);
	image_buffer_size = ftell(fin);
	fseek(fin, 0, SEEK_SET);
	while (read_byte = fread(buffer, 1, MAX_BUFFER_SIZE, fin))
	{
		if (start)
		{
			time_t rawtime;
			struct tm * timeinfo;
			time ( &rawtime );
			timeinfo = localtime ( &rawtime );
			fprintf( fout, "\n\n" );
			fprintf(fout, "static int %s_size = %d;\n", var_name, image_buffer_size);
			fprintf(fout, "static unsigned char %s[] = {\n", var_name);
			start = 0;
		}
		if (read_byte)
		{
			int i = 0;
			for (i = 0; i < read_byte; i++)
			{
				fprintf(fout, "0x%02x, ", buffer[i]);
				if (((i + 1) % length) == 0)
				{
					fprintf(fout, "\n");
				}
			}
		}
	}
	fprintf(fout, "\n");
	fprintf(fout, "};\n");
	fprintf(fout, "\n");
	fprintf(fout, "\n");
	fprintf(fout, "\n");
	fclose( fout );
err2:	
	fclose(fin);
err1:
	return ret;
}
int main(int argc, const char* argv[])
{
	int 	ret = 0;
	char** 	pp = NULL;
	char	in_path[512] = "xxx.bin";
	char	out_path[512] = "xxx.c";
	char	var_name[512] = "image_buffer";
	int		length = 16;
	if( argc == 1 )
	{
		help();
		return 0;
	}
#ifdef WIN32
	pp = (char**)(argv + 1);
	if (*pp[0] != '-')
	{
		strcpy(in_path, *pp);
		strcpy(out_path, in_path);
		strcat(out_path, ".c");
	}
#endif
	for (pp = (char**)(argv + 1); *pp; pp++)
	{
		if (strcmp(*pp, "-o") == 0)
        {
            pp ++;
            if( *pp ) strcpy(out_path, *pp);
            else break;
        }
		else if (strcmp(*pp, "-i") == 0)
        {
            pp ++;
            if( *pp ) strcpy(in_path, *pp);
            else break;
        }
		else if (strcmp(*pp, "-s") == 0)
		{
			pp++;
			if (*pp) strcpy(var_name, *pp);
			else break;
		}
		else if (strcmp(*pp, "-r") == 0)
		{
			pp++;
			if (*pp) length = atoi(*pp);
			else break;
		}
		else if (strcmp(*pp, "-v") == 0)
		{
			help();
			return 0;
		}
	}
	if (length <= 0)
	{
		length = 16;
	}
	bin2c(in_path, out_path, length, var_name);
	return ret;
}