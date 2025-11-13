#include <stdio.h>
void swap(int*ptr1, int*ptr2);
void perm(int list[], int startId, int endId);
void perm2(int list[], int startId, int endId);
int main(int argc, const char * argv[]) {
    int list1[] = {1};
    int size = ((int)sizeof(list1)/ sizeof(int));
    puts("list1");
    perm(list1, 0, size-1);
    perm2(list1, 0, size-1);
    puts("list2");
    int list2[] = {1, 2};
    size = ((int)sizeof(list2)/ sizeof(int));
    perm(list2, 0, size-1);
    perm2(list2, 0, size-1);
    puts("other test");
    perm(list2, 1,1);
    perm(list2, 1,0);
    puts("list3");
    int list3[] = {0, 1, 3, 5};
    size = ((int)sizeof(list3)/ sizeof(int));
    perm(list3, 0, size-1);
    perm2(list3, 0, size-1);
    return 0;
}
void perm(int list[], int startId, int endId){
    if(startId>endId || list == NULL)  {
        puts("error");
        return;
    }
    int pos=0;
    if(startId == endId){
        for(pos = 0; pos<=endId; pos++){
            printf("%3d", list[pos]);
        }
        printf("\n");
    }
    else {
        for(pos=startId ; pos<=endId;pos++){
            swap(&list[startId], &list[pos]);
            perm(list, startId +1, endId);
            swap(&list[startId], &list[pos]);
        }
    }
}
void perm2(int list[], int startId, int endId){
    if(startId>endId || list == NULL) {
        puts("error");
        return;
    }
    int pos=0;
    if(startId == endId){
        for(pos = 0; pos<=endId;pos++){
            printf("%3d", list[pos]);
        }
        printf("\n");
    }
    else {
        perm2(list, startId +1, endId);
        for(pos=startId+1 ; pos<=endId;pos++){
            swap(&list[startId], &list[pos]);
            perm2(list, startId +1, endId);
            swap(&list[startId], &list[pos]);
        }
    }
}
void swap(int*ptr1, int*ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    return ;
}