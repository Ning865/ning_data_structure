#include <iostream>
using namespace std;
typedef int Elemtype;
typedef struct qnode{
	Elemtype data;
	qnode *next;
}DataNode;
typedef struct{
	DataNode *front;
	DataNode *rear;
}LinkQuNode;
void InitQueue(LinkQuNode *&q){
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front=q->rear=NULL;
}
void Destroy(LinkQuNode *&q){
	DataNode *pre=q->front,*p;
	if(pre!=NULL){
		p=pre->next;
		while(p!=NULL){
			free(pre);
			pre=p;
			p=p->next;
		}
		free(pre);
	}
	free(q);
}
bool QueueEmpty(LinkQuNode *q)
{
	return q->rear==NULL;
}
void enQueue(LinkQuNode *&q,Elemtype e){
	DataNode *s;
	s = (DataNode*)malloc(sizeof(DataNode));
	s->data = e;
	s->next = NULL;
	if(q->rear==NULL){
		q->front=q->rear=s;
	}else{
		q->rear->next = s;
		q->rear = s;
	}
	//free(s);
}
bool deQueue(LinkQuNode *&q,Elemtype &e){
	if(q->rear == NULL) return false;
	DataNode *t;		
	t=q->front;
	if(q->front==q->rear)
		q->front=q->rear=NULL;
	else 
		q->front = q->front->next;
	e=t->data;
	free(t);
	return true;
}
void test(){
	LinkQuNode *q;
	InitQueue(q);
	if(QueueEmpty(q))
		cout << "队列为空！"<<endl;
	else 
		cout << "队列不空！"<<endl;
	enQueue(q,12);
	if(QueueEmpty(q))
		cout << "队列为空！"<<endl;
	else 
		cout << "队列不空！"<<endl;
	enQueue(q,20);
	int t=0;
	deQueue(q,t);
	cout << "t: "<<t<<endl;
	deQueue(q,t);
	cout << "t: "<<t<<endl;
	if(QueueEmpty(q))
		cout << "队列为空！"<<endl;
	else 
		cout << "队列不空！"<<endl;
	Destroy(q);
}

