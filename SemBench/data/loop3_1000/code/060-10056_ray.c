#include <stdio.h>
#include <string.h>
typedef signed long word;
word isqrt(word n)
{
    word x = n;
    word previous;
    do {
        previous = x;
        x = (x + n/x)/2;
    } while (x < previous);
    return x;
}
int main()
{
    word x0, y0, z0;    
    word xv, yv, zv;    
    word xc, yc, zc;    
    word xl, yl, zl;    
    word r;             
    word r2;            
    char line[200];     
    word column;        
    word errors[2][200]; 
    word currentErrors = 0; 
    x0 = 0;
    y0 = 0;
    z0 = 50;
    zv = -50;
    xc = 0;
    yc = 0;
    zc = -200;
    r = 150;
    r2 = r*r;
    xl = 57;
    yl = 57;
    zl = 57;
    for (yv = 50; yv >= -50; yv -= 2) {
        memset(line, ' ', sizeof(line));
        for (word i = 0; i < 200; i++) {
            errors[1 - currentErrors][i] = 0;
        }
        for (xv = -50, column = 0; xv <= 50; xv++, column++) {
            word xr = x0 - xc;
            word yr = y0 - yc;
            word zr = z0 - zc;
            word a = xv*xv + yv*yv + zv*zv;
            word b = 2*(xv*xr + yv*yr + zv*zr);
            word c = xr*xr + yr*yr + zr*zr - r2;
            word disc = b*b - 4*a*c;
            if (disc >= 0) {
                word t = (-b - isqrt(disc)) * 100 / (2*a);
                if (t >= 0) {
                    word x = x0 + t*xv/100;
                    word y = y0 + t*yv/100;
                    word z = z0 + t*zv/100;
                    word xn = x - xc;
                    word yn = y - yc;
                    word zn = z - zc;
                    word bright = (xn*xl + yn*yl + zn*zl)/r + errors[currentErrors][column];
                    if (bright < 0) {
                        bright = 0;
                    }
                    if (bright < 5) {
                        bright = 5;
                    }
                    if (bright > 99) {
                        bright = 99;
                    }
                    word quantBright = bright/10;
                    word error = bright - quantBright*10 - 5;
                    word errorLowerLeft = error*19/100;
                    word errorBelow = error*31/100;
                    word errorBelowRight = error*6/100;
                    word errorRight = error - errorLowerLeft - errorBelow - errorBelowRight;
                    if (column - 1 < 200) {
                        errors[currentErrors][column + 1] += errorRight;
                        errors[1 - currentErrors][column + 1] += errorBelowRight;
                    }
                    if (column > 0) {
                        errors[1 - currentErrors][column - 1] += errorLowerLeft;
                    }
                    errors[1 - currentErrors][column] += errorBelow;
                    line[column] = ".,-:;=*?#@"[quantBright];
                }
            }
        }
        line[column] = '\0';
        printf("%s\n", line);
        currentErrors = 1 - currentErrors;
    }
    return 0;
}