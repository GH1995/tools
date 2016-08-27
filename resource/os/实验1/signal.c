// 3．进程的软中断通信

/*
*	使用系统调用fork()创建两个子进程，再用系统调用signal()让父进程捕捉键盘上来的中断信号（即按Del键）；
*	当捕捉到中断信号后，父进程用系统调用kill()向两个子进程发出信号，子进程捕捉到信号后分别输出下列信息后终止：
*		Child process 1 is killed by parent!
*		Child process 2 is killed by parent!
*	父进程等待两个子进程终止后，输出如下的信息后终止：
*		Parent process is killed!
*/

#include <stdlib.h> 
#include <stdio.h> 
#include <signal.h>   

int wait_mark;										/*信号标志*/

void waiting();
void stop();

int main()
{
	int p[2];

	while ((p[0] = fork()) == -1);					/* 创建一个子进程 */
	if (p[0] > 0)									/* 创建子进程p[0] */
	{
		while ((p[1] = fork()) == -1);				/* 创建一个子进程 */
		if (p[1] > 0)								/* 创建子进程p[1] */
		{
			printf("parent\n");
			wait_mark = 1;
			signal(SIGINT, stop);					/* 接收到^c信号，转stop */
			waiting(0);
			kill(p[0], 16);							/* 向p[0]发软中断信号16 */
			kill(p[1], 17);							/* 向p[1]发软中断信号17 */
			wait(0);								/* 同步*/
			wait(0);
			printf("parent process is killed! \n");
			exit(0);
		}
		else
		{
			printf("p[1]\n");
			wait_mark = 1;
			signal(17, stop);
			signal(SIGINT, SIG_IGN);				/* 忽略 ^c信号 */
			waiting();
			lockf(1, 1, 0);
			printf("child process2 is killed by parent! \n");
			lockf(1, 0, 0);
			exit(0);
		}
	}
	else
	{
		printf("p[0]\n");
		wait_mark = 1;
		signal(16, stop);
		signal(SIGINT, SIG_IGN);					/* 忽略 ^c信号 */
		waiting();									/* 当wait_mark =1时，waiting方法不进行任何操作，不停循环，直到按下^c，调用stop()函数，使得flag=0,跳出循环 */
		lockf(1, 1, 0);
		printf("child process1 is killed by parent! \n");
		lockf(1, 0, 0);
		exit(0);									/* 利用exit()来实现进程的自我终止，通常父进程在创建子进程时，应在进程的末尾安排一条exit()，使子进程自我终止。exit(0)表示进程正常终止，exit(1)表示进程运行有错，异常终止 */
	}
}

void waiting()
{
	while (wait_mark != 0);
}

void stop()
{
	wait_mark = 0;
}
