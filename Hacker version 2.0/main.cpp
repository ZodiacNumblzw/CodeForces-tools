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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
map<string,string> mp;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(Accepted);
    cout.tie(Accepted);
    ifstream fin;
    ofstream fout;
    fin.open("Submit.cpp",ios::in);
    //fout.open("Code.cpp",ios::out);
    fout.open("main.cpp",ios::out);
    string s;
    int flag=0,flag2=0;
    while(getline(fin,s))
    {
        if(s.find("#include")==0||s.find("#pragma")==0)
        {
            fout<<s<<endl;
            flag2=1;
            continue;
        }
        else if(flag2)
        {
            flag=1;
        }
        if(flag==0)
        {
            stringstream ss;
            string key,value;
            ss<<s;
            int cnt=0;
            while(ss>>s)
            {
                if(cnt==0)
                {
                    cnt++;        //读入#define
                }
                else if(cnt==1)         //读入Donothackit(X)
                {
                    key=s;
                    cnt++;
                }
                else if(cnt==2)      //读入#define后的string
                {
                    value+=s;
                    value+=' ';
                }
            }
            mp[key]=value;
        }
        else if(flag==1)
        {
            if(mp.count(s))
            {
                fout<<mp[s]<<endl;
                //cout<<mp[s]<<endl;
            }
            else
                fout<<s<<endl;//cout<<s<<endl;
        }
    }
    return Accepted;
}
