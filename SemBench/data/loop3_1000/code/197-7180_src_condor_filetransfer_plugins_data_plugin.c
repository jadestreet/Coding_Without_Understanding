#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int decode_block(unsigned char *in, unsigned char *out) {
	unsigned char *c = in;
	int i = 0, j = 0;
	char temp[4];
	while(i < 4 && c && *c) {
		if(*c != ' ') {	
			if(*c == '+') {
				temp[i] = 62;
			} else if(*c == '/') {
				temp[i] = 63;
			} else if(*c == '=') {
				temp[i] = 0;	
			} else if(*c >= '0' && *c <= '9') {
				temp[i] = *c + 4;
			} else if(*c >= 'A' && *c <= 'Z') {
				temp[i] = *c - 65;
			} else if(*c >= 'a' && *c <= 'z') {
				temp[i] = *c - 71;
			} else if(*c == ' ') {
				j++;
			} else {
				break;	
			}
			i++;
		}
		j++;
		c++;
	}
	out[0] = (temp[0] << 2) + (temp[1] >> 4);
	out[1] = (temp[1] << 4) + (temp[2] >> 2);
	out[2] = (temp[2] << 6) + (temp[3] >> 0);
	return j;	
}
int main(int argc, char **argv) {
	char *c = NULL, *d = NULL, *data = NULL, *dest = NULL, *lastslash = NULL;
	unsigned char out[4];
	char hex[2];
	FILE *file = NULL;
	int base64 = 0, rval = -1;
    if(argc == 2 && strcmp(argv[1], "-classad") == 0) {
		printf("%s",
			"PluginVersion = \"0.1\"\n"
			"PluginType = \"FileTransfer\"\n"
			"SupportedMethods = \"data\"\n"
			);
        return 0;
    }
    if(argc != 3) {
		return -1;
	}
	data = strchr(argv[1], ',');
	lastslash = strrchr(argv[1], '/');
	dest = argv[2];
	if(data && lastslash && (file = fopen(dest, "w"))) {
		rval = 4;
		c = argv[1];
		d = NULL;
		do {
			d = strchr(c, ';');
			if(d && d < data) {
				base64 = !strncmp(d, ";base64,", 7);
				c = d+1;
			} else {
				break;
			}
		} while(!base64);
		c = data+1;
		if(base64) {
			out[3] = '\0';
			while(c && *c && c+3 < lastslash && rval >= 4) {
				rval = decode_block((unsigned char*)c, out);
				fputs((char*)out, file);
				c+=rval;
			}
			if(c < lastslash) {
				rval = -1;
			}
		} else {
			while(c && *c && *c != '/') {
				if(*c == '%') {
					c++;
					strncpy(hex, c, 2);
					fputc(strtol(hex, NULL, 16), file);
					c++;
				} else {
					fputc(*c, file);
				}
				c++;
			}
		}
		fclose(file);
		if(rval < 4) {
			remove(dest);	
		} else {
			rval = 0;
		}
	}
	return rval;	
}