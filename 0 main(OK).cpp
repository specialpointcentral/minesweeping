#include<stdio.h>
#include<windows.h>
#include<time.h>// ����ʱ���Ʋ����������ʱ�䵱��������� 
#include<stdlib.h>//srand����������  
int main()
{
	int map[10][10],bomb[10][10];//�����ͼ��С 
	int x,y,types;//���������꼰�����ʽ 
	int bombnum=10;//�������� 
	int marks=0;//������Ӯ����  
	LoadMap(map,bomb);//��һ�����г�ʼ����ͼ 
	while(1) //һֱѭ��ֱ����Ӯ 
	{
		MapUpdate(map); //���µ�ͼ 
		ClickData (&x,&y,&types);//����������� 
		if (DataProcess(x,y,types,map,bomb)==2)//���ݺ���DataProcess����ֵ�ж���Ӯ 
		break;//���� ����ѭ��������ʾ�Ѽ����ں���DataProcess�У� 
		marks=WinOrNot (map,bomb,bombnum);
		if (marks!=-1&&marks!=0)//�ж��Ƿ���� 
		return 1;//������ֵΪ1 
		else if(marks==-1)//ʤ�� 
		{
			Gameover (0);
			break;
		} 
	}
	return 0;
} 
