#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 256       
#define WIDTH  256
unsigned char smoothing(unsigned char px0,unsigned char px1,unsigned char px2,
                        unsigned char px3,unsigned char px4,unsigned char px5,
                        unsigned char px6,unsigned char px7,unsigned char px8){
    int px[9] = {px0,px1,px2, px3,px4,px5,px6,px7,px8};
    int px_out = 0;
    for(int i = 0; i < 9; i++){
        px_out += px[i];
    }
    px_out /= 9;
    return (unsigned char)px_out;
}
int main(){
    unsigned char image[HEIGHT][WIDTH];
    unsigned char image_w[HEIGHT][WIDTH] = {0}; 
    FILE *fp;
    fp = fopen("czp.dat", "rb");
    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);
    fclose(fp);
    for (int i = 1; i < HEIGHT-1; i++){
        for (int j = 1; j < WIDTH-1; j++){
            image_w[i][j] = smoothing(image[i-1][j-1],image[i-1][j],image[i-1][j+1],
                                      image[i][j-1],image[i][j],image[i][j+1],
                                      image[i+1][j-1],image[i+1][j],image[i+1][j+1]);
        }
    }
    fp = fopen("czp_ex2-1.dat", "wb");
    fwrite(image_w, sizeof(unsigned char), HEIGHT * WIDTH, fp);
    fclose(fp);
    system("zsh plot_ex2-1_czp.sh");
    return 0;
}