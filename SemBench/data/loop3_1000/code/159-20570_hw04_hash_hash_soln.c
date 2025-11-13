#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    enum Type {INT, STRING} type;
    union {
	int i;
	char *s;
    };
} Value;
Value *make_int_value(int i) 
{
    Value *value = (Value *) malloc (sizeof (Value));
    value->type = INT;
    value->i = i;
    return value;
}
Value *make_string_value(char *s) 
{
    Value *value = (Value *) malloc (sizeof (Value));
    value->type = STRING;
    value->s = s;
    return value;
}
void print_value (Value *value) 
{
    if (value == NULL) {
	printf ("%p", value);
	return;
    }
    switch (value->type) {
    case INT:
	printf ("%d", value->i);
	break;
    case STRING:
	printf ("%s", value->s);
	break;
    }
}
typedef struct {
    void *key;
    int (*hash) (void *);
    int (*equal) (void *, void *);
} Hashable;
Hashable *make_hashable(void *key, 
			int (*hash) (void *),
			int (*equal) (void *, void *)
			)
{
    Hashable *hashable = (Hashable *) malloc (sizeof (Hashable));
    hashable->key = key;
    hashable->hash = hash;
    hashable->equal = equal;
    return hashable;
}
void print_hashable(Hashable *hashable)
{
    printf ("key %p\n", hashable->key);
    printf ("hash %p\n", hashable->hash);
}
int hash_int(void *p)
{
    return *(int *)p;
}
int hash_string(void *p)
{
    char *s = (char *) p;
    int total = 0;
    int i = 0;
    while (s[i] != 0) {
	total += s[i];
	i++;
    }
    return total;
}
int hash_hashable(Hashable *hashable)
{
    return hashable->hash (hashable->key);
}
int equal_int (void *ip, void *jp)
{
    return *(int *)ip == *(int *)jp;
}
int equal_string (void *s1, void *s2)
{
    int x = strcmp ((char *) s1, (char *) s2);
    return (x == 0);
}
int equal_hashable(Hashable *h1, Hashable *h2)
{
    if (h1->equal != h2->equal) return 0;
    return h1->equal(h1->key, h2->key);
}
Hashable *make_hashable_int (int x)
{
    int *p = (int *) malloc (sizeof (int));
    *p = x;
    return make_hashable((void *) p, hash_int, equal_int);
}
Hashable *make_hashable_string (char *s)
{
    return make_hashable((void *) s, hash_string, equal_string);
}
typedef struct node {
    Hashable *key;
    Value *value;
    struct node *next;
} Node;
Node *make_node(Hashable *key, Value *value, Node *next)
{
    Node *node = (Node *) malloc (sizeof (Node));
    node->key = key;
    node->value = value;
    node->next = next;
    return node;
}
void print_node(Node *node)
{
    print_hashable(node->key);
    printf ("value %p\n", node->value);
    printf ("next %p\n", node->next);
}
void print_list(Node *node)
{
    if (node == NULL) {
	return;
    }
    print_hashable(node->key);
    printf ("value %p\n", node->value);
    print_list(node->next);
}
Node *prepend(Hashable *key, Value *value, Node *rest)
{
    return make_node(key, value, rest);
}
Value *list_lookup(Node *list, Hashable *key)
{
    Node *node;
    for (node = list; node != NULL; node = node->next) {
	if (equal_hashable(key, node->key)) {
	    return node->value;
	}
    }
    return NULL;
}
typedef struct map {
    int n;
    Node **lists;
} Map;
Map *make_map(int n)
{
    int i;
    Map *map = (Map *) malloc (sizeof (Map));
    map->n = n;
    map->lists = (Node **) malloc (sizeof (Node *) * n);
    for (i=0; i<n; i++) {
	map->lists[i] = NULL;
    }
    return map;
}
void print_map(Map *map)
{
    int i;
    for (i=0; i<map->n; i++) {
	if (map->lists[i] != NULL) {
	    printf ("%d\n", i);
	    print_list (map->lists[i]);
	}
    }
}
void map_add(Map *map, Hashable *key, Value *value)
{
    int hashval = hash_hashable(key) % map->n;
    Node *list = map->lists[hashval];
    map->lists[hashval] = prepend(key, value, list);
}
Value *map_lookup(Map *map, Hashable *key)
{
    int hashval = hash_hashable(key) % map->n;
    Node *list = map->lists[hashval];
    return list_lookup(list, key);
}
void print_lookup(Value *value)
{
    printf ("Lookup returned ");
    print_value (value);
    printf ("\n");
}
int main ()
{
    Hashable *hashable1 = make_hashable_int (1);
    Hashable *hashable2 = make_hashable_string ("Allen");
    Hashable *hashable3 = make_hashable_int (2);
    Value *value1 = make_int_value (17);
    Node *node1 = make_node(hashable1, value1, NULL);
    print_node (node1);
    Value *value2 = make_string_value ("Downey");
    Node *list = prepend(hashable2, value2, node1);
    print_list (list);
    Value *value = list_lookup (list, hashable1);
    print_lookup(value);
    value = list_lookup (list, hashable2);
    print_lookup(value);
    value = list_lookup (list, hashable3);
    print_lookup(value);
    Map *map = make_map(10);
    map_add(map, hashable1, value1);
    map_add(map, hashable2, value2);
    printf ("Map\n");
    print_map(map);
    value = map_lookup(map, hashable1);
    print_lookup(value);
    value = map_lookup(map, hashable2);
    print_lookup(value);
    value = map_lookup(map, hashable3);
    print_lookup(value);
    return 0;
}