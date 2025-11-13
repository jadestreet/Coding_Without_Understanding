#include <stdio.h>
#include <stdlib.h>
void merge_flash(char *binfile,char *flashfile,int flash_pos,int patch_hash)
{
    FILE *fbin;
    FILE *fflash;
    unsigned char *tmp_data;
    unsigned char *flash_data;
    int file_size=0;
    int flash_size=0;
    fbin = fopen(binfile, "r");
    if (fbin == NULL) {
        printf("   Can't open '%s' for reading.\n", binfile);
		return;
	}
    if (fseek(fbin, 0 , SEEK_END) != 0) {
    }
    file_size = ftell(fbin);
    if (fseek(fbin, 0 , SEEK_SET) != 0) {
    }
    fflash  = fopen(flashfile, "r+");
    if (fflash == NULL) {
        printf("   Can't open '%s' for writing.\n", flashfile);
        return;
    }
    if (fseek(fflash, 0 , SEEK_END) != 0) {
    }
    flash_size = ftell(fflash);
    rewind(fflash);
    fseek(fflash,flash_pos,SEEK_SET);
    tmp_data=malloc((1+file_size)*sizeof(char));
    if (file_size<=0) {
      printf("Not able to get file size %s",binfile);
    }
    int len_read=fread(tmp_data,sizeof(char),file_size,fbin);
    if (patch_hash==1) {
      int j=0;
      for (j=0;j<33;j++)
	{
          tmp_data[file_size-j]=0;
	}
    }
    int len_write=fwrite(tmp_data,sizeof(char),file_size,fflash);
    if (len_read!=len_write) {
      printf("Not able to merge %s",binfile);
    }
    fclose(fbin);
    if (fseek(fflash, 0 , SEEK_END) != 0) {
    }
    fclose(fflash);
    free(tmp_data);
}
int main(int argc,char *argv[])
{
    system("dd if=/dev/zero bs=1M count=4  | tr \"\\000\" \"\\377\" >  esp32flash.bin");
    merge_flash("build/bootloader/bootloader.bin","esp32flash.bin",0x1000,0);
    merge_flash("build/partitions_example.bin","esp32flash.bin",0x8000,0);
    merge_flash("build/spiffs_image.img","esp32flash.bin",0x180000,0);
    merge_flash(argv[1],"esp32flash.bin",0x10000,0);
    system("cp esp32flash.bin ~/qemu_esp32");
}