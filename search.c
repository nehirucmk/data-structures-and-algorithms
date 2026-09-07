#include <stdio.h>
#include <string.h>

#define size 15
int main() {

    char matrix[size][size]; // the grid
    char word[15]; // word to search  for
    int found_flag=0;
    int found[size][size] ={0};

    // gets the characters
    for (int i = 0; i < 15; i++) {
        printf("enter the characters: \n");
        scanf("%15s", matrix[i]);
    }

    // gets the word
    printf("enter a word : ");
    scanf("%s", word);

    // checks
    for(int i=0; i<15;i++){
        for(int j=0;j<15; j++){
            if(j+strlen(word)<=15){
                int check = 1;
                for (int k = 0; k < strlen(word); k++) {
                    if (matrix[i][j + k] != word[k]) {
                        check = 0;
                        break;
                    }
                }
                if(check == 1){
                    found_flag= 1;
                    for (int k = 0; k < strlen(word); k++) {
                        found[i][j + k] = 1;
                    }
                }
            }

            if (i + strlen(word) <= 15) {
                int check = 1;
                for (int k = 0; k < strlen(word); k++) {
                    if (matrix[i + k][j] != word[k]) {
                        check = 0;
                        break;
                    }
                }
                if (check == 1) {
                    found_flag = 1;
                    for (int k = 0; k < strlen(word); k++) {
                        found[i + k][j] = 1;
                    }
                }
            }

        }
    }

    // prints the result
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (found_flag && found[i][j] == 1)
                printf("%c ", matrix[i][j]);
            else
                printf("* ");
        }
        printf("\n");
    }
    return 0;
}
