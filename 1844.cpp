#include<iostream>
#include<cstring>
using namespace std;
int m;
int f[100005];
int max(int a,int b)
{
    if (a>b)
        return a;
    return b;
}
void zeroonepack(int cost,int weight)
{
    for (int v=m; v>=cost; v--)
        f[v] = max(f[v], f[v-cost]+weight);
}
void completepack(int cost, int weight)
{
    for (int v=cost; v<=m; v++)
        f[v] = max(f[v],f[v-cost]+weight);
}
int main()
{
    int n;
    int cost[105];
    int amount[105];
    while(scanf("%d%d",&n,&m),n+m)
    {
    memset(f,0,sizeof(f));
    for (int i=0; i<n; i++)
        cin>>cost[i];
    for (int i=0; i<n; i++)
        cin>>amount[i];
    for (int i=0; i<n; i++)
    {
        if (cost[i]*amount[i]>m)
            completepack(cost[i],cost[i]);
        else
        {
            int k=1;
            while (k<=amount[i])
            {
                zeroonepack(k*cost[i],k*cost[i]);
                amount[i] = amount[i] - k;
                k = k*2;
            }
            zeroonepack(cost[i]*amount[i],cost[i]*amount[i]);
        }
    }
    int s=0;
    for(int i=1;i<=m;i++)
    {
       if(f[i]==i)
            s++;
        }
    printf("%d\n",s);
    }
}