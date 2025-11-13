#include <stdio.h>
#include <string.h>
int is_non_blank_line(const char *str){
	int i=0;
	int non_blank_chars=0;
	for(i=0; str[i] != '\0'; i++){
		if(str[i] != '\n' || str[i] != ' ' || str[i] != '\r'){
			non_blank_chars++;
		}
	}
	return non_blank_chars;
}
int find_count_of_char(const char *str, char ch){
	const char *find_ptr = str;
	int times=0;
	do{
		find_ptr = strchr( find_ptr, ch);
		if (find_ptr){
			times++;
			find_ptr++;
		}
	}while(find_ptr != NULL);
	return times;
}
int find_count_of_words(const char *str){
	int words=0, i=0;
	for(i=0; str[i] != '\0'; i++){
		if( str[i] == ' ' || str[i] == '\n' || str[i]== '\r' ){
			words+=1;
			while(str[i]==' ' || str[i] == '\n' || str[i]== '\r'){
				i++;
			}
		}
	}
	return words;
}
int find_count_of_lines(const char *str){
	int liness=0, i=0;
	for(i=0; str[i] != '\0'; i++){
		if( str[i] == '\n' ){
			liness+=1;
		}
	}
	return liness;
}
int txt_file_number_of_char(FILE *fp, char ch){
	int lines=0;
	char buffer[1024]={0x00};
	size_t bytes=0;
	fseek(fp, 0L, SEEK_SET);
	do{
		memset(buffer, 0x00, sizeof(buffer));
		bytes = fread(buffer, sizeof(char), sizeof(buffer)-1, fp);
		if(bytes > 0){
			lines += find_count_of_char(buffer, ch);
		}
	}while(bytes>0);
	return lines;
}
int txt_file_wc(FILE *fp, int *linesp, int *wordsp, int *charsp){
	int lines=0, words=0, chars=0;
	char buffer[1024]={0x00};
	size_t bytes=0;
	fseek(fp, 0L, SEEK_SET);
	do{
		memset(buffer, 0x00, sizeof(buffer));
		bytes = fread(buffer, sizeof(char), sizeof(buffer)-1, fp);
		if(bytes > 0){
			lines += find_count_of_lines(buffer);
			if(is_non_blank_line(buffer)){
				words += find_count_of_words(buffer) ;
			}
			chars += bytes;
		}
	}while(bytes>0);
	*linesp = lines;
	*wordsp = words;
	*charsp = chars;
	return lines;
}
int main(int argc, char *argv[]){
	FILE *fp = NULL;
	fp = fopen(argv[1], "r");
	int number_of_lines= txt_file_number_of_char(fp, '\n');
	int number_of_words= txt_file_number_of_char(fp, ' ') + number_of_lines;
	printf("%d %d\n", number_of_lines, number_of_words);
	int lines, words, chars;
	txt_file_wc(fp, &lines, &words, &chars);
	printf("\t%d\t%d\t%d\n", lines, words, chars);
	fclose(fp);
	return 0;
}