#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main()
{
  char filename[]= "grid00001d.b"; 
  float boxsize;
  int nc, nc_check;
  float* delta;
  FILE* fp;
  int ix, iy, iz;
  fp= fopen(filename, "r");
  fread(&boxsize, sizeof(float), 1, fp);
  fread(&nc, sizeof(int), 1, fp);
  delta= malloc(sizeof(float)*nc*nc*nc); 
  fread(delta, sizeof(float), nc*nc*nc, fp);
  fread(&nc_check, sizeof(int), 1, fp);
  if(nc != nc_check) {
    fprintf(stderr, "Error: nc check failed. %d != %d.\n", nc, nc_check);
    return -1;
  }
  fclose(fp);
  printf("# boxsize= %.1f\n", boxsize);
  printf("# nc= %d\n", nc);
  for(ix=0; ix<nc; ix++) {
    for(iy=0; iy<nc; iy++) {
      for(iz=0; iz<nc; iz++) {
	printf("delta(%3d,%3d,%3d) = % e\n", ix, iy, iz, 
	       delta[(ix*nc + iy)*nc + iz]);
      }
    }
  }
  free(delta);
  return 0;
}