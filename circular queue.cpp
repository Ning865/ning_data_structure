#include <iostream>
#define MAX 50
using namespace std;
typedef int Elemtype;
typedef struct{
	Elemtype data[MAX];
	int front;
	int rear;
}SqQueue;
//初始化队列
void InitQueue(SqQueue *&q){
	q = (SqQueue*)malloc(sizeof(SqQueue));
	q->front = q->rear = 0;
}
//销毁队列
void DestroyQueue(SqQueue *&q){
	free(q);
}
//判断队列是否为空
bool QueueEmpty(SqQueue *q){
	return q->rear==q->front ;
}
//进队列
bool enQueue(SqQueue *&q,Elemtype e){
	if(q->rear == MAX-1) return false;
	q->rear = (q->rear+1)%MAX;
	q->data[q->rear]=e;
	return true;
}
//出队列
bool deQueue(SqQueue *&q,Elemtype &e){
	if(q->front==q->rear) return false;
	q->front = (q->front+1)%MAX; 
	e=q->data[q->front];
	return true;
}
void test(){
	SqQueue *q;
	InitQueue(q);
	if(QueueEmpty(q))
		cout << "队列为空" <<endl;
	else cout <<"队列不空" <<endl;
	enQueue(q,1);
	if(QueueEmpty(q))
		cout << "队列为空" <<endl;
	else cout <<"队列不空" <<endl;
	enQueue(q,2);
	int t;
	deQueue(q,t);
	cout << "t: "<<t<<endl;
	//deQueue(q,t);
	enQueue(q,1);
	cout << "t: "<<t<<endl;
	if(QueueEmpty(q))
		cout << "队列为空" <<endl;
	else cout <<"队列不空" <<endl;
	DestroyQueue(q);
}

