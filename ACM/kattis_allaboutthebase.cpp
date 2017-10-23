#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int charToNum(char num)
{
	if (num<='9' && num>='0')
	{
		return num-'0';
	}
	else
	{
		return num-'a'+11;
	}
}
int toDec(string num,int binary)
{
	int len = num.length();
	int decimal_num = 0;
	for (int i=0; i<len; i++)
	{
		decimal_num += charToNum(num[i])*pow(binary,len-i-1);
	}
	return decimal_num;
}
int main()
{
	int n;
	string equ;
	string num1;
	string num2;
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>equ;
		for (int k=0; k<equ.length()); k++)
		{
			flag = 0;
			if (equ[k]-' ' == 0)
			{
				flag = 1;
				continue;
			}
			if (equ[k]-'+' == 0)
			{
				ope = 1;
			}
			if (equ[k] - '-' == 0)
			{
				ope = 2;
			}
			if (flag == 0)
			{
				num1 += equ[k];
			}
			if (flag == 1) 
			{
				num2 += equ[k];
			}
		}
	}
	
}
