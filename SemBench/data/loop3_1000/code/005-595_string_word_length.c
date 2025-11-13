#include <stdio.h>
#include <ctype.h>
int my_isspace(char ch){
	return (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v' || ch == '\f');
}
const char* largest_word(const char *str){
	unsigned int word_len=0, cur_word_len=0;
	const char *word = str, *cur_word=str;
	int i = 0;
	while(str[i] != '\0'){
		if(isspace(str[i])){
			cur_word_len = (str+i) - cur_word;
			if(word_len < cur_word_len){
				word_len = cur_word_len;
				word = cur_word;
			}
			while(isspace(str[i])){
				i++;
			}
			cur_word = str+i;
		}else{
			i++;
		}
	}
	cur_word_len = (str+i) - cur_word;
	if(word_len < cur_word_len){
		word_len = cur_word_len;
		word = cur_word;
	}
	return word;
}
int find_largest_word(const char *str, char result[]){
	const char *word = largest_word(str);
	int i=0;
	while(word[i] != '\0' && (!isspace(word[i]))){
		result[i] = word[i];
		i++;
	}
	return i;
}
int main(int argc, char *argv[]){
	char word[256]={0x00};
	if(argc != 2){
		fprintf(stderr, "USAGE: %s <string>\n", argv[0]);
		return -1;
	}
	find_largest_word(argv[1], word);
	printf("%s\n", word);
	return 0;
}