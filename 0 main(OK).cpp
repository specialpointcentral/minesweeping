#include<stdio.h>
#include<windows.h>
#include<time.h>// 根据时间推测随机数，用时间当随机数种子 
#include<stdlib.h>//srand函数包含库  
int main()
{
	int map[10][10],bomb[10][10];//定义地图大小 
	int x,y,types;//定义点击坐标及点击方式 
	int bombnum=10;//定义雷数 
	int marks=0;//定义输赢类型  
	LoadMap(map,bomb);//第一次运行初始化地图 
	while(1) //一直循环直到输赢 
	{
		MapUpdate(map); //更新地图 
		ClickData (&x,&y,&types);//输入操作命令 
		if (DataProcess(x,y,types,map,bomb)==2)//根据函数DataProcess返回值判断输赢 
		break;//输了 跳出循环（输显示已集成在函数DataProcess中） 
		marks=WinOrNot (map,bomb,bombnum);
		if (marks!=-1&&marks!=0)//判断是否出错 
		return 1;//出错返回值为1 
		else if(marks==-1)//胜利 
		{
			Gameover (0);
			break;
		} 
	}
	return 0;
} 
