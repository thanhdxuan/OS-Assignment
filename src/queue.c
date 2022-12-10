#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

int empty(struct queue_t* q) {
   return (q->size == 0);
}

void enqueue(struct queue_t* q, struct pcb_t* proc) {
   /* TODO: put a new process to queue [q] */
   if (q->size >= MAX_QUEUE_SIZE) {
      printf("Queue is overflow!");
      return;
   }
   q->proc[q->size] = proc;
   q->size++;
}

struct pcb_t* dequeue(struct queue_t* q) {
   /* TODO: return a pcb whose prioprity is the highest
    * in the queue [q] and remember to remove it from q
    * */
	
   if (q->size == 0) return NULL;
	uint32_t maxPrio = q->proc[0]->priority;
   struct pcb_t* proc = q->proc[0];
	int index = 0;
	for (int i = 0; i < q->size; i++) {
		if (q->proc[i]->priority > maxPrio) {
			proc = q->proc[i];
			index = i;
		}
	}
   for (int i = index; i < q->size - 1; i++) {
   	q->proc[i] = q->proc[i + 1];
   }
   q->size--;
	return proc;
}
