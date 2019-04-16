#include <utility>
#include "grammar.h"
using namespace std;

grammar::grammar(int t1,int s1,int n1)
{
    nr_s = s1;
    nr_t = t1;

    n = n1;
    s = new char[nr_s];
    t = new char[nr_t];
    v = new str[n];
    count = new int[nr_t];

    for(int i=0;i<nr_t;i++)
        count[i]=0;

}

grammar::~grammar()
{
    delete[]s;
    delete[]t;
    delete[]v;
    delete[]count;
}

istream &operator>>(istream &in, grammar &g)
{
    if(g.nr_s==0)
    {
        in>>g.nr_s;
        delete[]g.s;
        g.s = new char[g.nr_s];
    }

    for(int i=0;i<g.nr_t;i++)
        in>>g.t[i];

    for(int i=0;i<g.nr_s;i++)
        in>>g.s[i];

    return in;
}

void grammar::push(istream &in)
{
    for(int i=0;i<n;i++)
     in>>v[i].first>>v[i].second>>v[i].third;

    for(int j=0;j<nr_t;j++)
        for(int i=0;i<n;i++)
            if(v[i].first==t[j])
                count[j]++;
}

bool grammar::compatibil(string w)
{
    int j,k;
    for(char i : w)
    {
        k=0;
        for(j=0;j<nr_s;j++)
            if(s[j] != i)
            {
                k++;
                if(k==nr_s)
                    return false;
            }
    }

    return true;
}

void grammar::get_pair()
{
    for(int i=0;i<n;i++)
        cout<<v[i].first<<" "<<v[i].second<<" "<<v[i].third<<endl;
    for(int i=0;i<nr_t;i++)
        cout<<t[i]<<" "<<count[i]<<endl;
}

bool grammar::generate(char start, string w, int it)
{

    int k=0;
    if(w.length()==0)
    {

        for ( int j = 0; j < n; j++ )
            if (start == v[j].first && v[j].third == '$')
               return true;

        return false;
    }


    if(w.length()==1&&it!=0)
    {
        for(int j=0;j<n;j++)
            if(start==v[j].first&&v[j].second=='$'&&v[j].third==w[0])
            {
                w.erase(0,1);
                return true;
            }

    }

    for(char p : w)
    {

        for ( int i = 0; i < n; i++ )
            if (start == v[i].first&&!w.empty())
            {
                if (v[i].third == p)
                {

                    w.erase(0, 1);
                    return generate(v[i].second,w,++it);

                } else
                {
                    for(int r=0;r<nr_t;r++)
                        if(start==t[r]&&k==count[r])
                        {
                            if(it==1)
                                cout<<"cuvant neacceptat"<<endl;

                            return false;
                        }
                    k++;
                }
            }

    }

}