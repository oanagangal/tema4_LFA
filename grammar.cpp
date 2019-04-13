#include "grammar.h"

grammar::grammar(int s1,unsigned int t)
{
    nr_s = s1;
    n=t;
    s = new char[nr_s];
    v = new str[n];

}

grammar::grammar(const grammar &g)
{
    nr_s = g.nr_s;
    n=g.n;
    s = new char[nr_s];
    v = new str[n];

    for(int i=0;i<nr_s;i++)
      s[i]=g.s[i];

    for(int i=0;i<n;i++)
    {
        v[i].first=g.v[i].first;
        v[i].second=g.v[i].second;
        v[i].third=g.v[i].third;
    }


}

grammar::~grammar()
{
    delete[]s;
    delete[]v;
}

istream &operator>>(istream &in, grammar &g)
{
    if(g.nr_s==0)
    {
        in>>g.nr_s;
        delete[]g.s;
        g.s = new char[g.nr_s];
    }

    for(int i=0;i<g.nr_s;i++)
        in>>g.s[i];

    return in;
}

void grammar::push(istream &in)
{
    for(int i=0;i<n;i++)
     in>>v[i].first>>v[i].second>>v[i].third;
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
        cout<<v[i].second<<" "<<v[i].third<<endl;
}

bool grammar::verify(char start, string w)
{
    for(char p : w)
    {
        for(int i=0;i<n;i++)
        {
            if(start==v[i].first)

        }
    }
    return false;
}








