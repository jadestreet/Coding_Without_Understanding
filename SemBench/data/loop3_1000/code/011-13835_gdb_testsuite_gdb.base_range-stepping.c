static int
func1 (int a, int b)
{
  volatile int r = a * b;
  r += (a | b);
  r += (a - b);
  return r;
}
int
main(void)
{
  volatile int a = 0;
  volatile int b = 1;
  volatile int c = 2;
  volatile int d = 3;
  volatile int e = 4;
  volatile double d1 = 1.0;
  volatile double d2 = 2.0;
#define LINE_WITH_MULTIPLE_INSTRUCTIONS		\
  do							\
    {							\
      a = b + c + d * e - a;				\
    } while (0)
  LINE_WITH_MULTIPLE_INSTRUCTIONS; 
  e = 10 + func1 (a + b, c * d); 
  e = 10 + func1 (a + b, c * d);
#define LINE_WITH_LOOP						\
  do								\
    {								\
      for (a = 0, e = 0; a < 15; a++)				\
	e += a;							\
    } while (0)
  LINE_WITH_LOOP;
  LINE_WITH_LOOP;
#define LINE_WITH_TIME_CONSUMING_LOOP					\
  do									\
    {									\
      for (c = 1, a = 0; a < 65535 && c; a++)				\
	for (b = 0; b < 65535 && c; b++)				\
	  {								\
	    d1 = d2 * a / b;						\
	    d2 = d1 * a;						\
	  }								\
    } while (0)
  LINE_WITH_TIME_CONSUMING_LOOP;
  LINE_WITH_MULTIPLE_INSTRUCTIONS;
  LINE_WITH_MULTIPLE_INSTRUCTIONS; 
  LINE_WITH_MULTIPLE_INSTRUCTIONS;
  return 0;
}