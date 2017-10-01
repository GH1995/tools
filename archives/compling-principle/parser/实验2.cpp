//ʵ���  �﷨����

//  �������ʽ->��|�������ʽ+��|�������ʽ-��
//  ��->����|��*����|��/����
//  ����->����|����|(�������ʽ)    
// 
//          ������ȹ�ϵ��    
//---------------------------------- 
//     +   -   *   /   (   )   i   #  
// +   >   >   <   <   <   >   <   >  
// -   >   >   <   <   <   >   <   >  
// *   >   >   >   >   <   >   <   >  
// /   >   >   >   >   <   >   <   >  
// (   <   <   <   <   <   =   <   ?  
// )   >   >   >   >   ?   >   ?   >  
// i   >   >   >   >   ?   >   ?   >   
// #   <   <   <   <   <   ?   <   =  
//---------------------------------- 

#define N 100
#define NULL 0

#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;


FILE *fp;//Ԥ�����ļ�ָ��
//�������ջ�Ĵ�С�������ַ����Ĵ�С�Լ��������ʽ�ַ����Ĵ�С
char stack[N],strings[N],oldstrings[N];
char a;
int top = -1, k = 0, step = 1, n = 0, No[N], id = 1;

//��ά���鶨���ַ�֮������ȹ�ϵ(1��ʾ>,-1��ʾ<,0��ʾ=,-2��ʾ����)
int M[N][N] = { { 1, 1, -1, -1, -1, 1, -1, 1 }, { 1, 1, -1, -1, -1, 1, -1, 1 }, { 1, 1, 1, 1, -1, 1, -1, 1 }, { 1, 1, 1, 1, -1, 1, -1, 1 },
{ -1, -1, -1, -1, -1, 0, -1, -2 }, { 1, 1, 1, 1, -2, 1, -2, 1 }, { 1, 1, 1, 1, -2, 1, -2, 1 }, { -1, -1, -1, -1, -1, -2, -1, 0 } };
char *word[6] = { "N+N", "N-N", "N*N", "N/N", ")N(", "i" };
//�ɹ�Լ�ַ���

//////////////////////////////////////////////////////////////////////////////////////////

int print(int t,int m)
{
	cout<<"\n "<<step++<<setw(10);
	cout<<stack<<setw(10);	

	if (m == 1)
		cout << ">" << setw(8);
	else if (m == 0)
		cout << "=" << setw(8);
	else
		cout << "<" << setw(8);

	cout << a << setw(10);
	cout << &strings[k] << setw(10);

	if (t)
	{
		cout << "��Լ" << setw(8);
		No[n++] = step - 1;
	}
	else
		cout << "�ƽ�" << setw(8);

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

void push(char ch)
{
	stack[++top]=ch;
}

//////////////////////////////////////////////////////////////////////////////////////////

char pop()
{
	char a;
	a = stack[top--];
	stack[top + 1] = '\0';
	return a;
}

//////////////////////////////////////////////////////////////////////////////////////////

int ch_di(char ch)
{
	switch(ch)
	{
		case'+':
			return 1;
		case'-':
			return 2;
		case'*':
			return 3;
		case'/':
			return 4;
		case'(':
			return 5;
		case')':
			return 6;
		case'i':
			return 7;
		case'#':
			return 8;
		default:
			return 0;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int IsVT(char ch)
{
	if(ch=='N')
		return 0;
	else
		return 1;
}

//////////////////////////////////////////////////////////////////////////////////////////

int readvt(char *a)
{
	if(IsVT(strings[k]))
	{
		(*a)=strings[k];
		k++;
		return 1;
	}
	else
	{
		k++;
		return 0;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////

int big(int t,char a)
{
	if(M[ch_di(stack[t])-1][ch_di(a)-1]==1)
		return 1;
	else
		return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

int leess(int t,char a)
{
	if(M[ch_di(stack[t])-1][ch_di(a)-1]==-1)
		return 1;
	else
		return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

int equal(int t,char a)
{
	if(M[ch_di(stack[t])-1][ch_di(a)-1]==0)
		return 1;
	else
		return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////

void error(int t)
{
	if(ch_di(stack[t])==6||ch_di(stack[t])==7)
	{
		printf("\n����e2:ȱ�������!");
	}
	else if(ch_di(stack[t])==5)
	{
		printf("\n����e1:�Ƿ�������!");
	}
	else 
		printf("\n����e3:�Ƿ�������!");
}

//////////////////////////////////////////////////////////////////////////////////////////

void prior_analysis()
{
	int i,j,m;
	char q,str,ch[20];   
	push('#');
	print(0,-1);	     
u:  readvt(&a);
	if(IsVT(stack[top]))
		j=top;
	else
		j=top-1;
	do 
	{	
		while(big(j,a)&&strcmp(stack,"#N")!=0)
		{
			do 
			{
				q=stack[j];
				if(IsVT(stack[j-1]))
					j=j-1;
				else
					j=j-2;
			} while (!leess(j, q));
			i=-1;
			while((top-j)!=0)
			{
				ch[++i]=pop();
			}
			ch[i+1]='\0';
			for (m=0;m<=5;m++)
			{
				if(strcmp(word[m],ch)==0)
					str='N';
			}
			push(str);
			print(1,1);
		}
		if (leess(j, a))
		{         
			push(a);
			print(0,-1);
			if(stack[top]!='#')
				goto u;
		}
		else
		{
			if(equal(j,a))
			{        
				push(a);
				print(0,0);
				if(stack[top]!='#')
					goto u;
			}
			else
			{
				error(j);
				a='#';
			}
		}
	}while(a!='#');
}

//////////////////////////////////////////////////////////////////////////////////////////

void main()
{
	cout<<"******************************��������﷨��������******************************"<<endl;
	cout<<" E->E+T|E-T|T"<<endl;
	cout<<" T->T*F|T/F|F"<<endl;
	cout<<" F->(E)|i"<<endl;
	cout<<" E��ʾ�������ʽ.T��ʾ��.F��ʾ����.i��ʾ��������."<<endl;
	cout<<"              ���ȱ�"<<endl;
	cout<<"     +   -   *   /   (   )   i   #"<<endl;
	cout<<" +   >   >   <   <   <   >   <   >"<<endl;
	cout<<" -   >   >   <   <   <   >   <   >"<<endl;
	cout<<" *   >   >   >   >   <   >   <   >"<<endl;
	cout<<" /   >   >   >   >   <   >   <   >"<<endl;
	cout<<" (   <   <   <   <   <   =   <   e1"<<endl;
	cout<<" )   >   >   >   >   e2  >   e2  >"<<endl;
	cout<<" i   >   >   >   >   e2  >   e2  >"<<endl;
	cout<<" #   <   <   <   <   <   e3  <   ="<<endl;
	if((fp=fopen("Ԥ����.txt","r"))==NULL)
	{
		cout<<"���Ƚ�ʵ��1�ļ����е�Ԥ����.txt�ļ����Ƶ�ʵ��2�ļ�����!"<<endl;
		system("pause");
		exit(0);
	}
	char ch=fgetc(fp);
	char ch1;
	while(ch!='#')
	{
		int i=-1,j=0,m=-1;
		while(ch!='='&&ch!='#')
		{
			ch1=ch;
			ch=fgetc(fp);
			if((ch1=='>'||ch1=='<')&&ch=='=')
				ch=fgetc(fp);
		}
		if(ch=='#')
		{
			cout<<"��������﷨��������!"<<endl;
			fclose(fp);
			system("pause");
			exit(0);
		}
		while(ch!=' '&&ch!='#')
		{
			ch=fgetc(fp);
			oldstrings[++i]=ch;
		}
		oldstrings[i]='\0';
		if(isalnum(oldstrings[j]))
			strings[++m]='i';
		else
			strings[++m]=oldstrings[j];
		j++;
		while(oldstrings[j]!='\0')
		{
			if(isalnum(oldstrings[j]))
			{
				if(isalnum(oldstrings[j-1])==0)
					strings[++m]='i';
			}
			else
				strings[++m]=oldstrings[j];
			j++;
		}
		strings[m+1]='#';
		strings[m+2]='\0';
		cout<<"�������ʽ"<<id<<"Ϊ: "<<oldstrings<<endl;
		cout<<"ת��Ϊ���봮: "<<strings<<endl;	
		cout<<" ����� ����ջ ���ȹ�ϵ ��ǰ������ ʣ�����봮 ����";
		prior_analysis();
		n=0;
		cout<<endl;
		cout<<"�������ʽ"<<id++<<"��"<<"��Լ����ʽ�����Ϊ:";
		while(No[n])
		{
			cout<<" "<<No[n];
			n++;
		}
		cout<<endl;
	
		while(stack[0]!='\0')
			pop();
		while(No[--n])
		{
			No[n]='\0';
		}
		top=-1;
		a='\0';
		k=0;
		step=1;
		n=0;
	}
	cout<<"��������﷨��������!"<<endl;
	fclose(fp);
	system("pause");
	exit(0);
}
