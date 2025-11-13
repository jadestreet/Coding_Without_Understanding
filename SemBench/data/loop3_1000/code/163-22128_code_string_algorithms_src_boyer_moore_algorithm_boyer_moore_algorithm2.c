#include <stdio.h>
#include <string.h>
#define NO_OF_CHARS 256
static void 
InitSkip(char const *const pattern, int skip[], size_t alphabetLen, int patternLen)
{
	for (int *skipVal = skip; alphabetLen; --alphabetLen, ++skipVal)
		*skipVal = patternLen;
	char const *patChar = pattern;
	int i = patternLen;
	while (*patChar && i)
		skip[*patChar++] = --i;
}
static const char *
NextSearchBegin(const char *const curSearch, int skip)
{
	return (curSearch + ((skip < 1) ? 1 : skip));
}
const char * 
BoyerMooreSearch(char const * const txt, char const * const pattern)
{
	if (!pattern || !txt)
		return (0);
	const int patternLen = strlen(pattern);
	const int txtLen = strlen(txt);
	if (patternLen > txtLen)
		return (0);
	int skip[NO_OF_CHARS];
	InitSkip(pattern, skip, NO_OF_CHARS, patternLen);
	const char *const patternEnd = pattern + (patternLen - 1);
	const char *const end = txt + (txtLen - patternLen);
	const char *searchBegin = txt;
	while (searchBegin <= end) {
		const char *patternChar = patternEnd;
		const char *searchChar = searchBegin + (patternLen - 1);
		while (searchChar >= searchBegin && *searchChar == *patternChar)
			--searchChar, --patternChar;
		if (searchChar < searchBegin) 
			return (searchBegin);
		searchBegin = NextSearchBegin(searchBegin, skip[*searchChar]);
	}
	return (0); 
}
int 
main()
{
	const char *testText;
	const char *testPattern;
	const char *result;
	int spaces;
	char *matchMarker = "^";
	testText = "A string searching example consisting of this sentence.";
	testPattern = "sting";
	result = BoyerMooreSearch(testText, testPattern);
	puts(testText);
	if (result) {
		spaces = result - testText;
		while (spaces--)
			putc(' ', stdout);
		puts(matchMarker);
	}
	else
		puts("Pattern not found.");
	return (0);
}