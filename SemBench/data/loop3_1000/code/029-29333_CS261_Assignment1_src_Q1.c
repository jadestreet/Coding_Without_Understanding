#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
struct student{
	int id;
	int score;
};
int contains(int values[], int want);
struct student* allocate(){
	struct student  *sptr = (struct student*)malloc(sizeof(struct student)*10);
	return sptr;
}
void generate(struct student* students){
	 srand((unsigned)time(NULL));
	int randNum, randScore, i;
	int x[10];
	for (i = 0; i < 10; i++){
		randNum = rand()%100000+100000;
		if (i != 0){
			if (contains(x, randNum) == 1){
				i--;
			} else {
				x[i] = randNum;
			}
		}
		x[i] = randNum;
	}
	for (i = 0; i < 10; i++){
		randScore = rand()%100;
		students[i].id = x[i];
		students[i].score = randScore;
	}
}
void output(struct student* students){
	int i;
	for(i = 0; i < 10; i++){
		printf("ID %4d    Score %4d\n", students[i].id, students[i].score);
	}
}
void summary(struct student* students){
	int min, max, total, i, a;
	float avg;
	int count = 0;
	for (i = 0; i < 10; i++){
		a = students[i].score;
		if (i == 0){
			min = a;
			max = a;
			total = a;
		}else{
			total = total + a;
			if ( a < min ) min = a;
			if ( a > max ) max = a;
		}
		count++;
	}
	avg = 1.0*total/count;
	printf("\nMinimum Score: %d\nMaximum Score: %d\nAverage Score: %2.2f", min, max, avg);
}
void deallocate(struct student* stud){
	free(stud);
}
int contains(int values[], int want){
	int i;
	for (i = 0; i < 10; i++){
		if (values[i] == want){
			return 1;
		}
	}
	return 0;
}
int main(){
    struct student* stud = 0;
    stud = allocate();
    generate(stud);
    output(stud);
    summary(stud);
    deallocate(stud);
    return 0;
}