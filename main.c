#include <stdio.h>
#include "malloc.h"
#include "string.h"
#define TRUE 1
#define FALSE 0
#define MAXSIZE 10
/**
 *  数据结构第七次实验第二题
 *   哈夫曼树的建立
 *   实现哈夫曼编码和译码
 *   输入每一个结点的权值，输入-1结束。
 *   根据权值生成哈夫曼树
 *   给出每个结点的哈夫曼编码
 *  @author HanaSakuIroha
 */

typedef int ElemType; //数据类型
typedef int Status ;
typedef struct Haffman{
     ElemType data;//数据类型
     char code[MAXSIZE];//哈夫曼编码
     struct Haffman *lchild,*rchild;//左右指针
     int ltag,rtag; //左右标签
} Haffman;//哈夫曼数据结构
typedef struct LinkedList{
    Haffman *haffman;
    struct LinkedList *next;
} LinkedList;//哈夫曼结构链表
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
}//创建一个链表结点
Status InsertListNode(LinkedList *list,Haffman *haffman){
        if (list->next == NULL){//如果只有头
            list->next = CreateListNode(haffman);
        }else{
            LinkedList *p = CreateListNode(haffman);
            p->next = list->next;
            list->next = p;
        }
    return TRUE;
}//链表插入元素
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
}//删除链表某个结点

Status getListLength(LinkedList *list){
    int num = 0;
    LinkedList *p = list->next;//初始化为第一个结点
    while (p != NULL){
        num++;
        p = p->next;
    }
    return num;
}//获取链表长度

Haffman *CreateHaffmanNode(ElemType elemType){
    Haffman *p = (Haffman *)malloc(sizeof(Haffman));
     p->data = elemType;
     strcpy( p->code , "");
     p->lchild = p->rchild = NULL;
     p->ltag = 0; p->rtag = 1; //左0右1
      return p;
}//创建哈夫曼结点

Haffman *getMinNode(LinkedList *linkedList){
    LinkedList *p = linkedList;
    LinkedList *r = linkedList;
    LinkedList *q = NULL;//作为返回结点
    if ( p->next == NULL){return NULL; //没有结点
    }else if(p->next->next == NULL){return p->next->haffman;//只有一个结点
    }else{
        p = linkedList->next;
        r = p->next;
        while (r != NULL){
              if (p->haffman->data <= r->haffman->data){
                  q = p; //中端结点给q
              } else{
                  q = r;//将小值指向r处
                  p = r; //把p移到r
              }
            r = r->next;
        }
        return q->haffman;
    }

}//获取最小的结点

Haffman *CreateHaffman(Haffman *haffman,LinkedList *linkedList){
    if (getListLength(linkedList) == 0){return  NULL;} //空链表 返回NULL
    Haffman *lhaffman, *rhaffman,*newNode;
    while (getListLength(linkedList) != 1){
            lhaffman = getMinNode(linkedList);
            DelectListNode(linkedList,lhaffman);
            rhaffman = getMinNode(linkedList);
            DelectListNode(linkedList,rhaffman);
            // 获取两个最小结点

            newNode = CreateHaffmanNode(0);
            newNode->data = lhaffman->data + rhaffman->data;
            newNode->lchild = lhaffman; newNode->rchild = rhaffman;
            //建立一个新节点 初始化

            InsertListNode(linkedList,newNode);
            //将新节点插入到链表中
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
    printf("哈夫曼树\n");
    printf("请输入每一个结点的权值，输入 -1 以结束输入\n");
    printf("请输入第%d个结点的权值:",i++);
    LinkedList *linkedList;
  //  linkedList = (LinkedList *)malloc(sizeof(LinkedList));
   // linkedList->haffman = NULL;
   // linkedList->next = NULL;
    linkedList =  InitList(linkedList);
     Haffman *haffman;

    scanf("%d",&data);
     while (data != -1){
      InsertListNode(linkedList,CreateHaffmanNode(data));
         printf("请输入第%d个结点的权值:",i++);
         scanf("%d",&data);
     }
  /*  InsertListNode(linkedList,CreateHaffmanNode(2));
    InsertListNode(linkedList,CreateHaffmanNode(4));
    InsertListNode(linkedList,CreateHaffmanNode(3));
    InsertListNode(linkedList,CreateHaffmanNode(11));*/

    printf("\n共输入%d个结点\n",getListLength(linkedList));
   haffman = CreateHaffman(haffman,linkedList);
   printf("生成的哈夫曼树为:\n");
   printf("权值\t左孩子\t右孩子\t哈夫曼编码\n");
   HaffmanCode(haffman);
    print_Hafffman(haffman);
    return 0;
}
