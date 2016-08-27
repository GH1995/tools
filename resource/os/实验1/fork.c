// 1．进程的创建

/*
*	编写一段程序，使用系统调用fork()创建两个子进程。当此程序运行时，在系统中有一个父进程和两个子进程活动。
*	让每一个进程在屏幕上显示一个字符：父进程显示字符“a”；子进程分别显示字符“b”和字符“c”。试观察记录屏幕上的显示结果，并分析原因。
*/

#include <stdio.h>
int main()
{
	int p[2];
	while ((p[0] = fork()) == -1);				/* 创建一个子进程 */
	

	if (p[0] == 0)								/* 子进程创建成功 */
	{
		printf("b ");							/* this is child 1 process */
	}
	else
	{
		while ((p[1] = fork()) == -1);			/* 创建另一个子进程 */
		if (p[1] == 0)							/* 子进程创建成功 */
		{
			printf("c ");						/* this is child 2 process */
		}
		else
		{
			printf("a ");						/* 父进程*/
		}
	}
}
