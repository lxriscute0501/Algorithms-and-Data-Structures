#include <iostream>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int a,b,c,k;
        int a1,b1,c1;
        cin>>a>>b>>c>>k;
        for (int i=1;i<=k;i++)
        {
            if (a==b and b==c and a==c) break;
            a1=(b+c)/2;
            b1=(a+c)/2;
            c1=(a+b)/2;
            a=a1; b=b1; c=c1;
        }
        cout<<a<<" "<<b<<" "<<c<<'\n';
    }
    return 0;
}