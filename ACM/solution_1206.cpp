#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{
	int number;
	double discount;
	cin>>number>>discount;
	int price = (int)number * discount/10;
	int temp = price%10;
	if (temp>=5)
		price = price + (10-temp);
	else 
		price = price - temp;
	cout<<price<<endl;
}
