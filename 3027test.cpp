    #include <iostream>  
    #include <algorithm>  
    using namespace std;  
    struct node  
    {  
      int a;  
      int b;  
      int c;  
    }line[1005];  
    int cmp(const node x, const node y)  
    {  
      return x.b < y.b;  
    }  
    int main()  
    {  
      int n;  
      cin >> n;  
      for(int i=0;i<n;i++)  
      {  
        cin>>line[i].a>>line[i].b>>line[i].c;  
      }  
      sort(line, line+n, cmp);  
      int max = 0;  
      for(int i=1; i<n; i++)  
      {  
        int k = 0;  
        for(int j=0; j<i; j++)  
        {  
          if(line[i].a>=line[j].b)  
          {  
            if(k<line[j].c)  
            {  
              k=line[j].c;  
            }  
          }  
        }  
        line[i].c = line[i].c + k;  
        if(max<line[i].c) max = line[i].c;  
      }  
      cout << max;  
      return 0;  
    }  
