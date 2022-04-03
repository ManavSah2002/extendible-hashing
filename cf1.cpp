#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long M=1e9+7;
vector<vector<ll>>v;
ll cap,glb;
long long poww(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b%2)
        {
            ans=(ans*a);
        }
        a=(a*a);
        b=b/2;
    }
    return ans;
}
string DtoB(int num)
{
    string str;
      while(num){
      if(num & 1)
        str+='1';
      else
        str+='0';
      num>>=1;
    }   
      return str;
}
void split(ll x)
{
    ll sum=0,y=v.size();
    vector<ll>w;
    w.push_back(v[x][0]+poww(2,v[x][1]));
    v[x][1]++;
    w.push_back(v[x][1]);
    v.push_back(w);
    w.clear();
    for(ll i=0;i<v[x].size();i++)
    {
        w.push_back(v[x][i]);
    }
    v[x].clear();
    v[x].push_back(w[0]);
    v[x].push_back(w[1]);
    for(ll i=2;i<w.size();i++)
    {
        sum=0;
        for(ll j=0;j<w[1];j++)
        {
            sum=sum+(w[i]&poww(2,j));
        }
        if(sum==w[0])
        {
            v[x].push_back(w[i]);
            continue;
        }
        v[y].push_back(w[i]);
    }
    w.clear();
    if(v[x].size()>cap+2)
    {
        split(x);
    }
    if(v[y].size()>cap+2)
    {
        split(y);
    }
    return;
}
void display( )
{
    ll sum=glb;
    for( ll i=0;i<v.size();i++)
    {
        sum=max(sum,v[i][1]);
    }
    cout<<sum<<"\n"<<v.size()<<"\n";
    for(ll i=0;i<v.size();i++)
    {
        cout<<v[i].size()-2<<" "<<v[i][1]<<"\n";
    }
    cout<<endl;
    return;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll x,y,sum;
    cin>>glb>>cap;
    vector<ll>w;
    for(ll i=0;i<poww(2,glb);i++)
    {
        w.push_back(i);
        w.push_back(glb);
        v.push_back(w);
        w.clear();
    }
    while(1)
    {
        cin>>x;
        if(x==6)break;
        
        if(x==5)display();
    
        if(x==4)
        {
            sum=0;
            cin>>y;
            for(ll i=0;i<v.size();i++)
            {
                auto it=v[i].begin();
                ++it;
                ++it;
                while(it!=v[i].end())
                {
                    if(*it==y)
                    {
                        v[i].erase(it);
                        sum=-1;
                        break;
                    }
                    ++it;
                }
                if(sum==-1)
                {
                    break;
                }
            }
        }
        if(x==3)
        {
            cin>>y;
            sum=0;
            for(ll i=0;i<v.size();i++)
            {
                for(ll j=2;j<v[i].size();j++)
                {
                    if(v[i][j]==y)
                    {
                        sum=-1;
                        break;
                    }
                }
                if(sum==-1)
                {
                    break;
                }
            }
        }
        if(x==2)
        {
            cin>>y;
            for(ll i=0;i<v.size();i++)
            {
                sum=0;
                for(ll j=0;j<v[i][1];j++)
                {
                    sum=sum+(y&poww(2,j));
                }
                if(sum==v[i][0])
                {
                    v[i].push_back(y);
                    if(v[i].size()>cap+2)
                    {
                        split(i);
                    }
                    break; 
                }
            }
        }
    }
}
