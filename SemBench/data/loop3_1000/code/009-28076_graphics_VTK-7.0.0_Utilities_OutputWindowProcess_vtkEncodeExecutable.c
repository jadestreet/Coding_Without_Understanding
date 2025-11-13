#include <stdio.h>
int main(int argc, char* argv[])
{
  FILE* ifp;
  FILE* ofp;
  int i;
  int n;
  int count = 0;
  unsigned char buffer[1024];
  if(argc != 4)
    {
    fprintf(stderr, "Usage: %s <input> <output> <array>\n",
            argv[0]);
    return 1;
    }
  ifp = fopen(argv[1], "rb");
  if(!ifp)
    {
    fprintf(stderr, "Cannot open input file: \"%s\"\n", argv[1]);
    return 2;
    }
  ofp = fopen(argv[2], "w");
  if(!ofp)
    {
    fprintf(stderr, "Cannot open output file: \"%s\"\n", argv[2]);
    fclose(ifp);
    return 2;
    }
  fprintf(ofp, "\n");
  fprintf(ofp, "\n");
  fprintf(ofp, "\n");
  fprintf(ofp, "#include <stdio.h>\n\n");
  while((n = (int)fread(buffer, 1, 1024, ifp)) > 0)
    {
    fprintf(ofp, "static unsigned char vtkEncodedArray%s_%d[%d] = {\n",
            argv[3], count++, n);
    for(i=0; i < n-1; ++i)
      {
      fprintf(ofp, "0x%02X", buffer[i]);
      if(i%10 == 9)
        {
        fprintf(ofp, ",\n");
        }
      else
        {
        fprintf(ofp, ", ");
        }
      }
    fprintf(ofp, "0x%02X};\n\n", buffer[n-1]);
    }
  fclose(ifp);
  fprintf(ofp, "extern int vtkEncodedArray%sWrite(const char* fname)\n",
          argv[3]);
  fprintf(ofp, "{\n");
  fprintf(ofp, "  FILE* ofp = fopen(fname, \"wb\");\n");
  fprintf(ofp, "  if(!ofp) { return 0; }\n");
  for(i=0; i < count; ++i)
    {
    fprintf(ofp, "  if(fwrite(vtkEncodedArray%s_%d, 1,\n"
                 "            sizeof(vtkEncodedArray%s_%d), ofp) !=\n"
                 "       sizeof(vtkEncodedArray%s_%d))\n",
            argv[3], i, argv[3], i, argv[3], i);
    fprintf(ofp, "    {\n");
    fprintf(ofp, "    fclose(ofp);\n");
    fprintf(ofp, "    _unlink(fname);\n");
    fprintf(ofp, "    return 0;\n");
    fprintf(ofp, "    }\n");
    }
  fprintf(ofp, "  fclose(ofp);\n");
  fprintf(ofp, "  return 1;\n");
  fprintf(ofp, "}\n");
  fclose(ofp);
  return 0;
}