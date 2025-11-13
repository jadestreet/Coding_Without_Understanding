#include <stdio.h>
#include <stdlib.h>
enum states { LOCKED, UNLOCKED, MAXSTATES };
enum events { PAYED, PERSONPASSED, TICK, MAXEVENTS };
int TS_State = LOCKED;
void Do( int State );
void OnEnter( int State);
void OnExit( int State);
void TurnstileSM(int event);
int main()
{	
    TurnstileSM( PAYED );
    TurnstileSM( PAYED );
    int i;
    for(i=0; i<4; i++)
		{
    	TurnstileSM( TICK );
		}
    TurnstileSM( PERSONPASSED );
    TurnstileSM( PAYED );
    for(i=0; i<5; i++)
    		{
        	TurnstileSM( TICK );
    		}
        TurnstileSM( PAYED );
        TurnstileSM( PERSONPASSED );
        for(i=0; i<20; i++)
        		{
            	TurnstileSM( TICK );
        		}
    return 0;
}
void TurnstileSM( int event )
{
    int NextState = TS_State;
    static int Timeout,Count = 0, t = 5;
    switch( TS_State )
    {
        case LOCKED:
            switch (event )
            {
			case PAYED:
				NextState = UNLOCKED;
				Count++;
				printf("You can enter\n");
				break;
			default:
				break;
            }
            break;
        case UNLOCKED:
        	switch (event )
			{
			case PAYED:
				Count++;
				Timeout  = Count*t;
				printf("Persons Payed for %i\n",Count);
				NextState = UNLOCKED;
				break;
			case PERSONPASSED:
				Count--;
				printf("Persons entered\n");
				printf("%i Persons can stil enter\n",Count);
				Timeout = Count*t;
				if(Count <= 0)
				{
					NextState = LOCKED;
					Count = 0;
					Timeout = 5;
				}
				break;
			case TICK:
				printf("Ticks = %i\n",Timeout);
				Timeout--;
				if(Timeout <= 0)
					{
						NextState = LOCKED;
						printf("You didnt make it - ");
						Timeout = t;
						Count = 0;
					}
				break;
			default:
				break;
			}
            break;
        default:
            break;
    }
    if (NextState != TS_State)
    {
        OnExit(TS_State);
        OnEnter(NextState);
        TS_State = NextState;
    }
    Do( TS_State );
}
void OnEnter( int State )
{
}
void OnExit( int State)
{
}
void Do( int State)
{
    switch (State)
    {
        case LOCKED:
            printf("Door is Locked!\n");
            break;
        case UNLOCKED:
            printf("Door is unlocked.\n");
            break;
    }
}