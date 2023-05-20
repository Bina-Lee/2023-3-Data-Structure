#include<stdio.h>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=3;i++){
		printf("%d%d%d\n",a,b,c);
		int temp=b;
		b=c;
		c=temp;
        printf("%d%d%d\n",a,b,c);
		
        for(int j=0;j<i;j++){
            temp=c;
		    c=b;
            b=a;
		    a=temp;
        }
	}
}