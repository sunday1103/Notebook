#include "stdio.h"
#include "stdlib.h"

// ["4", "13", "5", "/", "+"]
int evalRPN(char ** tokens, int tokensSize)
{
    int *s = (int*)malloc(sizeof(int) * tokensSize);
    if (s == NULL)
    {
        return 0;
    }
    int top = 0;

    int result = 0;
    for (size_t i = 0; i < tokensSize; i++)
    {
        char op = tokens[i][0];
        if (strlen(tokens[i]) == 1 && op == '+')
        {
            int r = s[top - 2] + s[top - 1];
            top = top - 2;
            s[top++] = r;
            continue;
        }

        if (strlen(tokens[i]) == 1 && op == '-')
        {
            int r = s[top - 2] - s[top - 1];
            top = top - 2;
            s[top++] = r;
            continue;
        }
        
        if (op == '*')
        {
            int r = s[top - 2] * s[top - 1];
            top = top - 2;
            s[top++] = r;
            continue;
        }

        if (op == '/')
        {
            int r = s[top - 2] / s[top - 1];
            top = top - 2;
            s[top++] = r;
            continue;
        }
    
        int n;    
        sscanf(tokens[i], "%d", &n);
        s[top++] = n;
    }
    int returnVal = s[top - 1];
    free(s);
    return returnVal;
}

int main()
{
    char *in[] = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    // char *in[5] = {"4", "13", "5", "/", "+"};
    evalRPN(in, sizeof(in) / sizeof(char *));
}