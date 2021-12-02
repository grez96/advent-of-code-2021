#include <stdio.h>
#include <stdlib.h>

#define WINDOW_SIZE 3

struct window {
    int sum;
    int count;
};
typedef struct window window;

struct node {
    struct window* window;
    struct node* next;
};
typedef struct node node;

struct queue {
    node* start;
    node* end;
};
typedef struct queue queue;

queue* createQueue() {
    queue* q = malloc(sizeof(queue));

    q->start = NULL;
    q->end = NULL;

    return q;
}

void enqueue(queue* q, window* w) {
    node* n = malloc(sizeof(node));
    n->window = w;
    n->next = NULL;

    if(q->start == NULL) {
        q->start = q->end = n;
    }
    else {
        q->end->next = n;
        q->end = n;
    }
}

window* dequeue(queue* q) {
    node* n = q->start;
    window* w = n->window;
    q->start = n->next;

    free(n);
    return w;
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    queue* q = createQueue();
    int curr;
    int largerCount = 0;

    while (fscanf(fp, "%d", &curr) == 1) {
        window* w = malloc(sizeof(window));
        w->sum = curr;
        w->count = 1;
        enqueue(q, w);

        node* qIter = q->start;
        while(qIter != q->end) {
            if(qIter->window->count < WINDOW_SIZE) {
                qIter->window->sum += curr;
                ++qIter->window->count;
            }
            qIter = qIter->next;
        }

        node* first = q->start;
        node* second = first->next;
        if(second != NULL && first->window->count == WINDOW_SIZE && second->window->count == WINDOW_SIZE) {
            if(second->window->sum > first->window->sum) {
                ++largerCount;
            }
            free(dequeue(q));
        }
    }

    printf("%d\n", largerCount);

    return 0;
}
