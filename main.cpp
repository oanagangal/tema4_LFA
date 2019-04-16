#include <iostream>
#include <fstream>
#include <string>
#include "grammar.h"

using namespace std;


int main()
{
    ifstream f,g;
    f.open("date");

    grammar G(3,2,6);
    f>>G;
    G.push(f);

    string word;
    getline(cin,word);

    if(!G.compatibil(word))
       return 0;

    if(G.generate('S',word))
        cout<<"cuvant acceptat "<<endl;
    else
        cout<<"cuvantul nu e acceptat"<<endl;


    g.close();
    f.close();

  return 0;
}