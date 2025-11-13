#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
	char* letters;
}word;
int main(void)
{
	char sentence[] = {"Benjamin Todd \"Ben\" Roethlisberger, nicknamed \"Big Ben\", is an American football quarterback"};
	printf("Original Sentence: %s\n",sentence);
	word* words;
	int numWords = 10;
	int numLetters = 10;
	int lengthOfSentence = strlen(sentence);
	int i;	
	int wordCount = 0;
	int letterCounter = 0;	
	char space = ' ';
	words = (word*) calloc(numWords,sizeof(word));
	words[wordCount].letters = (char*) calloc(numLetters,sizeof(char));
	for(i = 0; i < lengthOfSentence; i++)
	{
		if(sentence[i] == space)
		{
			wordCount++;
			letterCounter = 0;
			if(wordCount == numWords)
			{
				printf("doubling size for sentence\n");
				numWords*=2;	
				printf("%d\n",numWords);
				words = (word*) realloc(words,numWords);
			}
			words[wordCount].letters = (char*) calloc(numLetters,sizeof(char));
		}
		else
		{	
			words[wordCount].letters[letterCounter++] = sentence[i];
			if(letterCounter == numLetters)
			{
				printf("doubling size for a word\n");
				numLetters*=2;
				words[wordCount].letters = (char*) realloc(words[wordCount].letters,numLetters);
			}
		}
	}
	printf("Word count is: %d\n",wordCount);
	printf("New Sentence: ");
	for(i = wordCount-1; i >= 0; i--)
	{
		printf("%s ",words[i].letters);
	}
	printf("\n");
	return 0;
}