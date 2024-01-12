#include<stdio.h>
#include<stdbool.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
//#define OVERFLOW -2
#define ERROR 0
//#define NULL 0

typedef struct
{
    int x;
    int y;
}PosType, SElemType, MoveType;


//ջ�Ķ���
typedef struct
{
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;

//����һ����ջ
void InitStack(SqStack* S)
{
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    //if (!S->base)
        //exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

//����ջ
void DestroyStack(SqStack* S)
{
    free(S->base);
    S->top = NULL;
    S->base = NULL;
    S->stacksize = 0;
}

//��S��Ϊ��ջ
void ClearStack(SqStack* S)
{
    S->top = S->base;
}

//�ж�S�Ƿ�Ϊ��ջ
bool StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//����ջ��Ԫ�ظ���
int StackLength(SqStack S)
{
    return S.top - S.base;
}

//��e����ջ��ջ��Ԫ��
void GetTop(SqStack S, SElemType* e)
{
    if (S.top != S.base)
        //return ERROR;
        *e = *(S.top - 1);
}

//����eΪ�µ�ջ��Ԫ��
void Push(SqStack* S, SElemType e)
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (SElemType*)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        //if (!S->base)
            //return OVERFLOW;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top++ = e;
}

//ɾ��ջ��ջ��Ԫ�أ�����e������ֵ
void Pop(SqStack* S, SElemType* e)
{
    if (S->top != S->base)
        *e = *(--S->top);
}

void StackTraverse(SqStack S)
{
    while (S.top > S.base)
    {
        printf("(%d)-> ", *(S.base));
        S.base++;
    }
    printf("\n");
}

void visit(SElemType e)
{

}


int main()
{
    //���Դ���ջ����
    SqStack Stack;
    SElemType e, i;
    SElemType f = { 7,5 }, g = { 9,6 }, h;
    //e = &h;
    InitStack(&Stack);

    if (StackEmpty(Stack))
    {
        printf("kong->");
    }

    printf("%d->", StackLength(Stack));

    Push(&Stack, f);
    GetTop(Stack, &e);
    printf("(%d,%d)->", e.x, e.y);

    Push(&Stack, g);
    GetTop(Stack, &e);
    printf("(%d,%d)->", e.x, e.y);

    printf("%d->", StackLength(Stack));

    Pop(&Stack, &e);
    printf("(%d,%d)->", e.x, e.y);
    GetTop(Stack, &e);
    printf("(%d,%d)->", e.x, e.y);

    printf("%d->", StackLength(Stack));

    if (StackEmpty(Stack))
    {
        printf("kong->");
    }
    Pop(&Stack, &e);
    printf("(%d,%d)->", e.x, e.y);
    GetTop(Stack, &i);
    printf("%d->", StackLength(Stack));
    printf("(%d,%d)->", i.x, i.y);

    printf("%d->", StackLength(Stack));

    if (StackEmpty(Stack))
    {
        printf("kong->");
    }
    return 0;
    return 0;
}

