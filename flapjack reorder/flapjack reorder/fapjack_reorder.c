#include<stdio.h>
#include"flapjack_reorder.h"
unsigned char my_flapjack[FLAPJACK_NUM] = {5,3,13,9,12,19,14,134,53,32,212,176};
void main()
{
	unsigned char i = 0;
	Reorder_flapjack(my_flapjack,FLAPJACK_NUM);
	for(i=0; i<FLAPJACK_NUM; i++){
		printf("%d\n",my_flapjack[i]);
	}

}
void Insert_Num_To_Orderly(
	unsigned char *flapjack_size,
	unsigned char flapjack_num,  //��ǰ����������ݵ�������С�ڵ��������С��
	unsigned char insert_num     //��Ҫ���������
)
{
	unsigned char i = 0;
	unsigned char j = 0;
	while(i < flapjack_num){
		if(flapjack_size[i] > insert_num){
			j = i;
			break;
		}
		i++;
	}
	if(i < flapjack_num){//���������С�ڵ�ǰ������
		for(i=flapjack_num; i>j; i--){
			flapjack_size[i] = flapjack_size[i-1];
		}
		flapjack_size[j] = insert_num;
	}
	else{//��������ݴ��ڵ�ǰ������
		flapjack_size[i] = insert_num;
	}
}
//����
void Reorder_flapjack(
	unsigned char *my_flapjack_size,
	unsigned char my_flapjack_num  //�ӱ�����
)
{
	unsigned char i = 1;
	for(i=1; i<my_flapjack_num; i++){
		Insert_Num_To_Orderly(my_flapjack_size,i,my_flapjack_size[i]);
	}
}