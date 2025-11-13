#include <stdio.h>
#include <stdlib.h>
#define PARTITION 3
typedef struct Points{
  int x;
  int y;
  int quadrant; 
} Point;
typedef struct {
  Point *array;
  size_t used;
  size_t size;
} PointArray;
typedef struct Nodes{
  struct Nodes *ne;             
  struct Nodes *nw;             
  struct Nodes *se;             
  struct Nodes *sw;             
  struct Nodes *parent;         
  unsigned int currentSize;
  unsigned int limitSize;            
  unsigned int level;           
  unsigned int upperBound_X;
  unsigned int lowerBound_X;
  unsigned int upperBound_Y;
  unsigned int lowerBound_Y;
  PointArray pointsArray;       
  PointArray pointsArrayMean; 
  struct Nodes *leftNeighbor;
  struct Nodes *rightNeighbor;
  struct Nodes *bottomNeighbor;
  struct Nodes *topNeighbor;
} Node;
typedef struct {
  Node *root;
} QuadTree;
void insert (Node *node, PointArray *a, Point element);       
void subdivision (Node *node, PointArray *a, Point element);  
void initArray(PointArray *a, size_t initialSize);            
void freeArray(PointArray *a);                                
int getQuadrant(Node *node, Point *element);                  
void getPointsList(Node *node);                               
void getNodeMean(Node *node);                                 
void getNeighborList(Node *node);                             
void getListByLevel(Node *node, int level);                   
void leftNeighborList(Node *node);
void leftNeighborListUtil(Node *node);
void rightNeighborList(Node *node);
void rightNeighborListUtil(Node *node);
void bottomNeighborList(Node *node);
void bottomNeighborListUtil(Node *node);
void topNeighborList(Node *node);
void topNeighborListUtil(Node *node);
void insert(Node *node, PointArray *a, Point element) {
  node->currentSize++;
  if (node->currentSize >= node->limitSize){
    printf("The tree has exceeded it's capacity\n" );
  }else{
    node->pointsArrayMean.array[node->pointsArrayMean.used++] = element;
    if (a-> size == 0){
      int quadrant = getQuadrant(node, &element);
      if (quadrant == 1){
        insert(node->ne,&(node->ne->pointsArray),element);
      }else if (quadrant == 2){
        insert(node->se,&(node->se->pointsArray),element);
      }else if (quadrant == 3){
        insert(node->sw,&(node->sw->pointsArray),element);
      }else{
        insert(node->nw,&(node->nw->pointsArray),element);
      }
    }else if (a->used == a->size-1){
      printf("Number of points exceeded, partitioning into nodes!\n" );
      subdivision(node, a, element);
      freeArray(a);
    }else{ 
      printf("Inserting point x:%d y:%d \n", element.x, element.y );
      a->array[a->used++] = element;
    }
  }
}
void subdivision (Node *node, PointArray *a, Point element){
  a->array[a->used++] = element;
  node->ne = (Node *)malloc(sizeof(Node));
  node->nw = (Node *)malloc(sizeof(Node));
  node->se = (Node *)malloc(sizeof(Node));
  node->sw = (Node *)malloc(sizeof(Node));
  node->ne->parent = (Node *)malloc(sizeof(Node));
  node->nw->parent = (Node *)malloc(sizeof(Node));
  node->se->parent = (Node *)malloc(sizeof(Node));
  node->sw->parent = (Node *)malloc(sizeof(Node));
  node->ne->parent = node;
  node->nw->parent = node;
  node->se->parent = node;
  node->sw->parent = node;
  node->ne->limitSize = node->limitSize - node->currentSize;
  node->nw->limitSize = node->limitSize - node->currentSize;
  node->se->limitSize = node->limitSize - node->currentSize;
  node->sw->limitSize = node->limitSize - node->currentSize;
  initArray(&(node->ne->pointsArray),PARTITION);
  initArray(&(node->nw->pointsArray),PARTITION);
  initArray(&(node->se->pointsArray),PARTITION);
  initArray(&(node->sw->pointsArray),PARTITION);
  initArray(&(node->ne->pointsArrayMean),3000);
  initArray(&(node->nw->pointsArrayMean),3000);
  initArray(&(node->se->pointsArrayMean),3000);
  initArray(&(node->sw->pointsArrayMean),3000);
  node->ne->level = node->level + 1;
  node->nw->level = node->level + 1;
  node->se->level = node->level + 1;
  node->sw->level = node->level + 1;
      node->ne->leftNeighbor = node->nw;
      node->ne->rightNeighbor = NULL;
      node->ne->bottomNeighbor = node->se;
      node->ne->topNeighbor = NULL;
      node->se->leftNeighbor = node->sw;
      node->se->rightNeighbor = NULL;
      node->se->bottomNeighbor = NULL;
      node->se->topNeighbor = node->ne;
      node->sw->leftNeighbor = NULL;
      node->sw->rightNeighbor = node->se;
      node->sw->bottomNeighbor = NULL;
      node->sw->topNeighbor = node->nw;
      node->nw->leftNeighbor = NULL;
      node->nw->rightNeighbor = node->ne;
      node->nw->bottomNeighbor = node->sw;
      node->nw->topNeighbor = NULL;
  node->ne->upperBound_X = node->upperBound_X;
  node->ne->lowerBound_X = (node->upperBound_X + node->lowerBound_X) / 2;
  node->ne->upperBound_Y = node->upperBound_Y;
  node->ne->lowerBound_Y = (node->upperBound_Y + node->lowerBound_Y)/2;
  node->se->upperBound_X = node->upperBound_X;
  node->se->lowerBound_X = (node->upperBound_X + node->lowerBound_X) / 2;
  node->se->upperBound_Y = (node->upperBound_Y + node->lowerBound_Y) / 2;
  node->se->lowerBound_Y = node->lowerBound_Y;
  node->nw->upperBound_X = (node->upperBound_X + node->lowerBound_X)/2;
  node->nw->lowerBound_X = node->lowerBound_X;
  node->nw->upperBound_Y = node->upperBound_Y;
  node->nw->lowerBound_Y = (node->upperBound_Y + node->lowerBound_Y)/2;
  node->sw->upperBound_X = (node->upperBound_X + node->lowerBound_X)/2;
  node->sw->lowerBound_X = node->lowerBound_X;
  node->sw->upperBound_Y = (node->upperBound_Y + node->lowerBound_Y) / 2;
  node->sw->lowerBound_Y = node->lowerBound_Y;
  int i,x,y;
  for (i = 0; i < a->size; i++) {
    x = a->array[i].x;
    y = a->array[i].y;
    if (x > (node->upperBound_X + node->lowerBound_X)/2){ 
      if (y > (node -> upperBound_Y + node->lowerBound_Y) / 2){ 
        insert(node->ne,&(node->ne->pointsArray), a->array[i]);
        printf("Inserting Node in Northeast Point: x :%d  y: %d \n" ,x,y ); 
      }else{ 
        printf("Inserting Node in Southeast Point: x :%d  y: %d \n",x,y);
        insert(node->se,&(node->se->pointsArray), a->array[i]);
      }
    }else{ 
      if ( y > (node-> upperBound_Y + node->lowerBound_Y)/2){ 
        printf("Inserting Node in Northwest Point: x :%d  y: %d \n",x,y );
        insert(node->nw,&(node->nw->pointsArray), a->array[i]);
      }else{ 
        printf("Inserting Node in Southwest Point: x :%d  y: %d \n",x,y );
        insert(node->sw,&(node->sw->pointsArray), a->array[i]);
      }
    }
  }
  printf("END OF PARTITIONING\n" );
}
int getQuadrant(Node *node, Point *element){
  int x, y;
  x = element->x;
  y = element->y;
  if (x > node->upperBound_X/2){ 
    if (y > node -> upperBound_Y / 2){ 
      element->quadrant = 1;
    }else{ 
      element->quadrant = 2;
    }
  }else{ 
    if ( y > node-> upperBound_Y/2){ 
      element->quadrant = 4;
    }else{ 
      element->quadrant = 3;
    }
  }
  return element->quadrant;
}
void getPointsList(Node *node){
  if (node == NULL){
    printf("The node is NULL can't get any information about it\n" );
  }else{
    int i;
    printf("******** List of points inside this Node ********* \n" );
    printf("This node has a total of %zd Points\n", node->pointsArrayMean.used  );
    if (node->ne == NULL || node->nw == NULL || node->se == NULL || node->sw == NULL){
      for (i = 0; i < node->pointsArrayMean.used; i++){
        printf("(%d, %d)\n",node->pointsArrayMean.array[i].x,node->pointsArrayMean.array[i].y);
      }
    }else{
      getNodeMean(node);
    }
  }
}
void getNodeMean(Node *node){
  if (node->pointsArrayMean.used == 0){
    printf("This node doesn't have any values stored yet\n" );
  }else{
    int i;
    double x,y;
    for (i = 0; i < node->pointsArrayMean.used; i++){
      x+= node->pointsArrayMean.array[i].x;
      y+= node->pointsArrayMean.array[i].y;
    }
    x = x / node->pointsArrayMean.used;
    y = y / node->pointsArrayMean.used;
    printf("The node mean is (%f, %f)\n",x,y );
  }
}
void getNeighborList(Node *node){
  if (node == NULL){
    printf("This node doesn't exist\n" );
  }else{
    leftNeighborList(node);
    rightNeighborList(node);
    topNeighborList(node);
    bottomNeighborList(node);
  }
}
void leftNeighborList(Node *node){
  if (node->level == 1){
    if (node->leftNeighbor != NULL){
      leftNeighborListUtil(node->leftNeighbor);
    }
  }else if(node->level == 2){
    if (node->leftNeighbor == NULL){
      leftNeighborList(node->parent);
    }else{
      leftNeighborListUtil(node->leftNeighbor);
    }
  }else{
    leftNeighborList(node->parent);
  }
}
void leftNeighborListUtil(Node *node){
  if (node->ne != NULL || node->se != NULL){
    leftNeighborListUtil(node->ne);
    leftNeighborListUtil(node->se);
  }else{
    getPointsList(node);
  }
}
void rightNeighborList(Node *node){
  if (node->level == 1){
    if (node->rightNeighbor != NULL){
      rightNeighborListUtil(node->rightNeighbor);
    }
  }else if(node->level == 2){
    if (node->rightNeighbor == NULL){
      rightNeighborList(node->parent);
    }else{
      rightNeighborListUtil(node->rightNeighbor);
    }
  }else{
    rightNeighborList(node->parent);
  }
}
void rightNeighborListUtil(Node *node){
  if (node->nw != NULL || node->sw != NULL){
    rightNeighborList(node->nw);
    rightNeighborList(node->sw);
  }else{
    getPointsList(node);
  }
}
void topNeighborList(Node *node){
  if (node->level == 1){
    if (node->topNeighbor != NULL){
      topNeighborListUtil(node->topNeighbor);
    }
  }else if(node->level == 2){
    if (node->topNeighbor == NULL){
      topNeighborList(node->parent);
    }else{
      topNeighborListUtil(node->topNeighbor);
    }
  }else{
    topNeighborList(node->parent);
  }
}
void topNeighborListUtil(Node *node){
  if (node->se != NULL || node->sw != NULL){
    topNeighborListUtil(node->se);
    topNeighborListUtil(node->sw);
  }else{
    getPointsList(node);
  }
}
void bottomNeighborList(Node *node){
  if (node->level == 1){
    if (node->bottomNeighbor != NULL){
      bottomNeighborListUtil(node->bottomNeighbor);
    }
  }else if(node->level == 2){
    if (node->bottomNeighbor == NULL){
      bottomNeighborList(node->parent);
    }else{
      bottomNeighborListUtil(node->bottomNeighbor);
    }
  }else{
    bottomNeighborList(node->parent);
  }
}
void bottomNeighborListUtil(Node *node){
  if (node->ne != NULL || node->nw != NULL){
    topNeighborListUtil(node->ne);
    topNeighborListUtil(node->nw);
  }else{
    getPointsList(node);
  }
}
void getListByLevel(Node *node, int level){
  if (node == NULL){
    return;
  }else if(node->level == level){
    getPointsList(node);
  }else{
    getListByLevel(node->ne,level);
    getListByLevel(node->nw,level);
    getListByLevel(node->se,level);
    getListByLevel(node->sw,level);
  }
}
void initArray(PointArray *a, size_t initialSize) {
  a->array = (Point *)malloc((initialSize+1) * sizeof(Point));
  a->used = 0;
  a->size = initialSize+1;
}
void freeArray(PointArray *a) {
  free(a->array);
  a->used = a->size = 0;
}
int main(){
  QuadTree quadTree;
  Node root;
  root.limitSize = 20;
  root.currentSize = 0;
  root.lowerBound_X = 0;
  root.upperBound_X = 20;
  root.lowerBound_Y = 0;
  root.upperBound_Y = 20;
  root.level = 0;
  quadTree.root = &root;
  initArray(&root.pointsArray,PARTITION);
  initArray(&root.pointsArrayMean,3000);
  printf("\n\n********************* Testing the routine insert ********************* \n" );
  Point pt1; pt1.x = 1 ; pt1.y = 1; insert(quadTree.root, &root.pointsArray, pt1);
  Point pt2; pt2.x = 2 ; pt2.y = 3; insert(quadTree.root, &root.pointsArray, pt2);
  Point pt3; pt3.x = 15 ; pt3.y = 17; insert(quadTree.root, &root.pointsArray, pt3);
  printf("\n\n********************* Testing the routine subdivision (inserting a 4th point) ********************* \n" );
  Point pt4; pt4.x = 10 ; pt4.y = 16; insert(quadTree.root, &root.pointsArray, pt4);
  Point pt5; pt5.x = 13 ; pt5.y = 13; insert(quadTree.root, &root.pointsArray, pt5);
  Point pt6; pt6.x = 9 ; pt6.y = 12; insert(quadTree.root, &root.pointsArray, pt6);
  Point pt7; pt7.x = 8 ; pt7.y = 12; insert(quadTree.root, &root.pointsArray, pt7);
  Point pt8; pt8.x = 5 ; pt8.y = 15; insert(quadTree.root, &root.pointsArray, pt8);
  Point pt9; pt9.x = 12 ; pt9.y = 17; insert(quadTree.root, &root.pointsArray, pt9);
  Point pt10; pt10.x = 11 ; pt10.y = 12; insert(quadTree.root, &root.pointsArray, pt10);
  printf("\n\n********************* Testing the routine mean on the north east, node level 2 ********************* \n" );
  getNodeMean(quadTree.root->ne);
  printf("\n\n********************* Testing the routine getPointsList with northWest Node (prints the mean)  ********************* \n" );
  getPointsList(quadTree.root->nw);
  printf("\n\n********************* Testing the routine getPointsList with NorthWest -> SouthEast (prints points)  ********************* \n" );
  getPointsList(quadTree.root->nw->se);
  printf("\n\n********************* Testing the routine getNeighborList ********************* \n" );
  getNeighborList(quadTree.root->se);
  printf("\n\n********************* Testing the routine getListByLevel ********************* \n" );
  getListByLevel(quadTree.root, 2);
  return 1;
}