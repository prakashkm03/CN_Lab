#include<iostream>
using namespace std;

int main()
{
   int i,j,k; 
   int f,n,m;
   cout<<"Enter the data size "<<endl;
   cin>>f;

   cout<<"Enter the data "<<endl;
   
   int data[20];

   for(int i=0;i<f;i++)
   {
       cin>>data[i];
   }

   cout<<"Enter the divisor size "<<endl;
   cin>>m;

   cout<<"Enter the divisor "<<endl;
   int div[n];
   for(int i=0;i<m;i++)
   {
       cin>>div[i];
   }  

   int r = m-1;  // redundant bits added 
   n= r+f;

   for(int i=f;i<n;i++)
   {
     data[i] = 0;

   }   


  int temp[n];
  for(int i=0;i<n;i++)
  {
  	temp[i]=data[i];
  }


  cout<<"Data after appending zero is :";
  for(int i=0;i<n;i++)
  {
  	cout<<data[i];
  }

  cout<<endl;

    for(int i=0;i<f;i++)
    {
        j=0;
        k=i;
        if (temp[k]>=div[j])
        {
            for(j=0,k=i;j<m;j++,k++)
            {
                if((temp[k]==1 && div[j]==1) || (temp[k]==0 && div[j]==0))
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC bits are stored in crc array
    int crc[15];
    for(i=0,j=f;i<r;i++,j++)
    {
        crc[i]=temp[j];
    }
 
    cout<<"Code word is ";
    int ans[15];
    for(i=0;i<f;i++)
    {
        ans[i]=data[i];
    }
    for(i=f,j=0;i<f+r;i++,j++)
    {
        ans[i]=crc[j];
    }
    for(i=0;i<f+r;i++)
    {
        cout<<ans[i];
    }



	return 0;
}