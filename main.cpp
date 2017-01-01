#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int num[15],minn;
void dfs(int step,int sum1,int sum2,int len);
int main()
{
    int t,i,j;
    char str[100];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(str);
        int len = strlen(str); minn = 999999999;
        memset(num,0,sizeof(num));
        int number = 0;
        for(i=0; i<len; i++)
          if(str[i]>='0' && str[i]<='9')
             num[str[i]-'0'] += 1, number;
          dfs(0,0,0,number);
          printf("%d\n",minn);
    }
    return 0;
}
void dfs(int step,int sum,int sum2,int len)
{
    if(step == len)
    {
        cout<<"jah "<<sum<<" "<<sum2<<endl;
        minn = minn > abs(sum-sum2) ? abs(sum-sum2) : minn;
        return ;
    }

    for(int i=0; i<=9; i++)
    {
        if(num[i] >= 1)
        {
            if(step <= (len/2))
            {
                 num[i]--;
                 dfs(step+1,sum*10+i,sum2,len);
                 num[i]++;
            }

            else
            {
                num[i]--;
                dfs(step+1,sum,sum2*10+i,len);
                num[i]++;
            }

        }
    }
      //cout<<"jah "<<step<<" "<<sum<<" "<<sum2<<endl;
    return ;
}
