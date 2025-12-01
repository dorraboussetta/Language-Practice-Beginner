/*
---------------------------------------------------------------------------------------
DESCRIPTION:
This program is a mini string manipulation exercise designed to practice how strings are
declared, stored, and processed in C. It provides a menu-driven interface that allows
the user to perform various operations on strings using standard library functions
from <string.h>.


---------------------------------------------------------------------------------------
CONCEPTS PRACTICED:
- Declaring and storing strings (1D and 2D character arrays)
- Using predefined string functions (strlen, strcpy, strcmp)
- Iterating through strings using loops
---------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char sentence[100], word[20];

    do {
        // Display the menu
        printf("\n=== MAIN MENU ===\n");
        printf("1. Display the words of a sentence\n");
        printf("2. Display the vowels and their number in a word\n");
        printf("3. Compose a sentence\n");
        printf("4. Quit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Validate input
        if (choice < 1 || choice > 4) {
            printf("Invalid choice! Please enter a number between 1 and 7.\n");
            continue;
        }

        // Execute based on user choice
        switch (choice) {
            //Display the words of a sentence
            case 1: {
                int ch=0, j, nbw=0, length;
                do {
                   printf("Enter your sentence:\n"); fflush(stdin); gets(sentence);
                } while (strlen(sentence)==0);

                length=strlen(sentence);

                while (ch<=length) {
                        j=0;
                        while (sentence[ch]!=' ' && sentence[ch]!='\0' && sentence[ch]!='.') {
                            word[j]=sentence[ch];
                            ch++;
                            j++;

                        }
                        word[j]='\0';
                        nbw++; ch++;
                        while (sentence[ch]==' ') {
                        ch++;}
                    printf("Word %d: %s\n", nbw, word);
                }
                printf("\n");
                printf("The number of words= %d", nbw);

                break;
            }
            //Display the vowels and their number in a word
            case 2: {
                char word[20];
                int nbv=0;

                printf("Enter a word: \n"); fflush(stdin); gets(word);
                printf("The list of vowels: ");

                for (int ch=0; word[ch]!='\0'; ch++) {
                    if (word[ch]=='a' || word[ch]=='i' || word[ch]=='o' || word[ch]=='u' || word[ch]=='e' || word[ch]=='y') {
                            printf("%c  ", word[ch]);
                            nbv++;
                            }
                }
                printf("The number of vowels in %s is: %d\n", word,nbv);

                break;
            }


            //Compose a sentence
            case 3: {
                char original_sen[7][20]={"it's", "our", "seventh", "PBL", "for", "this", "year"};
                char words[7][20]= {"PBL", "seventh", "year", "our", "it's", "this","for"};
                char user_sen[7][20];
                int order, w, identical=1;


                printf("Here's your list of words: \n");
                printf("\"PBL\"  \"seventh\"  \"year\"  \"our\"  \"it's\"  \"this\"  \"for\" \n");

                printf("%s\n", words[1]);

                for (w=0; w<7; w++) {
                    do {
                        printf("Enter the order of the word \"%s\" in the sentence:  ", words[w]);
                        scanf("%d", &order);  } while (order<1 || order>7);
                        strcpy(user_sen[order-1], words[w]);
                    printf("\n");
                }
                w=0;

                do {
                    if (strcmp(original_sen[w], user_sen[w]) != 0) identical=0;

                    w++;
                } while (identical ==1 && w<7);

                if (identical==1) {
                    printf("Congrats! It is the right answer! \n");
                    printf("The sentence is: ");
                    for (w=0; w<7; w++){
                        printf("%s ", original_sen[w]);
                    }
                                    }
                else {
                    printf("Wrong answer! \n");
                       printf("The original sentence is: ");
                    for (w=0; w<7; w++){
                        printf("%s ", original_sen[w]);
                    }

                    printf("Your sentence is: ");
                        for (w=0; w<7; w++){
                        printf("%s ", user_sen[w]);
                    }

                }

                break;
            }

            case 4: {
                break;
            }

        }

    } while (choice != 4);

    return 0;
}


