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
	int nums;//������ 
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
