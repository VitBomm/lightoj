#include <iostream>
#include <string>
#include <math.h>
#include <map>
using namespace std;
void solved()
{
    int T;
    cin>>T;
    long long int n,m;
    int Case =0;
    while(T--)
    {
        Case++;
        cin>>n>>m;
        cout<<"Case "<<Case<<": "<<(m*m)*((n/m)/2)<<endl;
    }
}
int main()
{
    solved();
    return 0;
}
