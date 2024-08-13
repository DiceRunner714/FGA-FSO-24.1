typedef struct{
    int id;
    int cur;
    int *instructions;
} Process;

typedef struct{
    int front, rear;
    unsigned int capacity;
    Process *array;
} ProcessQueue;

ProcessQueue* createProcessQueue(unsigned int capacity){
    ProcessQueue* queue = (ProcessQueue*)malloc(sizeof(ProcessQueue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (Process*)malloc(queue->capacity * sizeof(Process));
    return queue;
}

int isEmpty(ProcessQueue* queue){ return (queue->front == -1); }

int isFull(ProcessQueue* queue){ return ((queue->rear + 1) % queue->capacity == queue->front); }

void enqueue(ProcessQueue* queue, Process process){
    if(isFull(queue)){
        printf("A fila está cheia.\n");
        return;
    }
    if(isEmpty(queue)){
        queue->front = queue->rear = 0;
    }else{
        queue->rear = (queue->rear + 1) % queue->capacity;
    }
    queue->array[queue->rear] = process;
}

Process dequeue(ProcessQueue* queue){
    Process empty_process = {-1, -1, NULL};
    if(isEmpty(queue)){
        printf("A fila está vazia. Não há processos para remover.\n");
        return empty_process;
    }
    Process process = queue->array[queue->front];
    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    }else{
        queue->front = (queue->front + 1) % queue->capacity;
    }
    return process;
}

Process front(ProcessQueue* queue){
    Process empty_process = {-1, -1, NULL};
    if(isEmpty(queue)){
        printf("A fila está vazia.\n");
        return empty_process;
    }
    return queue->array[queue->front];
}