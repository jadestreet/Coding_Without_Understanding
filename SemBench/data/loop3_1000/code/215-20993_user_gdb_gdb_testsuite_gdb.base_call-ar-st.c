#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int id_int;
typedef enum { 
	      BLACK,
	      BLUE,
	      BROWN,
	      ECRUE,
	      GOLD,
	      GRAY,
	      GREEN,
	      IVORY,
	      MAUVE,
	      ORANGE,
	      PINK,
	      PURPLE,
	      RED,
	      SILVER,
	      TAN,
	      VIOLET,
	      WHITE,
	      YELLOW} colors;
struct array_rep_info_t {
   int   next_index[10]; 
   int   values[10];
   int   head;
};
struct small_rep_info_t {
   int   value;
   int   head;
};
struct bit_flags_t {
       unsigned alpha   :1;
       unsigned beta    :1;
       unsigned gamma   :1;
       unsigned delta   :1;
       unsigned epsilon :1;
       unsigned omega   :1;
};
struct bit_flags_combo_t {
       unsigned alpha   :1;
       unsigned beta    :1;
       char     ch1;
       unsigned gamma   :1;
       unsigned delta   :1;
       char     ch2;
       unsigned epsilon :1;
       unsigned omega   :1;
};
struct one_double_t {
       double double1;
};
struct two_floats_t {
       float float1;
       float float2;
};
struct two_char_t {
       char ch1;
       char ch2;
};
struct three_char_t {
       char ch1;
       char ch2;
       char ch3;
};
struct five_char_t {
       char ch1;
       char ch2;
       char ch3;
       char ch4;
       char ch5;
};
struct int_char_combo_t {
       int  int1;
       char ch1;
};
#ifdef PROTOTYPES
void print_student_id_shirt_color (id_int student, colors shirt)
#else
void print_student_id_shirt_color ( student, shirt ) 
 id_int student;
 colors shirt;
#endif
{
 printf("student id : %d\t", student);
 printf("shirt color : ");
 switch (shirt) {
   case BLACK :  printf("BLACK\n"); 
		 break;
   case BLUE :   printf("BLUE\n");
		 break;
   case BROWN :  printf("BROWN\n");
		 break;
   case ECRUE :  printf("ECRUE\n");
		 break;
   case GOLD :   printf("GOLD\n");
		 break;
   case GRAY :   printf("GRAY\n");
		 break;
   case GREEN :  printf("GREEN\n");
		 break;
   case IVORY :  printf("IVORY\n");
		 break;
   case MAUVE :  printf("MAUVE\n");
		 break;
   case ORANGE : printf("ORANGE\n");
		 break;
   case PINK :   printf("PINK\n");
		 break;
   case PURPLE : printf("PURPLE\n");
		 break;
   case RED :    printf("RED\n");
		 break;
   case SILVER : printf("SILVER\n");
		 break;
   case TAN :    printf("TAN\n");
		 break;
   case VIOLET : printf("VIOLET\n");
		 break;
   case WHITE :  printf("WHITE\n");
		 break;
   case YELLOW : printf("YELLOW\n");
		 break;
 }
}
#ifdef PROTOTYPES
void print_char_array (char array_c[])
#else
void print_char_array ( array_c ) 
     char    array_c[];
#endif
{
  int index;
  printf("array_c :\n");
  printf("=========\n\n");
  for (index = 0; index < 120; index++) {
      printf("%1c", array_c[index]); 
      if ((index%50) == 0) printf("\n");
  }
  printf("\n\n");
}
#ifdef PROTOTYPES
void print_double_array (double  array_d[])
#else
void print_double_array (array_d) 
     double  array_d[];
#endif
{
  int index;
  printf("array_d :\n");
  printf("=========\n\n");
  for (index = 0; index < 9; index++) {
      printf("%f  ", array_d[index]); 
      if ((index%8) == 0) printf("\n");
  }
  printf("\n\n");
}
#ifdef PROTOTYPES
void print_float_array (float array_f[])
#else
void print_float_array ( array_f )
     float array_f[];
#endif
{
  int index;
  printf("array_f :\n");
  printf("=========\n\n");
  for (index = 0; index < 15; index++) {
      printf("%f  ", array_f[index]); 
      if ((index%8) == 0) printf("\n");
  }
  printf("\n\n");
}
#ifdef PROTOTYPES
void print_int_array (int array_i[])
#else
void print_int_array ( array_i )
     int array_i[];
#endif
{
  int index;
  printf("array_i :\n");
  printf("=========\n\n");
  for (index = 0; index < 50; index++) {
      printf("%d  ", array_i[index]); 
      if ((index%8) == 0) printf("\n");
  }
  printf("\n\n");
}
#ifdef PROTOTYPES
void print_all_arrays(int array_i[], char array_c[], float array_f[], double array_d[])
#else
void print_all_arrays( array_i, array_c, array_f, array_d )
     int array_i[];
     char array_c[];
     float array_f[];
     double array_d[];
#endif
{
  print_int_array(array_i);
  print_char_array(array_c);
  print_float_array(array_f);
  print_double_array(array_d);
}
void loop_count () {
     int index;
     for (index=0; index<4; index++);
}
#ifdef PROTOTYPES
void compute_with_small_structs (int seed)
#else
void compute_with_small_structs ( seed ) 
 int seed;
#endif
{
     struct small_rep_info_t array[4];
     int index;
     for (index = 0; index < 4; index++) {
         array[index].value = index*seed;
	 array[index].head = (index+1)*seed;
     }
     for (index = 1; index < 4; index++) {
	 array[index].value = array[index].value + array[index-1].value;
	 array[index].head = array[index].head + array[index-1].head;
     }
}
#ifdef PROTOTYPES
void init_bit_flags (struct bit_flags_t *bit_flags, unsigned a, unsigned b, unsigned g, unsigned d, unsigned e, unsigned o)
#else
void init_bit_flags ( bit_flags, a, b, g, d, e, o )
struct bit_flags_t *bit_flags;
unsigned a;
unsigned b;
unsigned g;
unsigned d;
unsigned e;
unsigned o; 
#endif
{
   bit_flags->alpha = a;
   bit_flags->beta = b;
   bit_flags->gamma = g;
   bit_flags->delta = d;
   bit_flags->epsilon = e;
   bit_flags->omega = o;
}
#ifdef PROTOTYPES
void init_bit_flags_combo (struct bit_flags_combo_t *bit_flags_combo, unsigned a, unsigned b, char ch1, unsigned g, unsigned d, char ch2, unsigned e, unsigned o)
#else
void init_bit_flags_combo ( bit_flags_combo, a, b, ch1, g, d, ch2, e, o )
     struct bit_flags_combo_t *bit_flags_combo;
     unsigned a;
     unsigned b;
     char     ch1;
     unsigned g;
     unsigned d;
     char     ch2;
     unsigned e;
     unsigned o; 
#endif
{
   bit_flags_combo->alpha = a;
   bit_flags_combo->beta = b;
   bit_flags_combo->ch1 = ch1;
   bit_flags_combo->gamma = g;
   bit_flags_combo->delta = d;
   bit_flags_combo->ch2 = ch2;
   bit_flags_combo->epsilon = e;
   bit_flags_combo->omega = o;
}
#ifdef PROTOTYPES
void init_one_double (struct one_double_t *one_double, double init_val)
#else
void init_one_double ( one_double, init_val )
     struct one_double_t *one_double;
     double init_val; 
#endif
{
     one_double->double1  = init_val;
}
#ifdef PROTOTYPES
void init_two_floats (struct two_floats_t *two_floats, float init_val1, float init_val2)
#else
void init_two_floats ( two_floats, init_val1, init_val2 )
     struct two_floats_t *two_floats; 
     float init_val1;
     float init_val2;
#endif
{
     two_floats->float1 = init_val1;
     two_floats->float2 = init_val2;
}
#ifdef PROTOTYPES
void init_two_chars (struct two_char_t *two_char, char init_val1, char init_val2)
#else
void init_two_chars ( two_char, init_val1, init_val2 )
     struct two_char_t *two_char;
     char init_val1;
     char init_val2; 
#endif
{
     two_char->ch1 = init_val1;
     two_char->ch2 = init_val2;
}
#ifdef PROTOTYPES
void init_three_chars (struct three_char_t *three_char, char init_val1, char init_val2, char init_val3)
#else
void init_three_chars ( three_char, init_val1, init_val2, init_val3 )  
     struct three_char_t *three_char; 
     char init_val1;
     char init_val2;
     char init_val3;
#endif
{
     three_char->ch1 = init_val1;
     three_char->ch2 = init_val2;
     three_char->ch3 = init_val3;
}
#ifdef PROTOTYPES
void init_five_chars (struct five_char_t *five_char, char init_val1, char init_val2, char init_val3, char init_val4, char init_val5)
#else
void init_five_chars ( five_char, init_val1, init_val2, init_val3,init_val4,init_val5 )
     struct five_char_t *five_char;
     char init_val1;
     char init_val2;
     char init_val3;
     char init_val4;
     char init_val5;
#endif
{
     five_char->ch1 = init_val1;
     five_char->ch2 = init_val2;
     five_char->ch3 = init_val3;
     five_char->ch4 = init_val4;
     five_char->ch5 = init_val5;
}
#ifdef PROTOTYPES
void init_int_char_combo (struct int_char_combo_t *combo, int init_val1, char init_val2)
#else
void init_int_char_combo ( combo, init_val1, init_val2 )
     struct int_char_combo_t *combo;
     int init_val1; 
     char init_val2; 
#endif
{
     combo->int1 = init_val1;
     combo->ch1 = init_val2;
}
#ifdef PROTOTYPES
void init_struct_rep(struct small_rep_info_t *small_struct, int seed)
#else
void init_struct_rep( small_struct, seed )
     struct small_rep_info_t *small_struct;
     int    seed;
#endif
{
      small_struct->value = 2 + (seed*2); 
      small_struct->head = 0; 
}
#ifdef PROTOTYPES
void init_small_structs (
     struct small_rep_info_t  *struct1,
     struct small_rep_info_t  *struct2,
     struct small_rep_info_t  *struct3,
     struct small_rep_info_t  *struct4,
     struct bit_flags_t       *flags,
     struct bit_flags_combo_t *flags_combo,
     struct three_char_t      *three_char,
     struct five_char_t       *five_char,
     struct int_char_combo_t  *int_char_combo,
     struct one_double_t      *d1,
     struct one_double_t      *d2,
     struct one_double_t      *d3,
     struct two_floats_t      *f1,
     struct two_floats_t      *f2,
     struct two_floats_t      *f3)
#else
void init_small_structs (struct1, struct2, struct3,struct4,flags,flags_combo,
three_char, five_char,int_char_combo, d1, d2,d3,f1,f2,f3)
     struct small_rep_info_t  *struct1;
     struct small_rep_info_t  *struct2;
     struct small_rep_info_t  *struct3;
     struct small_rep_info_t  *struct4;
     struct bit_flags_t       *flags;
     struct bit_flags_combo_t *flags_combo;
     struct three_char_t      *three_char;
     struct five_char_t       *five_char;
     struct int_char_combo_t  *int_char_combo;
     struct one_double_t      *d1;
     struct one_double_t      *d2;
     struct one_double_t      *d3;
     struct two_floats_t      *f1;
     struct two_floats_t      *f2;
     struct two_floats_t      *f3;
#endif
{
     init_bit_flags(flags, (unsigned)1, (unsigned)0, (unsigned)1, 
		           (unsigned)0, (unsigned)1, (unsigned)0 ); 
     init_bit_flags_combo(flags_combo, (unsigned)1, (unsigned)0, 'y',
				       (unsigned)1, (unsigned)0, 'n',
                    		       (unsigned)1, (unsigned)0 ); 
     init_three_chars(three_char, 'a', 'b', 'c');
     init_five_chars(five_char, 'l', 'm', 'n', 'o', 'p');
     init_int_char_combo(int_char_combo, 123, 'z');
     init_struct_rep(struct1, 2);
     init_struct_rep(struct2, 4);
     init_struct_rep(struct3, 5);
     init_struct_rep(struct4, 6);
     init_one_double ( d1, 10.5); 
     init_one_double ( d2, -3.375); 
     init_one_double ( d3, 675.09375); 
     init_two_floats ( f1, 45.234, 43.6); 
     init_two_floats ( f2, 78.01, 122.10); 
     init_two_floats ( f3, -1232.345, -199.21); 
}
#ifdef PROTOTYPES
void print_ten_doubles (
     double d1,
     double d2,
     double d3,
     double d4,
     double d5,
     double d6,
     double d7,
     double d8,
     double d9,
     double d10)
#else
void print_ten_doubles ( d1, d2, d3, d4, d5, d6, d7, d8, d9, d10 )
     double d1;
     double d2;
     double d3;
     double d4;
     double d5;
     double d6;
     double d7;
     double d8;
     double d9;
     double d10; 
#endif
{
  printf("Two Doubles : %f\t%f\n", d1, d2);
  printf("Two Doubles : %f\t%f\n", d3, d4);
  printf("Two Doubles : %f\t%f\n", d5, d6);
  printf("Two Doubles : %f\t%f\n", d7, d8);
  printf("Two Doubles : %f\t%f\n", d9, d10);
}
#ifdef PROTOTYPES
void print_bit_flags (struct bit_flags_t bit_flags)
#else
void print_bit_flags ( bit_flags )
struct bit_flags_t bit_flags;
#endif
{
     if (bit_flags.alpha) printf("alpha\n");
     if (bit_flags.beta) printf("beta\n");
     if (bit_flags.gamma) printf("gamma\n");
     if (bit_flags.delta) printf("delta\n");
     if (bit_flags.epsilon) printf("epsilon\n");
     if (bit_flags.omega) printf("omega\n");
}
#ifdef PROTOTYPES
void print_bit_flags_combo (struct bit_flags_combo_t bit_flags_combo)
#else
void print_bit_flags_combo ( bit_flags_combo )
     struct bit_flags_combo_t bit_flags_combo;
#endif
{
     if (bit_flags_combo.alpha) printf("alpha\n");
     if (bit_flags_combo.beta) printf("beta\n");
     if (bit_flags_combo.gamma) printf("gamma\n");
     if (bit_flags_combo.delta) printf("delta\n");
     if (bit_flags_combo.epsilon) printf("epsilon\n");
     if (bit_flags_combo.omega) printf("omega\n");
     printf("ch1: %c\tch2: %c\n", bit_flags_combo.ch1, bit_flags_combo.ch2);
}
#ifdef PROTOTYPES
void print_one_double (struct one_double_t one_double)
#else
void print_one_double ( one_double )
struct one_double_t one_double;
#endif
{
     printf("Contents of one_double_t: \n\n");
     printf("%f\n", one_double.double1);
}
#ifdef PROTOTYPES
void print_two_floats (struct two_floats_t two_floats)
#else
void print_two_floats ( two_floats )
struct two_floats_t two_floats; 
#endif
{
     printf("Contents of two_floats_t: \n\n");
     printf("%f\t%f\n", two_floats.float1, two_floats.float2);
}
#ifdef PROTOTYPES
void print_two_chars (struct two_char_t two_char)
#else
void print_two_chars ( two_char )
struct two_char_t two_char; 
#endif
{
     printf("Contents of two_char_t: \n\n");
     printf("%c\t%c\n", two_char.ch1, two_char.ch2);
}
#ifdef PROTOTYPES
void print_three_chars (struct three_char_t three_char)
#else
void print_three_chars ( three_char )
struct three_char_t three_char;
#endif
{
     printf("Contents of three_char_t: \n\n");
     printf("%c\t%c\t%c\n", three_char.ch1, three_char.ch2, three_char.ch3);
}
#ifdef PROTOTYPES
void print_five_chars (struct five_char_t five_char)
#else
void print_five_chars ( five_char ) 
struct five_char_t five_char; 
#endif
{
     printf("Contents of five_char_t: \n\n");
     printf("%c\t%c\t%c\t%c\t%c\n", five_char.ch1, five_char.ch2, 
				    five_char.ch3, five_char.ch4, 
				    five_char.ch5);
}
#ifdef PROTOTYPES
void print_int_char_combo (struct int_char_combo_t int_char_combo)
#else
void print_int_char_combo ( int_char_combo )
struct int_char_combo_t int_char_combo;
#endif
{
     printf("Contents of int_char_combo_t: \n\n");
     printf("%d\t%c\n", int_char_combo.int1, int_char_combo.ch1);
}     
#ifdef PROTOTYPES
void print_struct_rep(
     struct small_rep_info_t struct1,
     struct small_rep_info_t struct2,
     struct small_rep_info_t struct3)
#else
void print_struct_rep( struct1, struct2, struct3)
     struct small_rep_info_t struct1;
     struct small_rep_info_t struct2;
     struct small_rep_info_t struct3;
#endif
{
  printf("Contents of struct1: \n\n");
  printf("%10d%10d\n", struct1.value, struct1.head); 
  printf("Contents of struct2: \n\n");
  printf("%10d%10d\n", struct2.value, struct2.head); 
  printf("Contents of struct3: \n\n");
  printf("%10d%10d\n", struct3.value, struct3.head); 
}
#ifdef PROTOTYPES
void sum_struct_print (
     int seed,
     struct small_rep_info_t struct1,
     struct small_rep_info_t struct2, 
     struct small_rep_info_t struct3,
     struct small_rep_info_t struct4)
#else
void sum_struct_print ( seed, struct1, struct2, struct3, struct4) 
     int seed;
     struct small_rep_info_t struct1;
     struct small_rep_info_t struct2; 
     struct small_rep_info_t struct3; 
     struct small_rep_info_t struct4; 
#endif
{
     int sum;
     printf("Sum of the 4 struct values and seed : \n\n");
     sum = seed + struct1.value + struct2.value + struct3.value + struct4.value;
     printf("%10d\n", sum);
}
#ifdef PROTOTYPES
void print_small_structs (
     struct small_rep_info_t  struct1,
     struct small_rep_info_t  struct2,
     struct small_rep_info_t  struct3,
     struct small_rep_info_t  struct4,
     struct bit_flags_t       flags,
     struct bit_flags_combo_t flags_combo,
     struct three_char_t      three_char,
     struct five_char_t       five_char,
     struct int_char_combo_t  int_char_combo,
     struct one_double_t      d1,
     struct one_double_t      d2,
     struct one_double_t      d3,
     struct two_floats_t      f1,
     struct two_floats_t      f2,
     struct two_floats_t      f3)
#else
void print_small_structs ( struct1, struct2, struct3,  struct4, flags, 
flags_combo, three_char, five_char, int_char_combo, d1, d2,d3,f1,f2,f3)
     struct small_rep_info_t  struct1;
     struct small_rep_info_t  struct2;
     struct small_rep_info_t  struct3;
     struct small_rep_info_t  struct4;
     struct bit_flags_t       flags;
     struct bit_flags_combo_t flags_combo;
     struct three_char_t      three_char;
     struct five_char_t       five_char;
     struct int_char_combo_t  int_char_combo;
     struct one_double_t      d1;
     struct one_double_t      d2;
     struct one_double_t      d3;
     struct two_floats_t      f1;
     struct two_floats_t      f2;
     struct two_floats_t      f3;
#endif
{
   print_bit_flags(flags);
   print_bit_flags_combo(flags_combo);
   print_three_chars(three_char);
   print_five_chars(five_char);
   print_int_char_combo(int_char_combo);
   sum_struct_print(10, struct1, struct2, struct3, struct4);
   print_struct_rep(struct1, struct2, struct3);
   print_one_double(d1);
   print_one_double(d2);
   print_one_double(d3);
   print_two_floats(f1);
   print_two_floats(f2);
   print_two_floats(f3);
}
#ifdef PROTOTYPES
void print_long_arg_list (
     double a,
     double b,
     int c,
     int d,
     int e,
     int f,
     struct small_rep_info_t  struct1,
     struct small_rep_info_t  struct2,
     struct small_rep_info_t  struct3,
     struct small_rep_info_t  struct4,
     struct bit_flags_t       flags,
     struct bit_flags_combo_t flags_combo,
     struct three_char_t      three_char,
     struct five_char_t       five_char,
     struct int_char_combo_t  int_char_combo,
     struct one_double_t      d1,
     struct one_double_t      d2,
     struct one_double_t      d3,
     struct two_floats_t      f1,
     struct two_floats_t      f2,
     struct two_floats_t      f3)
#else
void print_long_arg_list ( a, b, c, d, e, f, struct1, struct2, struct3, 
struct4, flags, flags_combo, three_char, five_char, int_char_combo, d1,d2,d3,
f1, f2, f3 )
     double a;
     double b;
     int c;
     int d;
     int e;
     int f;
     struct small_rep_info_t  struct1;
     struct small_rep_info_t  struct2;
     struct small_rep_info_t  struct3;
     struct small_rep_info_t  struct4;
     struct bit_flags_t       flags;
     struct bit_flags_combo_t flags_combo;
     struct three_char_t      three_char;
     struct five_char_t       five_char;
     struct int_char_combo_t  int_char_combo;
     struct one_double_t      d1;
     struct one_double_t      d2;
     struct one_double_t      d3;
     struct two_floats_t      f1;
     struct two_floats_t      f2;
     struct two_floats_t      f3;
#endif
{
    printf("double : %f\n", a);
    printf("double : %f\n", b);
    printf("int : %d\n", c);
    printf("int : %d\n", d);
    printf("int : %d\n", e);
    printf("int : %d\n", f);
    print_small_structs( struct1, struct2, struct3, struct4, flags, flags_combo,
			 three_char, five_char, int_char_combo, d1, d2, d3, 
			 f1, f2, f3);
}
#ifdef PROTOTYPES
void print_one_large_struct (struct array_rep_info_t linked_list1)
#else
void print_one_large_struct( linked_list1 )
     struct array_rep_info_t linked_list1;
#endif
{
      printf("%10d%10d\n", linked_list1.values[0], 
			   linked_list1.next_index[0]); 
}
#ifdef PROTOTYPES
void print_array_rep(
     struct array_rep_info_t linked_list1,
     struct array_rep_info_t linked_list2,
     struct array_rep_info_t linked_list3)
#else
void print_array_rep( linked_list1, linked_list2, linked_list3 )
     struct array_rep_info_t linked_list1;
     struct array_rep_info_t linked_list2;
     struct array_rep_info_t linked_list3;
#endif
{
  int index;
  printf("Contents of linked list1: \n\n");
  printf("Element Value | Index of Next Element\n");
  printf("-------------------------------------\n");
  printf("              |                      \n");
  for (index = 0; index < 10; index++) {
      printf("%10d%10d\n", linked_list1.values[index], 
			   linked_list1.next_index[index]); 
  }
  printf("Contents of linked list2: \n\n");
  printf("Element Value | Index of Next Element\n");
  printf("-------------------------------------\n");
  printf("              |                      \n");
  for (index = 0; index < 10; index++) {
      printf("%10d%10d\n", linked_list2.values[index], 
			   linked_list2.next_index[index]); 
  }
  printf("Contents of linked list3: \n\n");
  printf("Element Value | Index of Next Element\n");
  printf("-------------------------------------\n");
  printf("              |                      \n");
  for (index = 0; index < 10; index++) {
      printf("%10d%10d\n", linked_list3.values[index], 
			   linked_list3.next_index[index]); 
  }
}
#ifdef PROTOTYPES
void sum_array_print (
     int seed,
     struct array_rep_info_t linked_list1,
     struct array_rep_info_t linked_list2,
     struct array_rep_info_t linked_list3,
     struct array_rep_info_t linked_list4)
#else
void sum_array_print ( seed, linked_list1, linked_list2, linked_list3,linked_list4)
     int seed;
     struct array_rep_info_t linked_list1;
     struct array_rep_info_t linked_list2;
     struct array_rep_info_t linked_list3;
     struct array_rep_info_t linked_list4;
#endif
{
     int index;
     int sum;
     printf("Sum of 4 arrays, by element (add in seed as well): \n\n");
     printf("Seed: %d\n", seed);
     printf("Element Index | Sum \n");
     printf("-------------------------\n");
     printf("              |          \n");
     for (index = 0; index < 10; index++) {
         sum = seed + linked_list1.values[index] + linked_list2.values[index] +
	       linked_list3.values[index] + linked_list4.values[index];
         printf("%10d%10d\n", index, sum);
     }
}
#ifdef PROTOTYPES
void init_array_rep(
     struct array_rep_info_t *linked_list,
     int    seed)
#else
void init_array_rep( linked_list, seed )
     struct array_rep_info_t *linked_list;
     int    seed;
#endif
{
  int index;
  for (index = 0; index < 10; index++) {
      linked_list->values[index] = (2*index) + (seed*2); 
      linked_list->next_index[index] = index + 1;
  }
  linked_list->head = 0; 
}
int main ()  {
  static char     char_array[121];
  static double   double_array[9];
  static float    float_array[15];
  static int      integer_array[50]; 
  static int      index;
  static id_int   student_id = 23;
  static colors   my_shirt = YELLOW;
  static int number = 10;
  static struct array_rep_info_t *list1;
  static struct array_rep_info_t *list2;
  static struct array_rep_info_t *list3;
  static struct array_rep_info_t *list4;
   static double                    a;
   static double                    b;
   static int                       c;
   static int                       d;
   static int                       e;
   static int                       f;
   static struct small_rep_info_t  *struct1;
   static struct small_rep_info_t  *struct2;
   static struct small_rep_info_t  *struct3;
   static struct small_rep_info_t  *struct4;
   static struct bit_flags_t       *flags;
   static struct bit_flags_combo_t *flags_combo;
   static struct three_char_t      *three_char;
   static struct five_char_t       *five_char;
   static struct int_char_combo_t  *int_char_combo;
   static struct one_double_t      *d1;
   static struct one_double_t      *d2;
   static struct one_double_t      *d3;
   static struct two_floats_t      *f1;
   static struct two_floats_t      *f2;
   static struct two_floats_t      *f3;
  for (index = 0; index < 120; index++) {
      if ((index%2) == 0) char_array[index] = 'Z';
	 else char_array[index] = 'a';
  }
  char_array[120] = '\0';
  for (index = 0; index < 9; index++) {
      double_array[index] = index*23.4567;
  }
  for (index = 0; index < 15; index++) {
      float_array[index] = index/7.02;
  }
  for (index = 0; index < 50; index++) {
      integer_array[index] = -index;
  }
  print_char_array(char_array);
  print_double_array(double_array);
  print_float_array(float_array);
  print_student_id_shirt_color(student_id, my_shirt); 
  print_int_array(integer_array);
  print_all_arrays(integer_array, char_array, float_array, double_array);
  list1 = (struct array_rep_info_t *)malloc(sizeof(struct array_rep_info_t));
  list2 = (struct array_rep_info_t *)malloc(sizeof(struct array_rep_info_t));
  list3 = (struct array_rep_info_t *)malloc(sizeof(struct array_rep_info_t));
  list4 = (struct array_rep_info_t *)malloc(sizeof(struct array_rep_info_t));
  init_array_rep(list1, 2);
  init_array_rep(list2, 4);
  init_array_rep(list3, 5);
  init_array_rep(list4, 10);
  printf("HELLO WORLD\n");
  printf("BYE BYE FOR NOW\n");
  printf("VERY GREEN GRASS\n");
  sum_array_print(10, *list1, *list2, *list3, *list4);
  print_array_rep(*list1, *list2, *list3);
  print_one_large_struct(*list1);
  struct1     = (struct small_rep_info_t  *)malloc(sizeof(struct small_rep_info_t));
  struct2     = (struct small_rep_info_t  *)malloc(sizeof(struct small_rep_info_t));
  struct3     = (struct small_rep_info_t  *)malloc(sizeof(struct small_rep_info_t));
  struct4     = (struct small_rep_info_t  *)malloc(sizeof(struct small_rep_info_t));
  flags       = (struct bit_flags_t *)malloc(sizeof(struct bit_flags_t));
  flags_combo = (struct bit_flags_combo_t *)malloc(sizeof(struct bit_flags_combo_t));
  three_char  = (struct three_char_t *)malloc(sizeof(struct three_char_t));
  five_char   = (struct five_char_t *)malloc(sizeof(struct five_char_t));
  int_char_combo = (struct int_char_combo_t *)malloc(sizeof(struct int_char_combo_t));
  d1 = (struct one_double_t *)malloc(sizeof(struct one_double_t));
  d2 = (struct one_double_t *)malloc(sizeof(struct one_double_t));
  d3 = (struct one_double_t *)malloc(sizeof(struct one_double_t));
  f1 = (struct two_floats_t *)malloc(sizeof(struct two_floats_t));
  f2 = (struct two_floats_t *)malloc(sizeof(struct two_floats_t));
  f3 = (struct two_floats_t *)malloc(sizeof(struct two_floats_t));
  init_small_structs ( struct1, struct2, struct3, struct4, flags, 
		       flags_combo, three_char, five_char, int_char_combo,
		       d1, d2, d3, f1, f2, f3);
  print_small_structs ( *struct1, *struct2, *struct3, *struct4, *flags, 
			*flags_combo, *three_char, *five_char, *int_char_combo,
			*d1, *d2, *d3, *f1, *f2, *f3);
  a = 22.25;
  b = 33.375;
  c = 0;
  d = -25;
  e = 100;
  f = 2345;
  print_long_arg_list ( a, b, c, d, e, f, *struct1, *struct2, *struct3, *struct4, 
			*flags, *flags_combo, *three_char, *five_char, *int_char_combo,
			*d1, *d2, *d3, *f1, *f2, *f3);
  init_one_double ( d1, 1.11111); 
  init_one_double ( d2, -345.34); 
  init_one_double ( d3, 546464.2); 
  init_two_floats ( f1, 0.234, 453.1); 
  init_two_floats ( f2, 78.345, 23.09); 
  init_two_floats ( f3, -2.345, 1.0); 
  init_bit_flags(flags, (unsigned)1, (unsigned)0, (unsigned)1, 
		 (unsigned)0, (unsigned)1, (unsigned)0 ); 
  init_bit_flags_combo(flags_combo, (unsigned)1, (unsigned)0, 'y',
				     (unsigned)1, (unsigned)0, 'n',
				     (unsigned)1, (unsigned)0 ); 
  init_three_chars(three_char, 'x', 'y', 'z');
  init_five_chars(five_char, 'h', 'e', 'l', 'l', 'o');
  init_int_char_combo(int_char_combo, 13, '!');
  init_struct_rep(struct1, 10);
  init_struct_rep(struct2, 20);
  init_struct_rep(struct3, 30);
  init_struct_rep(struct4, 40);
  compute_with_small_structs(35);
  loop_count();
  printf("HELLO WORLD\n");
  printf("BYE BYE FOR NOW\n");
  printf("VERY GREEN GRASS\n");
  print_one_double(*d1);
  print_one_double(*d2);
  print_one_double(*d3);
  print_two_floats(*f1);
  print_two_floats(*f2);
  print_two_floats(*f3);
  print_bit_flags(*flags);
  print_bit_flags_combo(*flags_combo);
  print_three_chars(*three_char);
  print_five_chars(*five_char);
  print_int_char_combo(*int_char_combo);
  sum_struct_print(10, *struct1, *struct2, *struct3, *struct4);
  print_struct_rep(*struct1, *struct2, *struct3);
  return 0;
}