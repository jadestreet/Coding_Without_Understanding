#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct elem {
	struct node *node;
	struct elem *next;
	struct elem *prev;
};
struct queue {
	struct elem *first;
	struct elem *last;
	unsigned int size;
};
struct node {
	char c;
	struct node * children[4];	
	struct node *next;		
	unsigned char end;		
	struct node *parent;		
	struct node *fail;
};
struct queue * queue_add(struct queue *queue, struct node *node)
{
	struct elem *elem;
	elem = calloc(1, sizeof(struct elem));
	elem->node = node;
	queue->size++;
	if (!queue->first) {
		queue->first = elem;
		queue->last = elem;
		return queue;
	}
	queue->first->prev = elem;
	elem->next = queue->first;
	queue->first = elem;
	return queue;
}
struct node * queue_dequeue(struct queue *queue)
{
	struct elem *elem;
	struct node *ret;
	elem = queue->last;
	queue->last = queue->last->prev;
	queue->size--;
	ret = elem->node;
	free(elem);
	return ret;
}
struct node * get_child(struct node *node, char c)
{
	struct node *child = NULL;
	if (node->children[c % 4]) {
		child = node->children[c % 4];
		while (child) {
			if (child->c == c)
				return child;
			child = child->next;
		}
	}
	return child;
}
void add_word(struct node *root, char *word)
{
	struct node *curnode;
	struct node *tmp;
	unsigned int i;
	curnode = root;
	i = 0;
	while (word[i]) {
		if (tmp = get_child(curnode, word[i])) {
			curnode = tmp;
		} else {
			tmp = calloc(1, sizeof(struct node));
			tmp->c = word[i];
			tmp->parent = curnode;
			tmp->fail = root;
			if (word[i + 1] == 0)
				tmp->end = 1;
			if (curnode->children[word[i] % 4]) {
				curnode = curnode->children[word[i] % 4];
				while (curnode->next) {
					curnode = curnode->next;
				}
				curnode->next = tmp;
			} else {
				curnode->children[word[i] % 4] = tmp;
			}
		}
		i++;
		curnode = tmp;
	}
}
void make_fail(struct node *root)
{
	struct queue *queue;
	struct node *node, *tmp, *fail;
	int i;
	root->fail = root;
	queue = calloc(1, sizeof(struct queue));
	queue = queue_add(queue, root);
	while (queue->size) { 
		node = queue_dequeue(queue);
		for (i = 0; i < 4; i++) {
			tmp = node->children[i];
			if (!tmp)
				continue;
			while (tmp->next) {
				queue_add(queue, tmp);
				tmp = tmp->next;
			}
		}
		if (node == root)
			continue;
		fail = node->parent->fail;
		while (get_child(fail, node->c) == NULL && fail != root)
			fail = fail->fail;
		node->fail = get_child(fail, node->c);
		if (node->fail == NULL)	
			node->fail = root;
		if (node->fail == node)
			node->fail = root;
	}
}
unsigned int exists(struct node *root, char *word)
{
	struct node *curnode;
	unsigned int i;
	unsigned int length = strlen(word);
	curnode = root;
	i = 0;
	while (curnode = get_child(curnode, word[i])) {
		if (curnode->end && i == length - 1) {
			printf("%s exists\n", word);
			return 1;
		}
		i++;
	}
	printf("%s doesn't exist\n", word);
	return 0;
}
int search(struct node *root, char *pattern)
{
	struct node *node, *tmp, *state, *result;
	unsigned int i;
	i = 0;
	state = root;
	while (pattern[i]) {
		node = state;
		while (get_child(node, pattern[i]) == NULL && node != root)
			node = node->fail;
		if (node == root) {
			node = get_child(node, pattern[i]);
			if (node == NULL)
				node = root;
		} else {
			node = get_child(node, pattern[i]);
		}
		tmp = node;
		while (tmp != root) {
			if (tmp->end) {
				printf("Match at %d\n", i);
				result = tmp;
				while (result->parent) {
					printf("%c", result->c);
					result = result->parent;
				}
				printf("\n");
			}
			tmp = tmp->fail;
		}
		state = node;
		i++;
	}
	return -1;
}
int ac(char *text, char *pattern)
{
	struct node *root;
	root = calloc(1, sizeof(struct node));
	add_word(root, pattern);
	make_fail(root);
	return search(root, "text") - strlen(pattern) + 1;
}
int main(int argc, char *argv[])
{
	struct node *root;
	root = calloc(1, sizeof(struct node));
	add_word(root, "stupid");
	add_word(root, "string");
	make_fail(root);
	search(root, "stupid spring string bla whatever dumpshit crap string");
}