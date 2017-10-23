
#include<string>

#include<iostream>

#include<cstring>

#include<algorithm>

#include<cstdio>

using namespace std;

string a[100];

int main()

{

int i=1;

while(cin>>a[i])

{
i++;

}

for(int j=i;j>=1;j--)

{

cout<<a[j]<<" ";

}

return 0;

}
