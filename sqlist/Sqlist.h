#ifndef SHUNXUBIAO_H_INCLUDED
#define SHUNXUBIAO_H_INCLUDED



#define ElemType    int
#define Status      int
#define LIST_INIT_SIZE  100 //线性表存储空间的初始分配量
#define LISTINCREMENT   10  //线性表存储空间的分配增量
#define MAXSIZE 200
#define OK 0
#define ERROR -1
#define OVERFLOW -2



typedef struct{
    ElemType    *elem;//存储空间基址
    int length;
    int listsize;
}Sqlist;

Status InitSqList(Sqlist *L);//初始化

Status CreateSqList(Sqlist *L,int nagasa);//创建长度为length的sqlist

Status PrintSqList(Sqlist L);

Status Delete_Element(Sqlist *L,int position,ElemType * e);//删除指定位置的元素并返回其值

Status Insert_Element(Sqlist *L,int position,ElemType e);//在指定位置前前插入

Status Get_Element(Sqlist L, int position ,ElemType *e);//用E返回L中第position 个元素的值


void judgeStatus(Status i);


#endif // SHUNXUBIAO_H_INCLUDED


