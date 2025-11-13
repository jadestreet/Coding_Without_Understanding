#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int strrev(char *s,int start,int last);
void str_words_in_rev(char *input, int len){
	int start = 0, end = 0;
	strrev(input, 0, len-1);
	while(input[end] != '\0'){
	end ++;
	while (input[end] != ' ' && input[end] != '\0') {
		end++;
	}
	strrev(input, start, end - 1);
	start = end + 1;
}
}
int strrev(char *s,int start,int last){
	char temp;
	while (start < last) {
		temp = s[start];
		s[start++] = s[last];
		s[last--] = temp;
	}
}
 int main(int argc, char const *argv[]) {
	char s[] = "I like coding";
	int len = strlen(s);
	printf("\n%s-->",s );
	str_words_in_rev(s, len);
	printf("%s \n", s);
	return 0;
}