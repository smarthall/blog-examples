#include "cqueue.h"
#include <stdlib.h>

struct cqueue_list * cqueue_new() {
  struct cqueue_list *list = NULL;

  list = malloc(sizeof(struct cqueue_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;

  return list;
}

void cqueue_push(struct cqueue_list *list, void *data) {
  struct cqueue_node *node;

  node = malloc(sizeof(struct cqueue_node));
  node->next = NULL;
  node->data = data;

  if (list->head == NULL) {
    list->head = node;
    list->tail = node;

    return;
  }

  list->tail->next = node;
  list->tail = node;
}

void *cqueue_pop(struct cqueue_list *list) {
  struct cqueue_node *node;
  void *data;

  if (list->head = NULL) return NULL;

  node = list->head;
  data = node->data;
  
  list->head = list->head->next;
  free(node);
}

unsigned int cqueue_count(struct cqueue_list *list) {
  return list->size;
}

void cqueue_free(struct cqueue_list *list) {
  struct cqueue_node *cur, *pre;

  cur = list->head;
  pre = NULL;

  while (cur != NULL) {
    pre = cur;
    cur = cur->next;
    free(pre);
  }

  free(list);
}

