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
