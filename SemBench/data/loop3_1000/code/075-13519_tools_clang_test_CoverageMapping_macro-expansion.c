#define M1 do { if (0) {} } while (0)
#define M2(x) do { if (x) {} } while (0)
#define M3(x) do { M2(x); } while (0)
#define M4(x) ((x) && (x))
#define M5(x) ((x) || (x))
#define M6(x) ((x) + (x))
#define M7(x) (x)
void func(int x) {
  if (x) {}
  M1;
  M2(!x);
  M2(x);
  M3(x);
  if (M4(x)) {}
  if (M5(x)) {}
  if (M6(x)) {}
  if (M7(x)) {}
}
int main(int argc, const char *argv[]) {
  func(0);
}