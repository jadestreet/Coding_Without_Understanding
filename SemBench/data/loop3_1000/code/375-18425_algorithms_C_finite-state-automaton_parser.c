#include <stdio.h>
#define LETTERS "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_"
#define LETTERS_AND_NUMBERS "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM_0123456789"
#define STATE_ONE "Vv"
#define STATE_TWO "Aa"
#define STATE_THREE "Rr"
#define STATE_COUNT 8
#define SUCCESS_STATE 7
char *automat[STATE_COUNT][STATE_COUNT];
int check(char *str, char currentChar) {
	int result = 0;
	int i = 0;
	char c;
	while((c=str[i++])&&!(result=(c==currentChar)))
		;
	return result;
}
int analyze(char *str) {
	int currentState = 0;
	int i = 0, j;
	char c;
	int isFound;
	while((c=str[i++])) {
		isFound = 0;
		for(j = 0; j < STATE_COUNT&&(!isFound); j++) {
			if(check(automat[j][currentState],c)) {
				currentState=j;
				isFound=1;
			}
		}
		if(!isFound) {
			return 0;
		}
	}
	return (currentState==SUCCESS_STATE);
}
void initAutomat() {
	int i,j;
	for(i = 0; i<STATE_COUNT; i++) {
		for(j = 0; j<STATE_COUNT; j++) {
			automat[i][j] = "";
		}
	}
	automat[0][0] = " ";
	automat[1][0] = STATE_ONE;
	automat[2][1] = STATE_TWO;
	automat[3][2] = STATE_THREE;
	automat[4][3] = " ";
	automat[4][4] = " ";
	automat[5][4] = LETTERS;
	automat[5][5] = LETTERS_AND_NUMBERS;
	automat[6][5] = " ";
	automat[7][5] = ":";
	automat[6][6] = " ";
	automat[7][6] = ":";
	automat[7][7] = " ";	
}
char* viewResult(int r) {
	return (r==1)?"SUCCESS":"FAILURE";
}
void printResulFor(char *str) {
	int res = analyze(str);
	printf("expression \"%s\" is ", str);
	puts(viewResult(res));
}
int main() {
	initAutomat();
	printResulFor(" var sdf : ");
	printResulFor("vr sdRR   :");
	printResulFor("Varr f");
	printResulFor("var 33sdf:");
	printResulFor("    var  dd345345");
	printResulFor("    var  dd345345:");
	printResulFor("    var  dd345345    :     ");
	printResulFor(" VaR _Sdd54f : ");
	return 0;
}