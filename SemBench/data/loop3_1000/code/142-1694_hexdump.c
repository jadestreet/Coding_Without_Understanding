#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
void print_cp437(unsigned char *buf, size_t len)
{
	size_t i;
	wchar_t codepage[] =
	    L" ☺☻♥♦♣♠•◘○◙♂♀♪♫☼►◄↕‼¶§▬↨↑↓→←∟↔▲▼"
	    " !\"#$%&'()*+,-./0123456789:;<=>"
	    "?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]"
	    "^_`abcdefghijklmnopqrstuvwxyz{|}"
	    "~⌂ÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜ¢£¥"
	    "₧ƒáíóúñÑªº¿⌐¬½¼¡«»░▒▓│┤╡╢╖╕╣║╗╝╜"
	    "╛┐└┴┬├─┼╞╟╚╔╩╦╠═╬╧╨╤╥╙╘╒╓╫╪┘┌█▄▌"
	    "▐▀αßΓπΣσµτΦΘΩδ∞φε∩≡±≥≤⌠⌡÷≈°∙·√ⁿ²■ ";
	for (i = 0; i < 16; i++)
		if (i < len)
			putwchar(codepage[buf[i]]);
	putwchar('\n');
}
void print_hex(unsigned char *buf, size_t len)
{
	size_t i;
	for (i = 0; i < 16; i++) {
		if (i < len)
			wprintf(L"%02X", buf[i]);
		else
			wprintf(L"  ");
		if (i % 2)
			putwchar(' ');
	}
	putwchar(' ');
}
int main(int argc, char *argv[])
{
	size_t len;
	unsigned char buf[16];
	unsigned int addr = 0;
	FILE *fp = NULL;
	if (!setlocale(LC_CTYPE, "")) {
		fprintf(stderr, "Can't set the specified locale! "
				"Check LANG, LC_CTYPE, LC_ALL.\n");
		return EXIT_FAILURE;
	}
	if (argc > 1)
		fp = fopen(argv[1], "r");
	if (fp == NULL)
		fp = stdin;
	while ((len = fread(buf, 1, 16, fp)) > 0) {
		wprintf(L"%08X: ", addr);
		print_hex(buf, len);
		print_cp437(buf, len);
		if (len < 16)
			wprintf(L"%08X:\n", addr + (unsigned int)len);
		addr += 16;
	}
	fclose(fp);
}