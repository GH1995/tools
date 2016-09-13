// 4．进程的管道通信

/*
*	编制一段程序，实现进程的管道通信。使用系统调用pipe()建立一条管道线；两个子进程P1和P2分别向管道各写一句话：
*		Child 1 is sending a message!
*		Child 2 is sending a message!
*	而父进程则从管道中读出来自于两个子进程的信息，显示在屏幕上。要求父进程先接收P1发来的消息，然后再接收P2发来的消息。
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int p[2];

int main()
{
	int fd[2];

	char OutPipe[100], InPipe[100];
	pipe(fd);								/* 创建一个管道 */

	while ((p[0] = fork()) == -1);
	if (p[0] == 0)
	{
		printf("p[0]\n");
		lockf(fd[1], 1, 0);					/* 加锁 */
		sprintf(OutPipe, "Child 1 is sending a message!");			/* 把串放入数组outpipe中 */
		write(fd[1], OutPipe, 50);			/* 向管道写长为50字节的串 */
		sleep(1);							/* 自我阻塞1秒 */
		lockf(fd[1], 0, 0);					/* 解锁 */
		exit(0);
	}
	else
	{
		while ((p[1] = fork()) == -1);
		if (p[1] == 0)
		{
			printf("p[1]\n");
			lockf(fd[1], 1, 0);				/* 加锁，互斥 */
			sprintf(OutPipe, "Child 2 is sending a message!");		/* 把串放入数组outpipe中 */
			write(fd[1], OutPipe, 50);		/* 向管道写长为50字节的串 */
			sleep(1);						/* 自我阻塞1秒 */
			lockf(fd[1], 0, 0);				/* 解锁 */
			exit(0);
		}
		else
		{
			printf("parent\n");
			wait(0);						/* 同步 */
			read(fd[0], InPipe, 50);
			printf("%s\n", InPipe);			/* 从管道中读长为50字节的串 */
			wait(0);
			read(fd[0], InPipe, 50);
			printf("%s\n", InPipe);
			exit(0);
		}
	}
}
