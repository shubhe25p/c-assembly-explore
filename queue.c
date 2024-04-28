#include "queue.h"
#include <stdio.h>

void queue__init(queue_s *queue, void *static_memory_for_queue, size_t static_memory_size_in_bytes) {

  queue->curr_count = 0;
  queue->push_index = 0;
  queue->pop_index = 0;
  queue->static_memory_size_in_bytes = static_memory_size_in_bytes;
  queue->static_memory_for_queue = static_memory_for_queue;
}

bool queue__push(queue_s *queue, uint8_t push_value) {

  if (queue->push_index == queue->pop_index &&
      queue->curr_count == (queue->static_memory_size_in_bytes / sizeof(uint8_t)))
      {
        printf("Queue is full\n");
        return false;
      }

  queue->static_memory_for_queue[queue->push_index] = push_value;
  queue->push_index = (queue->push_index + 1) % (queue->static_memory_size_in_bytes / sizeof(uint8_t));
  queue->curr_count++;
  return true;
}

bool queue__pop(queue_s *queue, uint8_t *pop_value_ptr) {

  if (queue->push_index == queue->pop_index && queue->curr_count == 0){
    printf("Queue is empty\n");
    return false;
  }

  *pop_value_ptr = queue->static_memory_for_queue[queue->pop_index];
  queue->pop_index = (queue->pop_index + 1) % (queue->static_memory_size_in_bytes / sizeof(uint8_t));
  queue->curr_count--;
  return true;
}

size_t queue__get_item_count(const queue_s *queue) { 
    return queue->curr_count; 
}

int main(){
    queue_s queue;
    uint8_t static_memory_for_queue[5];
    queue__init(&queue, static_memory_for_queue, sizeof(static_memory_for_queue));
    queue__push(&queue, 1);
    queue__push(&queue, 2);
    queue__push(&queue, 3);
    queue__push(&queue, 4);
    queue__push(&queue, 5);
    printf("item count: %zu\n", queue__get_item_count(&queue));

    queue__push(&queue, 6);

    uint8_t pop_value;
    queue__pop(&queue, &pop_value);
    printf("first pop value: %d\n", pop_value);
    queue__pop(&queue, &pop_value);
    printf("second pop value: %d\n", pop_value);
}