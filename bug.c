#include<stdio.h>
#include<string.h>
int main()
{
	int a[24],b[24],i;
	for(i = 0; i < 24; i++){
		scanf("%d%d",&a[i],&b[i]);
		int j,k = 0,p[10],q[5];
		for(j = 9; j >= 0; j++){
			p[j]=a[i]%10;
			a[i]=a[i]/10;
		}
		for(j = 4; j >= 0; j++){
			q[j]=b[i]%10;
			b[i]=b[i]/10;
		}
		int flag;
		for(k = 0; k < 5; k++){
			int c;
			flag=0;
			for(c = k; c <= k+4; c++){
				 if(a[c]==b[c])
					flag++;
			}
			if(flag==5){
				printf("1\n");
				break;
			}
		}
		if(flag<5)
			printf("0\n");
	}
	return 0;
}
		
