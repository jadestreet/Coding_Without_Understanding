#include <stdio.h>
#define MAX_SIZE 20
typedef int ElemType;
typedef struct {
    ElemType data[MAX_SIZE];
    int length;
}SqList;
SqList ListDelete(SqList *L,int i, ElemType e);
int main(int argc, const char * argv[]){
    SqList list;
    for (int i = 0; i < 15; i++) {
        list.data[i] = i + 1;
        list.length++;
        printf("%d--",list.data[i]);
    }
    printf("\n");
    int location = 6;
    SqList newList = ListDelete(&list, location, 5);
    for (int i = 0; i < newList.length; i++) {
        printf("%d--",newList.data[i]);
    }
    printf("\nnewList.length = %d--\n",newList.length);
    return 0;
}
SqList ListDelete(SqList *L,int i, ElemType e){
    int k;
    SqList List;
    if (L->length == 0) {
        printf("空表\n");
        return List;
    } else if(i < 0 || i > L->length) {
        printf("i值超出了范围\n");
        return List;
    }else {
        ElemType elem = L->data[i - 1];
        printf("删除的元素是%d\n",elem);
        for (k = i - 1; k < L->length - 1; k++) {
            L->data[k] = L->data[k + 1];
        }
        L->length--;
        return *L;
    }
}