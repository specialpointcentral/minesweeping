/*
**������ ClickData
**�Ե�������ݴ����������꣬�Լ����һ���
**���ᴫ����ֵx y types ָ��
**����˵�� int ClickData (int *x,int *y,int *types)
**����ֵ ��
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
