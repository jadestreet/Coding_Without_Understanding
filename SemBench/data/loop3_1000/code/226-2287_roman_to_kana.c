#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned int table[] = {
			0xffe38181, 
			0xffe38182, 
			0xffe38183, 
			0xffe38184, 
			0xffe38185, 
			0xffe38186, 
			0xffe38187, 
			0xffe38188, 
			0xffe38189, 
			0xffe3818a, 
			0xffe3818b, 
			0xffe3818c, 
			0xffe3818d, 
			0xffe3818e, 
			0xffe3818f, 
			0xffe38190, 
			0xffe38191, 
			0xffe38192, 
			0xffe38193, 
			0xffe38194, 
			0xffe38195, 
			0xffe38196, 
			0xffe38197, 
			0xffe38198, 
			0xffe38199, 
			0xffe3819a, 
			0xffe3819b, 
			0xffe3819c, 
			0xffe3819d, 
			0xffe3819e, 
			0xffe3819f, 
			0xffe381a0, 
			0xffe381a1, 
			0xffe381a2, 
			0xffe381a3, 
			0xffe381a4, 
			0xffe381a5, 
			0xffe381a6, 
			0xffe381a7, 
			0xffe381a8, 
			0xffe381a9, 
			0xffe381aa, 
			0xffe381ab, 
			0xffe381ac, 
			0xffe381ad, 
			0xffe381ae, 
			0xffe381af, 
			0xffe381b0, 
			0xffe381b1, 
			0xffe381b2, 
			0xffe381b3, 
			0xffe381b4, 
			0xffe381b5, 
			0xffe381b6, 
			0xffe381b7, 
			0xffe381b8, 
			0xffe381b9, 
			0xffe381ba, 
			0xffe381bb, 
			0xffe381bc, 
			0xffe381bd, 
			0xffe381be, 
			0xffe381bf, 
			0xffe38280, 
			0xffe38281, 
			0xffe38282, 
			0xffe38283, 
			0xffe38284, 
			0xffe38285, 
			0xffe38286, 
			0xffe38287, 
			0xffe38288, 
			0xffe38289, 
			0xffe3828a, 
			0xffe3828b, 
			0xffe3828c, 
			0xffe3828d, 
			0xffe3828e, 
			0xffe3828f, 
			0xffe38290, 
			0xffe38291, 
			0xffe38292, 
			0xffe38293, 
			0xffe382a1, 
			0xffe382a2, 
			0xffe382a3, 
			0xffe382a4, 
			0xffe382a5, 
			0xffe382a6, 
			0xffe382a7, 
			0xffe382a8, 
			0xffe382a9, 
			0xffe382aa, 
			0xffe382ab, 
			0xffe382ac, 
			0xffe382ad, 
			0xffe382ae, 
			0xffe382af, 
			0xffe382b0, 
			0xffe382b1, 
			0xffe382b2, 
			0xffe382b3, 
			0xffe382b4, 
			0xffe382b5, 
			0xffe382b6, 
			0xffe382b7, 
			0xffe382b8, 
			0xffe382b9, 
			0xffe382ba, 
			0xffe382bb, 
			0xffe382bc, 
			0xffe382bd, 
			0xffe382be, 
			0xffe382bf,  
			0xffe38380, 
			0xffe38381, 
			0xffe38382, 
			0xffe38383, 
			0xffe38384, 
			0xffe38385, 
			0xffe38386, 
			0xffe38387, 
			0xffe38388, 
			0xffe38389, 
			0xffe3838a, 
			0xffe3838b, 
			0xffe3838c, 
			0xffe3838d, 
			0xffe3838e, 
			0xffe3838f, 
			0xffe38390, 
			0xffe38391, 
			0xffe38392, 
			0xffe38393, 
			0xffe38394, 
			0xffe38395, 
			0xffe38396, 
			0xffe38397, 
			0xffe38398, 
			0xffe38399, 
			0xffe3839a, 
			0xffe3839b, 
			0xffe3839c, 
			0xffe3839d, 
			0xffe3839e, 
			0xffe3839f, 
			0xffe383a0, 
			0xffe383a1, 
			0xffe383a2, 
			0xffe383a3, 
			0xffe383a4, 
			0xffe383a5, 
			0xffe383a6, 
			0xffe383a7, 
			0xffe383a8, 
			0xffe383a9, 
			0xffe383aa, 
			0xffe383ab, 
			0xffe383ac, 
			0xffe383ad, 
			0xffe383ae, 
			0xffe383af, 
			0xffe383b0, 
			0xffe383b1, 
			0xffe383b2, 
			0xffe383b3, 
			0xffe383b4, 
			0xffe383b5, 
			0xffe383b6 
	};
int my_strlen_utf8_c(char *s) {
   int i = 0, j = 0;
   while (s[i]) {
     if ((s[i] & 0xc0) != 0x80)
    	 j++;
    	 i++;
   }
   return j;
}
void shift(unsigned int *wide) {
	int count = 0;
	int flag = 0;
	while (wide[count]) {
		if (flag) {
			wide[count -1] = wide[count];
		}
		if (wide[count] == 0xffffffff) {
			flag = 1;
		}
		count++;
	}
	if (flag) {
		wide[count-1] = '\0';
		shift(wide);
	}
}
void set(unsigned int *wide, int count, unsigned int value, int del) {
	wide[count] = value;
	for (del = del; del > 0; del--) {
		wide[count + del] = 0xffffffff;
	}
	shift(wide);
}
void THREE(unsigned int *wide, int count, unsigned int kotomi) {
	switch (wide[count + 2]) {
		case 'A':
			set(wide, count, kotomi, 0); 
			set(wide, count + 1, table[66], 1); 
			break;
		case 'O':
			set(wide, count, kotomi, 0); 
			set(wide, count + 1, table[70], 1); 
			break;
		case 'U':
			set(wide, count, kotomi, 0); 
			set(wide, count + 1, table[68], 1); 
			break;
		case 'I':
			set(wide, count, kotomi, 2); 
			break;
	}
}
void AEIOU(unsigned int *wide, int count, unsigned int a, unsigned int e, unsigned int i, unsigned int o, unsigned int u) {
	switch (wide[count + 1]) {
		case 'A':
			if (a > 0) {
				set(wide, count, a, 1);
			}
			break;
		case 'E':
			if (e > 0) {
				set(wide, count, e, 1);
			}
			break;
		case 'I':
			if (i > 0) {
				set(wide, count, i, 1);
			}
			break;
		case 'Y':
			if (i > 0) {
				THREE(wide, count, i);
			}
			break;
		case 'O':
			if (o > 0) {
				set(wide, count, o, 1);
			}
			break;
		case 'U':
			if (u > 0) {
				set(wide, count, u, 1);
			}
			break;
		case 'S':
			if (wide[count + 2] == 'U') {
				set(wide, count, table[119], 2); 
			}
		break;
	}
}
void AEIOU_h(unsigned int *wide, int count, unsigned int a, unsigned int e, unsigned int i, unsigned int o, unsigned int u, unsigned int h) {
	if (wide[count + 1] == 'H') {
			THREE(wide, count, h);
	} else {
		AEIOU(wide, count, a, e, i, o, u);
	}
}
void three(unsigned int *wide, int count, unsigned int kotomi) {
	switch (wide[count + 2]) {
		case 'a':
			set(wide, count, kotomi, 0); 
			set(wide, count + 1, table[66], 1); 
			break;
		case 'o':
			set(wide, count, kotomi, 0); 
			set(wide, count + 1, table[70], 1); 
			break;
		case 'u':
			set(wide, count, kotomi, 0); 
			set(wide, count + 1, table[68], 1); 
			break;
		case 'i':
			set(wide, count, kotomi, 2); 
			break;
	}
}
void aeiou(unsigned int *wide, int count, unsigned int a, unsigned int e, unsigned int i, unsigned int o, unsigned int u) {
	switch (wide[count + 1]) {
	case 'a':
		if (a > 0) {
			set(wide, count, a, 1);
		}
		break;
	case 'e':
		if (e > 0) {
			set(wide, count, e, 1);
		}
		break;
	case 'i':
		if (i > 0) {
			set(wide, count, i, 1);
		}
		break;
	case 'y':
		if (i > 0) {
			three(wide, count, i);
		}
		break;
	case 'o':
		if (o > 0) {
			set(wide, count, o, 1);
		}
		break;
	case 'u':
		if (u > 0) {
			set(wide, count, u, 1);
		}
		break;
	case 's':
		if (wide[count + 2] == 'u') {
			set(wide, count, table[35], 2); 
		}
	break;
	}
}
void aeiou_h(unsigned int *wide, int count, unsigned int a, unsigned int e, unsigned int i, unsigned int o, unsigned int u, unsigned int h) {
	if (wide[count + 1] == 'h') {
			three(wide, count, h);
	} else {
		aeiou(wide, count, a, e, i, o, u);
	}
}
void to_wide(char * input, unsigned int *wide) {
	int count = 0;
	int count_2 = 0;
	while(input[count]) {
		if (input[count] > 0) {
			wide[count_2] = input[count];
			count++;
		} else {
			wide[count_2] = (0x10000 * (input[count] + 1)) + (0x100 * (input[count+1] + 1)) + (0x1 * input[count+2]);
			count +=3;
		}
		count_2++;
	}
}
void to_uni(char *output, unsigned int *wide) {
	int count = 0;
	int count_2 = 0;
	while (wide[count]) {
		if (wide[count] < 0xff) {
			output[count_2] = wide[count];
		} else {
			output[count_2] = (((wide[count] - 0xff000000 ) / 0x10000) % 0x100);
			output[++count_2] = (((wide[count] - 0xff000000 ) / 0x100) % 0x100);
			output[++count_2] =   (wide[count] - 0xff000000 ) % 0x100;
		}
		count_2++;
		count++;
	}
}
char * convert(char *input) {
	int size = (strlen(input) * 3) + 1;
	unsigned int * wide;
	wide = malloc(size * sizeof(unsigned int));
	to_wide(input, wide);
	int count = 0;
	while (wide[count]) {
		switch (wide[count]) {
		case 'k':
			aeiou(wide, count, table[10], table[16], table[12], table[18], table[14]);
			break;
		case 'g':
			aeiou(wide, count, table[11], table[17], table[13], table[19], table[15]);
			break;
		case 's':
			aeiou_h(wide, count, table[20], table[26], 0, table[28], table[24], table[22]);
			break;
		case 'z':
			aeiou(wide, count, table[21], table[27], 0, table[29], table[25]);
			break;
		case 'j':
			aeiou(wide, count, 0, 0, table[23], 0, 0);
			break;
		case 't':
			aeiou(wide, count, table[30], table[37], 0, table[39], 0);
			break;
		case 'c':
			if (wide[count + 1] == 'h') {
				three(wide, count, table[32]); 
			}
			break;
		case 'd':
			aeiou(wide, count, table[31], table[38], 0, table[40], 0);
			break;
		case 'n':
			if (wide[count + 1] != 'a' && wide[count + 1] != 'e' && wide[count + 1] != 'i' && wide[count + 1] != 'o' && wide[count + 1] != 'u') {
				set(wide, count, table[82], 0);
			}
			aeiou(wide, count, table[41], table[44], table[42], table[45], table[43]);
			break;
		case 'm':
			aeiou(wide, count, table[61], table[64], table[62], table[65], table[63]);
			break;
		case 'h':
			aeiou(wide, count, table[46], table[55], table[49], table[58], 0);
			break;
		case 'b':
			aeiou(wide, count, table[47], table[56], table[50], table[59], table[53]);
			break;
		case 'p':
			aeiou(wide, count, table[48], table[57], table[51], table[60], table[54]);
			break;
		case 'r':
			aeiou(wide, count, table[72], table[75], table[73], table[76], table[74]);
			break;
		case 'y':
			aeiou(wide, count, table[72], 0, 0, table[71], table[69]);
			break;
		case 'f':
			aeiou(wide, count, 0, 0, 0, 0, table[52]);
			break;
		case 'w':
			aeiou(wide, count, table[78], 0, 0, table[81], 0);
			break;
		case 'a':
			set(wide, count, table[1], 0);
			break;
		case 'e':
			set(wide, count, table[7], 0);
			break;
		case 'i':
			set(wide, count, table[3], 0);
			break;
		case 'o':
			set(wide, count, table[9], 0);
			break;
		case 'u':
			set(wide, count, table[5], 0);
			break;
		case 'K':
			AEIOU(wide, count, table[93], table[99], table[95], table[101], table[97]);
			break;
		case 'G':
			AEIOU(wide, count, table[94], table[100], table[96], table[102], table[98]);
			break;
		case 'S':
			AEIOU_h(wide, count, table[103], table[109], 0, table[111], table[107], table[105]);
			break;
		case 'Z':
			AEIOU(wide, count, table[104], table[110], 0, table[112], table[108]);
			break;
		case 'J':
			AEIOU(wide, count, 0, 0, table[106], 0, 0);
			break;
		case 'T':
			AEIOU(wide, count, table[113], table[120], 0, table[122], 0);
			break;
		case 'C':
			if (wide[count + 1] == 'h') {
				THREE(wide, count, table[115]); 
			}
			break;
		case 'D':
			AEIOU(wide, count, table[114], table[121], 0, table[123], 0);
			break;
		case 'N':
			AEIOU(wide, count, table[124], table[127], table[125], table[128], table[126]);
			break;
		case 'M':
			AEIOU(wide, count, table[144], table[147], table[145], table[148], table[146]);
			break;
		case 'H':
			AEIOU(wide, count, table[129], table[138], table[132], table[141], 0);
			break;
		case 'B':
			AEIOU(wide, count, table[130], table[139], table[133], table[142], table[136]);
			break;
		case 'P':
			AEIOU(wide, count, table[131], table[140], table[134], table[143], table[137]);
			break;
		case 'R':
			AEIOU(wide, count, table[155], table[158], table[156], table[159], table[157]);
			break;
		case 'Y':
			AEIOU(wide, count, table[150], 0, 0, table[154], table[152]);
			break;
		case 'F':
			AEIOU(wide, count, 0, 0, 0, 0, table[135]);
			break;
		case 'W':
			AEIOU(wide, count, table[161], 0, 0, table[164], 0);
			break;
		case 'A':
			set(wide, count, table[84], 0);
			break;
		case 'E':
			set(wide, count, table[90], 0);
			break;
		case 'I':
			set(wide, count, table[86], 0);
			break;
		case 'O':
			set(wide, count, table[92], 0);
			break;
		case 'U':
			set(wide, count, table[88], 0);
			break;
		default:
			break;
		}
		if (wide[count] == wide[count + 1]) {
			set(wide, count, table[34], 0);
		}
		count++;
	}
	shift(wide);
	char *output = '\0';
	output = malloc((((size - 1) / 3) + 1) * sizeof(char));
	to_uni(output, wide);
	free(wide);
	return output;
}
int main(int argc, char *argv[]) {
	char * output;
	output = convert(argv[1]);
	printf("%s\n",  output);
}