#include <stdio.h>

#define n 10
#define komsular 3

struct node {
    int id;
    int komsu[komsular];
};

// graf olusturuluyor
struct node graf[n] = {
    {0, {1, 4, 5}},
    {1, {0, 2, 6}},
    {2, {1, 3, 7}},
    {3, {2, 4, 8}},
    {4, {0, 3, 9}},
    {5, {0, 7, 8}},
    {6, {1, 8, 9}},
    {7, {2, 5, 9}},
    {8, {3, 5, 6}},
    {9, {4, 6, 7}}
};

// harfler numaralarla eslesiyor
int numaralandir(char harf, int i) {
    int numara = harf - 'A';
    if (i % 2 == 0) {
        return numara;
    }
    else {
        return numara + 5;
    }
}

// komsuluk durumuna bakiliyor
int komsuluk(int a, int b) {
    for (int i = 0; i < komsular; i++)
        if (graf[a].komsu[i] == b)
            return 1;
    return 0;
}

int main() {
    char harfler[] = "AADDCCEE";
    int yol[20];

    // yol olusturuluyor
    for (int i = 0; i < 8; i++) {
        yol[i] = numaralandir(harfler[i], i);
        if (i > 0 && !komsuluk(yol[i - 1], yol[i])) {
            printf("-1");
            return 0;
        }
    }

    // cikti yaziliyor
    for (int i = 0; i < i; i++)
        printf("%d", yol[i]);

    return 0;
}

