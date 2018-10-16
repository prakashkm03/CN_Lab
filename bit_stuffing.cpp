#include <iostream>
#include <string.h>
using namespace std;

int main()
{
   int n;
   cout<<"Enter the size of frame"<<endl;
   cin>>n;
   

   int i=0,j=0,k,count=1;
   int str[n],ans[n];
   cout<<"Enter the data to be send"<<endl;
   
   for(int i=0;i<n;i++)
   {
   	cin>>str[i];
   }

   // flag is 01111110

    while(i<n)
    {
        if(str[i]==1)
        {
            ans[j]=str[i];
            for(k=i+1; str[k]==1 && k<n && count<5; k++)
            {
                j=j+1;
                ans[j]=str[k];
                count++;
                if(count==5){
                    j++;
                    ans[j]=0;
                }
                i=k;
            }
        }
        else
        {
            ans[j]=str[i];
        }

        i++;
        j++;
    }

    cout<<"Information to be sent to receiver is: "<<endl;
    
    cout<<"01111110";
    for(int i=0;i<j;i++)
    {
    	cout<<ans[i];
    }
    cout<<"01111110"<<endl;


    return 0;

}