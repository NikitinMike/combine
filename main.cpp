using namespace std;

#include <iostream>     // std::cout
#include <string>
#include <locale>
#include <algorithm>    // std::for_each
//#include <vector>       // std::vector
//#include <array>

typedef string String;
#define SWAP swap2

/*
ostream& operator<<(ostream& os, VI vi)
{
    for(auto a : vi) os << a << ".";
    return os;
}
*/

int factorial(int n) {
    if (n>0) return factorial(n-1)*n;
    return 1;
}

class Combiner {

    String comb[1*2*3*4*5*6*7*8]; // *9

    String swap1(String vi,int a,int b){
        ::swap(vi[a],vi[b]);
        return vi;
    }

    String swap2(String vi,int a,int b){
        ::swap(vi[a*2],vi[b*2]);
        ::swap(vi[a*2+1],vi[b*2+1]);
        return vi;
    }

    int combiner(int n){
        if (n<3) {
            comb[1]=SWAP(comb[0],0,1); // N=2
            return 2;
        }
        int nf=combiner(n-1);
        for(int i=0;i<nf;i++)
            for(int j=1;j<n;j++)
                comb[nf*j+i]=SWAP(comb[nf*(j-1)+i],n-j,n-j-1);
        return nf*n;
    }

    public:
        int amount=0;
        Combiner(String initseq,int bytes=2){
            comb[0]=initseq;
            amount=combiner(initseq.length()/bytes);
        }
        void out(int i=0)
        {
            for(auto c : comb)
                if(i<amount)
                    cout << c << " : " << ++i << '\t'; // endl;
        }
};

//char rus[] = "абвгдеёжзийклмнопрстуфхцчшщьъыэюя";
int main()
{
    setlocale(LC_ALL, "rus");
    Combiner combs("главрыба");
    cout << combs.amount << endl;
    combs.out();
}
