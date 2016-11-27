/*
**函数名 DrawFlag
**对已经标明旗帜的取消旗帜，换为未扫雷区域；未标明旗帜的，换为旗帜。
**注意 map[ ][ ]请对应更新值
**函数说明 int DrawFlag (int x,int y, int map[10][10])
**输入值 x坐标，y坐标，map的地址。
**输出值 1、0，0表示成功，1表示失败。

**Project:LC
**Time:16/11/26 9:15
**Ver. 1.0
*/
int DrawFlag(int x,int y,int map[10][10])//插旗函数 
{
	if(map[y][x]==-1)//如果该地图块未插旗 
	map[y][x]=-2;//将该地图块插旗 
	else if(map[y][x]==-2)//如果该地图块已经插旗 
	map[y][x]=-1;//将该地图块插旗取消 
	else return 1;//返回错误值 
	return 0;
}

