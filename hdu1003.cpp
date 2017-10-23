#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	int sum,ans,num,S,E,start,end;
	for (int i=1; i<=n; i++)
	{
		start = 1;
		end = 1;
		sum = 0;
		ans = -100001;
		S = 1;
		E = 1;
		cin>>m;
		for (int j=1; j<=m; j++)
		{

			cin>>num;
			if (sum+num>=num)
			{
				end = j;
				sum = sum+num;
			}
			else
			{
				start = j;
				end = j;
				sum = num;
			}
			if (sum>ans)
			{
				ans = sum;
				S = start;
				E = end;
			}
			//cout<<sum<<" "<<ans<<" "<<i<<" "<<start<<" "<<end<<endl;
		}
		cout<<"Case "<<i<<":"<<endl;
		cout<<ans<<" "<<S<<" "<<E<<endl;
		if (i!=n)
			cout<<endl;
	}
} 
