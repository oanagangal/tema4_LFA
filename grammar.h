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
    int nr_t; // nr terminale
    char *s;  // neterminale
    char *t;// terminalele
    int n; // nr tranzitii
    int *count;  // numara terminalele
    str* v;

public:

    explicit grammar(int t1=0,int s1=0,int n1=0);
    ~grammar();

    friend istream&operator>>(istream&,grammar&);

    void push(istream&);
    bool compatibil(string);
    void get_pair();  // doar pt a testa daca mi a citit bine
    bool generate(char,string,int it=0);  // char-> terminalul de start
    // string -> cuvantu meu, it-> de cate ori apeleaza
};


#endif //TEMA4_LFA_GRAMMAR_H
