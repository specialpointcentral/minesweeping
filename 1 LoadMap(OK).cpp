/*
**函数名 LoadMap
**画出10*10的地图，即将map bomb数组初始化。
**调用MapUpdate，画出图形。
**注意对函数MapUpdate参数赋值（指针参数）
**函数说明 int LoadMap (int map[10][10],int bomb[10][10])
**输入值 全局变量map的地址，全局变量bomb的地址。
**输出值 1、0，0表示成功，1表示失败。

**Project:SPC
**Time:16/11/26 8:40
**Ver. 1.0
*/
int LoadMap (int map[10][10],int bomb[10][10])
{
	int i,j;//循环遍历变量 
	int a,b;//随机地雷方位变量 
	int nums;//地雷数 
	for (i=0;i<=10-1;i++)
		for(j=0;j<=10-1;j++)
		{//初始化地图和地雷 
			map[i][j]=-1;
			bomb[i][j]=0;
		}
	srand( (unsigned)time( NULL ) );//初始化随机数种子
	while(nums<=10)
	{
		a=rand()%10;//产生随机数a用于列
		b=rand()%10;//产生随机数b用于行 
		if(bomb[a][b]==1) nums--;//如果此处有雷，则放弃此处，为保证此次循环雷数与上次不变，雷数减一 
		else bomb[a][b]=1;//变成地雷 
		nums++;//地雷数加一 
	}
	return 0;
}
