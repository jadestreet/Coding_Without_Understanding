#include <stdio.h>
#include <stdlib.h>
#define  nil		0
#define	 false		0
#define  true		1
#define  bubblebase	1.61f
#define  dnfbase 	3.5f
#define  permbase 	1.75f
#define  queensbase 1.83f
#define  towersbase 2.39f
#define  quickbase 	1.92f
#define  intmmbase 	1.46f
#define  treebase 	2.5f
#define  mmbase 	0.0f
#define  fpmmbase 	2.92f
#define  puzzlebase	0.5f
#define  fftbase 	0.0f
#define  fpfftbase 	4.44f
#define maxcells 	 18
#define rowsize 	 40
#define size	 	 511
#define classmax 	 3
#define typemax 	 12
#define d 		     8
#define sortelements 5000
#define srtelements  500
#define fftsize 	 256 
#define fftsize2 	 129  
#define permrange     10
struct node {
	struct node *left,*right;
	int val;
};
#define    stackrange	3
struct    element {
	int discsize;
	int next;
};
struct    complex { float rp, ip; } ;
float value, fixed, floated;
long    seed;  
int    permarray[permrange+1];
unsigned int    pctr;
struct node *tree;
int	   stack[stackrange+1];
struct element    cellspace[maxcells+1];
int    freelist,  movesdone;
int   ima[rowsize+1][rowsize+1], imb[rowsize+1][rowsize+1], imr[rowsize+1][rowsize+1];
float rma[rowsize+1][rowsize+1], rmb[rowsize+1][rowsize+1], rmr[rowsize+1][rowsize+1];
int	piececount[classmax+1],	class[typemax+1], piecemax[typemax+1];
int	puzzl[size+1], p[typemax+1][size+1], n, kount;
int sortlist[sortelements+1], biggest, littlest, top;
struct complex    z[fftsize+1], w[fftsize+1], e[fftsize2+1];
float    zr, zi;
void Initrand () {
    seed = 74755L;   
}
int Rand () {
    seed = (seed * 1309L + 13849L) & 65535L;  
    return( (int)seed );     
}
void bInitarr()	{
	int i;
	long temp; 
	Initrand();
	biggest = 0; littlest = 0;
	for ( i = 1; i <= srtelements; i++ ) {
	    temp = Rand();
	    sortlist[i] = (int)(temp - (temp/100000L)*100000L - 50000L);
	    if ( sortlist[i] > biggest ) biggest = sortlist[i];
	    else if ( sortlist[i] < littlest ) littlest = sortlist[i];
	}
}
void Bubble(int run) {
	int i, j;
	bInitarr();
	top=srtelements;
	while ( top>1 ) {
		i=1;
		while ( i<top ) {
			if ( sortlist[i] > sortlist[i+1] ) {
				j = sortlist[i];
				sortlist[i] = sortlist[i+1];
				sortlist[i+1] = j;
			}
			i=i+1;
		}
		top=top-1;
	}
	if ( (sortlist[1] != littlest) || (sortlist[srtelements] != biggest) )
	printf ( "Error3 in Bubble.\n");
	printf("%d\n", sortlist[run + 1]);
}
int main()
{
	int i;
	for (i = 0; i < 100; i++) Bubble(i);
	return 0;
}