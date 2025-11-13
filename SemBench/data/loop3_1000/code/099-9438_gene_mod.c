#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SEQUENCE_SIZE 1000
#define WINDOW_SIZE 12
typedef struct {
	size_t len;
	char *data;
	size_t pos;
} Sequence;
Sequence *Sequence_new(size_t len)
{
	assert(len % 4 == 0);
	Sequence *o = malloc(sizeof(*o));
	assert(o);
	o->len = len;
	o->pos = len / 2;
	o->data = malloc(len * sizeof(*o->data));
	assert(o->data);
	for (int i = 0; i < len;) {
		o->data[i++] = 'A';
		o->data[i++] = 'T';
		o->data[i++] = 'G';
		o->data[i++] = 'C';
	}
	return o;
}
typedef void (*Sequence_op)(Sequence *o);
void Sequence_x2y(Sequence *o, char x, char y)
{
	for (int i = 0; i < o->len; i++) {
		if (o->data[i] == x) {
			o->data[i] = y;
 		}
	}
}
void a2t(Sequence *o) {
	Sequence_x2y(o, 'A', 'T');
}
void t2g(Sequence *o) {
	Sequence_x2y(o, 'T', 'G');
}
void g2c(Sequence *o) {
	Sequence_x2y(o, 'G', 'C');
}
void c2a(Sequence *o) {
	Sequence_x2y(o, 'C', 'A');
}
void shl(Sequence *o) {
	o->pos--;
	assert(o->pos >= 0);
}
void shr(Sequence *o) {
	o->pos++;
	assert(o->pos + WINDOW_SIZE < o->len);
}
Sequence_op ops[] = {a2t, t2g, g2c, c2a, shl, shr};
void Sequence_printWindow(Sequence *o)
{
	for (int i = o->pos; i < o->pos + WINDOW_SIZE; i++) {
		printf("%c", o->data[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	Sequence *s = Sequence_new(1000);
	Sequence_printWindow(s);
	for (int i = 0; i < 100; i++) {
		ops[rand() % 6](s);
		Sequence_printWindow(s);
	}
	return 0;
}