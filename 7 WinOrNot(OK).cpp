/*
**函数名 WinOrNot
**判断是否胜利，并返回处理结果。
**提示 遍历map数组，判断有无"未扫的块"以及比对标旗帜的块数是否与雷数一致（二者同时满足）也可以用其他方法（bomb地址也给了），想想看~
**注意 请不要改变map[ ][ ]和bomb[ ][ ]值
**函数说明 int WinOrNot (int map[10][10],int bomb[10][10],int bombnum)
**输入值 map的地址, bomb的地址，雷数。
**输出值 1、0、-1，-1表示成功并且游戏胜利，0表示成功但游戏没有胜利，1表示失败。



**Project:SPC
**Time:16/11/27 6:31 
**Ver. 1.0
*/
int WinOrNot (int map[10][10],int bomb[10][10],int bombnum)
{
 	int i,j;//行列循环 
 	int getflag=0;//旗子数 
	for (i=0;i<=10-1;i++)
	{
		for(j=0;j<=10-1;j++)
		{
			if(map[i][j]==-1) return 0;//判断未扫区域，有未扫区域，没有赢 
			else  if(map[i][j]==-2) getflag++;//判断插旗数是否和雷数相等 
		} 
	}
	if (getflag!=bombnum) return 0;//标旗数与地雷数不相符，没有赢
	/*
	以防万一，判断旗帜是否插在雷上 这段可以省略以加快查找速度 
	*/ 
	for (i=0;i<=10-1;i++)
	{
		for(j=0;j<=10-1;j++)
		{
			if(map[i][j]==-2) 
			{
				if (bomb[i][j]!=1) return 0;//判断插旗地方是否是雷 
			}
			if(bomb[i][j]==1) 
			{
				if (map[i][j]!=-2) return 0;//判断地雷区是否有旗 
			}
		} 
	} 
	return -1;//胜利标志 
}
