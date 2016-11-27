/*
**函数名 SearchBomb
**搜索对应xy的块周围地雷数目，更新map数组对应元的值为地雷数，并返回处理结果。
**注意 bomb[ ][ ]请不要更改值，map[ ][ ]请对应更新值
**函数说明 int SearchBomb (int x, int y, int map[10][10],int bomb[10][10])
**输入值 x坐标，y坐标，map的地址，bomb的地址。
**输出值 1、0、-1，-1表示成功并且周围无雷，0表示成功并且周围有雷，1表示失败。


**Project:YY
**Time:16/11/26 15:11
**Ver. 1.0
*/
int SearchBomb (int x, int y, int map[10][10],int bomb[10][10]) 
{
	int i,j;//行列遍历查找 
	int numbs=0;//雷数统计 
	for (i=y-1;i<=y+1;i++)//对列查找 
		for (j=x-1;j<=x+1;j++)//对行查找 
		{
		 if (i>9||j>9||i<0||j<0)//防止查找出界 
		 continue;
		 numbs+=bomb[i][j];
		}
	map[y][x]=numbs;//更新地图位置 
	if (numbs==0) return -1;//没有地雷 
	else return 0;//有地雷 
}

