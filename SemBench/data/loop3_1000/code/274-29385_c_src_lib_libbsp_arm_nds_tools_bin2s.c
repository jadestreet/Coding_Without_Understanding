#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void strnident(FILE *fout, const char *src) {
	char got_first = 0;
	while(*src != 0) {
		int s = *src++;
		if(isdigit(s) && !got_first)
		fputc('_', fout);  
		if(!isalpha(s) && !isdigit(s) && (s != '_')) {
			if(s == '-' || s == '.' || s == '/') s = '_';
		else
			s = 0;
		}
		if(s) {
			fputc(s, fout);
			got_first = 1;
		}
	}
}
int main(int argc, char **argv) {
	FILE *fin;
	size_t filelen;
	int linelen;
	int arg;
	int alignment = 4;
	if(argc < 2) {
		fputs(	"bin2s - convert binary files to assembly language\n"
						"typical usage: bin2s foo.bin bar.bin baz.bin > foo.s\n", stderr);
		return 1;
	}
  for(arg = 1; arg < argc; arg++) {
		if (argv[arg][0] == '-')
		{
			switch (argv[arg][1])
			{
				case 'a':
					alignment = (argc > arg) ? strtoul(argv[++arg], 0, 0) : 0;
					if ( alignment == 0 ) alignment =4;
					break;
			}
			continue;
		}
  	fin = fopen(argv[arg], "rb");
  	if(!fin) {
  		fputs("bin2s: could not open ", stderr);
  		perror(argv[arg]);
  		return 1;
  	}
		fseek(fin, 0, SEEK_END);
		filelen = ftell(fin);
		rewind(fin);
		if(filelen == 0) {
			fclose(fin);
			fprintf(stderr, "bin2s: warning: skipping empty file %s\n", argv[arg]);
			continue;
		}
		char *ptr = argv[arg];
		char chr;
		char *filename = NULL;
		while ( (chr=*ptr) ) {
			if ( chr == '\\' || chr == '/') {
				filename = ptr;
			}
			ptr++;
		}
		if ( NULL != filename ) {
			filename++;
		} else {
			filename = argv[arg];
		}
		fprintf(	stdout, "\n"
						"\t.section .rodata\n"
						"\t.balign %d\n"
						"\t.global ", alignment);
		strnident(stdout, filename);
		fputs("_size\n", stdout);
		strnident(stdout, filename);
		printf("_size: .int %lu\n\t.global ", (unsigned long)filelen);
		strnident(stdout, filename);
		fputs("\n", stdout);
		strnident(stdout, filename);
		fputs(":\n\t.byte ", stdout);
		linelen = 0;
		while(filelen > 0) {
			unsigned char c = fgetc(fin);
			printf("%3u", (unsigned int)c);
			filelen--;
			if(filelen) {
				if(++linelen >= 16) {
					linelen = 0;
					fputs("\n\t.byte ", stdout);
				} else {
					fputc(',', stdout);
				}
			}
		}
		fputs("\n\n\t.global ", stdout);
		strnident(stdout, filename);
		fputs("_end\n", stdout);
		strnident(stdout, filename);
		fputs("_end:\n\n", stdout);
		fclose(fin);
	}
	return 0;
}