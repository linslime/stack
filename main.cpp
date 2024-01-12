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


//栈的定义
typedef struct
{
    SElemType* base;
    SElemType* top;
    int stacksize;
}SqStack;

//构造一个空栈
void InitStack(SqStack* S)
{
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    //if (!S->base)
        //exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

//销毁栈
void DestroyStack(SqStack* S)
{
    free(S->base);
    S->top = NULL;
    S->base = NULL;
    S->stacksize = 0;
}

//把S设为空栈
void ClearStack(SqStack* S)
{
    S->top = S->base;
}

//判断S是否为空栈
bool StackEmpty(SqStack S)
{
    if (S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

//返回栈的元素个数
int StackLength(SqStack S)
{
    return S.top - S.base;
}

//用e返回栈的栈顶元素
void GetTop(SqStack S, SElemType* e)
{
    if (S.top != S.base)
        //return ERROR;
        *e = *(S.top - 1);
}

//插入e为新的栈顶元素
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

//删除栈的栈顶元素，并用e返回其值
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
    //测试创建栈函数
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

