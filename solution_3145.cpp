#include<iostream>
using namespace std;
long count = 0;
int a[10000];
char b[10000][2];
void move(int n,char from,char to)
{
	count = count + 1;
	b[count][1] = from;
	b[count][2] = to;
	a[count] = n;
}
void tprint()
{
	for (int i=1; i<=count; i++)
	{
		cout<<a[i]<<" from "<<b[i][1]<<" to "<<b[i][2]<<endl;
	}
}
void solve(int n,char from, char depend, char to)
{
	if (n==1)
	{
		move(1,from,to);
	}
	else
	{
		solve(n-1,from,to,depend);
		move(n,from,to);
		solve(n-1,depend,from,to);
	}
}
int main()
{
	int n;
	cin>>n;
	solve(n,'A','B','C');
	cout<<count<<endl;
	tprint();
	return 0;
}
