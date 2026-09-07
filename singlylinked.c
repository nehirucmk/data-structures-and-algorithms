#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * next;
    int data;
};

// creating the first node
struct node* firstNode(int value){
    struct node * newNode= (struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}


struct node* prepend(struct node* head, int value){
    struct node* newNode = firstNode(value);
    newNode->next=head;
    return newNode;
}

struct node* append(struct node* head, int value){
    struct node * newNode = firstNode(value);
    if (head==NULL){
        return newNode;
    }
    struct node* temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newNode;
    return head;
}

struct node* search (struct node* head, int value){
    struct node* temp=head;
    while(temp->next!=NULL){
        if(temp==value){
            return temp;
        }
        temp=temp->next;
    }
    printf("there is no number\n");
}

struct node* delete(struct node* head, int value){
    if(head==NULL){
        printf("the list is empty");
    }
    struct node* temp=head;
    if(head->data==value){
        head=head->next;
        free(temp);
        return head;
    }
    struct node* temp2=head;
    while(temp2->next!=NULL && temp2->next->data!= value){
        temp2=temp2->next;
    }
    if(temp2->next==NULL){
        printf("there is nothing to delete");
    } else{
        temp=temp2->next;
        temp2->next=temp2->next->next;
        free(temp);
    }
    return head;
}

struct node* deleteFirst(struct node* head){
    if(head==NULL){
        printf("there is nothing to delete");
    }
    struct node* temp=head;
    head=head->next;
    free(temp);
    return head;

}

struct node* deleteLast(struct node* head){
    if(head==NULL){
        printf("there is nothing to delete");
    }
    struct node* temp=head;
    struct node* temp2=head;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}

struct node* addAtPosition (struct node* head, int pos, int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data= data;
    newNode->next=NULL; // yeni düğüm oluşturuluyor şu anlık bir listeye bağlı değil

    if(head==NULL){
        printf("the list is probably empty");
    }

    if(pos ==0 ){
        newNode->next=head;
        return newNode;
    }

    struct node * temp= head;

    for(int i=0;i<pos-1;i++){
        if(temp==NULL){
            printf("position cant be found");
            free(newNode);
            return head;
        } temp=temp->next;
    }

    newNode->next=temp->next;
    temp->next = newNode;
    return head;

}

struct node* deleteAtPosition(struct node* head, int pos){
    if(head==NULL){
        printf("this list is empty");
        return head;
    }
    if(pos==0){
        struct node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    struct node* temp=head;
    for (int i=0; temp!=NULL&&i<pos-1;i++){
        temp=temp->next;
    }
    if(temp==NULL||temp->next==NULL){
        printf("invalid position");
        return head;
    }
    struct node* nodeToDelete = temp->next;
    temp->next=nodeToDelete->next;
}

int difference(struct node* head){
    if(head==NULL){
        printf("list is empty");
        return 0;
    }

    struct node* temp=head;
    int max=head->data;
    int min=head->data;

    while(temp!=NULL){
        if(max<temp->data)
            max=temp->data;
        if(min>temp->data)
            min=temp->data;
        temp=temp->next;
    }
    return (max - min);
}


void printList(struct node* head){
    if(head== NULL){
        printf("this list is empty");
    }
    struct node* temp=head;
    while(temp->next!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    } printf("null\n");
}

void freeList(struct node* head){
    struct node* temp=head;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}


int main() {
    struct node* head;
    int data;


}
