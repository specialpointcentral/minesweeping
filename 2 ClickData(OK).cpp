/*
**函数名 ClickData
**对点击的数据处理。包括坐标，以及左右击。
**将会传出数值x y types 指针
**函数说明 int ClickData (int *x,int *y,int *types)
**输入值 无
**输出值 1、0，0表示成功，1表示失败。



**Project:SPC
**Time:16/11/26 13:40
**Ver. 1.0
*/
int ClickData (int *x,int *y,int *types)
{
	int tempx,tempy;//为坐标减一准备 
	printf("请输入坐标和操作\n(x,y,types)\ntypes表示模式，1为点击，2为插旗:");
	scanf("%d,%d,%d",&tempx,&tempy,types);
	*x=tempx-1;
	*y=tempy-1; //坐标与参数统一 
	return 0; 
}
