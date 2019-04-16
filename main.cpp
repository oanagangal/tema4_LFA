#include <iostream>
#include <fstream>
#include <string>
#include "grammar.h"

using namespace std;


int main()
{
    ifstream f;
    f.open("date");

    grammar G(3,2,6);  // (nr terminale, nr neterminale, nr tranzitii)
    f>>G;
    G.push(f);

    string word;
    getline(cin,word);

    if(!G.compatibil(word))
    {   
        cout<<"cuvantul nu e compatibil cu multimea neterminalelor";
        return 0;
    }

    if(G.generate('S',word))
        cout<<"cuvant acceptat "<<endl;
    else
        cout<<"cuvantul nu e acceptat"<<endl;

    f.close();

  return 0;
}
