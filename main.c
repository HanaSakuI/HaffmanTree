#include <stdio.h>
#include "malloc.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10
/**
 *  ���ݽṹ���ߴ�ʵ��ڶ���
 *   ���������Ľ���
 *   ʵ�ֹ��������������
 *   ����ÿһ������Ȩֵ������-1������
 *   ����Ȩֵ���ɹ�������
 *   ����ÿ�����Ĺ���������
 *  @author HanaSakuIroha
 */

typedef int ElemType; //��������
typedef int Status ;
typedef struct Haffman{
     ElemType data;//��������
     char code[MAXSIZE];//����������
     struct Haffman *lchild,*rchild;//����ָ��
     int ltag,rtag; //���ұ�ǩ
} Haffman;//���������ݽṹ
typedef struct LinkedList{
    Haffman *haffman;
    struct LinkedList *next;
} LinkedList;//�������ṹ����
LinkedList *InitList(LinkedList *list){
    list = (LinkedList *)malloc(sizeof(LinkedList));
    list->next = NULL;
    return list;
}
LinkedList *CreateListNode(Haffman *haffman){
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->haffman = haffman;
    list->next = NULL;
    return list;
}//����һ��������
Status InsertListNode(LinkedList *list,Haffman *haffman){
        if (list->next == NULL){//���ֻ��ͷ
            list->next = CreateListNode(haffman);
        }else{
            LinkedList *p = CreateListNode(haffman);
            p->next = list->next;
            list->next = p;
        }
    return TRUE;
}//�������Ԫ��
Status DelectListNode(LinkedList *list,Haffman *haffman){
    LinkedList *p = list->next;
    LinkedList *r = list;
    while (p != NULL){
        if(p->haffman->data == haffman->data){
            r->next = p->next;
            p->next = NULL;
            free(p);
            return TRUE;
        }
         p = p->next;
         r = r->next;
    }
    return FALSE;
}//ɾ������ĳ�����

Status getListLength(LinkedList *list){
    int num = 0;
    LinkedList *p = list->next;//��ʼ��Ϊ��һ�����
    while (p != NULL){
        num++;
        p = p->next;
    }
    return num;
}//��ȡ������

Haffman *CreateHaffmanNode(ElemType elemType){
    Haffman *p = (Haffman *)malloc(sizeof(Haffman));
     p->data = elemType;
     strcpy( p->code , "");
     p->lchild = p->rchild = NULL;
     p->ltag = 0; p->rtag = 1; //��0��1
      return p;
}//�������������

Haffman *getMinNode(LinkedList *linkedList){
    LinkedList *p = linkedList;
    LinkedList *r = linkedList;
    LinkedList *q = NULL;//��Ϊ���ؽ��
    if ( p->next == NULL){return NULL; //û�н��
    }else if(p->next->next == NULL){return p->next->haffman;//ֻ��һ�����
    }else{
        p = linkedList->next;
        r = p->next;
        while (r != NULL){
              if (p->haffman->data <= r->haffman->data){
                  q = p; //�ж˽���q
              } else{
                  q = r;//��Сֵָ��r��
                  p = r; //��p�Ƶ�r
              }
            r = r->next;
        }
        return q->haffman;
    }

}//��ȡ��С�Ľ��

Haffman *CreateHaffman(Haffman *haffman,LinkedList *linkedList){
    if (getListLength(linkedList) == 0){return  NULL;} //������ ����NULL
    Haffman *lhaffman, *rhaffman,*newNode;
    while (getListLength(linkedList) != 1){
            lhaffman = getMinNode(linkedList);
            DelectListNode(linkedList,lhaffman);
            rhaffman = getMinNode(linkedList);
            DelectListNode(linkedList,rhaffman);
            // ��ȡ������С���

            newNode = CreateHaffmanNode(0);
            newNode->data = lhaffman->data + rhaffman->data;
            newNode->lchild = lhaffman; newNode->rchild = rhaffman;
            //����һ���½ڵ� ��ʼ��

            InsertListNode(linkedList,newNode);
            //���½ڵ���뵽������
    }

     haffman = getMinNode(linkedList);
    return haffman;
}
Status HaffmanCode(Haffman *haffman){
    if (haffman == NULL){return FALSE;}
    else{
        if (haffman->lchild ){
           strcpy(haffman->lchild->code ,  haffman->code);
            strcat(haffman->lchild->code ,  "0");
            HaffmanCode(haffman->lchild);
            }
        if (haffman->rchild ){
            strcpy(haffman->rchild->code ,  haffman->code);
            strcat(haffman->rchild->code ,  "1");
            HaffmanCode(haffman->rchild);
        }
        //if (haffman->lchild ){ HaffmanCode(haffman->lchild);}
       // if (haffman->rchild ){ HaffmanCode(haffman->rchild);}
    }
}
int print_Hafffman(Haffman *haffman){
    if (haffman == NULL){return FALSE;}
    else{
        printf("%d\t",haffman->data);
        if(haffman->lchild){ printf("%d\t",haffman->lchild->data);}
        else { printf("NULL\t");	}
        if(haffman->rchild){ printf("%d\t",haffman->rchild->data);}
        else { printf("NULL\t");	}
        printf("%s\n",haffman->code);

        if (haffman->lchild ){ print_Hafffman(haffman->lchild);}
        if (haffman->rchild ){ print_Hafffman(haffman->rchild);}
        return TRUE;
    }
}
int main() {
    int data,i = 1;
    printf("��������\n");
    printf("������ÿһ������Ȩֵ������ -1 �Խ�������\n");
    printf("�������%d������Ȩֵ:",i++);
    LinkedList *linkedList;
  //  linkedList = (LinkedList *)malloc(sizeof(LinkedList));
   // linkedList->haffman = NULL;
   // linkedList->next = NULL;
    linkedList =  InitList(linkedList);
     Haffman *haffman;

    scanf("%d",&data);
     while (data != -1){
      InsertListNode(linkedList,CreateHaffmanNode(data));
         printf("�������%d������Ȩֵ:",i++);
         scanf("%d",&data);
     }
  /*  InsertListNode(linkedList,CreateHaffmanNode(2));
    InsertListNode(linkedList,CreateHaffmanNode(4));
    InsertListNode(linkedList,CreateHaffmanNode(3));
    InsertListNode(linkedList,CreateHaffmanNode(11));*/

    printf("\n������%d�����\n",getListLength(linkedList));
   haffman = CreateHaffman(haffman,linkedList);
   printf("���ɵĹ�������Ϊ:\n");
   printf("Ȩֵ\t����\t�Һ���\t����������\n");
   HaffmanCode(haffman);
    print_Hafffman(haffman);
    return 0;
}
