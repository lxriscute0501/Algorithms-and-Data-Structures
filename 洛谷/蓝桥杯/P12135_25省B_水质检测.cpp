#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.length(),ans=0,loc=-1;
    bool b1=false, b2=false;
    
    for (int i=0;i<n;i++)
    {
        if (s1[i]=='.' and s2[i]=='.') continue;
        else if (s1[i]=='#' and s2[i]=='#') {
            if (loc>-1) ans+=i-loc-1;
            b1=true; b2=true; loc=i;
        } else {
            if (s1[i]=='#' and s2[i]=='.') {
                if (b1) {
                    if (loc>-1) ans+=i-loc-1;
                    b2=false;
                    loc=i;
                } else {
                    if (loc>-1) { ans+=i-loc; b2=true;}
                    b1=true;
                    loc=i;
                }
            }
            if (s1[i]=='.' and s2[i]=='#') {
                if (b2) {
                    if (loc>-1) ans+=i-loc-1;
                    b1=false;
                    loc=i;
                } else {
                    if (loc>-1) { ans+=i-loc; b1=true;}
                    b2=true;
                    loc=i;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}