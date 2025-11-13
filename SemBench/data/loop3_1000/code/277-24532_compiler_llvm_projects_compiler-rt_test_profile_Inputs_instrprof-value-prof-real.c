#define DEF_FUNC(x)                                                            \
  void x() {}
#define DEF_2_FUNCS(x) DEF_FUNC(x##_1) DEF_FUNC(x##_2)
#define DEF_4_FUNCS(x) DEF_2_FUNCS(x##_1) DEF_2_FUNCS(x##_2)
#define DEF_8_FUNCS(x) DEF_4_FUNCS(x##_1) DEF_4_FUNCS(x##_2)
#define DEF_16_FUNCS(x) DEF_8_FUNCS(x##_1) DEF_8_FUNCS(x##_2)
#define DEF_32_FUNCS(x) DEF_16_FUNCS(x##_1) DEF_16_FUNCS(x##_2)
#define DEF_64_FUNCS(x) DEF_32_FUNCS(x##_1) DEF_32_FUNCS(x##_2)
#define DEF_128_FUNCS(x) DEF_64_FUNCS(x##_1) DEF_64_FUNCS(x##_2)
#define DEF_256_FUNCS(x) DEF_128_FUNCS(x##_1) DEF_128_FUNCS(x##_2)
#define DEF_512_FUNCS(x) DEF_256_FUNCS(x##_1) DEF_256_FUNCS(x##_2)
#define FUNC_ADDR(x) &x,
#define FUNC_2_ADDRS(x) FUNC_ADDR(x##_1) FUNC_ADDR(x##_2)
#define FUNC_4_ADDRS(x) FUNC_2_ADDRS(x##_1) FUNC_2_ADDRS(x##_2)
#define FUNC_8_ADDRS(x) FUNC_4_ADDRS(x##_1) FUNC_4_ADDRS(x##_2)
#define FUNC_16_ADDRS(x) FUNC_8_ADDRS(x##_1) FUNC_8_ADDRS(x##_2)
#define FUNC_32_ADDRS(x) FUNC_16_ADDRS(x##_1) FUNC_16_ADDRS(x##_2)
#define FUNC_64_ADDRS(x) FUNC_32_ADDRS(x##_1) FUNC_32_ADDRS(x##_2)
#define FUNC_128_ADDRS(x) FUNC_64_ADDRS(x##_1) FUNC_64_ADDRS(x##_2)
#define FUNC_256_ADDRS(x) FUNC_128_ADDRS(x##_1) FUNC_128_ADDRS(x##_2)
#define FUNC_512_ADDRS(x) FUNC_256_ADDRS(x##_1) FUNC_256_ADDRS(x##_2)
DEF_512_FUNCS(foo)
void *CalleeAddrs[] = {FUNC_512_ADDRS(foo)};
typedef void (*FPT)(void);
FPT getFunc(int I) { return CalleeAddrs[I]; }
int main() {
  int I;
  for (I = 0; I < 512; I++) {
    FPT Fp = getFunc(I);
    int J;
    for (J = 0; J < 1000 - I; J++)
      Fp();
    Fp = getFunc(511 - I);
    for (J = 0; J < 2000 - I; J++)
      Fp();
  }
  return 0;
}