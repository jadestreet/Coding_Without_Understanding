#include <stdio.h>
#include <string.h>
#include <ctype.h>
enum {
	FALSE,
	TRUE
};
#define CHARS_LWSP " \t\n\r"               
#define CHARS_TSPECIAL "()<>@,;:\\\"/[]?="
#define CHARS_SPECIAL "()<>@,;:\\\".[]"
#define CHARS_CSPECIAL "()\\\r"	           
#define CHARS_DSPECIAL "[]\\\r \t"	   
#define CHARS_ESPECIAL "()<>@,;:\"/[]?.=_" 
#define CHARS_PSPECIAL "!*+-/=_"           
#define CHARS_ATTRCHAR "*'% "              
static unsigned short gmime_special_table[256];
enum {
	IS_CTRL		= (1 << 0),
	IS_LWSP		= (1 << 1),
	IS_TSPECIAL	= (1 << 2),
	IS_SPECIAL	= (1 << 3),
	IS_SPACE	= (1 << 4),
	IS_DSPECIAL	= (1 << 5),
	IS_QPSAFE	= (1 << 6),
	IS_ESAFE	= (1 << 7),  
	IS_PSAFE	= (1 << 8),  
	IS_ATTRCHAR     = (1 << 9),  
	IS_ASCII        = (1 << 10), 
	IS_BLANK        = (1 << 11), 
};
#define is_ctrl(x) ((gmime_special_table[(unsigned char)(x)] & IS_CTRL) != 0)
#define is_lwsp(x) ((gmime_special_table[(unsigned char)(x)] & IS_LWSP) != 0)
#define is_tspecial(x) ((gmime_special_table[(unsigned char)(x)] & IS_TSPECIAL) != 0)
#define is_type(x, t) ((gmime_special_table[(unsigned char)(x)] & (t)) != 0)
#define is_ttoken(x) ((gmime_special_table[(unsigned char)(x)] & (IS_TSPECIAL|IS_LWSP|IS_CTRL)) == 0)
#define is_atom(x) ((gmime_special_table[(unsigned char)(x)] & (IS_SPECIAL|IS_SPACE|IS_CTRL)) == 0)
#define is_dtext(x) ((gmime_special_table[(unsigned char)(x)] & IS_DSPECIAL) == 0)
#define is_fieldname(x) ((gmime_special_table[(unsigned char)(x)] & (IS_CTRL|IS_SPACE)) == 0)
#define is_qpsafe(x) ((gmime_special_table[(unsigned char)(x)] & IS_QPSAFE) != 0)
#define is_especial(x) ((gmime_special_table[(unsigned char)(x)] & IS_ESAFE) != 0)
#define is_psafe(x) ((gmime_special_table[(unsigned char)(x)] & IS_PSAFE) != 0)
#define is_attrchar(x) ((gmime_special_table[(unsigned char)(x)] & IS_ATTRCHAR) != 0)
#define is_ascii(x) ((gmime_special_table[(unsigned char)(x)] & IS_ASCII) != 0)
#define is_blank(x) ((gmime_special_table[(unsigned char)(x)] & IS_BLANK) != 0)
static void
header_remove_bits (unsigned short bit, char *vals)
{
	register unsigned char *inptr = (unsigned char *) vals;
	while (*inptr != '\0')
		gmime_special_table[*inptr++] &= ~bit;
}
static void
header_init_bits (unsigned short bit, unsigned short bitcopy, int remove, char *vals)
{
	register unsigned char *inptr = (unsigned char *) vals;
	int i;
	if (!remove) {
		while (*inptr != '\0')
			gmime_special_table[*inptr++] |= bit;
		if (bitcopy) {
			for (i = 0; i < 256; i++) {
				if (gmime_special_table[i] & bitcopy)
					gmime_special_table[i] |= bit;
			}
		}
	} else {
		for (i = 0; i < 256; i++)
			gmime_special_table[i] |= bit;
		while (*inptr != '\0')
			gmime_special_table[*inptr++] &= ~bit;
		if (bitcopy) {
			for (i = 0; i < 256; i++) {
				if (gmime_special_table[i] & bitcopy)
					gmime_special_table[i] &= ~bit;
			}
		}
	}
}
static void
header_decode_init (void)
{
	int i;
	for (i = 0; i < 256; i++) {
		gmime_special_table[i] = 0;
		if (i < 32 || i == 127)
			gmime_special_table[i] |= IS_CTRL;
		if (i > 32 && i < 127)
			gmime_special_table[i] |= IS_ATTRCHAR;
		if ((i >= 33 && i <= 60) || (i >= 62 && i <= 126) || i == 32)
			gmime_special_table[i] |= (IS_QPSAFE | IS_ESAFE);
		if ((i >= '0' && i <= '9') || (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
			gmime_special_table[i] |= IS_PSAFE;
		if (isascii (i))
			gmime_special_table[i] |= IS_ASCII;
	}
	gmime_special_table[' '] |= IS_SPACE | IS_BLANK;
	gmime_special_table['\t'] |= IS_QPSAFE | IS_BLANK;
	header_init_bits (IS_LWSP, 0, FALSE, CHARS_LWSP);
	header_init_bits (IS_TSPECIAL, IS_CTRL, FALSE, CHARS_TSPECIAL);
	header_init_bits (IS_SPECIAL, 0, FALSE, CHARS_SPECIAL);
	header_init_bits (IS_DSPECIAL, 0, FALSE, CHARS_DSPECIAL);
	header_remove_bits (IS_ESAFE, CHARS_ESPECIAL);
	header_remove_bits (IS_ATTRCHAR, CHARS_TSPECIAL CHARS_ATTRCHAR);
	header_init_bits (IS_PSAFE, 0, FALSE, CHARS_PSPECIAL);
}
int main (int argc, char **argv)
{
	int i;
	header_decode_init ();
	printf ("\n\n");
	printf ("\n\n");
	printf ("static unsigned short gmime_special_table[256] = {");
	for (i = 0; i < 256; i++) {
		printf ("%s%4d%s", (i % 16) ? "" : "\n\t",
			gmime_special_table[i], i != 255 ? "," : "\n");
	}
	printf ("};\n\n");
	printf ("enum {\n");
	printf ("\tIS_CTRL     = (1 << 0),\n");
	printf ("\tIS_LWSP     = (1 << 1),\n");
	printf ("\tIS_TSPECIAL = (1 << 2),\n");
	printf ("\tIS_SPECIAL  = (1 << 3),\n");
	printf ("\tIS_SPACE    = (1 << 4),\n");
	printf ("\tIS_DSPECIAL = (1 << 5),\n");
	printf ("\tIS_QPSAFE   = (1 << 6),\n");
	printf ("\tIS_ESAFE    = (1 << 7),  \n");
	printf ("\tIS_PSAFE    = (1 << 8),  \n");
	printf ("\tIS_ATTRCHAR = (1 << 9),  \n");
	printf ("\t\n");
	printf ("\t\n");
	printf ("\tIS_ASCII    = (1 << 10), \n");
	printf ("\tIS_BLANK    = (1 << 11), \n");
	printf ("};\n\n");
	printf ("#define is_ctrl(x) ((gmime_special_table[(unsigned char)(x)] & IS_CTRL) != 0)\n");
	printf ("#define is_lwsp(x) ((gmime_special_table[(unsigned char)(x)] & IS_LWSP) != 0)\n");
	printf ("#define is_tspecial(x) ((gmime_special_table[(unsigned char)(x)] & IS_TSPECIAL) != 0)\n");
	printf ("#define is_type(x, t) ((gmime_special_table[(unsigned char)(x)] & (t)) != 0)\n");
	printf ("#define is_ttoken(x) ((gmime_special_table[(unsigned char)(x)] & (IS_TSPECIAL|IS_LWSP|IS_CTRL)) == 0)\n");
	printf ("#define is_atom(x) ((gmime_special_table[(unsigned char)(x)] & (IS_SPECIAL|IS_SPACE|IS_CTRL)) == 0)\n");
	printf ("#define is_dtext(x) ((gmime_special_table[(unsigned char)(x)] & IS_DSPECIAL) == 0)\n");
	printf ("#define is_fieldname(x) ((gmime_special_table[(unsigned char)(x)] & (IS_CTRL|IS_SPACE)) == 0)\n");
	printf ("#define is_qpsafe(x) ((gmime_special_table[(unsigned char)(x)] & IS_QPSAFE) != 0)\n");
	printf ("#define is_especial(x) ((gmime_special_table[(unsigned char)(x)] & IS_ESAFE) != 0)\n");
	printf ("#define is_psafe(x) ((gmime_special_table[(unsigned char)(x)] & IS_PSAFE) != 0)\n");
	printf ("#define is_attrchar(x) ((gmime_special_table[(unsigned char)(x)] & IS_ATTRCHAR) != 0)\n");
	printf ("\n");
	printf ("\n");
	printf ("#define is_ascii(x) ((gmime_special_table[(unsigned char)(x)] & IS_ASCII) != 0)\n");
	printf ("#define is_blank(x) ((gmime_special_table[(unsigned char)(x)] & IS_BLANK) != 0)\n");
	printf ("\n");
	printf ("#define CHARS_LWSP \" \\t\\n\\r\"               \n");
	printf ("#define CHARS_TSPECIAL \"()<>@,;:\\\\\\\"/[]?=\"\n");
	printf ("#define CHARS_SPECIAL \"()<>@,;:\\\\\\\".[]\"\n");
	printf ("#define CHARS_CSPECIAL \"()\\\\\\r\"	           \n");
	printf ("#define CHARS_DSPECIAL \"[]\\\\\\r \\t\"         \n");
	printf ("#define CHARS_ESPECIAL \"()<>@,;:\\\"/[]?.=_\" \n");
	printf ("#define CHARS_PSPECIAL \"!*+-/=_\"           \n");
	printf ("#define CHARS_ATTRCHAR \"*'%% \"              \n");
	printf ("\n");
	printf ("#define GMIME_FOLD_LEN 76\n");
	return 0;
}