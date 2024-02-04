#include <stdio.h>
#include <stdlib.h>

typedef int Status;
typedef int TElemType;

#define OK 1
#define OVERFLOW -2

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree, *SElemType;

typedef struct SNode
{
    SElemType data;
    struct SNode *next;
} SNode;

Status CreateBiTree(BiTree &T)
{
    char ch;
    scanf("%c", &ch);
    if ('#' == ch)
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        // Insert your code here
        T->data = ch;	
        CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
    }
    return OK;
}

int DeepTree(BiTree T)
{
    if (T == NULL)
        return 0;

    int ldeep, rdeep, deep = 0;
    // Insert your code here
    ldeep = DeepTree(T->lchild);
    rdeep = DeepTree(T->rchild);
    deep = (ldeep > rdeep ? ldeep : rdeep);

    return (deep + 1);
}

int main()
{
    BiTree T;
    CreateBiTree(T);
    printf("%d", DeepTree(T));
    return 0;
}
