#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isPropositionalSymbol(char c) 
{
    return isalpha(c) && isupper(c);
}

bool isLogicalOperator(char c) 
{
    return c == '&' || c == '|' || c == '~' || c == '>' || c == '<';
}

bool isWellFormedFormula(const char *sentence) 
{
    int len = strlen(sentence);
    int balance = 0; 
    
    if (len == 0) 
    {
        return false;
    }

    for (int i = 0; i < len; i++) 
    {
        char c = sentence[i];

        if (isPropositionalSymbol(c)) 
        {
        } 
        else if (isLogicalOperator(c)) 
        {
            
        } 
        else if (c == '(') 
        {
            balance++;
        } 
        else if (c == ')') 
        {
            balance--;
            if (balance < 0) 
            {
                return false; 
            }
        } 
        else if (c == ' ') 
        {
           
        } 
        else
        {
            return false; 
        }
    }

    return balance == 0; 
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

    if (isWellFormedFormula(sentence)) 
    {
        printf("A sentenca '%s' pertence ah linguagem da logica proposicional.\n", sentence);
    } 
    else 
    {
        printf("A sentenca '%s' NAO pertence ah linguagem da logica proposicional.\n", sentence);
    }

    return 0;
}
