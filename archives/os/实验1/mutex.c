// 2．进程的控制
// （1）未加锁

/* 
*	（2）进程的控制
*	修改已有程序，将每个进程输出一个字符改为每个进程输出几行字符，再观察程序执行时屏幕上的现象，并分析原因。
*	如果在程序中使用系统调用lockf()来给每一个进程加锁，可以实现进程之间的互斥，观察并分析出现的现象。
 */


#include <stdio.h>
int main()
{
	int p[2], i;
	while ((p[0] = fork()) == -1);				/* 创建一个子进程 */
	if (p[0] == 0)								/* 子进程创建成功 */
	{
		for (i = 0; i < 10; i++)				/* 如果结果不准确,可改为循环500次 */
			printf("b\n");						/* this is child 1 process */
	}
	else
	{
		while ((p[1] = fork()) == -1);			/*  创建另一个子进程  */
		if (p[1] == 0)							/* 子进程创建成功 */
		{
			for (i = 0; i < 10; i++)
				printf("c\n");					/* this is child 2 process */
		}
		else
		{
			for (i = 0; i < 10; i++)
				printf("a\n");					/* this is father */
		}
	}
}