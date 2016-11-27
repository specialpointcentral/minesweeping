/*
**函数名 MapUpdate
**清屏并重新打印map数组。调用printf。
**注意 请不要改变map[ ][ ]值。打印前请清屏（system("cls")）
**同时所有的数据都要用图形替换
**未扫的块 -1 ■
**已经扫的块 n（n表示周围的雷数，周围无雷的情况用0）（n<=8）□
**插旗的块 -2 ★
**地雷 -3 ●
**函数说明 int MapUpdate (int map[10][10])
**输入值 map的地址。
**输出值 1、0，0表示成功，1表示失败。


**Project:SPC
**Time:16/11/26 13:40
**Ver. 1.0
*/
int MapUpdate (int map[10][10])
{
 	int i,j;//行列循环 
 	system("cls"); //清屏，准备下一次打印 
	for (i=0;i<=10-1;i++)
	{
		for(j=0;j<=10-1;j++)
		{
			switch(map[i][j])
			{
			//条件判断
			//未扫的块 -1 
			//已经扫的块 n（n表示周围的雷数，周围无雷的情况用0）（n<=8）
			//插旗的块 -2 
			//地雷 -3 
			case -1: printf("■");break;
			case -2: printf("★");break;
			case -3: printf("●");break;
			case 0:printf("  ");break;//0颗雷 
			default: printf("%d ",map[i][j]);break;
			}
		}
		printf("\n");//换行 
	}
}
