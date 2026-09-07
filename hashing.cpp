#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define BUCKET 7

struct node {
    int key;
    struct node* next;
};

struct node* hastTable[BUCKET];

int hashFunction(int key) {
    return key % BUCKET;
}

struct node* createNode(int key) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode) {
        printf("bellek tahsis hatasi");
        exit(1);
    }
    newNode->key = key;
    newNode->next = NULL;
    return newNode;

}

void insertItem(int key) {
    int index = hashFunction(key);
    struct node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

}

void deleteItem(int key) {
    int index = hashFunction(key);
    struct node* curr = hashTable[index];
    struct node* prev = NULL;
    while (curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)return;
    if (prev == NULL) {
        hashTable[index] = curr->next;
    }
    else {
        prev->next = curr->next;
    }
    free(curr);
}

void displayHash() {
    for (int i = 0;i < BUCKET;i++) {
        printf("%d", i);
        struct node* curr = hashTable[i];
        while (curr != NULL) {
            printf("--> %d", curr->key);
            curr = curr->next;
        }
        printf("\n");
    }
}
int main()
{
    int keys[] = { 15, 11,27, 8,12 };
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0;i < n;i++) {
        insertItem(keys[i]);
    }

    deleteItem(12);

    displayHash();

    return 0;
}
