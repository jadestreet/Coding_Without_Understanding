#include <stdio.h>
#include <stdlib.h>
#include <iconv.h>
enum {
	ISO_UNSUPPORTED          = 0,
	ISO_DASH_UINT_DASH_UINT_LOWER  = (1 << 0),
	ISO_DASH_UINT_DASH_UINT        = (1 << 1),
	ISO_UINT_DASH_UINT             = (1 << 2),
	ISO_UINT_UINT                  = (1 << 3),
	ISO_UNDER_UINT_DASH_UINT       = (1 << 4),
	NO_ISO_UINT_DASH_UINT          = (1 << 5),
	ISO_DASH_UINT_LOWER            = (1 << 3),
	ISO_DASH_UINT                  = (1 << 4),
	ISO_UINT                       = (1 << 5),
	UCS4                           = (1 << 6),
	ISO_DASH_UINT_DASH_STR_LOWER   = (1 << 0),
	ISO_DASH_UINT_DASH_STR         = (1 << 1),
	ISO_UINT_DASH_STR              = (1 << 2),
};
typedef struct {
	char *charset;
	char *format;
	int id;
} CharInfo;
static CharInfo iso8859_tests[] = {
	{ "iso-8859-1",  "iso-%u-%u", ISO_DASH_UINT_DASH_UINT_LOWER },
	{ "ISO-8859-1",  "ISO-%u-%u", ISO_DASH_UINT_DASH_UINT },
	{ "ISO8859-1",   "ISO%u-%u",  ISO_UINT_DASH_UINT },
	{ "ISO88591",    "ISO%u%u",   ISO_UINT_UINT },
	{ "ISO_8859-1",  "ISO_%u-%u", ISO_UNDER_UINT_DASH_UINT },
	{ "8859-1",      "%u-%u",     NO_ISO_UINT_DASH_UINT },
};
static int num_iso8859_tests = sizeof (iso8859_tests) / sizeof (CharInfo);
static CharInfo iso2022_tests[] = {
	{ "iso-2022-jp", "iso-%u-%s", ISO_DASH_UINT_DASH_STR_LOWER },
	{ "ISO-2022-JP", "ISO-%u-%s", ISO_DASH_UINT_DASH_STR },
	{ "ISO2022-JP",  "ISO%u-%s",  ISO_UINT_DASH_STR },
};
static int num_iso2022_tests = sizeof (iso2022_tests) / sizeof (CharInfo);
static CharInfo iso10646_tests[] = {
	{ "iso-10646-1", "iso-%u-%u",  ISO_DASH_UINT_DASH_UINT_LOWER },
	{ "ISO-10646-1", "ISO-%u-%u",  ISO_DASH_UINT_DASH_UINT },
	{ "ISO10646-1",  "ISO%u-%u",   ISO_UINT_DASH_UINT },
	{ "iso-10646",   "iso-%u",     ISO_DASH_UINT_LOWER },
	{ "ISO-10646",   "ISO-%u",     ISO_DASH_UINT },
	{ "ISO10646",    "ISO%u",      ISO_UINT },
	{ "UCS-4BE",     "UCS-4BE",    UCS4 },
};
static int num_iso10646_tests = sizeof (iso10646_tests) / sizeof (CharInfo);
int main (int argc, char **argv)
{
	unsigned int iso8859, iso2022, iso10646;
	CharInfo *info;
	iconv_t cd;
	FILE *fp;
	int i;
	if (!(fp = fopen ("iconv-detect.h", "w")))
		return EXIT_FAILURE;
	fprintf (fp, "\n\n");
	iso8859 = ISO_UNSUPPORTED;
	info = iso8859_tests;
	for (i = 0; i < num_iso8859_tests; i++) {
		cd = iconv_open (info[i].charset, "UTF-8");
		if (cd != (iconv_t) -1) {
			iconv_close (cd);
			fprintf (stderr, "System prefers %s\n", info[i].charset);
			iso8859 = info[i].id;
			break;
		}
	}
	if (iso8859 == ISO_UNSUPPORTED) {
		fprintf (stderr, "System doesn't support any ISO-8859-1 formats\n");
		fprintf (fp, "#define ICONV_ISO_INT_FORMAT \"%s\"\n", info[0].format);
#ifdef CONFIGURE_IN
		return EXIT_FAILURE;
#endif
	} else {
		fprintf (fp, "#define ICONV_ISO_INT_FORMAT \"%s\"\n", info[i].format);
	}
	iso2022 = ISO_UNSUPPORTED;
	info = iso2022_tests;
	for (i = 0; i < num_iso2022_tests; i++) {
		cd = iconv_open (info[i].charset, "UTF-8");
		if (cd != (iconv_t) -1) {
			iconv_close (cd);
			fprintf (stderr, "System prefers %s\n", info[i].charset);
			iso2022 = info[i].id;
			break;
		}
	}
	if (iso2022 == ISO_UNSUPPORTED) {
		fprintf (stderr, "System doesn't support any ISO-2022 formats\n");
		fprintf (fp, "#define ICONV_ISO_STR_FORMAT \"%s\"\n", info[0].format);
#ifdef CONFIGURE_IN
		return EXIT_FAILURE;
#endif
	} else {
		fprintf (fp, "#define ICONV_ISO_STR_FORMAT \"%s\"\n", info[i].format);
	}
	iso10646 = ISO_UNSUPPORTED;
	info = iso10646_tests;
	for (i = 0; i < num_iso10646_tests; i++) {
		cd = iconv_open (info[i].charset, "UTF-8");
		if (cd != (iconv_t) -1) {
			iconv_close (cd);
			fprintf (stderr, "System prefers %s\n", info[i].charset);
			iso10646 = info[i].id;
			break;
		}
	}
	if (iso10646 == ISO_UNSUPPORTED) {
		fprintf (stderr, "System doesn't support any ISO-10646-1 formats\n");
		fprintf (fp, "#define ICONV_10646 \"%s\"\n", info[0].charset);
#ifdef CONFIGURE_IN
		return EXIT_FAILURE;
#endif
	} else {
		fprintf (fp, "#define ICONV_10646 \"%s\"\n", info[i].charset);
	}
	fclose (fp);
	return EXIT_SUCCESS;
}