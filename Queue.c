#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isempty(struct queue *q);
void enqueue(struct queue *q,int val);
int  dequeue(struct queue *q);

int main(){
    struct queue q;
    q.size = 5;
    q.front=q.rear=-1;
    q.arr = (int *)malloc(q.size*sizeof(int ));

    while(1){
        int choice,val;
        printf("\n1. enqueue \n 2. dequeue \n 3. exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter a val for enqueue\n");
            scanf("%d",&val);
            enqueue(&q,val);
            break;
            case 2:
            dequeue(&q);
            break;
            case 3:
            printf("Exit");
            break;
            default:
            printf("Invalid number\n");

        }
    }


}

int isempty(struct queue *q){
if(q->front==-1){
    return 1;
}else{
    return 0;
}

}
int isfull(struct queue *q){
    if(q->rear==q->size-1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct queue *q,int val){
    if(isfull(q)){
        printf("queue is Full!\n");
    }else{
        if(q->front==-1){
            q->front = 0;
        }
        q->rear++;
        q->arr[q->rear] = val;
        printf("Enqueue val is %d\n",val);
    }

}


int dequeue(struct queue *q) {
    if (isempty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }

    int val = q->arr[q->front];
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }

    printf("Dequeued value is %d\n", val);
    return val;
}
