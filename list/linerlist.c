#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

#define NOERR 0
#define ERROR -1
#define NOFIND -100

typedef int elem;
typedef LinerList linerlist;

struct LinerList
{
	int len;
	int size;
	elem* liner;
};

linerlist* initLinerList(int num)
{
	linerlist* list = NULL;
	list = (linerlist*)malloc(sizeof(linerlist));
	if( list == NULL)
	{
		printf("memory out \n");
		return NULL;
	}
	list->len = 0;
	list->size = num;
	list->liner = (elem*)malloc(sizeof(elem)*list->size);
	{
		printf("memry out\n");
		free(list);
		return NULL;
	}
	memset(list->liner,0,sizeof(elem)*list->size);
	return list;
}

int clearList(linerlist* list)
{
	if(list == NULL)
	{
		printf("the list is null\n");
		return ERROR;
	}
	list->len = 0;
	memset(list->liner,0,sizeof(elem)*list->size);
	return NOERR;
}

int listEmpty(linerlist* list)
{
	if(list == NULL)
	{
		printf("the list is null\n");
		return ERROR;
	}
	if(list->len)
	{
		return FALSE;
	}
	return TRUE;
}

int listLenth(linerlist* list)
{
	if(list == NULL)
	{
		printf("the list is null\n");
		return ERROR;
	}
	return list->len;
}

int getElem(linerlist* list, int i, elem* el)
{
	if(list == NULL)
	{
		printf("the list is null\n");
		return ERROR;
	}
	if(el == NULL)
	{
		printf("the elem is null\n");
		return ERROR;
	}
	if(abs(i)>= list->len)
	{
		printf("the i out of the list lenth\n");
		return ERROR;
	}
	memcpy(el,list->liner[(i+list->len)%list->len],sizeof(elem));
	return NOERR;
}

int locateElem(linerlist* list, elem* el, int (compare*)(elem* ,elem* ))
{
	int i;
	if(list==NULL || el==NULL || compare==NULL)
	{
		printf("the in put para formate err\n");
		return ERROR;
	}
	for(i=0;i<list->len;i++)
	{
		if( NOERR == (*compare)(list->liner+i,el) )
		{
			return i;
		}
	}
	return NOFIND;
}

//int priorElem(linerlist* list, elem* el, pre_e)
//int nextElem

int insertList()
