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
    return px_out/9;
}
int main(){
    unsigned char image[HEIGHT][WIDTH];
    unsigned char image_smooth[HEIGHT][WIDTH]; 
    unsigned char image_w[HEIGHT/2][WIDTH/2] = {0}; 
    FILE *fp;
    fp = fopen("czp.dat", "rb");
    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);
    fclose(fp);
    for (int i = 1; i < HEIGHT-1; i++){
        for (int j = 1; j < WIDTH-1; j++){
            image_smooth[i][j] = smoothing(image[i-1][j-1],image[i-1][j],image[i-1][j+1],
                                           image[i][j-1],image[i][j],image[i][j+1],
                                           image[i+1][j-1],image[i+1][j],image[i+1][j+1]);
        }
    }
    for (int i = 0; i < HEIGHT / 2; i++){
        for (int j = 0; j < WIDTH / 2; j++){
            image_w[i][j] = image_smooth[2 * i][2 * j];
        }
    }
    fp = fopen("czp_smoothing.dat", "wb");
    fwrite(image_w, sizeof(unsigned char), HEIGHT * WIDTH, fp);
    fclose(fp);
    system("zsh plot_ex3.sh");
    return 0;
}