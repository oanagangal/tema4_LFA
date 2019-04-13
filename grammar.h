#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef TEMA4_LFA_GRAMMAR_H
#define TEMA4_LFA_GRAMMAR_H
struct str
{
    char first;
    char second,third;
};


class grammar
{
    int nr_s; // nr neterminate
    char *s;  // neterminale
    unsigned int n; // tranzitii
    str** v;

public:

    explicit grammar(int s1=0,unsigned int t=0);
    grammar(const grammar &g);
    ~grammar();

    friend istream&operator>>(istream&,grammar&);
    void push(istream&);
    bool compatibil(string);
    void get_pair();
    bool verify(char,string);


};


#endif //TEMA4_LFA_GRAMMAR_H
