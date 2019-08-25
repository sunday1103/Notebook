#include <stdio.h>
#include <string.h>

int g_addNum;
int g_multiNum;

#define MAX_LIST_NUM 4000
int g_addListNum;
int g_addList[MAX_LIST_NUM];

#define MAX_MULTI_ITEM_NUM 1000
int g_multiListNum[MAX_MULTI_ITEM_NUM];
int g_multiLists[MAX_MULTI_ITEM_NUM][MAX_LIST_NUM];

// 1+8+3*4+5*6*7+9*2+7*8*9*3+2

void Input()
{
    scanf("%d %d", &g_addNum, &g_multiNum); 

    scanf("%*[\r\n]");
    char source[MAX_LIST_NUM];
    memset(source, 0, MAX_LIST_NUM);
    scanf("%s", source);
    char *pch;
    printf ("%s\n", source);
    pch = strtok (source,"+");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, "+");
    }
}

void Process()
{
    
}

int main()
{
    //freopen("input.txt","r",stdin);
    Input();
    Process();

    return 0;
}