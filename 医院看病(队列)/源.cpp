#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
#define OK 1
#define OVERFLOW -2
#define ERROR 0
#define MAXSIZE 100
#define MAXQSIZE 100
#define Empty 0 
typedef struct patient
{
    string name[20];
    string num[10];
    struct patient* next;
}patient,*Patient;
typedef struct
{
    Patient front;
    Patient rear;
}LinkQueue;
int InitQueue(LinkQueue& Q)
{   
    Q.front = Q.rear = new patient;
    Q.front->next = NULL;
    return OK;
}
int EnQueue(LinkQueue& Q)
{
    string e, e1;
    patient* p;
    p = new patient;
    cout <<"姓名"<<endl;
    fflush(stdin);
    cin >> e;
    *p->name = e;
    cout << "病历号" << endl;
    fflush(stdin);
    cin >> e1;   
    *p->num = e1;
    p->next = NULL; Q.rear->next = p;
    Q.rear = p;
    return OK;
}
int DeQueue(LinkQueue& Q)
{
    patient* p;
    p = new patient;
    if (Q.front == Q.rear)return ERROR;
    p = Q.front->next;
    Q.front->next = p->next;
    if (Q.rear == p)Q.rear = Q.front;
    delete p;
    return OK;
}
void Traverse(LinkQueue& Q)
{
    patient* p;
    p = Q.front->next;
    while (p != NULL)
    {
        cout <<"姓名：" << *p->name << "    " <<"病历号：" << *p->num << endl;
        p = p->next;
    }
    return;
}
void Traverses(LinkQueue& Q)
{
    patient* p;
    p = Q.front->next;
    while (p != NULL)
    {
        cout << "姓名：" << *p->name << "    " << "病历号：" << *p->num << endl;
        p = p->next;
    }
    return;
}
int main()
{
    LinkQueue Q;
    InitQueue(Q);
    for(int i=0;i<5;i++)
    EnQueue(Q);
    Traverse(Q);
    DeQueue(Q);
    Traverse(Q);
}