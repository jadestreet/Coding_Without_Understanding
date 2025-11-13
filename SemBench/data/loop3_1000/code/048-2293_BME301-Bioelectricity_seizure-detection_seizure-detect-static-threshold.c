# include <stdio.h>
int threshold=150;      
int size=2;
int seizure_detect(int data[]){
    int average=0;
    int i=0;
    while (i < size){
        average = data[i] + average;
        i = i++;}
    average = average >> 1;
    if ((average <= threshold)||(average >= (threshold+3))){
        return 0;}
    else{
        return 1;}
}
int main(){
    FILE *file = fopen("TrainingData.bin","rb");        
    FILE *f = fopen("output.csv","w");
    int check,i=0;                               
    int j = 0;
    int raw_data[size];
    int output_data;
    int detect;
    while (EOF != fgetc(file)){       
        i = 0;
        while (i < size){                  
            raw_data[i] = fgetc(file);
            i = i++;}
            output_data = seizure_detect(raw_data);
            fprintf(f,"%d\n", output_data);
            j = j++;}
    fclose(f);
    fclose(file);
    printf("j = %d\n",j);
    return 0;}