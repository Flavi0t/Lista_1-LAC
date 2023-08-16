#include <stdio.h>
#include <string.h>
#include <ctype.h>

char getPropositionalSymbol(char proposition) 
{
    switch (proposition) 
    {
        case 'm': return 'M';
        case 'n': return '~';
        case 'o': return 'O';
        case 'p': return 'P';
        case 'q': return 'Q';
        case 'r': return 'R';
        case 's': return 'S';
        case 'u': return 'U';
        case 'v': return 'V';
        case 'x': return 'X';
        case 'y': return 'Y';
        case 'z': return 'Z';
        default: return '\0';
    }
}

int main() 
{
    char sentence[1000];
    printf("Digite a sentença em linguagem natural: ");
    fgets(sentence, sizeof(sentence), stdin);

    char *conjunctions[] = {"e", "e também", "além disso"};
    char *disjunctions[] = {"ou", "ou então", "ou ainda"};
    char *negations[] = {"não", "nunca"};

    printf("Tradução para lógica proposicional:\n");

    char *word = strtok(sentence, " ");
    while (word != NULL) 
    {
        int isConjunction = 0;
        int isDisjunction = 0;
        int isNegation = 0;
        
        for (int i = 0; i < sizeof(conjunctions) / sizeof(conjunctions[0]); i++) 
        {
            if (strcmp(word, conjunctions[i]) == 0) 
            {
                isConjunction = 1;
                break;
            }
        }

        for (int i = 0; i < sizeof(disjunctions) / sizeof(disjunctions[0]); i++) 
        {
            if (strcmp(word, disjunctions[i]) == 0) 
            {
                isDisjunction = 1;
                break;
            }
        }

        for (int i = 0; i < sizeof(negations) / sizeof(negations[0]); i++) 
        {
            if (strcmp(word, negations[i]) == 0) 
            {
                isNegation = 1;
                break;
            }
        }

        if (isConjunction) 
        {
            printf("^ ");
        } 
        else if (isDisjunction) 
        {
            printf("v ");
        } 
        else if (isNegation) 
        {
            printf("~ ");
        } 
        else 
        {
            char propositionalSymbol = getPropositionalSymbol(word[0]);
            if (propositionalSymbol != '\0') 
            {
                printf("%c ", propositionalSymbol);
            } 
            else 
            {
                printf("%s ", word);
            }
        }

        word = strtok(NULL, " ");
    }

    return 0;
}
