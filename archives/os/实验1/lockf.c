// （2）进程的控制
/*	修改已有程序，将每个进程输出一个字符改为每个进程输出几行字符，再观察程序执行时屏幕上的现象，并分析原因。
*	如果在程序中使用系统调用lockf()来给每一个进程加锁，可以实现进程之间的互斥，观察并分析出现的现象。
*/

/*
*	int lockf(int fd, int cmd, off_t len);
*	①fd 是打开文件的文件描述符。
*	②cmd 是指定要采取的操作的控制值，允许的值在中定义。
*	③len是要锁定或解锁的连续字节数。
*	参见:http://man7.org/linux/man-pages/man3/lockf.3.html
*	
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	int p[2], i;

	while ((p[0] = fork()) == -1);		/* 创建一个子进程 */
	if (p[0] == 0)						/* 子进程创建成功 */
	{
		lockf(1, 1, 0);					/* 加锁，由该进程占用处理机 */

		for (i = 0; i < 1000; i++)
			printf("b ");				/* this is child 1 process */
		printf("\n");

		lockf(0, 0, 0);					/* 解锁 */
	}
	else
	{
		while ((p[1] = fork()) == -1);	/* 创建另一个子进程 */
		if (p[1] == 0)					/* 子进程创建成功 */
		{
			lockf(1, 1, 0);				/* 加锁，由该进程占用处理机 */

			for (i = 0; i < 1000; i++)
				printf("c ");			/* this is child 2 process */
			printf("\n");

			lockf(1, 0, 0);				/* 解锁 */
		}
		else
		{
			lockf(1, 1, 0);

			for (i = 0; i < 1000; i++)
				printf("a ");			/* 父进程*/
			printf("\n");

			lockf(1, 0, 0);
		}
	}
}
