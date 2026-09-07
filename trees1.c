/*struct node {
    int id, grade;
    struct node *left; struct node *right;
};

struct node* yeni (int id, int grade){
    struct node* n =(struct node*)malloc(sizeof(struct node));
    n->id=id; n->grade=grade;
    n->left=NULL;
    n->right=NULL;
    return n;
}

struct node* insert(struct node* root, int id, int grade) {
    if (!root) return yeni(id, grade);
    if(grade<root->grade){
        root->left = insert(root->left, id, grade);}
    else
        root ->right=insert(root->right, id, grade);
    return root;
}

void inorder(struct node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    printf("%d %d\n", root->id, root->grade);
    inorder(root->right);
}

int yukseklik(struct node* root){
    if(root==NULL) return 0;
    int sol = yukseklik(root->left);
    int sag = yukseklik(root->right);
    return (sol > sag ? sol : sag) + 1;
}

void levelYaz(struct node* root, int level, struct node* ebeveyn, char c){
    if(!root) return;
    if(level==0){
        if (!ebeveyn)
            printf("%d %d ", root->id, root->grade);
        else printf("%d %d (%d %c) ", root->id, root->grade, ebeveyn->grade, c);
    } else{
        levelYaz(root->left, level - 1, root, 'L');
        levelYaz(root->right, level - 1, root, 'R');
    }
}

void print(struct node* root){
    int h = yukseklik(root);
    for (int i = 0; i < h; i++) {
        levelYaz(root, i, NULL, ' ');
        printf("\n");
    }

}

int main() {
    struct node* root=NULL;
    int g;
    int id;
    while (scanf("%d", &id) && id != -1) {
        scanf("%d", &g);
        root = insert(root, id, g);
    } inorder(root);
    printf("\n");
    print(root);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

struct node* insert(struct node* root, int data){
    if (root==NULL) return createNode(data);
    if (data<root->data){
        root->left=insert(root->left,data);
    } else{
        root->right=insert(root->right, data);
    } return root;
}

struct node* search(struct node* root, int data){
    if(root==NULL || root->data ==data)return root;
    if(data<root->data)
        return search(root->left,data);
    else
        return search(root->right,data);

}

struct node* findMin(struct node* root){
    while(root&&root->left!=NULL)
        root=root->left;
    return root;
}

struct node* delete(struct node* root, int data){
    if(root==NULL) return root;
    if(data<root->data)
        root->left=delete(root->left,data);
    else if (data>root->data)
        root->right=delete(root->right,data);
    else{
        // yapraklar icin
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // iki cocuklu dugum
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;

}

int height(struct node* root){
    if(root==NULL) return -1;
    if(root->left==NULL && root->right==NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

}

int depth(struct node* root, struct node* target, int currentDepth){
    if(root==NULL) return -1;
    if(root==target) return currentDepth;
    int leftDepth = depth(root->left,target,currentDepth+1);
    int rightDepth = depth(root->right,target,currentDepth+1);

    if(leftDepth!=-1)return leftDepth;
    return rightDepth;
}

int countNodes (struct node* root){
    if(root==NULL) return 0;
    return countNodes(root->left)+countNodes(root->right)+1;
}

// TRAVERSAL YONTEMLERI


void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    } }

int main(){
    struct node* root=NULL;
    int data, secim;
    while( 1){
        printf("\n1- Deger ekle\n");
        printf("2- Deger ara\n");
        printf("3- Minimumu bul\n");
        printf("4- Deger sil\n");
        printf("5- Inorder yazdir\n");
        printf("6- Preorder yazdir\n");
        printf("7- Postorder yazdir\n");
        printf("8- Yukseklik bul\n");
        printf("9- Dugum sayisi bul\n");
        printf("0- Cikis\n");
        printf("Seciminiz: ");
        scanf("%d",&secim);

        switch(secim){
            case 1:
                printf("eklenecek deger: ");
                scanf("%d", &data);
                root=insert(root,data);
                break;
            case 2:
                printf("aranacak deger: ");
                scanf("%d", &data);
                if(search(root,data)!=NULL){
                    printf("\nsayi bulundu");
                } else{
                    printf("\nsayi bulunamadi");
                } break;
            case 3:
                if(root!=NULL){
                    struct node* min = findMin(root);
                    printf("\nmin deger: %d", min->data);
                } else {
                    printf("\nagac bos");
                } break;
            case 4:
                printf("silinecek deger: ");
                scanf("%d", &data);
                root=delete(root,data);
                break;
            case 5:
                printf("inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 7:
                printf("postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 8:
                printf("yukseklik: %d\n", height(root));
                break;
            case 9:
                printf("dugum sayisi: %d\n", countNodes(root));
                break;
            case 0:
                exit(0);
            default:
                printf("gecersiz secim");

        }

    }
}
