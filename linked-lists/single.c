#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct item {
  int value;
  struct item *next;
};

struct item *head = NULL;

void insert(int value) {
  struct item *new, *current;

  new = malloc(sizeof(struct item));
  new->value = value;
  new->next = head;
  head = new;
}

void print() {
  struct item *current;

  current = head;
  while (current != NULL) {
    printf("Number: %d\n", current->value);
    current = current->next;
  }
}

int main(int argc, char **argv) {

  /* Seed the random generator */
  srand(time(NULL));

  for (int i = 0; i < 20; i++) {
    int val = rand();
    insert(val);
  }

  print();

  printf("It Works!\n");
}

