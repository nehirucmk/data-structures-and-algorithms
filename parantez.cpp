#include <stdio.h>
#define DEGERLER 100

char stack[DEGERLER];
int top = -1;

void push(char a) {
    if (top < DEGERLER - 1) {
        stack[++top] = a;
    }
    else {
        printf("Hata: Stack dolu!\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    else {
        printf("Hata: Stack boş!\n");
        return '\0';
    }
}

int kontrolEt(const char ifade[]) {
    top = -1;  

    for (int i = 0; ifade[i] != '\0'; i++) {
        if (ifade[i] == '(') {
            push('(');
        }
        else if (ifade[i] == ')') {
            if (top == -1) {
                return 0;  
            }
            pop();
        }
    }

    return (top == -1);  
}

int main() {
    const char ifade[] = "((a+b)*((c-d)))";  

    printf("İfade: %s\n", ifade);

    if (kontrolEt(ifade)) {
        printf("Parantezler DENGELİ\n");
    }
    else {
        printf("Parantezler DENGESİZ\n");
    }

    return 0;
}
