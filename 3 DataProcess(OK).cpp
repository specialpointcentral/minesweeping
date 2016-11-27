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
