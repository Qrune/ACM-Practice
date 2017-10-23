#include<iostream>
using namespace std;
void quickSort(int s[], int l, int r)
{
    if (l < r)
    {      
      int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x)
                            j--; 
            if(i < j)
                            s[i++] = s[j];
                    
            while(i < j && s[i] < x)
                            i++; 
            if(i < j)
                            s[j--] = s[i];
        }
        s[i] = x;
        quickSort(s, l, i - 1);
        quickSort(s, i + 1, r);
    }
}
int main()
{
	long n,m,i,j;
	int a[100000];
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>m;	
		int num = 1;
		int base = 1;
		for (int i=1; i<17; i++)
		{
			num = num * 2;
			if (m<num)
			{
				base = i-1;
				break;
			}
		}
		num = num /2;
		int sum = 0;
		for (int i=0; i<m; i++)
		{
			cin>>a[i];
			sum +=a[i];
		} 
		quickSort(a,0,m-1);
		int toadd = 0;
		for (int i=1; i<=2*(m-num); i++)
		{
			toadd +=a[i-1];
		}
		cout<<sum<<" "<<base<<" ">>toadd<<endl;
		
	}
} 
