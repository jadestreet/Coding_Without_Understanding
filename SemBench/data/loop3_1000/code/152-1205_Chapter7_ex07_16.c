#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getRandomNumber( int );
void printDeck(const int [][13]);
void shuffle( int [][13] );
void reinitialiseDeck( int [][13] );
int main()
{
    srand( time(0));
    int deck[4][13] = { {0} };
    reinitialiseDeck( deck );
    printf("\n\n -- Before Shuffling ----\n\n");
    printDeck( deck );
    shuffle( deck );
    printf("\n\n -- After Shuffling ----\n\n");
    printDeck( deck );
    return 0;
}
int getRandomNumber( int max )
{
    return rand()%max;
}
void printDeck(const int wDeck[][13])
{
    int row, column;
    printf(" ");
    for(column=0; column<13; column++)
        printf("%4d",column);
    printf("\n");
    for( row=0; row<4; row++) {
        printf("%d", row);
        for(column=0; column<13; column++)
            printf("%4d",wDeck[row][column]);
        printf("\n");
    }
}
void shuffle( int wDeck[][13] )
{
    int row, column;
    int randRow, randColumn, temp;
    int pass;
    for(pass=0; pass<4; pass++)
    {
        for( row=0; row<1; row++) {
            for(column=0; column<13; column++) {
                randRow    = getRandomNumber(4);
                randColumn = getRandomNumber(13);  
                temp = wDeck[row][column];
                wDeck[row][column] = wDeck[randRow][randColumn];
                wDeck[randRow][randColumn] = temp;
            }   
        }       
    }
}
void reinitialiseDeck( int wDeck[][13] )
{
    int row, column;
    int startValue = 1;
    for( row=0; row<4; row++) {
        for(column=0; column<13; column++)
            wDeck[row][column] = startValue++;  
    }
}