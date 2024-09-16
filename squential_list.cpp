#include <iostream>
#include <cstdlib>
#define MAX_SIZE 50
using namespace std;
typedef int Elem;
typedef struct{
    Elem val[MAX_SIZE];
    int length;
}SqL;
//创建顺序表
void CreatList(SqL *&L,Elem a[],int n){
    for(int i=0;i<n;++i){
        L->val[i]=a[i];
    }
    L->length=n;
}
//初始化顺序表
void InitList(SqL *&L){
    L = (SqL*)malloc(sizeof(SqL));
	L -> length = 0 ;
}
//销毁线性表
void DestroyList(SqL *&L){
    free(L);
}
//判断线性表是否为空
bool ListEmpty(SqL &L){
    return L.length == 0 ;
}
//求线性表的长度
int ListLength(SqL &L){
	return L.length;
}
//输出线性表
void DispList(SqL &L){
	for(int i=0;i<L.length;++i){
		cout << L.val[i]<< " " ;
	}
	cout << endl ;
}
//按序号求线性表中的元素
bool GetElem(SqL &L,int i,Elem &e){
	if(i>0&&i<=L.length){
		e = L.val[i-1];
		return true;
	}else return false;
}
//按元素查找,查找元素e的位置
int LocateELem(SqL &L,Elem e){
	int i=0;
	while(i<L.length){
		if(L.val[i] == e){
			break;
		}
		++i;
	}
	if(i == L.length) return 0;
	else return i+1 ;
}
//再第i个位置插入元素e
bool ListInsert(SqL &L,int i,Elem e){
	if(i<1||i>L.length+1||L.length==MAX_SIZE)
		return false;
	for(int j=L.length;j>=i;--j){
		L.val[j]=L.val[j-1];
	}
	L.val[i-1] = e;
	++L.length;
	return true;
}
//删除第i个位置的元素，使用e返回该位置的元素值
bool ListDelete(SqL &L,int i,Elem &e){
	if(i<1||i>L.length){
		return false;
	}
	else{
		e = L.val[i-1];
		for(int j=i-1;j<L.length;++j){
			L.val[j]=L.val[j+1];
		}
		--L.length; 
		return true;
	}
}
//测试函数
void test(){
	SqL *L;
	InitList(L);
	int a[5]={1,2,3,4,5};
	cout << "List is empy? "<<ListEmpty(*L)<<endl ;
	CreatList(L,a,5);
	cout << "List is empty? "<<ListEmpty(*L) << endl ;
	DispList(*L);
	cout << "There are "<<ListLength(*L)<<" Elempties in the List" << endl ;
	int e2,e1;
	GetElem(*L,1,e1);
	GetElem(*L,2,e2);
	cout << "The first and second elem is " << e1 <<" and "<<e2<<endl;
	int l5;
	l5 = LocateELem(*L,5);
	cout << "The elem of 5 is in "<<l5<<endl;
	if(ListInsert(*L,2,8)) cout << "Succeed in inserting." << endl ;
	else cout << "Fail to insert!" << endl ;
	DispList(*L);
	cout << "There are "<<ListLength(*L)<<"Elempties in the List" << endl ;
	l5 = LocateELem(*L,5);
	cout << "The elem of 5 is in "<<l5<<endl;
	if(ListDelete(*L,5,l5)) cout << "Succeed in deleting !" <<endl;
	else cout << "Fail to delete !";
	l5 = LocateELem(*L,5);
	DispList(*L);
	cout << "The elem of 5 is in "<<l5<<endl;
	cout << "There are "<<ListLength(*L)<<"Elempties in the List" << endl ;
	DestroyList(L);
}
int main(){
	test();
    return 0;
}
