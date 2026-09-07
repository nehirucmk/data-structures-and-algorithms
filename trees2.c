#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
    int h;
};

int max(int a, int b) { return (a>b) ?a:b ; }

int height(struct node *root) {
    if(root==NULL) return 0;
    return root->h;
}

int denge(struct node *root) {
    if(root==NULL) return 0;
    return height(root->left) - height(root->right);
}

struct node* newNode(int v) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->val = v;
    root->left = NULL;
    root->right = NULL;
    root->h = 1;
    return root;
}

struct node* right(struct node* root) {
    struct node* x = root->left;
    struct node* t = x->right;
    x->right = root;
    root->left = t;
    root->h = max(height(root->left), height(root->right)) + 1;
    x->h = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct node* left(struct node* root) {
    struct node* y = root->right;
    struct node* t = y->left;
    y->left = root;
    root->right = t;
    root->h = max(height(root->left), height(root->right)) + 1;
    y->h = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct node* ekle(struct node* root, int v) {
    if(root==NULL) return newNode(v);

    if(v < root->val) root->left = ekle(root->left,v);
    else if(v > root->val) root->right = ekle(root->right,v);
    else return root;

    root->h = 1 + max(height(root->left), height(root->right));
    int b = denge(root);

    if(b>1 && v < root->left->val){
        return right(root);
    }
    if(b<-1 && v > root->right->val)
        return left(root);
    if(b>1 && v > root->left->val) {
        root->left = left(root->left);
        return right(root);
    }
    if(b<-1 && v < root->right->val) {
        root->right = right(root->right);
        return left(root);
    }
    return root;
}

void inorder(struct node* root) {
    if(root==NULL) return;
    inorder(root->left);
    printf("%d\n", root->val);
    inorder(root->right);
}

void print(struct node* root, struct node* parent, int level) {
    if(root==NULL)
        return;
    if(level==1) {
        if(parent==NULL) {
            printf("%d (-1 B) ", root->val);
        } else {
            char c = (parent->left==root) ? 'L' : 'R' ;
            printf("%d (%d %c) (%d B) ", root->val, parent->val, c, denge(root));
        }
    } else {
        print(root->left, root, level-1);
        print(root->right, root, level-1);
    }
}

int tree(struct node* root) {
    if(root==NULL) return 0;
    int l = tree(root->left);
    int r = tree(root->right);
    return (l>r?l:r)+1;
}

int main() {
    struct node* root = NULL;
    int x;
    while(1) {
        scanf("%d", &x);
        if(x==-1)
            break;
        root = ekle(root,x);
    }

    inorder(root);
    printf("\n");
    int h = tree(root);
    for(int i=1;i<=h;i++) {
        print(root,NULL,i);
        printf("\n");
    }
    return 0;
}
