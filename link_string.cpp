#include <iostream>
using namespace std;
#define MiXSIZE 50
typedef struct snode{
	char data;
	snode *next;
}LkString;
//生成串
void StrAssign(LkString *&s,string cstr){
	LkString *p,*r;
	s=(LkString*)malloc(sizeof(LkString));
	s->next=NULL;
	r=s;
	for(int i=0;i<(int)cstr.length();++i){
		p = (LkString*)malloc(sizeof(LkString));
		p->data =  cstr[i];
		r->next = p;
		r=p;
	}
	r->next = NULL;
}
//销毁串
void DestroyStr(LkString *&s){
	LkString *p1=s,*p2=s->next;
	while(p2!=NULL){
		free(p1);
		p1=p2;
		p2=p2->next;
	}
	free(p1);
}
//串复制
void StrCopy(LkString *&s,LkString *t){
	s =(LkString*)malloc(sizeof(LkString));
	s->next = NULL;
	LkString *p=s,*q=t->next,*l;
	while(q!=NULL){
		l=(LkString*)malloc(sizeof(LkString));
		l->data=q->data;
		p->next=l;
		p=l;
		q=q->next;
	}
	p->next = NULL;
}
//判断串是否相等
bool StrEqual(LkString *s,LkString *t){
	LkString *p=s->next,*q=t->next;
	//bool flag=true;
	while(p!=NULL && q!=NULL && p->data==q->data){
		p=p->next;
		q=q->next;
	}
	if(q==NULL && p==NULL) return true;
	else return false;
}
//求串的长度
int StrLength(LkString *s){
	int cnt=0;
	LkString *p=s->next;
	while(p!=NULL){
		++cnt;
		p=p->next;
	}
	return cnt;
}
//串拼接
LkString *Concat(LkString *s,LkString *t){
	LkString *str,*p,*q=t->next,*r,*l;
	//str = (LkString*)malloc(sizeof(LkString));
	StrCopy(str,s);
	l=str;
	while(l!=NULL){
		p=l;
		l=l->next;
	}
	while(q!=NULL){
		r=(LkString*)malloc(sizeof(LkString));
		r->data = q->data;
		p->next=r;
		p=r;
		q=q->next;
	}
	p->next=NULL;
	return str;
}
//求子串
LkString *SubStr(LkString *s,int i,int j){
	LkString *str;
	str = (LkString*)malloc(sizeof(LkString));
	str->next = NULL;
	int k=1;
	if(i+j>StrLength(s)||i<=0)
		return str;
	LkString *p=s->next,*q=str,*t;
	while(k<i){
		p=p->next;
		++k;
	}
	for(int k=0;k<j;++k){
		t = (LkString*)malloc(sizeof(LkString));
		t->data=p->data;
		q->next=t;
		q=t;
		p=p->next;
	}
	q->next=NULL;
	return str;
}
//子串插入
LkString *InStr(LkString *s1,int i,LkString *s2){
	LkString *str;
	str = (LkString*)malloc(sizeof(LkString));
	str->next = NULL;
	if(i<=0 || i>StrLength(s1)+1)
		return str;
	LkString *p=s1->next,*q=str,*t,*p2=s2->next;
	for(int k=1;k<i;++k){
		t=(LkString*)malloc(sizeof(LkString));
		t->data=p->data;
		q->next=t;
		q=t;
		p=p->next;
	}
	while(p2!=NULL){
		t=(LkString*)malloc(sizeof(LkString));
		t->data = p2->data;
		q->next=t;
		q=t;
		p2=p2->next;
	}
	while(p!=NULL){
		t=(LkString*)malloc(sizeof(LkString));
		t->data = p->data;
		q->next=t;
		q=t;
		p=p->next;
	}
	q->next=NULL;
	return str;
}
//子串删除
LkString *DelStr(LkString *s,int i,int j){
	LkString *str;
	str = (LkString*)malloc(sizeof(LkString));
	str->next = NULL;
	if(i<=0 || i+j>=StrLength(s))
		return str;
	LkString *r=str,*t,*p=s->next;
	for(int k=1;k<i;++k){
		t=(LkString*)malloc(sizeof(LkString));
		t->data=p->data;
		r->next=t;
		r=t;
		p=p->next;
	}
	for(int k=0;k<j;++k)
		p=p->next;
	while(p!=NULL){
		t=(LkString*)malloc(sizeof(LkString));
		t->data=p->data;
		r->next=t;
		r=t;
		p=p->next;
	}
	r->next = NULL;
	return str;
}
//子串替换
LkString *RepStr(LkString *s,int i,int j,LkString *s2){
	LkString *str;
	str = (LkString*)malloc(sizeof(LkString));
	str->next = NULL;
	if(i<=0 || i>StrLength(s) || i+j-1 >StrLength(s))
		return str;
	LkString *r=str,*t,*p=s->next,*q=s2->next;
	for(int k=1;k<i;++k){
		t=(LkString*)malloc(sizeof(LkString));
		t->data=p->data;
		r->next=t;
		r=t;
		p=p->next;
	}
	while(q!=NULL){
		t=(LkString*)malloc(sizeof(LkString));
		t->data=q->data;
		r->next=t;
		r=t;
		q=q->next;
	}
	for(int k=0;k<j;++k)
		p=p->next;
	while(p!=NULL){
		t=(LkString*)malloc(sizeof(LkString));
		t->data=p->data;
		r->next=t;
		r=t;
		p=p->next;
	}
	r->next = NULL;
	return str;
}
void DispStr(LkString *s){
	LkString *p=s->next;
	while(p!=NULL){
		cout << p->data<<" ";
		p=p->next;
	}
	cout << endl;
}
void test(){
	string a="abcde";
	//cout << "请输入串得内容：";
	//cin >> a ;
	LkString *s1,*s2;
	StrAssign(s1,a);
	DispStr(s1);
	cout << StrLength(s1)<<endl;
	StrCopy(s2,s1);
	DispStr(s2);
	cout << StrLength(s2)<<endl;
	if(StrEqual(s1,s2)) cout <<"串相等！"<<endl;
	else cout << "串不等！"<<endl;
	LkString *t;
	t=Concat(s1,s2);
	DispStr(t);
	cout << "T: "<<StrLength(t) <<endl;
	LkString *s3=SubStr(s1,1,3);
	DispStr(s3);
	cout << "S3: "<<StrLength(s3)<<endl;
	LkString *s4=InStr(s2,4,s3);
	DispStr(s4);
	cout << "S4: "<<StrLength(s4)<<endl;
	LkString *s5=DelStr(s4,4,3);
	DispStr(s5);
	cout << "S5 : "<<StrLength(s5)<<endl;
	LkString *s6=RepStr(s1,1,1,s3);
	DispStr(s6);
	cout << "S6: "<<StrLength(s6);
}

