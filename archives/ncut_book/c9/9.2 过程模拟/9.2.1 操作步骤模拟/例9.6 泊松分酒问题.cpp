/*
*	借助于容量分别为bv和cv的两个空杯，将总容量为偶数a的酒平分，输出分酒的步骤。
*
*	杯中酒量分别为：a、b、c。通常 av > bv,cv。
*	例如：按a->b->c->a的顺序倒。
*	若能分出R升时，由a倒入b执行x次，由c倒入a执行y次。
*	则有：
*		bv*x-cv*y=R
*	此方程的最小整数解即为倒的次数。
*
*	还有很多东西不懂！
*	程序存在问题
*/\r/\r/g


// 草稿
//while (!(a==R || b==R|c==R))
//{
// /*
// *	前两种情况，后一种情况
// */
//	if (!b)					// b不空，从a倒满b
//	{
//		a = a - bv;
//		b = bv;
//	}
//	else if (c == cv)		// c满，从c倒回a
//	{
//		a += cv;
//		c = 0;
//	}
//	else if (b > cv - c)	// 从b倒满c，b不空
//	{
//		b = b - (cv - c);
//		c = cv;
//	}
//	else					// 从b倒满c，倒空b
//	{
//		c += b;
//		b = 0;
//	}
//}





#include <iostream>
using namespace std;

int main()
{
	int a;				// a 杯中的酒量
	int b = 0;			// b 杯中的酒量
	int c = 0;			// c 杯中的酒量

	int bv, cv;			// bv, cv为空杯
	cin >> a >> bv >> cv;

	int R = a / 2;		// 分出R升
	int n = 0;



	while (!(a == R || b == R || c == R))
	{
		if (!b)			// b不空就要采取行动
		{
			if (a < bv)	// 无法倒满b，则不能分
			{
				n = -1;
				break;
			}
			else if(!(a < bv))		// 倒满b
			{
				a = a - bv;
				b = bv;
			}
			else if (c == cv)
			{
				a = a + cv;
				c = 0;
			}
			else if (b > cv - c)
			{
				b -= cv - c;
				c = cv;
			}
			else
			{
				c += b;
				b = 0;
			}
		}

		n++;
		cout << a << " " << b << " " << c << endl;
	}

	cout << endl;

	return 0;
}
