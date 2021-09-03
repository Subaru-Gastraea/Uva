/* p100 */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i,j,k,ti,tj,temp,cnt,max;
	
	while(scanf("%d %d",&i,&j) != EOF)
	{
		if(i>j)
		{
			ti=j;
			tj=i;
		}
		else
		{
			ti=i;
			tj=j;
		}
	
		for(k=ti,max=1;k<=tj;k++)
		{
			cnt=1;
			temp=k;
			
			while(temp!=1)
			{
				if(temp%2==0)
				{
					temp/=2;
				}
				else
				{
					temp=3*temp+1;
				}
				cnt++;
			}
		
			if(max<cnt) max=cnt;

		}
	
		printf("%d %d %d\n",i,j,max);
	}

    return 0;
}

