#include<stdio.h>
#include<stdlib.h>

typedef struct person {
	int age;
	char name[10];
	struct person* next;
	struct person* last;
}person_list;

person_list* create(int n) {
	person_list* head, * node, * end;
	head = (person_list*)malloc(sizeof(person_list));
	scanf_s("%d", &head->age);
	scanf_s("%s", &head->name, 9);
	end = head;
	for (int i = 0; i < n-1; i++) {
		node = (person_list*)malloc(sizeof(person_list));
		scanf_s("%d", &node->age);
		scanf_s("%s", &node->name, 9);
		node->last = end;
		end->next = node;
		end = node;
	}
	end->next = head;
	head->last = end;
	return head;
}

void anti_get(person_list* head, int n) {
	person_list* t = head;
	for (int i = 0; i < n; i++) {
		t = t->last;
	}
	if (t != NULL) {
		printf("%d", t->age);
		printf("%s", t->name);
	}
}

int main()
{
	person_list* people = create(4);
	anti_get(people, 2);
}
































