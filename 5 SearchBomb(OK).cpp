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

