#include<stdio.h>
#include<stdlib.h>

typedef struct qnode
{
    int data;
    struct qnode* next;
} DataNode;

typedef struct
{
    DataNode *front,*rear;
} LinkQuNode;

void SeeDoctor(void);
void Enqueue(LinkQuNode* &qu,DataNode* &p);
void ReceiveTreatment(LinkQuNode* &qu,DataNode* &p);
void CheckQueue(LinkQuNode* &qu,DataNode* &p);
void StopEnqueuingAndReceiveTreatmentInOrder(LinkQuNode* &qu,DataNode* &p,int &flag);
void BeOffWork(LinkQuNode* &qu,DataNode* &p,int &flag);
void DestroyQueue(LinkQuNode* &qu,DataNode* &p);

int main(void)
{
    SeeDoctor();
    return 0;
}

void SeeDoctor(void)
{
    int selection;
    int flag=1;
    LinkQuNode *qu;
    DataNode *p;
    qu=(LinkQuNode *)malloc(sizeof(LinkQuNode)); 
    qu->front=qu->rear=NULL;

    printf("����ģ�����\n\n");
    while (flag==1)                             
    {
        printf("\n");
        printf("1:�Ŷ� 2:���� 3:�鿴�Ŷ� 4.�����Ŷ�,�������ξ��� 5:�°�  ��ѡ��:");
        scanf("%d",&selection);
        switch(selection)
        {
        case 1:
            Enqueue(qu,p);
            break;
        case 2:
            ReceiveTreatment(qu,p);
            break;
        case 3:
            CheckQueue(qu,p);
            break;
        case 4:
            StopEnqueuingAndReceiveTreatmentInOrder(qu,p,flag);
            break;
        case 5:
            BeOffWork(qu,p,flag);
            break;
        }
    }
    DestroyQueue(qu,p);
}

void Enqueue(LinkQuNode* &qu,DataNode* &p)
{
    int isfind,number;

    printf("\n");
    printf("  >>�����벡����:");
    do
    {
        scanf("%d",&number);
        isfind=0;
        p=qu->front;
        while (p!=NULL && isfind == 0)
        {
            if (p->data==number)
                isfind=1;
            else
                p=p->next;
        }
        if (isfind)
            printf("  >>����Ĳ������ظ�,��������:");
    }while (isfind==1);

    p=(DataNode *)malloc(sizeof(DataNode));
    p->data=number;
    p->next=NULL;
    if (qu->rear==NULL)                 /*��һ�������Ŷ�*/
    {
        qu->front=qu->rear=p;
    }
    else
    {
        qu->rear->next=p;
        qu->rear=p; /*��*p������*/
    }

}

void ReceiveTreatment(LinkQuNode* &qu,DataNode* &p)
{
    if (qu->front==NULL)                /*�ӿ�*/
        printf("  >>û���ŶӵĲ���!\n");
    else                                /*�Ӳ���*/
    {
        p=qu->front;
        printf("  >>����%d����\n",p->data);
        if (qu->rear==p)            /*ֻ��һ�������Ŷӵ����*/
        {
            qu->front=qu->rear=NULL;
        }
        else
            qu->front=p->next;
        free(p);
    }
}

void CheckQueue(LinkQuNode* &qu,DataNode* &p)
{
    if (qu->front==NULL)            /*�ӿ�*/
        printf("  >>û�����еĲ���!\n");
    else                            /*�Ӳ���*/
    {
        p=qu->front;
        printf("  >>�ŶӲ���:");
        while (p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
}

void StopEnqueuingAndReceiveTreatmentInOrder(LinkQuNode* &qu,DataNode* &p,int &flag)
{
    if (qu->front==NULL)            /*�ӿ�*/
        printf("  >>û�����еĲ���!\n");
    else                            /*�Ӳ���*/
    {
        p=qu->front;
        printf("  >>���˰�����˳�����:");
        while (p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("\n");
    }
    flag=0;                         /*�˳�*/

}

void BeOffWork(LinkQuNode* &qu,DataNode* &p,int &flag)
{
    if (qu->front!=NULL)            /*�Ӳ���*/
        printf("  >>���ŶӵĲ��������ҽ!\n");
    flag=0;                     /*�˳�*/
}

void DestroyQueue(LinkQuNode* &qu,DataNode* &p)
{
    p=qu->front;  //���ٶ���
    DataNode* q;
    while (p!=NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
}