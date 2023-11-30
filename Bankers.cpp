#include<bits/stdc++.h>
using namespace std;

int main ()
{
    int p=5;
    int r=3;
    int alloc[p][r] = { {0,0,1},
                        {3,0,0},
                        {1,0,0},
                        {2,3,2},
                        {0,0,3} };
    int max[p][r] = { {7,6,3},
                      {3,2,2},
                      {8,0,2},
                      {2,1,2},
                      {5,2,3} };

    int avail[3]={2,3,2};
    int need[p][r];
    for (int i = 0; i <p; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
        
    }
    int f[p],ans[p],index=0;
    for (int i = 0; i < p; i++)
    {
        f[i]=0;
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if(f[j]==0){
                int flag=0;
                for(int k=0;k<r;k++)
                {
                    if(need[j][k]>avail[k]) {
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    ans[index++]=j;
                    for(int l=0;l<r;l++)
                    {
                        avail[l]+=alloc[j][l];
                    }
                    f[j]=1;
                }

            }
        }
        
    }
    
    for(int i=0;i<p;i++)
    {
        cout<<"P"<<ans[i];
        if(i<p-1)
        cout<<"-> ";
    }
}