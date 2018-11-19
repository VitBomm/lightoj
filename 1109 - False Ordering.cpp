#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int countUocSo(int N)
{
    int dem = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
            dem++;
    }

    return dem;
}
struct Temp{
    int so;
    int soluonguocso;
};
bool compare(const Temp &a, const Temp &b)
{
    return a.soluonguocso < b.soluonguocso || (a.soluonguocso == b.soluonguocso && a.so > b.so);
}
void solved()
{
    vector<Temp> v;
    map<int,int> mapp;
    Temp a;
    for(int i = 1 ; i<=1000; i++)
    {
        a.so = i;
        a.soluonguocso = countUocSo(i);
        v.push_back(a);
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 1; i<= 1000;i++)
    {
       mapp[i] = v[i-1].so;
    }
    int T;
    cin>>T;
    int e;
    int casee = 0;
    while(T--)
    {
        casee++;
        cin>>e;
        cout<<"Case "<<casee<<": "<<mapp[e]<<endl;
    }
}
int main()
{
    solved();
    return 0;
}
