#include <iostream>
using namespace std;
#define MAXSIZE 50
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int top;
}SqStack;
//初始化栈
void InitStack(SqStack *&s){
    s = (SqStack*)malloc(sizeof(SqStack));
    s->top = -1;
}
//销毁栈
void DestroyStack(SqStack *&s){
    free(s);
}
//判断栈是否为空
bool StackEmpty(SqStack *s){
    return s->top == -1 ;
}
//进栈
bool Push(SqStack *&s,ElemType e){
    if(s->top == MAXSIZE-1) return false;
    else{
        s->top++;
        s->data[s->top]=e;
        return true; 
    }
}
//出栈
bool Pop(SqStack *&s,ElemType &e){
    if(s->top == -1) return false;
    e=s->data[s->top];
    s->top--;
    return true;
}
//取栈顶元素
bool GetTop(SqStack *s,ElemType &e){
    if(s->top == -1) return false;
    e = s->data[s->top];
    return true;
}
void test(){
    SqStack *t;
    InitStack(t);
    cout << "Is Stack empty? " <<StackEmpty(t)<<" "<<endl;
    Push(t,10);
    Push(t,20);
    int e;
    GetTop(t,e);
    cout << "The top of the Stack is "<<e<<endl;
    Pop(t,e);
    cout << "The Element of "<<e<<" is exiting!"<<endl;
    GetTop(t,e);
    cout << "The top of the Stack is "<<e<<endl;
    cout << "Is Stack empty? " <<StackEmpty(t)<<" "<<endl;
    DestroyStack(t);
}
