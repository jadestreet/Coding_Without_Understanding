#include <stdio.h>
#include <stdlib.h>
#undef NO_SPECIAL
static char *atom2human_type(int type)
{
switch (type)
{
  case 0x766F6F6D: return "Information sections"; 
  case 0x6468766D: return "Movie header"; 
  case 0x6169646D: return "Media stream"; 
  case 0x64686D76: return "Video media header"; 
  case 0x64686D73: return "Sound media header"; 
  case 0x6468646D: return "Media header"; 
  case 0x666E696D: return "Media information"; 
  case 0x726C6468: return "Handler reference"; 
  case 0x6B617274: return "New track (stream)"; 
  case 0x75716D72: return "rmqu";
  case 0x65657266: return "free";
  case 0x64686B74: return "Track header"; 
  case 0x61746475: return "User data"; 
  case 0x7461646D: return "Movie data"; 
  case 0x6C627473: return "Sample information table"; 
  case 0x64737473: return "Sample description"; 
  case 0x6F637473: return "Chunk offset table"; 
  case 0x73747473: return "Sample time table"; 
  case 0x63737473: return "Sample->Chunk mapping table"; 
  case 0x7A737473: return "Sample size table"; 
}
    return "unknown";
}
#define S_NONE 0
#define S_AUDIO 1
#define S_VIDEO 2
int stream = S_NONE;
int v_stream = 0;
int a_stream = 0;
static unsigned int read_dword(FILE *f){
 unsigned char atom_size_b[4];
 if(fread(&atom_size_b,4,1,f)<=0) return -1;
 return (atom_size_b[0]<<24)|(atom_size_b[1]<<16)|(atom_size_b[2]<<8)|atom_size_b[3];
}
static void video_stream_info(FILE *f, int len)
{
  int orig_pos = ftell(f);
  unsigned char data[len-8];
  int i;
  len -= 8;
  for (i=0; i<len; i++)
	fread(&data[i], 1, 1, f);
  fseek(f,orig_pos,SEEK_SET);
}
static void audio_stream_info(FILE *f, int len)
{
  int orig_pos = ftell(f);
  unsigned char data[len-8];
  int i;
  len -= 8;
  for (i=0; i<len; i++)
	fread(&data[i], 1, 1, f);
  printf("  [%d bit", data[19]);
  if (data[17] == 1)
    printf(" mono");
  else
    printf(" %d channels", data[17]);
  printf("]\n");
  fseek(f,orig_pos,SEEK_SET);
}
#if 0
static void userdata_info(FILE *f, int len, int pos, int level)
{
  int orig_pos = pos; 
  unsigned int atom_size = 1;
  unsigned int atom_type;
  while (atom_size != 0)
  {
    atom_size=read_dword(f);
    if(fread(&atom_type,4,1,f)<=0) break;
    if(atom_size<8) break; 
    switch(atom_type)
    {
      case 0x797063A9: 
        {
	  char *data = malloc(atom_size-8);
	  fseek(f, pos+6, SEEK_SET);
	  fread(data, atom_size-8, 1, f);
	  printf(" Copyright: %s\n", data);
	  free(data);
	}
        break;
      case 0x666E69A9: 
        {
	  char data[atom_size-8];
	  fread(&data, 1, atom_size-8, f);
	  printf(" Owner: %s\n", &data);
	}
        break;
      case 0x6D616EA9: 
        {
	  char data[atom_size-8];
	  fread(&data, 1, atom_size-8, f);
	  printf(" Name: %s\n", &data);
	}
        break;
    }
  }
  fseek(f,orig_pos,SEEK_SET);
}
#endif
int time_scale = 0;
static void lschunks(FILE *f,int level,unsigned int endpos){
 unsigned int atom_size;
 unsigned int atom_type;
 int pos;
 while(endpos==0 || ftell(f)<endpos){
  pos=ftell(f);
  atom_size=read_dword(f);
  if(fread(&atom_type,4,1,f)<=0) break;
  if(atom_size<8) break; 
  printf("%08X:  %*s %.4s (%08X) %05d [%s] (begin: %08X)\n",pos,level*2,"",&atom_type,atom_type,atom_size,
    atom2human_type(atom_type), pos+8); 
#ifndef NO_SPECIAL
  if (atom_type == 0x6468646D)
  {
    char data[4];
    fread(&data, 1, 1, f); 
    printf("mdhd version %d\n", data[0]);
    fread(&data, 3, 1, f); 
    fread(&data, 4, 1, f); 
    fread(&data, 4, 1, f); 
    fread(&data, 4, 1, f); 
    time_scale = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
    printf("timescale: %d\n", time_scale);
    fread(&data, 4, 1, f); 
    fread(&data, 2, 1, f); 
    fread(&data, 2, 1, f); 
  }
  if (atom_type == 0x64686D76)
  {
    stream = S_VIDEO;
    printf(" Found VIDEO Stream #%d\n", v_stream++);
  }
  if (atom_type == 0x64686D73)
  {
    stream = S_AUDIO;
    printf(" Found AUDIO Stream #%d\n", a_stream++);
  }
  if (atom_type == 0x64686B74) 
  {
    int i;
    unsigned char data[atom_size];
    int x, y;
    for (i=0; i<atom_size; i++)
	fread(&data[i], 1, 1, f);
    x = data[77];
    y = data[81];
    printf(" Flags: %d\n", data[3]);
    printf(" Picture size: %dx%d\n", x, y);
    if (x == 0 && y == 0)
	printf(" Possible audio stream!\n");
  }
  if(atom_type==0x64737473) {  
    unsigned int tmp;
    unsigned int count;
    int i;
    fread(&tmp,4,1,f);
    count=read_dword(f);
    printf("desc count = %d\n",count);
    for(i=0;i<count;i++){
      unsigned int len;
      unsigned int format;
      len=read_dword(f); 
      fread(&format,4,1,f);
      printf("  desc #%d: %.4s  (%d)\n",i+1,&format,len);
      if (stream == S_VIDEO)
        video_stream_info(f, len);
      if (stream == S_AUDIO)
        audio_stream_info(f, len);
      fseek(f,len-8,SEEK_CUR);
    }
  }
  if(atom_type==0x6F637473) {  
    int len,i;
    read_dword(f);
    len=read_dword(f);
    printf("Chunk table size :%d\n",len);
    for(i=0;i<len;i++) printf("  chunk #%d: 0x%X\n",i+1,read_dword(f));
  }
  if(atom_type==0x73747473) {  
    int len,i;
    read_dword(f);
    len=read_dword(f);
    printf("T->S table size :%d\n",len);
    for(i=0;i<len;i++){
      int num=read_dword(f);
      int dur=read_dword(f);
      printf("%5d samples: %d duration", num, dur);
      if (stream == S_AUDIO)
        printf("(rate: %f Hz)\n", (float)time_scale/dur);
      else
	printf("(fps: %f)\n", (float)time_scale/dur);
    }
  }
  if(atom_type==0x63737473) {  
    int len,i;
    read_dword(f);
    len=read_dword(f);
    printf("S->C table size :%d\n",len);
    for(i=0;i<len;i++){
      int first=read_dword(f);
      int spc=read_dword(f);
      int sdid=read_dword(f);
      printf("  chunk %d...  %d s/c   desc: %d\n",first,spc,sdid);
    }
  }
  if(atom_type==0x7A737473) {  
    int len,i,ss;
    read_dword(f);
    ss=read_dword(f);
    len=read_dword(f);
    printf("Sample size table len: %d\n",len);
    if(ss){
      printf("  common sample size: %d bytes\n",ss);
    } else {
      for(i=0;i<len;i++) printf("  sample #%d: %d bytes\n",i+1,read_dword(f));
    }
  }
#endif
#if 1
  switch(atom_type){
  case 0x7461646D: 
  case 0x75716D72: 
  case 0x65657266: 
  case 0x64686B74: 
  case 0x61746475: 
  case 0x64737473: 
  case 0x6F637473: 
  case 0x73747473: 
  case 0x63737473: 
  case 0x7A737473: 
  case 0x746f6e70: 
  case 0x54434950: 
  case 0x70797466:
      break;
  default: lschunks(f,level+1,pos+atom_size);
  }
#else
  switch(atom_type){
  case 0x766F6F6D: 
  case 0x61726D72: 
  case 0x61646D72: 
    lschunks(f,level+1,pos+atom_size);
  }
#endif
  fseek(f,pos+atom_size,SEEK_SET);
 }
}
int main(int argc,char* argv[])
{
    FILE *f;
    if ((f = fopen(argc>1?argv[1]:"Akira.mov","rb")) == NULL)
	return 1;
    printf("%.8s    %.4s (%.8s) %5s [%s]\n\n",
	"position", "atom", "atomtype", "len", "human readable atom name");
    lschunks(f, 0, 0);
    printf("\nSummary: streams: %d video/%d audio\n", v_stream, a_stream);
    return 0;
}