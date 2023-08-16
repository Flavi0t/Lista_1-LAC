#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertSentence(char *sentence) 
{
    int len = strlen(sentence);
    printf("Sentenca original: %s\n", sentence);

    for (int i = 0; i < len; i++) 
    {
        if (sentence[i] == '&') 
        {
            printf("Substituindo '&' por '|'\n");
            sentence[i] = '|';
        } 
        else if (sentence[i] == '|') 
        {
            printf("Substituindo '|' por '&'\n");
            sentence[i] = '&';
        } 
        else if (sentence[i] == '>') {
            printf("Substituindo '>' por '<'\n");
            sentence[i] = '<';
        } 
        else if (sentence[i] == '<') 
        {
            printf("Substituindo '<' por '>'\n");
            sentence[i] = '>';
        }
    }
}

int main() 
{
    char sentence[100];
    printf("Digite uma sentenca logica: ");
    fgets(sentence, sizeof(sentence), stdin);

    if (sentence[strlen(sentence) - 1] == '\n') 
    {
        sentence[strlen(sentence) - 1] = '\0';
    }

    convertSentence(sentence);
    printf("A sentenca equivalente eh: %s\n", sentence);

    return 0;
}
