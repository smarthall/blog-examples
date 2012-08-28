/**
 * Name:        cqueue.c
 * Author:      Daniel Hall <daniel@danielhall.me>
 * Description:
 *   This is an implementation of an unbounded queue in C using a linked list.
 *   It is important to note here that as it is unbounded it can cause several
 *   issues if the consuming end should stop responding as then the queue may
 *   grow to fill all available memory. Also note that currently this
 *   implementation is not reentrant and as such not suitable from a threaded
 *   application without some kind of locking wrapper around it.
 *
 **/

/* Data structures */
struct cqueue_node {
  void *data;
  struct cqueue_node *next;
};

struct cqueue_list {
  struct cqueue_node *head;
  struct cqueue_node *tail;
  unsigned int size;
};

/* Methods */
struct cqueue_list * cqueue_new();
void cqueue_push(struct cqueue_list *list, void *data);
void *cqueue_pop(struct cqueue_list *list);
unsigned int cqueue_count(struct cqueue_list *list);
void cqueue_free(struct cqueue_list *list);

