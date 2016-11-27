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
