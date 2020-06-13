#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define n 16
int main(void)
{
    int i,j,k,l;
    int S[n];//用于存储已访问过的城市
    int D[n][n];//用于存储两个城市间的距离
    int sum=0;//用于存储已访问过城市的最小长度
    int Dtemp;//保证Dtemp比任意两个城市之间的距离都大
    int flag;//为访问的标志，若被访问过则为1，未被访问过为0
    /*用随机数生成器初始化城市距离*/
    printf("各城市间距离:\n");
    srand(time(NULL));
    for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                if (i==j)
                    {
                        D[i][j]=0;
                        printf("%3d\t",D[i][j]);
                    }
                else
                {
                    D[i][j]=rand()%100+1;
                    D[j][i]=D[i][j];
                    printf("%3d\t",D[i][j]);
                }
                
            }
            printf("\n");
        }
    i=1;//i是至今已经访问过的城市
    S[0]=0;
    do{
        k=1;Dtemp=10000;
        do{
            l=0;flag=0;
            do{
                if(S[l]==k)
                    {//判断该城市是否被访问过，若被访问过，
                    flag=1;
                    break;//跳出循环，不参与距离比较
                    }
                else
                    l++;
            }
            while (l<i);
            if(flag==0&&D[k][S[i-1]]<Dtemp){//D[k][i-1]表示当前未被访问的城市k与上一个访问城市i-1之间的距离
                j=k;//j用于存储已访问过的城市k
                Dtemp=D[k][S[i-1]];//Dtemp用于暂时存储当前最小路径的值
            }
            k++;
        }while (k<n);
        S[i]=j;//将已访问的城市j存入到S[i]中
        i++;
        sum+=Dtemp;
    }while(i<n);
    sum+=D[0][j];//D[0][j]为旅行商所在最后的一个城市与原出发城市的距离
    for(j=0;j<n;j++){
        printf("%d>>",S[j]);//输出城市路径
    }
    printf("0");
    printf("\n最短路径的值为：%d",sum);
    return 0;
}