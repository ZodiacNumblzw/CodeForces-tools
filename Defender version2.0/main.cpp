#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define ll long long
#define ld long double
const ld pi=acos(-1);
const ll mod=1e9+7;
#define lowbit(x) (x&(-x))
const ld eps=1e-6;
const int maxn=1e5+10;
#define Accepted 0
ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}
vector<pair<string,string> >v;
vector<string> vs;
const string D="Donothackit";
const string F="#define";
string turn(int x)      //int 转为string
{
    string s;
    while(x)
    {
        s+=('0'+x%10);
        x/=10;
    }
    int len=s.length();
    string ss;
    for(int i=len-1; i>=0; i--)
        ss+=s[i];
    return ss;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(Accepted);
    cout.tie(Accepted);
    ifstream fin;
    ofstream fout;
    fin.open("main.cpp",ios::in);
    fout.open("Submit.cpp",ios::out);
    string s;
    int len=0,temp;
    srand(time(0));
    while(getline(fin,s))
    {
        string ss;
        if(s.find("#")==0)
        {
            vs.push_back(s);
        }
        else
        {
            if(!len)
            {
                ss=D+turn(++len);
                v.push_back(make_pair(ss,s));
            }
            else
            {
                temp=rand()%len;
                ss=D+turn(++len);
                v.push_back(make_pair(ss,s));       //把最末端的pair和前面的交换一下
                swap(v[temp],v[len-1]);
            }
            vs.push_back(ss);
        }
    }
    for(int i=0; i<len; i++)
    {
        fout<<F<<' '<<v[i].first<<' '<<v[i].second<<endl;
    }
    for(string ss:vs)
    {
        fout<<ss<<endl;
    }
    return Accepted;
}
