#include<stdio.h>
#include<windows.h>
#include<time.h>// ����ʱ���Ʋ����������ʱ�䵱��������� 
#include<stdlib.h>//srand����������  
int main()
{
	int LoadMap (int map[10][10],int bomb[10][10]);
	int ClickData (int *x,int *y,int *types);
	int DataProcess (int x, int y,int types,int map[10][10],int bomb[10][10]);
	int DrawFlag (int x,int y, int map[10][10]);
	int SearchBomb (int x, int y, int map[10][10],int bomb[10][10]);
	int MapUpdate (int map[10][10]);
	int WinOrNot (int map[10][10],int bomb[10][10],int bombnum);
	int Gameover (int flags);
	int BombShow (int map[10][10],int bomb[10][10]); 
	
	
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
	system("pause");
	return 0;
} 

/*
**������ LoadMap
**����10*10�ĵ�ͼ������map bomb�����ʼ����
**����MapUpdate������ͼ�Ρ�
**ע��Ժ���MapUpdate������ֵ��ָ�������
**����˵�� int LoadMap (int map[10][10],int bomb[10][10])
**����ֵ ȫ�ֱ���map�ĵ�ַ��ȫ�ֱ���bomb�ĵ�ַ��
**���ֵ 1��0��0��ʾ�ɹ���1��ʾʧ�ܡ�

**Project:SPC
**Time:16/11/26 8:40
**Ver. 1.0
*/
int LoadMap (int map[10][10],int bomb[10][10])
{
	int i,j;//ѭ���������� 
	int a,b;//������׷�λ���� 
	int nums=1;//������ 
	for (i=0;i<=10-1;i++)
		for(j=0;j<=10-1;j++)
		{//��ʼ����ͼ�͵��� 
			map[i][j]=-1;
			bomb[i][j]=0;
		}
	srand( (unsigned)time( NULL ) );//��ʼ�����������
	while(nums<=10)
	{
		a=rand()%10;//���������a������
		b=rand()%10;//���������b������ 
		if(bomb[a][b]==1) nums--;//����˴����ף�������˴���Ϊ��֤�˴�ѭ���������ϴβ��䣬������һ 
		else bomb[a][b]=1;//��ɵ��� 
		nums++;//��������һ 
	}
	return 0;
}

/*
**������ ClickData
**�Ե�������ݴ����������꣬�Լ����һ���
**���ᴫ����ֵx y types ָ��
**����˵�� int ClickData (int *x,int *y,int *types)
**����ֵ x,y,types��ָ������� 
**���ֵ 1��0��0��ʾ�ɹ���1��ʾʧ�ܡ�

**Project:SPC
**Time:16/11/26 13:40
**Ver. 1.0
*/
int ClickData (int *x,int *y,int *types)
{
	int tempx,tempy;//Ϊ�����һ׼�� 
	printf("����������Ͳ���\n(x,y,types)\ntypes��ʾģʽ��1Ϊ�����2Ϊ����:");
	scanf("%d,%d,%d",&tempx,&tempy,types);
	*x=tempx-1;
	*y=tempy-1; //���������ͳһ 
	return 0; 
}



/*
**������ DataProcess
**��������xy�Լ�����������Ҽ���ͬʱ�ж�����Ƿ�Ϸ���
**����˵�� int DataProcess (int x, int y,int types)
**����ֵ x���꣬y���꣬������Ҽ���1���,2�һ���
**���ֵ 1��0��0��ʾ�ɹ���1��ʾʧ�ܡ�
**ע�� �ⲿ�ֽ���������������
**������Ϸ���������������ĺ���������������������ͼ�θ��º�����ʤ���жϺ����ȡ�������Ҫģ�顣

**Project:SPC
**Time:16/11/26 8:40
**Ver. 1.0
*/
int DataProcess (int x, int y,int types,int map[10][10],int bomb[10][10])
{
	int ClickData (int *x,int *y,int *types);
	int DataProcess (int x, int y,int types,int map[10][10],int bomb[10][10]);
	int DrawFlag (int x,int y, int map[10][10]);
	int SearchBomb (int x, int y, int map[10][10],int bomb[10][10]);
	int MapUpdate (int map[10][10]);
	int WinOrNot (int map[10][10],int bomb[10][10],int bombnum);
	int Gameover (int flags);
	int BombShow (int map[10][10],int bomb[10][10]); 
	
	int marks;//SearchBomb����ֵ��־ 
	int i,j;//���б������� 
	if (map[y][x]==-1||map[y][x]==-2)//�ж��Ƿ�����Ч��� 
	{
		if(types==1)
		{//��� 
			if(bomb[y][x]==1)//�ж��Ƿ��ǵ��� 
			{
				BombShow (map,bomb);//��ʾ���� 
				MapUpdate(map);//���µ�ͼ 				//�ⲿ��û���������ж� 
				Gameover(1);//������Ϸ�������� 
				return 2; 
			}
			
			else//���ǵ��� 
			{
				marks=SearchBomb(x,y,map,bomb);
				if (marks==-1)
				{//��־��Χ���ף�ģ������Χ 
					 for (i=y-1;i<=y+1;i++)//���в��� 
						for (j=x-1;j<=x+1;j++)//���в��� 
						{
							if (i>9||j>9||i<0||j<0)//��ֹ���ҳ��� 
							continue;
							DataProcess(j,i,1,map,bomb);//ģ���� 
						}
				}
				else if (marks==0)
				{//��־��Χ���� 
					return MapUpdate(map);//���µ�ͼ 
				} 
				else return 1; //���� 
			}
		}
		else if (types==2)//�һ� 
		{//������ 
			if (DrawFlag(x,y,map)==0) 
			return MapUpdate(map);//���µ�ͼ 
			else return 1;
		}
		else return 1;//���� 
	}
	else//����ִ�к��� 
	return 0;
}

/*
**������ DrawFlag
**���Ѿ��������ĵ�ȡ�����ģ���Ϊδɨ������δ�������ĵģ���Ϊ���ġ�
**ע�� map[ ][ ]���Ӧ����ֵ
**����˵�� int DrawFlag (int x,int y, int map[10][10])
**����ֵ x���꣬y���꣬map�ĵ�ַ��
**���ֵ 1��0��0��ʾ�ɹ���1��ʾʧ�ܡ�

**Project:LC
**Time:16/11/26 9:15
**Ver. 1.0
*/
int DrawFlag(int x,int y,int map[10][10])//���캯�� 
{
	if(map[y][x]==-1)//����õ�ͼ��δ���� 
	map[y][x]=-2;//���õ�ͼ����� 
	else if(map[y][x]==-2)//����õ�ͼ���Ѿ����� 
	map[y][x]=-1;//���õ�ͼ�����ȡ�� 
	else return 1;//���ش���ֵ 
	return 0;
}


/*
**������ SearchBomb
**������Ӧxy�Ŀ���Χ������Ŀ������map�����ӦԪ��ֵΪ�������������ش�������
**ע�� bomb[ ][ ]�벻Ҫ����ֵ��map[ ][ ]���Ӧ����ֵ
**����˵�� int SearchBomb (int x, int y, int map[10][10],int bomb[10][10])
**����ֵ x���꣬y���꣬map�ĵ�ַ��bomb�ĵ�ַ��
**���ֵ 1��0��-1��-1��ʾ�ɹ�������Χ���ף�0��ʾ�ɹ�������Χ���ף�1��ʾʧ�ܡ�

**Project:YY
**Time:16/11/26 15:11
**Ver. 1.0
*/
int SearchBomb (int x, int y, int map[10][10],int bomb[10][10]) 
{
	int i,j;//���б������� 
	int numbs=0;//����ͳ�� 
	for (i=y-1;i<=y+1;i++)//���в��� 
		for (j=x-1;j<=x+1;j++)//���в��� 
		{
		 if (i>9||j>9||i<0||j<0)//��ֹ���ҳ��� 
		 continue;
		 numbs+=bomb[i][j];
		}
	map[y][x]=numbs;//���µ�ͼλ�� 
	if (numbs==0) return -1;//û�е��� 
	else return 0;//�е��� 
}


/*
**������ MapUpdate
**���������´�ӡmap���顣����printf��
**ע�� �벻Ҫ�ı�map[ ][ ]ֵ����ӡǰ��������system("cls")��
**ͬʱ���е����ݶ�Ҫ��ͼ���滻
**δɨ�Ŀ� -1 ��
**�Ѿ�ɨ�Ŀ� n��n��ʾ��Χ����������Χ���׵������0����n<=8����
**����Ŀ� -2 ��
**���� -3 ��
**����˵�� int MapUpdate (int map[10][10])
**����ֵ map�ĵ�ַ��
**���ֵ 1��0��0��ʾ�ɹ���1��ʾʧ�ܡ�

**Project:SPC
**Time:16/11/26 13:40
**Ver. 1.0
*/
int MapUpdate (int map[10][10])
{
 	int i,j;//����ѭ�� 
 	system("cls"); //������׼����һ�δ�ӡ
	printf("  ");//��֤���� 
 	for (i=1;i<=10;i++)
 	printf("%d ",i);//��ӡ������ 
 	printf(" X����");//��ӡ����ʾ 
 	printf("\n");
 	
	for (i=0;i<=10-1;i++)
	{
		if(i<9) 
		printf("%d ",i+1); //��ӡ1-9������ 
		else
		printf("%d",i+1); //��10�����ӡ 
		for(j=0;j<=10-1;j++)
		{
			switch(map[i][j])
			{
			//�����ж�
			//δɨ�Ŀ� -1 
			//�Ѿ�ɨ�Ŀ� n��n��ʾ��Χ����������Χ���׵������0����n<=8��
			//����Ŀ� -2 
			//���� -3 
			case -1: printf("��");break;
			case -2: printf("��");break;
			case -3: printf("��");break;
			case 0:printf("��");break;//0���� 
			default: printf("%d ",map[i][j]);break;
			}
		}
		printf("\n");//���� 
	}
	printf("Y����");//��ӡ��ʾ 
	printf("\n");//���� 
}

/*
**������ WinOrNot
**�ж��Ƿ�ʤ���������ش�������
**��ʾ ����map���飬�ж�����"δɨ�Ŀ�"�Լ��ȶԱ����ĵĿ����Ƿ�������һ�£�����ͬʱ���㣩Ҳ����������������bomb��ַҲ���ˣ������뿴~
**ע�� �벻Ҫ�ı�map[ ][ ]��bomb[ ][ ]ֵ
**����˵�� int WinOrNot (int map[10][10],int bomb[10][10],int bombnum)
**����ֵ map�ĵ�ַ, bomb�ĵ�ַ��������
**���ֵ 1��0��-1��-1��ʾ�ɹ�������Ϸʤ����0��ʾ�ɹ�����Ϸû��ʤ����1��ʾʧ�ܡ�

**Project:SPC
**Time:16/11/27 6:31 
**Ver. 1.0
*/
int WinOrNot (int map[10][10],int bomb[10][10],int bombnum)
{
 	int i,j;//����ѭ�� 
 	int getflag=0;//������ 
	for (i=0;i<=10-1;i++)
	{
		for(j=0;j<=10-1;j++)
		{
			if(map[i][j]==-1) return 0;//�ж�δɨ������δɨ����û��Ӯ 
			else  if(map[i][j]==-2) getflag++;//�жϲ������Ƿ��������� 
		} 
	}
	if (getflag!=bombnum) return 0;//��������������������û��Ӯ
	/*
	�Է���һ���ж������Ƿ�������� ��ο���ʡ���Լӿ�����ٶ� 
	*/ 
	for (i=0;i<=10-1;i++)
	{
		for(j=0;j<=10-1;j++)
		{
			if(map[i][j]==-2) 
			{
				if (bomb[i][j]!=1) return 0;//�жϲ���ط��Ƿ����� 
			}
			if(bomb[i][j]==1) 
			{
				if (map[i][j]!=-2) return 0;//�жϵ������Ƿ����� 
			}
		} 
	} 
	return -1;//ʤ����־ 
}

/*
**������ Gameover
**ע�� �벻Ҫ������ֱ��printf("\n");����Ȼ���ӡ����
**������ַ����������ɣ���Ӯ����Ū�ò�ͬһ��ɣ�������ģ�������ʾ�����ף���μ�ģ��9��������printf��
**����˵�� int Gameover (int flags)
**����ֵ ��־��1��0��1���ˣ�0Ӯ�ˡ�
**���ֵ 1��0��0��ʾ�ɹ���1��ʾʧ�ܡ�

**Project:SPC
**Time:16/11/27 6:37 
**Ver. 1.0
*/
int Gameover (int flags)
{
	printf("\n"); 
 	if(flags==1)
		printf("���ź�����ȵ�����") ;
	else if(flags==0)
		printf("��ϲʤ��");
	else return 1;//�����д�,����1
	return 0;//��������0 
}

/*
**������ BombShow
**��ʾ �Ƚ�bomb���׵���Ϣд��map�У�map�е���ֵΪ-3��,Ȼ�����MapUpdate
**ע�� �벻Ҫ�ı�bomb[ ][ ]ֵ��map[ ][ ]�ı���ע�⡣ 
**����˵�� int BombShow (int map[10][10],int bomb[10][10])
**����ֵ map�ĵ�ַ, bomb�ĵ�ַ��
**���ֵ 1��0��0��ʾ�ɹ���1��ʾʧ�ܡ�

**Project:SPC
**Time:16/11/27 6:41 
**Ver. 1.0
*/
int BombShow (int map[10][10],int bomb[10][10])
{
	int i,j;//����ѭ��
	for (i=0;i<=10-1;i++)
		for(j=0;j<=10-1;j++)
		{
			if(bomb[i][j]==1)//�ж��Ƿ����� 
			map[i][j]=-3;//���ĵ�ͼֵ	
		} 
		return 0;
}
