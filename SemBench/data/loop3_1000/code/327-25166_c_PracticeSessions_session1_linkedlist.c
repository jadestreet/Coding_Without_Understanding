#include <stdio.h>
struct Node {
	int value;
	struct Node* next;
};
int list_get(struct Node* first, int index) {
	struct Node* current = first;
	for (int i = 0; i < index && current != NULL; i++) {
		current = current->next;
	}
	return current == NULL || index < 0 ? -1 : current->value;
}
struct Node* list_remove(struct Node* first, int index) {
	if (index == 0) return first->next;
	struct Node* current = first;
	for (int i = 0; i < index - 1 && current != NULL; i++) {
		current = current->next;
	}
	if (current != NULL) {
		if(current->next->next == NULL) current->next = NULL;
		else current->next = current->next->next;
	}
	return first;
}
int list_length(struct Node* first) {
	int length = 0;	
	struct Node* current = first;
	while (current != NULL) {
		length++;
		current = current->next;
	}
	return length;
}
int main() {
	struct Node third;
	third.value = 3;
	third.next = NULL;
	struct Node second;
	second.value = 2;
	second.next = &third;
	struct Node first;
	first.value = 1;
	first.next = &second;
	return 0;
}