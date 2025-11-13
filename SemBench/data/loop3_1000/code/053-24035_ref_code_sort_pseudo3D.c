#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDATA 4096
#define MAX_PLANE 256
int main(int argc, char *argv[])
{
void help(char *name);
FILE *infile, 
*outfile[MAX_PLANE]; 
char head[50], 
*inptr;
long data[MAXDATA]; 
int i,j,jj,k,
mode, 
ni,
np,
planes,
planes2=1, 
inflag = 1,
outflag = 1,
modeflag = 1,
niflag = 1,
npflag = 1;
i = 1;
while (i < argc) {
if (!strcmp(argv[i], "-in")) {
infile = fopen(argv[i+1],"r");
inptr = argv[i+1];
inflag = 0;
}
else if (!strcmp(argv[i], "-plane")) {
planes = atoi(argv[i+1]);
}
else if (!strcmp(argv[i], "-plane2")) {
planes2 = atoi(argv[i+1]);
}
else if (!strcmp(argv[i], "-mode")) {
mode = atoi(argv[i+1]);
modeflag = 0;
}
else if (!strcmp(argv[i], "-ni")) {
ni = atoi(argv[i+1]);
niflag = 0;
}
else if (!strcmp(argv[i], "-np")) {
np = atoi(argv[i+1]);
npflag = 0;
}
else {
help(argv[0]);
return 1;
}
i += 2;
}
outflag = 0;
for (jj=0; jj<planes*planes2; jj++) {
char dummy[20];
sprintf(dummy, "%d", jj);
strcat(dummy, ".fid");
if ((outfile[jj] = fopen(dummy, "w")) == NULL)
outflag = 1;
}
if (inflag || outflag || modeflag || niflag || npflag) {
help(argv[0]);
return 1;
}
if (!infile) {
fprintf(stderr, "Error opening in data file!");
return 1;
}
for (i=0; i<planes; i++)
if (!outfile[i]) {
fprintf(stderr, "Error opening output files!");
return 1;
}
if (np > MAXDATA) {
fprintf(stderr, "np > 4096. If you want to continue, you\n");
fprintf(stderr, "have to change the code and recompile.\n");
return 1;
}
if (planes*planes2 > MAX_PLANE) {
fprintf(stderr, "Number of planes (plane*plane2) must be less than %d!\n",
MAX_PLANE);
fprintf(stderr, "If you need this no. planes, change code and recompile!\n",
MAX_PLANE);
return 1;
}
fread(head, 1, 32, infile);
for (i=0; i<planes*planes2; i++)
fwrite(head, 1, 32, outfile[i]);
for(jj=0; jj<ni; jj++) {
if (!mode) {
for (i=0; i<2*planes*planes2; i++) {
fread(head, 1, 28, infile);
fread(data, 4, np, infile);
fwrite(head, 1, 28, outfile[i/2]);
fwrite(data, 4, np, outfile[i/2]);
}
}
else if (mode==-1) {
int l=0, ll=0;
for (k=0; k<planes2; k++)
for (j=0; j<2; j++) {
l=ll;
for (i=0; i<planes; i++) {
fread(head, 1, 28, infile);
fread(data, 4, np, infile);
fwrite(head, 1, 28, outfile[l]);
fwrite(data, 4, np, outfile[l]);
l++;
if (j==1) ll++;
}
}
}
else {
for (i=0; i<2*planes*planes2; i++) {
fread(head, 1, 28, infile);
fread(data, 4, np, infile);
fwrite(head, 1, 28, outfile[i%planes]);
fwrite(data, 4, np, outfile[i%planes]);
}
}
}
fclose(infile);
for (i=0; i<planes; i++)
fclose(outfile[i]);
return 0;
}
void help(char *name) {
fprintf(stderr, "\n%s -in <infile> -plane <no. exp.> -mode <0/1> -ni <ni> -np <np>\n\n", name);
fprintf(stderr, "This program will separate a pseudo 3D experiment\n");
fprintf(stderr, "recorded with array='parameter,phase' (or opposite)\n");
fprintf(stderr, "into regular 2D fids.\n");
fprintf(stderr, "'parameter' might be a relaxation delay, cpmg\n");
fprintf(stderr, "repetition rate, offset or whatever.\n");
fprintf(stderr, "The output files will be called 0.fid, 1.fid...\n\n");
fprintf(stderr, "Arguments:\n\n"),
fprintf(stderr, "-in\tinput file\n");
fprintf(stderr, "-plane\tNo. interleaved experiments (in 3rd dim.)\n");
fprintf(stderr, "-plane2\tNo. interleaved experiments (in 4th dim.)\n");
fprintf(stderr, "-mode\t0 for array='par,phase'; 1 for 'phase,par'; -1 for 'par1,phase,par2'\n");
fprintf(stderr, "-ni\tNumber of increments (ni)\n");
fprintf(stderr, "-np\tTotal number of acq. points: np (REAL + IMAG)\n\n");
}