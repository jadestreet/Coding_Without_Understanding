#include <stdio.h>
int my_strcmp(char* arg1, char* arg2);
int main(int argc, char** argv){
  if (argc != 3)
  {
    printf("Nombre de parametres insuffisants");
    return 1;
  }
  printf("%d\n", my_strcmp(argv[1], argv[2]));
  return 0;
}
int my_strcmp(char* arg1, char* arg2){
  int i, taille1, taille2, tailleMax;
  taille1 = taille2 = tailleMax = 0;
  do{
    taille1++;
  }while(arg1[taille1] != '\0');
  do{
    taille2++;
  }while(arg2[taille2] != '\0');
  tailleMax = (taille1 < taille2 ? taille2 : taille1);
  for(i = 0; i < tailleMax; i++){
    if(arg1[i] == arg2[i])
      continue;
    else if(arg1[i] < arg2[i])
      return -1;
    else
      return 1;
  }
  return 0;
}