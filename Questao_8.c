#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool evaluate_op(const char *op, bool left, bool right) 
{
    if (strcmp(op, "not") == 0) 
    {
        return !right;
    } 
    else if (strcmp(op, "and") == 0) 
    {
        return left && right;
    } 
    else if (strcmp(op, "or") == 0) 
    {
        return left || right;
    }
    return false;
}

bool evaluate_expression(const char **tokens, int num_tokens) 
{
    int stack_size = 0;
    bool stack[num_tokens];
    
    for (int i = 0; i < num_tokens; i++) 
    {
        if (strcmp(tokens[i], "True") == 0 || strcmp(tokens[i], "False") == 0) 
        {
            stack[stack_size] = strcmp(tokens[i], "True") == 0;
            printf("Pilha[%d]: %s\n", stack_size, stack[stack_size] ? "True" : "False");
        } 
        else if (strcmp(tokens[i], "not") == 0 || strcmp(tokens[i], "and") == 0 || strcmp(tokens[i], "or") == 0) 
        {
            bool result;
            if (strcmp(tokens[i], "not") == 0) 
            {
                result = evaluate_op(tokens[i], false, stack[stack_size - 1]);
            } 
            else 
            {
                bool right = stack[--stack_size];
                bool left = stack[--stack_size];
                result = evaluate_op(tokens[i], left, right);
            }
            stack[stack_size++] = result;
            printf("Pilha[%d]: %s\n", stack_size - 1, result ? "True" : "False");
        } 
        else 
        {
            return false; 
        }
    }
    
    return stack[0];
}

int main() {
    char sentence[100];
    const char *delimiters = " \t\n";
    const char *operators[] = {"not", "and", "or"};
    
    printf("Digite a sentenca proposicional logica: ");
    fgets(sentence, sizeof(sentence), stdin);
    
   
    const char *token = strtok(sentence, delimiters);
    const char *tokens[100];
    int num_tokens = 0;
    
    while (token != NULL) 
    {
        tokens[num_tokens++] = token;
        token = strtok(NULL, delimiters);
    }
    
    printf("\nAnalise da Sentenca:\n");
    printf("Sentenca: %s", sentence);
    
    bool is_tautology = evaluate_expression(tokens, num_tokens);
    bool is_contradiction = evaluate_expression(operators, 1) && evaluate_expression(tokens, num_tokens);
    bool is_satisfiable = !is_contradiction;
    bool is_contingency = !(is_tautology || is_contradiction);
    
    printf("\n\nResultado:\n");
    printf("Tautologia: %s\n", is_tautology ? "Sim" : "Nao");
    printf("Contradicao: %s\n", is_contradiction ? "Sim" : "Nao");
    printf("Satisfativel: %s\n", is_satisfiable ? "Sim" : "Nao");
    printf("Contingencia: %s\n", is_contingency ? "Sim" : "Nao");

    return 0;
}
