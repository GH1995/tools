/*
*	源代码参考：http://blog.csdn.net/songzitea/article/details/48136285
*/
#include <stdio.h>

char dt[11][5][3]={
{ {' ','_',' '},{'|',' ','|'},{' ',' ',' '},{'|',' ','|'},{' ','_',' '}},//0
{ {' ',' ',' '},{' ',' ','|'},{' ',' ',' '},{' ',' ','|'},{' ',' ',' '}},//1
{ {' ','_',' '},{' ',' ','|'},{' ','_',' '},{'|',' ',' '},{' ','_',' '}},//2
{ {' ','_',' '},{' ',' ','|'},{' ','_',' '},{' ',' ','|'},{' ','_',' '}},//3
{ {' ',' ',' '},{'|',' ','|'},{' ','_',' '},{' ',' ','|'},{' ',' ',' '}},//4
{ {' ','_',' '},{'|',' ',' '},{' ','_',' '},{' ',' ','|'},{' ','_',' '}},//5
{ {' ','_',' '},{'|',' ',' '},{' ','_',' '},{'|',' ','|'},{' ','_',' '}},//6
{ {' ','_',' '},{' ',' ','|'},{' ',' ',' '},{' ',' ','|'},{' ',' ',' '}},//7
{ {' ','_',' '},{'|',' ','|'},{' ','_',' '},{'|',' ','|'},{' ','_',' '}},//8
{ {' ','_',' '},{'|',' ','|'},{' ','_',' '},{' ',' ','|'},{' ','_',' '}} //9
};

int main(){
   int i,j,w,h,k,n,p,m =0,a[10];
   while(1){
     scanf("%d%d%ld",&w,&h,&n);
	 if(w ==0) break; 
	 
	 while(n){
	 	a[m++] = n%10;
		n/=10;
	}
	
	for( i =0;i<5;i++){
		for(p =0;p<h;p++){ 
			for (k = m-1;k>=0;k--){
				printf("%c",dt[a[k]][i][0]);
				
				for(j =0; j<w;j++)
					printf("%c",dt[a[k]][i][1]);
				printf("%c",dt[a[k]][i][2]);
				printf(" ");
			}
			
			printf("\n");
			if(i !=1&&i!=3) break;
		}
	}
   }
   
   return 0;
}