#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Sqlist.h"

Status InitSqList(Sqlist *L){
    (*L).elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!(*L).elem) exit(ERROR);
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;
    printf("INIT sucessfully!!!\n");
    return OK;
}


void judgeStatus(Status i){
    if(i==ERROR){
        printf("there is something wrong\n");
    }
    if(i==OVERFLOW){
        printf("overflow may be \n");
    }
    if(i==OK)
    printf("fine \n");

}


Status CreateSqList(Sqlist *L,int nagasa){
    srand(time(NULL));
    if(nagasa>=(*L).listsize){
        int *Newbase=(ElemType*)realloc((*L).elem,sizeof(ElemType)*nagasa);
        if(!Newbase)
        {
            printf("fail to realloc");
        }
        (*L).elem=Newbase;
        (*L).listsize=nagasa;
    }
    int i;
    printf("you want to auto generate (press 1)or input by hand(press 2)?\n");
    char c =getch();
    if(c=='2'){
        for(i=0;i<nagasa;i++){
            scanf("%d",&(*L).elem[i]);
            printf("add element : %d  sucess!!\n",(*L).elem[i]);
            (*L).length++;
        }
    }
    else{
        for(i=0;i<nagasa;i++){
            (*L).elem[i]=rand()%100;
            (*L).length++;
        }
        printf("Generate Success\n");
    }
    return OK;

}

Status PrintSqList(Sqlist L){
    if(!L.elem){
        return ERROR;
    }
	printf("\nstart the travel,\nprint the Squence list right now!\n");
    int i;
    for(i=0;i<L.length;i++)
    {
		printf("%3d",L.elem[i]);
    }
    printf("\n");
    return OK;
}


Status Delete_Element(Sqlist *L, int position ,int *e){
    if(position>(*L).length||position<=0)
    {
        return OVERFLOW;
    }
    ElemType *p=(*L).elem;
    *e=*(p+position-1);
    for(p=(*L).elem+position-1;p<(*L).elem+(*L).length-1;p++)
    {
       *p=*(p+1);
    }
    --(*L).length;
    return OK;

}


Status Insert_Element(Sqlist *L,int position ,ElemType e){
    if ((*L).length >= MAXSIZE)
	{
		return OVERFLOW;
	}
	if (position<=1||position>(*L).length)
	{
		return ERROR;
	}
	int k;
	for (k=(*L).length;k>position;k--)
	{
		(*L).elem[k] = (*L).elem[k - 1];
	}
	(*L).elem[position] = e;
	(*L).length++;
	return OK;

}

Status Get_Element(Sqlist L,int position, int *e){
    if (position<=1||position>L.length)
	{
		return ERROR;
	}
	*e=L.elem[position-1];
	return OK;
}
