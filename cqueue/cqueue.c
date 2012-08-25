#include "cqueue.h"
#include <stdlib.h>

struct cqueue_list * cqueue_new() {
  struct cqueue_list *list = NULL;

  list = malloc(sizeof(struct cqueue_list));
  list->head = NULL;
  list->tail = NULL;

  return list;
}

void cqueue_push(struct cqueue_list *list, void *data) {

}

void *cqueue_pop(struct cqueue_list *list) {

}

void cqueue_count(struct cqueue_list *list) {

}

void cqueue_free(struct cqueue_list *list) {

}

