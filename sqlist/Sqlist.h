#ifndef SHUNXUBIAO_H_INCLUDED
#define SHUNXUBIAO_H_INCLUDED



#define ElemType    int
#define Status      int
#define LIST_INIT_SIZE  100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT   10  //���Ա�洢�ռ�ķ�������
#define MAXSIZE 200
#define OK 0
#define ERROR -1
#define OVERFLOW -2



typedef struct{
    ElemType    *elem;//�洢�ռ��ַ
    int length;
    int listsize;
}Sqlist;

Status InitSqList(Sqlist *L);//��ʼ��

Status CreateSqList(Sqlist *L,int nagasa);//��������Ϊlength��sqlist

Status PrintSqList(Sqlist L);

Status Delete_Element(Sqlist *L,int position,ElemType * e);//ɾ��ָ��λ�õ�Ԫ�ز�������ֵ

Status Insert_Element(Sqlist *L,int position,ElemType e);//��ָ��λ��ǰǰ����

Status Get_Element(Sqlist L, int position ,ElemType *e);//��E����L�е�position ��Ԫ�ص�ֵ


void judgeStatus(Status i);


#endif // SHUNXUBIAO_H_INCLUDED


