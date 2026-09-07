#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*struct stackNode {
    int data;
    struct stackNode* next;
};

struct stack{
    struct stackNode* top;
};


void push(struct stack* stack, int data){
    struct stackNode* newNode = (struct stackNode*)malloc(sizeof(struct stackNode));
    newNode->data=data;
    newNode->next=stack->top;
    stack->top=newNode;
}

int pop(struct stack* stack){
    if(stack->top==NULL){
        printf("yigin bos\n");
        return -1;
    }
    struct stackNode* temp=stack->top;
    int data = temp->data;
    stack->top=temp->next;
    free(temp);
    return data;
}

int isEmpty(struct stack* stack){
    return stack->top == NULL; // eşitse 1 değilse 0
}

int peek(struct stack* stack){
    if(stack->top==NULL){
        printf("yigin bos\n");
        return -1;
    } return stack->top->data;
}

void print(struct stack * stack){
    struct stackNode* temp= stack->top;
    printf("yigin: ");
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

}

int main(void){
    struct stack s;
    s.top =NULL;

    char input[500];
    int secim, data;

    do{
        printf("menu\n");
        printf("1 - Push (Ekle)\n");
        printf("2 - Pop (Cikar)\n");
        printf("3 - Peek (En ustu gor)\n");
        printf("4 - Yazdir\n");
        printf("5 - Bos mu kontrol et\n");
        printf("0 - cikis\n");
        printf("Seciminiz: ");

        fgets(input, sizeof(input),stdin);
        sscanf(input, "%d", &secim);

        switch(secim){
            case 1:
                printf("ekleyecegin sayi: ");
                fgets(input, sizeof(input), stdin);
                if(sscanf(input, "%d", &data) == 1) {
                    push(&s, data);
                } else {
                    printf("Geçersiz sayı!\n");
                }
                break;
            case 2:
                data = pop(&s);
                if(data!=-1)
                    printf("cikarilan sayi: %d\n", data);
                break;
            case 3:
                data = peek(&s);
                if(data!=-1)
                    printf("en ustteki sayi: %d\n", data);
                break;
            case 4:
                print(&s);
                break;
            case 5:
                if(isEmpty(&s))
                    printf("yigin bos\n");
                else
                    printf("yigin dolu\n");
                break;
        }

    } while(secim!=0);

    return 0;
}*/

#define max 5

int queue[max];
int front =-1, rear=-1;

int isEmpty(){
    return (front==-1); // true or false, checks if its empty or not, if the front is -1, returns 1 (true)
}

int isFull() {
    return ((rear + 1) % max == front);
}

void add(int data){
    if(rear==max-1){
        printf("dolu\n");
    } else{
        if(front==-1){
            front =0;
            rear++;
            queue[rear]=data;
        }
    }
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
    printf("1-ekle\n");
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
            printf("silmek istedigin sayi: ");
            scanf("%d", &number);
            delete(number);
            break;
        case 3:
            print();
            break;
        case 4:
            return 0;
    }
}
