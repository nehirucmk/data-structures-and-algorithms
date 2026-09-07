#include <stdio.h>
#include <stdlib.h>

#define max 5

int queue[max];
int front =-1, rear=-1;

int isEmpty(){
    return (front==-1); // true or false, checks if its empty or not, if the front is -1, returns 1 (true)
}

int isFull() {
    return (rear==max-1);
}

void add(int data) {
    if (isFull()) {
        printf("Kuyruk dolu\n");
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = data;
}

void delete(){
    if(front==-1 || front>rear){
        printf("bos\n");
        front =-1;
        rear=-1;
    }
    else{
        front =front+1;
    }
}

void print(){
    if(front==-1)
        printf("kuyruk bos\n");
    else {
        for(int i=front;i<=rear;i++){
            printf("%d ", queue[i]);
        }
    }
}
int main(){
    int number, choice;
    while(1){
    printf("\n1-ekle\n");
    printf("2-cikar\n");
    printf("3-yazdir\n");
    printf("4-cik\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("eklemek istedigin sayi: ");
            scanf("%d", &number);
            add(number);
            break;
        case 2:
            delete();
            break;
        case 3:
            print();
            break;
        case 4:
            return 0;
    }}
}
