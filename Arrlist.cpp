# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Array
{
	int *pBase;//地址
	int len;//长度
	int cnt;//有效元素的个数
}AR, *PAR;

void init_Arr(PAR, int);//初始化
bool append(PAR, int); //追加
bool insert_Arr(PAR, int, int);//插入
bool delete_Arr(PAR pArr, int loc);//删除
int get(PAR, int);//获取
bool is_Empty(PAR);//判断是否为空
bool is_Full(PAR);//满
bool sort_Arr(PAR,int);//排序 ...//目前还不能对相同的数排序后面改进
void show_Arr(PAR);//显示
void inversion_Arr(PAR);//倒置


void main(void)
{
	AR arr;
	init_Arr(&arr,10);
	append(&arr, 4);
	append(&arr, 3);
	append(&arr, 2);
	append(&arr, 1);
	append(&arr, 8);
	append(&arr, 81);
	append(&arr, 28);
	append(&arr, 84);
	append(&arr, 82);
	
	show_Arr(&arr);
				
				
				
}

void init_Arr(PAR pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if(pArr->pBase == NULL) {
		printf("分配内存失败\n");
		exit(-1);
	}
	else {
		pArr->len = length;
		pArr->cnt = 0;
	}
	
}
bool is_Empty(PAR pArr) //空
{
	if((pArr->cnt) == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool is_Full(PAR pArr) //满
{
	if((pArr->len) == (pArr->cnt)) {
		return true;
	}
	else {
		return false;
	}
}
void show_Arr(PAR pArr)
{
	int i;
	if(is_Empty(pArr)) {
		printf("数组为空,请输入有效数值\n");
	}
	else {
		for(i=0; i<pArr->cnt; i++) {
			printf("第%d个元素 = %d\n", i, (pArr->pBase)[i]);
		}
	}
}
bool append(PAR pArr, int value)
{
	if(is_Full(pArr)) {
		printf("已经满了无法添加\n");
		return false;
	}
	else {
		pArr->pBase[pArr->cnt] = value;//pArr->pBase[pArr->cnt]
		++(pArr->cnt);
		return true;
	}
}
bool insert_Arr(PAR pArr, int loc, int val)
{
	int T, i;
	if(is_Full(pArr)) {
		printf("抱歉无法插入,数组已满!!!\n");
		return false;
	}
	if(loc<0 || loc>pArr->cnt) {
		printf("抱歉插入位置错误，请在loc在1 ~ %d中插入\n", pArr->cnt);
		return false;
	}
	if(is_Empty(pArr)) {
		(pArr->pBase)[loc-1] = val;
		return true;
	}
	for(i=loc; i<=(2*((pArr->cnt)-loc+1) + loc); i++) {
		T = (pArr->pBase)[loc-1];
		(pArr->pBase)[loc-1] = (pArr->pBase)[i];
		(pArr->pBase)[i] = T;		
	}
	(pArr->pBase)[loc-1] = val;
	return true;
}
/*
bool delete_Arr(PAR pArr, int loc)
{
	int i,t;
	
	if(loc>=0 && loc<=(pArr->cnt)) {
		for(i=loc; i<(pArr->cnt); i++) {
			t = (pArr->pBase)[loc-1];
			(pArr->pBase)[loc-1] = (pArr->pBase)[i];
			(pArr->pBase)[i] = t;
		}
		printf("你所删除的是%d\n", (pArr->pBase)[pArr->cnt - 1]);
		--(pArr->cnt);
		return true;
	}
	else {
		printf("抱歉请你别存心找麻烦！！！！\n");
		return false;
	}
}
*/
void inversion_Arr(PAR pArr)
{
	int i=0;
	int j=(pArr->cnt - 1);
	int t;
	while(i >= j) {
		t = (pArr->pBase)[i];
		(pArr->pBase)[i] = (pArr->pBase)[j]; 
		(pArr->pBase)[j] = t;
		i++;
		j--;
	}
}
bool sort_Arr(PAR pArr, int s) //冒泡
{
	int i,j,t;
	//1是从小到大
	if(s == 1) {
		goto a1;
	}
	else {
		goto a2;
	}
a1: {
		for(i=0; i<(pArr->cnt-2); i++) {
			for(j=i+1; j<(pArr->cnt-1); j++) {
				if((pArr->pBase)[i] > (pArr->pBase)[j]) {
					t = (pArr->pBase)[i];
					(pArr->pBase)[i] = (pArr->pBase)[j];
					(pArr->pBase)[j] = t;
				}
			}
		}
		return true;
	}
		//2是从大到小
a2: {
		for(i=0; i<(pArr->cnt-2); i++) {
			for(j=i+1; j<(pArr->cnt-1); j++) {
				if((pArr->pBase)[i] < (pArr->pBase)[j]) {
					t = (pArr->pBase)[i];
					(pArr->pBase)[i] = (pArr->pBase)[j];
					(pArr->pBase)[j] = t;
				}
			}		
		}	
		return true;
	}
}
int get(PAR pArr, int loc)
{
	int i;
	i = (pArr->pBase)[loc-1];
	printf("你所获取第%d个值为%d\n", loc, i);
	return i;
}	
