#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getStringLength(char *string);
long convertToDecimal(char *inputNumber, int base, int cIndex,
                      int numberLength);
char * convertDecimalToBase(long inputNumber, int destBase);
char * concatenate_string(char * original, char * add);
int convertCharToNumber(char inputChar);
int convertCharNumberToInt(char *number);
long power(long number, long exponent);
int main(int argc, char **argv) {
  char *inputNumber = argv[1];
  char *srcBase = argv[2];
  char *destBase = argv[3];
  int srcBaseInt = convertCharNumberToInt(srcBase);
  int destBaseInt = convertCharNumberToInt(destBase);
  long inputNumberLong = convertToDecimal(inputNumber, srcBaseInt,0,getStringLength(inputNumber));
  printf("Conversion of %s base %s to base %s is : %s\n",inputNumber, srcBase, destBase, convertDecimalToBase(inputNumberLong, destBaseInt));
  return 0;
}
long power(long base, long exponent) {
  long sum = 1;
  int i = 1;
  while (i <= exponent) {
    sum = sum * base;
    i++;
  }
  return sum;
}
char * convertDecimalToBase(long inputNumber, int destBase){
  if(inputNumber==0) return "";
  long nextNumber = inputNumber / destBase;
  int digit = inputNumber%destBase;
  char digitCharArray[25];
  sprintf(digitCharArray, "%d", digit);
  char *newdigit = (char *) digitCharArray;
  char * finalDigit = NULL;
  if(strcmp(newdigit, "10")==0)
    finalDigit = "A";
  else if(strcmp(newdigit, "11")==0)
    finalDigit = "B";
  else if(strcmp(newdigit, "12")==0)
    finalDigit = "C";
  else if(strcmp(newdigit, "13")==0)
    finalDigit = "D";
  else if(strcmp(newdigit, "14")==0)
    finalDigit = "E";
  else if(strcmp(newdigit, "15")==0)
    finalDigit = "F";
  else
    finalDigit = newdigit;
  return concatenate_string(convertDecimalToBase(nextNumber, destBase), finalDigit);
}
char * concatenate_string(char * original, char * add) {
  int originalSize = strlen(original);
  int addSize = strlen(add);
  int totalSize = originalSize + addSize;
  char * combinedWord = (char *) malloc(totalSize * sizeof(char));
  int i;
  for(i=0; i<originalSize;i++){
    combinedWord[i]=original[i];
  }
  for(i=0; i<addSize; i++){
    combinedWord[originalSize + i]=add[i];
  }
  return combinedWord;
}
long convertToDecimal(char *inputNumber, int base, int cIndex,
                      int numberLength) {
  long number = 0;
  if (cIndex < numberLength) {
    char digitChar = inputNumber[numberLength - 1 - cIndex];
    long digit = convertCharToNumber(digitChar);
    long sumTemp = power(base, cIndex) * digit;
    cIndex++;
    number = sumTemp;
    return number + convertToDecimal(inputNumber, base, cIndex, numberLength);
  } else
    return number;
}
int convertCharNumberToInt(char *number) {
  int i;
  int place = 1;
  int sum = 0;
  for (i = getStringLength(number) - 1; number[i]; i--) {
    int temp = convertCharToNumber(number[i]);
    sum = sum + (temp * place);
    place = place * 10;
  }
  return sum;
}
int getStringLength(char *string) {
  int i, length = 0;
  for (i = 0; string[i]; i++) {
    length++;
  }
  return length;
}
int convertCharToNumber(char inputChar) {
  switch (inputChar) {
  case '1':
    return 1;
    break;
  case '2':
    return 2;
    break;
  case '3':
    return 3;
    break;
  case '4':
    return 4;
    break;
  case '5':
    return 5;
    break;
  case '6':
    return 6;
    break;
  case '7':
    return 7;
    break;
  case '8':
    return 8;
    break;
  case '9':
    return 9;
    break;
  case 'A':
    return 10;
    break;
  case 'B':
    return 11;
    break;
  case 'C':
    return 12;
    break;
  case 'D':
    return 13;
    break;
  case 'E':
    return 14;
    break;
  case 'F':
    return 15;
    break;
  default:
    return 0;
  }
}