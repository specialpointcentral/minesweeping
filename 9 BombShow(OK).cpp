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
