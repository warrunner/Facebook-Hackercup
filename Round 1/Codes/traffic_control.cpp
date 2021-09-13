#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream infile("traffic_control_input.txt");
    ofstream outfile("traffic_control_output.txt");

    int t;
    infile>>t;

    for(int i=1;i<t+1;i++)
    {
        int a,b,n,m;
        infile>>n>>m>>a>>b;

        if(m+n-1>a or m+n-1>b)
            outfile<<"Case #"<<i<<": Impossible"<<endl;
        else
        {
            outfile<<"Case #"<<i<<": Possible"<<endl;
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    if(j==0 and k==0)
                    {
                        outfile<<(a-m-n+2)<<" ";
                        continue;
                    }
                    

                    else if(j==n-1 and k==0)
                    {
                        outfile<<(b-m-n+2)<<" ";
                        continue;
                    }
                    

                    else if(j==0)
                    {
                        outfile<<1<<" ";
                        continue;
                    }
                    

                    else if(j==n-1)
                    {
                         outfile<<1<<" ";
                        continue;
                    }
                   

                    else if(k==m-1)
                    {
                        outfile<<1<<" ";
                        continue;
                    }
                    

                    else
                    {
                        outfile<<max(a,b)<<" ";
                        continue;
                    }
                    

                }
                outfile<<endl;
            }
        }
    }
    infile.close();
    outfile.close();
}
