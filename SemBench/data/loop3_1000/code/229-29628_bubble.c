#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Tur { sirali = 1, ters_sirali = 2, rastgele = 3 };
int boyut = 100000;
enum Tur tur = ters_sirali;
int * diziOlustur(int boyut, enum Tur tip){
    int *dizi;
    int i;
    dizi = (int *) malloc( sizeof(int) * boyut );
    if(tip  == 1){
        for( i=0; i < boyut; i++ ){
            dizi[i] = i;
        }
    }else if(tip == 2){
        for( i=0; i < boyut; i++ ){
            dizi[i] = boyut -i -1;
        }
    }else{
        srand(time(NULL)); 
        for(i=0; i < boyut; i++ ){
            dizi[i] = (rand() % boyut);
        }
    }
    return dizi;
}
void diziYaz(int * dizi){
    int l;
    for( l = 0; l < boyut; l++){
        printf("%d,", dizi[l]);
    }
}
int main(){
    int *dizi = diziOlustur(boyut, tur);
    int i, j, gecici, degisim;
    time_t baslangic, bitis;
    double toplam_sure;
    unsigned long long int adim_degisim, adim_karsilastirma, toplam_degisim=0, toplam_karsilastirma = 0;
    printf("Baslayalim, dizinin hali:\n");
    printf("\n----------------\n");
    time(&baslangic);
    for( i = 0; i < boyut; i++ ){ 
        degisim = 0;
        adim_degisim = 0;
        adim_karsilastirma = 0;
        for( j = 0; j < (boyut - i - 1); j++){ 
            if(dizi[j] > dizi[j+1] ){
                gecici = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = gecici;
                degisim = 1;
                adim_degisim++;
                toplam_degisim++;
            }else{
            }
            adim_karsilastirma++;
            toplam_karsilastirma++;
        }
        if(degisim == 0){ break; }
    }
    time(&bitis);
    toplam_sure = difftime(bitis, baslangic);
    printf("----------------\n%d elemanli dizi %d adimda %llu karsilastirma ve %llu degistirme ile siralandi, %.2f saniye surdu.\n----------------\n",
           boyut, i+1, toplam_karsilastirma, toplam_degisim, toplam_sure);
    return 0;
}