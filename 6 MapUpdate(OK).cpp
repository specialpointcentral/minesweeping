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
	for (i=0;i<=10-1;i++)
	{
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
			case 0:printf("  ");break;//0���� 
			default: printf("%d ",map[i][j]);break;
			}
		}
		printf("\n");//���� 
	}
}
