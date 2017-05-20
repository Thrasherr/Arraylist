# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

typedef struct Array
{
	int *pBase;//��ַ
	int len;//����
	int cnt;//��ЧԪ�صĸ���
}AR, *PAR;

void init_Arr(PAR, int);//��ʼ��
bool append(PAR, int); //׷��
bool insert_Arr(PAR, int, int);//����
bool delete_Arr(PAR pArr, int loc);//ɾ��
int get(PAR, int);//��ȡ
bool is_Empty(PAR);//�ж��Ƿ�Ϊ��
bool is_Full(PAR);//��
bool sort_Arr(PAR,int);//���� ...//Ŀǰ�����ܶ���ͬ�����������Ľ�
void show_Arr(PAR);//��ʾ
void inversion_Arr(PAR);//����


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
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	else {
		pArr->len = length;
		pArr->cnt = 0;
	}
	
}
bool is_Empty(PAR pArr) //��
{
	if((pArr->cnt) == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool is_Full(PAR pArr) //��
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
		printf("����Ϊ��,��������Ч��ֵ\n");
	}
	else {
		for(i=0; i<pArr->cnt; i++) {
			printf("��%d��Ԫ�� = %d\n", i, (pArr->pBase)[i]);
		}
	}
}
bool append(PAR pArr, int value)
{
	if(is_Full(pArr)) {
		printf("�Ѿ������޷����\n");
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
		printf("��Ǹ�޷�����,��������!!!\n");
		return false;
	}
	if(loc<0 || loc>pArr->cnt) {
		printf("��Ǹ����λ�ô�������loc��1 ~ %d�в���\n", pArr->cnt);
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
		printf("����ɾ������%d\n", (pArr->pBase)[pArr->cnt - 1]);
		--(pArr->cnt);
		return true;
	}
	else {
		printf("��Ǹ�����������鷳��������\n");
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
bool sort_Arr(PAR pArr, int s) //ð��
{
	int i,j,t;
	//1�Ǵ�С����
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
		//2�ǴӴ�С
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
	printf("������ȡ��%d��ֵΪ%d\n", loc, i);
	return i;
}	
