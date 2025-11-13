#include<stdio.h>
double powerOfTen(int num) {
    double rst = 1.0;
    int i;
    if(num >= 0) {
        for(i = 0; i < num ; i++) {
            rst *= 10.0;
        }
    } else {
        for(i = 0; i < (0 - num ); i++) {
            rst *= 0.1;
        }
    }
    return rst;
}
double
squareRoot ( double a ) {
    double z = a;
    double rst = 0.0;
    int	max = 8;
    int	i;
    double j = 1.0;
    for ( i = max; i > 0; i-- ) {
        if ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
            while ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
                j++;
                if ( j >= 10 )
                    break;
            }
            j--;
            z -= ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) );
            rst += j * powerOfTen ( i );
            j = 1.0;
        }
    }
    for ( i = 0; i >= 0 - max; i-- ) {
        if ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
            while ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
                j++;
            }
            j--;
            z -= ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) );
            rst += j * powerOfTen ( i );
            j = 1.0;
        }
    }
    return rst;
}
int main() {
	int num=2;
	printf("sqrt(%d)=%f\n",num,squareRoot(num));
	return 0;
}