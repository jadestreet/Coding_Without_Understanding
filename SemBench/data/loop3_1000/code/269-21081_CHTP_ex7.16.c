#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle( int wDeck[][ 13 ] );
void deal( const int wDeck[][ 13 ], const char *wFace[],
           const char *wSuit[] );
int main( void )
{
   const char *suit[ 4 ] = { "Hearts", "Diamonds", "Clubs", "Spades" };
   const char *face[ 13 ] =
      { "Ace", "Deuce", "Three", "Four",
        "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King" };
   int deck[ 4 ][ 13 ] = { 0 };
   int row,column,card=1;
   for (row=0; row<4; row++) {
     for(column=0;column<13;column++){
       deck[row][column]=card;
       card++;
     }
   }
   srand( time( 0 ) ); 
   shuffle( deck ); 
   deal( deck, face, suit ); 
   return 0; 
} 
void shuffle( int wDeck[][ 13 ] )
{
   void swap(int *element1Ptr,int *element2ptr);
   int row; 
   int column; 
   int card; 
   int rowTemp,columnTemp;
    int countt=0;
    for (row=0; row<4; row++) {
      for(column=0;column<13;column++){
        rowTemp = rand() % 4;
        columnTemp = rand() % 13;
        if(rowTemp>row||columnTemp>column){
          swap(&wDeck[row][column],&wDeck[rowTemp][columnTemp]);
          countt++;
        }
      }
    }
} 
void deal( const int wDeck[][ 13 ], const char *wFace[],
           const char *wSuit[] )
{
   int card; 
   int row; 
   int column; 
   for ( card = 1; card <= 52; card++ ) {
      for ( row = 0; row <= 3; row++ ) {
         for ( column = 0; column <= 12; column++ ) {
            if ( wDeck[ row ][ column ] == card ) {
               printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],
                  card % 2 == 0 ? '\n' : '\t' );
            } 
         } 
      } 
   } 
} 
void swap(int *element1Ptr,int *element2ptr){
  int hold;
  hold=*element1Ptr;
  *element1Ptr=*element2ptr;
  *element2ptr=hold;
}