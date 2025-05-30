#include<bits/stdc++.h>
using namespace std;

long long ans;
int n,m,c,d;
int flag[30][30];
unsigned long long a[30][30];
int dhorsex[10] = {0, -1, -1, 1, 1, -2, -2, 2, 2};
int dhorsey[10] = {0, -2, 2, -2, 2, 1, -1, 1, -1};

int main()
{
    cin>>n>>m>>c>>d;
    for (int i=0; i<=8; i++)
    {
        if ((c + dhorsex[i]) >= 0 && (d + dhorsey[i]) >= 0)
        {
            flag[c + dhorsex[i]][d + dhorsey[i]] = -1;
        }
    }
    a[1][0] = 1;
    for (int i=1; i<=n+1; i++)
    {
        for (int j=1; j<=m+1; j++)
        {
            a[i][j] = a[i-1][j] + a[i][j-1];
            if (flag[i-1][j-1] == -1) a[i][j] = 0;
        }
    }
    cout<<a[n+1][m+1]<<endl;
    return 0;
}