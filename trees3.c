#include <stdio.h>
#include <stdlib.h>

#define RED 0
#define BLACK 1

struct node{
    int data;
    char color;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* root = NULL;

struct node* createNode (int data){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->color=RED;
    n->parent=NULL;
    n->left=NULL;
    n->right=NULL;
    return n;
}

struct node* left(struct node* x){
    struct node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }
    y->parent = x->parent;

    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->left = x;
    x->parent = y;
    return y;
}

struct node* right(struct node* x) {
    struct node* y = x->left;
    x->left = y->right;

    if (y->right != NULL) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }

    y->right = x;
    x->parent = y;

    return y;
}

void fix(struct node* n) {
    while (n != root && n->parent->color == RED) {
        if (n->parent == n->parent->parent->left) {
            struct node* uncle = n->parent->parent->right;

            if (uncle != NULL && uncle->color == RED) {
                n->parent->color = BLACK;
                uncle->color = BLACK;
                n->parent->parent->color = RED;
                n = n->parent->parent;
            } else {
                if (n == n->parent->right) {
                    n = n->parent;
                    left(n);
                }

                n->parent->color = BLACK;
                n->parent->parent->color = RED;
                right(n->parent->parent);
            }
        } else {
            struct node* uncle = n->parent->parent->left;

            if (uncle != NULL && uncle->color == RED) {
                n->parent->color = BLACK;
                uncle->color = BLACK;
                n->parent->parent->color = RED;
                n = n->parent->parent;
            } else {
                if (n == n->parent->left) {
                    n = n->parent;
                    right(n);
                }

                n->parent->color = BLACK;
                n->parent->parent->color = RED;
                left(n->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void ekle(int data) {
    struct node* n = createNode(data);
    if (root == NULL) {
        root = n;
        root->color = BLACK;
        return;
    }

    struct node* t = root;
    struct node* parent = NULL;

    while (t != NULL) {
        parent = t;
        if (data < t->data) t = t->left;
        else t = t->right;
    }

    n->parent = parent;
    if (data < parent->data) parent->left = n;
    else parent->right = n;

    fix(n);
}

void inorder(struct node* n) {
    if (n == NULL) return;
    inorder(n->left);
    printf("%d\n", n->data);
    inorder(n->right);
}

void print(struct node* n) {
    if (n == NULL) return;

    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = n ;

    while (front < rear) {
        int levelSize = rear - front;
        for (int i = 0; i < levelSize; i++) {

            struct node* t = queue[front++];
            printf("%d %c", t->data, t->color == RED ? 'R' : 'B');
            if (t->parent != NULL) {
                if (t == t->parent->left) printf(" (%d L)", t->parent->data);
                else {
                    printf(" (%d R)", t->parent->data);
                }
            }
            printf(" ");
            if (t->left != NULL) queue[rear++] = t->left;
            if (t->right != NULL) queue[rear++] = t->right;
        }
        printf("\n");
    }

}

int main() {
    int deger;
    while (1) {
        scanf("%d", &deger);
        if (deger == -1) break;
        ekle(deger);
    }

    inorder(root);
    printf("\n\n");
    print(root);

    return 0;
}
