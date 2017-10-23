#include<iostream>
using namespace std;
double have,pro,icave, mave,test1,test2,test3,finalto;
double h[100],c[100],m[100];
int n;
int main()
{
	cout<<"input Homework number: "<<endl;
	cin>>n;
	cout<<"input Grade: "<<endl;
	for (int i=0; i<n; i++)
	{
		cin>>h[i];
		have = have+h[i];
	}
	have = have/n;
	cout<<have;
	have = have * 0.09;
	cout<<"input project grade: "<<endl;
	cin>>pro;
	pro = pro * 0.1;
	cout<<"input inclass Quizzes number: "<<endl;
	cin>>n;
	cout<<"input Grade: "<<endl;
	for (int i=0; i<n; i++)
	{
		cin>>c[i];
		icave = icave + c[i];
	}
	icave = icave / n;
	cout<<icave;
	icave = icave * 0.1;
	cout<<"input Moddle Quizzes number: "<<endl;
	cin>>n;
	cout<<"input Grade: "<<endl;
	for (int i=0; i<n; i++)
	{
		cin>>m[i];
		mave = mave + m[i];
	}
	mave = mave / n;
	cout<<mave;
	mave = mave * 0.06;
	test1 = 92 * 0.15;
	test2 = 81 * 0.1;
	test3 = 89 * 0.15;
	finalto = 90 - test1 - test2 - test3 - icave - mave - pro - have;
	finalto = finalto * 4;
	cout<<finalto;
}
