#include <iostream>
using namespace std;
typedef int Elemtype;
typedef struct LinkStNode{
    Elemtype data;
    LinkStNode *next;
}Snode;
void InitStack(Snode *&s){
    s = (Snode*)malloc(sizeof(Snode));
    s->next = NULL;
}
void DestroyStack(Snode *&s){
    Snode *pre=s,*p=s->next;
    while(p!=NULL){
        free(pre);
        pre=p;
        p=p->next;
    }
    free(pre);
}
bool StackEmpty(Snode *s){
    return s->next==NULL;
}
void PushStack(Snode *&s,Elemtype e){
    Snode *t=(Snode*)malloc(sizeof(Snode));
    t->data = e ;
    t->next=s->next;
    s->next = t;
}
bool Pop(Snode *&s,Elemtype &e){
    if(s->next == NULL) return false;
    Snode *p=s->next;
    e=s->next->data;
    s->next = p->next;
    free(p);
    return true;
}
bool GetTop(Snode *s,Elemtype &e){
    if(s->next == NULL) return false;
    e=s->next->data;
    return true;
}
void test(){
    Snode *t;
    InitStack(t);
    cout << "Is Stack empty? " <<StackEmpty(t)<<" "<<endl;
    PushStack(t,10);
    PushStack(t,20);
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
