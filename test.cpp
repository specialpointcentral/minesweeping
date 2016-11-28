#include<stdio.h>
#include<windows.h>
#include<time.h>// 根据时间推测随机数，用时间当随机数种子 
#include<stdlib.h>//srand函数包含库  
int main()
{
	int LoadMap (int map[10][10],int bomb[10][10]);
	int ClickData (int *x,int *y,int *types);
	int DataProcess (int x, int y,int types,int map[10][10],int bomb[10][10]);
	int DrawFlag (int x,int y, int map[10][10]);
	int SearchBomb (int x, int y, int map[10][10],int bomb[10][10]);
	int MapUpdate (int map[10][10]);
	int WinOrNot (int map[10][10],int bomb[10][10],int bombnum);
	int Gameover (int flags);
	int BombShow (int map[10][10],int bomb[10][10]); 
	
	
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
	system("pause");
	return 0;
} 

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
	int nums=1;//地雷数 
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

/*
**函数名 ClickData
**对点击的数据处理。包括坐标，以及左右击。
**将会传出数值x y types 指针
**函数说明 int ClickData (int *x,int *y,int *types)
**输入值 x,y,types（指针变量） 
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



/*
**函数名 DataProcess
**传入坐标xy以及鼠标点击的左右键。同时判定点击是否合法。
**函数说明 int DataProcess (int x, int y,int types)
**输入值 x坐标，y坐标，鼠标左右键（1左击,2右击）
**输出值 1、0，0表示成功，1表示失败。
**注意 这部分将集合其它函数！
**包括游戏结束函数、画旗帜函数、搜索角雷区函数、图形更新函数、胜利判断函数等、函数主要模块。

**Project:SPC
**Time:16/11/26 8:40
**Ver. 1.0
*/
int DataProcess (int x, int y,int types,int map[10][10],int bomb[10][10])
{
	int ClickData (int *x,int *y,int *types);
	int DataProcess (int x, int y,int types,int map[10][10],int bomb[10][10]);
	int DrawFlag (int x,int y, int map[10][10]);
	int SearchBomb (int x, int y, int map[10][10],int bomb[10][10]);
	int MapUpdate (int map[10][10]);
	int WinOrNot (int map[10][10],int bomb[10][10],int bombnum);
	int Gameover (int flags);
	int BombShow (int map[10][10],int bomb[10][10]); 
	
	int marks;//SearchBomb返回值标志 
	int i,j;//行列遍历查找 
	if (map[y][x]==-1||map[y][x]==-2)//判断是否是有效点击 
	{
		if(types==1)
		{//左击 
			if(bomb[y][x]==1)//判断是否是地雷 
			{
				BombShow (map,bomb);//显示地雷 
				MapUpdate(map);//更新地图 				//这部分没经过错误判断 
				Gameover(1);//调用游戏结束函数 
				return 2; 
			}
			
			else//不是地雷 
			{
				marks=SearchBomb(x,y,map,bomb);
				if (marks==-1)
				{//标志周围无雷，模拟点击周围 
					 for (i=y-1;i<=y+1;i++)//对列查找 
						for (j=x-1;j<=x+1;j++)//对行查找 
						{
							if (i>9||j>9||i<0||j<0)//防止查找出界 
							continue;
							DataProcess(j,i,1,map,bomb);//模拟点击 
						}
				}
				else if (marks==0)
				{//标志周围有雷 
					return MapUpdate(map);//更新地图 
				} 
				else return 1; //出错 
			}
		}
		else if (types==2)//右击 
		{//画旗帜 
			if (DrawFlag(x,y,map)==0) 
			return MapUpdate(map);//更新地图 
			else return 1;
		}
		else return 1;//出错 
	}
	else//否则不执行函数 
	return 0;
}

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
	printf("  ");//保证对齐 
 	for (i=1;i<=10;i++)
 	printf("%d ",i);//打印列坐标 
 	printf(" X坐标");//打印行提示 
 	printf("\n");
 	
	for (i=0;i<=10-1;i++)
	{
		if(i<9) 
		printf("%d ",i+1); //打印1-9行坐标 
		else
		printf("%d",i+1); //对10特殊打印 
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
			case 0:printf("□");break;//0颗雷 
			default: printf("%d ",map[i][j]);break;
			}
		}
		printf("\n");//换行 
	}
	printf("Y坐标");//打印提示 
	printf("\n");//换行 
}

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

/*
**函数名 Gameover
**注意 请不要清屏，直接printf("\n");换行然后打印结束
**这个部分发挥想象力吧，输赢界面弄得不同一点吧！（特殊的，输了显示所有雷，请参见模块9）。调用printf。
**函数说明 int Gameover (int flags)
**输入值 标志（1、0）1输了，0赢了。
**输出值 1、0，0表示成功，1表示失败。

**Project:SPC
**Time:16/11/27 6:37 
**Ver. 1.0
*/
int Gameover (int flags)
{
	printf("\n"); 
 	if(flags==1)
		printf("很遗憾，你踩到雷了") ;
	else if(flags==0)
		printf("恭喜胜利");
	else return 1;//程序有错,返回1
	return 0;//正常返回0 
}

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
