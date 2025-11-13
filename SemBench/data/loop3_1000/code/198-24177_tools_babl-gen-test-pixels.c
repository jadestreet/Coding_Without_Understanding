#include <stdlib.h>
#include <stdio.h>
#define BABL_PATH_NUM_TEST_PIXELS       3072
#define BABL_CONVERSION_NUM_TEST_PIXELS 128
#define BABL_FROMAT_NUM_TEST_PIXELS     256
#define BABL_MODEL_NUM_TEST_PIXELS      512
#define BABL_TYPE_NUM_TEST_PIXELS       512
static double rand_double (void)
{
  return (double) random () / RAND_MAX;
}
static double rand_range_double (double min, double max)
{
  return rand_double () * (max - min) + min;
}
static void gen_path_pixels (void)
{
  int i;
  srandom (20050728);
  printf ("static const int babl_num_path_test_pixels = %d;\n\n", BABL_PATH_NUM_TEST_PIXELS);
  printf ("static const double babl_path_test_pixels[%d] = {\n", BABL_PATH_NUM_TEST_PIXELS * 4);
  for (i = 0; i < 256; i++)
    {
      printf ("%a, %a, %a, %a,\n",
        rand_double (),
        rand_double (),
        rand_double (),
        rand_double ());
    }
  for (i = 0; i < 16; i++)
    {
      printf ("%a, %a, %a, %a,\n",
        rand_range_double (-1.0, 0.0),
        rand_range_double (-1.0, 0.0),
        rand_range_double (-1.0, 0.0),
        rand_range_double (-1.0, 0.0));
    }
  for (i = 0; i < 16; i++)
    {
      printf ("%a, %a, %a, %a,\n",
        rand_range_double (1.0, 2.0),
        rand_range_double (1.0, 2.0),
        rand_range_double (1.0, 2.0),
        rand_range_double (1.0, 2.0));
    }
  for (i = 288; i < BABL_PATH_NUM_TEST_PIXELS; i++)
    {
      printf ("%a, %a, %a, %a,\n",
        rand_double (),
        rand_double (),
        rand_double (),
        rand_double ());
    }
  printf ("};\n\n");
  printf ("static const int babl_num_conversion_test_pixels = %d;\n\n", BABL_CONVERSION_NUM_TEST_PIXELS);
  printf ("static const double *babl_conversion_test_pixels = babl_path_test_pixels;\n\n");
  printf ("static const int babl_num_format_test_pixels = %d;\n\n", BABL_FROMAT_NUM_TEST_PIXELS);
  printf ("static const double *babl_format_test_pixels = babl_path_test_pixels;\n\n");
}
static void gen_model_pixels (void)
{
  int i;
  srandom (20050728);
  printf ("static const int babl_num_model_test_pixels = %d;\n\n", BABL_MODEL_NUM_TEST_PIXELS);
  printf ("static const double babl_model_test_pixels[%d] = {\n", BABL_MODEL_NUM_TEST_PIXELS * 4);
  for (i = 0; i < BABL_MODEL_NUM_TEST_PIXELS; i++)
    {
      printf ("%a, %a, %a, %a,\n",
        rand_range_double (-0.2, 1.2),
        rand_range_double (-0.2, 1.2),
        rand_range_double (-0.2, 1.2),
        rand_range_double (-0.2, 1.2));
    }
  printf ("};\n\n");
}
static void gen_type_pixels (void)
{
  int i;
  srandom (20050728);
  printf ("static const int babl_num_type_test_pixels = %d;\n\n", BABL_TYPE_NUM_TEST_PIXELS);
  printf ("static const double babl_type_test_pixels[%d] = {\n", BABL_TYPE_NUM_TEST_PIXELS * 4);
  for (i = 0; i < BABL_MODEL_NUM_TEST_PIXELS; i++)
    {
      printf ("%a, %a, %a, %a,\n",
        rand_range_double (0.0, 128.0),
        rand_range_double (0.0, 128.0),
        rand_range_double (0.0, 128.0),
        rand_range_double (0.0, 128.0));
    }
  printf ("};\n\n");
}
int main (int argc, char **argv)
{
  printf (
    "\n"
    "\n");
  printf ("\n\n");
  gen_path_pixels ();
  gen_model_pixels ();
  gen_type_pixels ();
}