/*
**函数名 BombShow
**提示 先将bomb里雷的信息写入map中（map中地雷值为-3）,然后调用MapUpdate
**注意 请不要改变bomb[ ][ ]值，map[ ][ ]改变请注意。 
**函数说明 int BombShow (int map[10][10],int bomb[10][10])
**输入值 map的地址, bomb的地址。
**输出值 1、0，0表示成功，1表示失败。



**Project:SPC
**Time:16/11/27 6:41 
**Ver. 1.0
*/
int BombShow (int map[10][10],int bomb[10][10])
{
	int i,j;//行列循环
	for (i=0;i<=10-1;i++)
		for(j=0;j<=10-1;j++)
		{
			if(bomb[i][j]==1)//判断是否是雷 
			map[i][j]=-3;//更改地图值	
		} 
		return 0;
}
