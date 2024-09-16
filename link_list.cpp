#include <iostream>
#include <cstdlib>
using namespace std;
typedef int ElemType;
typedef struct LNode{
	ElemType val;
	LNode *next;
}LinkNode;
//创建顺序表
//头插法
void CreatListL(LinkNode* &L,ElemType a[],int n){
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next =nullptr;
	LinkNode *s;
	for(int i=0;i<n;++i){
		s=(LinkNode*)malloc(sizeof(LinkNode));
		s->val=a[i];
		s->next = L->next;
		L->next =s;
	}
}
//尾插法
void CreatListR(LinkNode *&L,ElemType a[],int n){
	L = (LinkNode*)malloc(sizeof(LinkNode));
	LinkNode *p1,*p2;
	p1=L;
	for(int i=0;i<n;++i){
		p2=(LinkNode*)malloc(sizeof(LinkNode));
		p2->val=a[i];
		p1->next=p2;
		p1=p2;
	}
	p2->next=nullptr;
	
}
//初始化顺序表
void InitList(LinkNode *&L){
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = nullptr ;
}
//销毁顺序表
void DestoryList(LinkNode *&L){
	LinkNode *pr,*pl;
	pl=pr=L;
	while(pr!=nullptr){
		pr=pr->next;
		free(pl);
		pl=pr;
	}
	free(pl);
}
//判断顺序表是否为空
bool LsitEmpty(LinkNode *L){
	return (L->next == nullptr) ;
}
//求顺序表的长度
int ListLength(LinkNode *L){
	int len=0;
	L=L->next;
	while(L!=nullptr){
		++len;
		L=L->next;
	}
	return len;
}
//输出顺序表
void DispList(LinkNode *L){
	if(L->next==nullptr) cout << "The LinkList is empty!" ;
	L=L->next;
	while(L!=nullptr){
		cout << L->val << " " ;
		L=L->next;
	}
	cout << endl;
}
//按序号求第i个元素，使用e存储返回
bool GetElem(LinkNode *L,int i,ElemType &e){
	if(i<0 || i>ListLength(L)) return false;
	int j=0;
	while(j<i&&L!=nullptr){
		L=L->next;
		++j;
	}
	e = L->val;
	return true;
}
//按元素查找元素e所在的位置
int LocateElem(LinkNode *L,ElemType e){
	int i=1;
	L=L->next;
	while(L!=nullptr&&L->val!=e){
		L=L->next;
		++i;
	}
	if(L!=nullptr) return i;
	else return 0;
}
//在顺序表的第i个位置插入元素e
bool ListInsert(LinkNode *&L,int i,ElemType e){
	LinkNode *p,*t;
	int j=0;
	if(i<=0) return false;
	p=L;
	while(j<i-1&&p!=nullptr){
		++j;
		p=p->next;
	}
	if(p==nullptr) return false;
	else{
		t=(LinkNode*)malloc(sizeof(LinkNode));
		t->val=e;
		t->next = p->next ;
		p->next=t;
		return true;
	}
}
//删除顺序表第i个位置的元素，并使用e返回该元素值
bool LsitDelete(LinkNode *&L,int i,ElemType &e){
	if(i<=0) return false;
	int j=0;
	LinkNode *p=L,*q;
	while(j<i-1&&p!=nullptr){
		++j;
		p=p->next;
	}
	if(p==nullptr) return false;
	else{
		q=p->next;
		if(q == nullptr) return false;
		e=q->val;
		p->next = q->next;
		free(q);
		return true;
	}
}
//测试函数
void test(){
	LinkNode *L;
	int a[5]={1,2,3,4,5};
	InitList(L);
	cout <<"The list is empty? " <<LsitEmpty(L)<<endl ;
	CreatListR(L,a,5);
	cout <<"The list is empty? " <<LsitEmpty(L)<<endl ;
	DispList(L);
	cout << "There are "<<ListLength(L)<<" elements in the list!"<<endl;
	int e1,e2,e;
	GetElem(L,1,e1);
	GetElem(L,2,e2);
	cout << "The first and the second element of the list is "<<e1<<" andl "<<e2 <<endl;
	cout << "The element of 4 in the list is in "<<LocateElem(L,4)<<endl;
	if(ListInsert(L,1,0)) cout << "The element of 0 have inserted into the list!"<<endl;
	DispList(L);
	cout << "There are "<<ListLength(L)<<" elements in the list now!"<<endl;
	if(LsitDelete(L,6,e)) cout <<"The element of "<<e <<" has been deleted!"<<endl;
	DispList(L);
	cout << "There are "<<ListLength(L)<<" elements in the list now!"<<endl;
	DestoryList(L);
}
int main(){
	test();
	return 0;
}
