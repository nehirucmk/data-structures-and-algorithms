// hastane randevu sistemi

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient { // hastalar -> bagli liste (listelenmis bilgiler)
    int id;
    char name[30];
    char surname[30];
    char disease[50];
    struct Patient* next;
};

struct Appointment{ // randevular -> kuyruk (ilk giren ilk cikar, gercek randevu sistemiyle ayni mantik)
    struct Patient * patient;
    struct Appointment * next;
    char date[20];
    char time[20];
};

struct Doctor { // doktorlar -> agac (daha hizli arama)
    int id;
    char name[30];
    char branch[30];
    struct Doctor * left;
    struct Doctor * right;
};

struct Appointment * front =NULL;
struct Appointment * rear = NULL;

struct Patient * newPatient(int id, char* name, char* surname, char* disease){
    struct Patient* newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    newPatient->id=id;
    strcpy(newPatient->name, name);
    strcpy(newPatient->surname, surname);
    strcpy(newPatient->disease, disease);
    newPatient -> next=NULL;
    return newPatient;
}

struct Patient* insertAtEnd(struct Patient * head, int id, char* name, char* surname, char* disease){
    struct Patient* patient =newPatient(id, name, surname, disease);
    if(head==NULL)
        return patient;
    struct Patient* temp=head;
    while(temp->next!=NULL) temp = temp->next;
    temp->next=patient;
    return head;
}

struct Patient* deletePatient(struct Patient* head, int id){
    if(head==NULL){
        printf("no patient data found!\n");
        return NULL;
    }

    struct Patient * temp=head;
    struct Patient* prev=NULL;

    if(temp!=NULL && temp->id==id){
        head=temp->next;
        free(temp);
        return head;
    }

    while(temp!=NULL && temp->id!=id){
        prev = temp;
        temp = temp->next;
    }

    if(temp==NULL){
        printf("patient with %d id not found\n", id);
        return head;
    }

    prev->next=temp->next;
    free(temp);
    return head;
}

void writePatients(struct Patient* head, char* filename){
    FILE *fp = fopen(filename, "w");
    if(fp == NULL){
        printf("file not found!\n");
        return;
    }
    struct Patient* temp=head;
    while(temp!=NULL){
        printf("patient id: %d\n", temp->id);
        printf("patient name: %s\n", temp->name);
        printf("patient surname: %s\n", temp->surname);
        printf("patient's disease: %s\n", temp->disease);
        temp=temp->next;
    }
    fclose(fp);
}

void enqueue(struct Patient* patient, char* date, char* time ){
    struct Appointment* new = (struct Appointment*)malloc(sizeof(struct Appointment));
    new->patient=patient;
    strcpy(new->date, date);
    strcpy(new->time, time);
    new->next=NULL;

    if(rear==NULL){
        front=rear=new;
        return;
    }

    rear->next=new;
    rear=new;
}

void dequeue(){
    if(front ==NULL){
        printf("no appointment found\n");
        return;
    }
    struct Appointment* temp=front;
    printf("appointment of %s %s at %s %s is removed from the list\n", temp->patient->name,
           temp->patient->surname, temp->date, temp->time);
    front=front->next;

    if(front ==NULL)
        rear= NULL;
    free(temp);
}

void printApps(){
    if(front==NULL){
        printf("no appointments in the list\n");
        return;
    }
    struct Appointment* temp=front;
    while(temp!=NULL){
        printf("--PATIENT INFO--\n");
        printf("NAME: %s %s\n", temp->patient->name, temp->patient->surname);
        printf("DATE: %s\n", temp->date);
        printf("TIME: %s\n", temp->time);
        temp=temp->next;
    }
}

struct Doctor * newDoctor (int id, char * name, char * branch){
    struct Doctor * doctor = (struct Doctor*)malloc(sizeof(struct Doctor));
    doctor -> id=id;
    strcpy(doctor->name, name);
    strcpy(doctor->branch, branch);
    doctor->left=NULL;
    doctor -> right= NULL;
    return doctor;
}

struct Doctor* insertDoctor(struct Doctor* root, int id, char * name, char * branch){
    if(root==NULL) return newDoctor(id, name, branch);

    if(id<root->id) root->left= insertDoctor(root->left, id, name, branch);
    else if (id>root->id) root->right = insertDoctor(root->right, id, name, branch);
    else printf("this doctor already exists\n");
    return root;
}


int main() {
    return 0;
}

