using namespace std;

// for_each example
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <array>

typedef vector<char> VI;
typedef vector<VI> COMB;

ostream& operator<<(ostream& os, VI vi)
{
    for(auto n : vi) os << n << ".";
    return os;
}

long factorial(int n) {
    if (n>0) return factorial(n-1)*n;
    return 1;
}

class Combiner {

    // VI comb[factorial(n)];
    VI comb[1*2*3*4*5*6*7*8]; //

    VI swap(VI vi,long a,long b){
        ::swap(vi[a],vi[b]);
        return vi;
    }

    long combiner(int n){
        if (n>2) {
            long nf=combiner(n-1);
            for(long i=0;i<nf;i++)
                for(long j=1;j<n;j++)
                    comb[nf*j+i]=swap(comb[nf*(j-1)+i],n-j,n-j-1);
            return nf*n;
        }
        comb[1]=swap(comb[0],0,1); // N=2
        return 2;
    }

    public:

        long amount=0;
        Combiner(VI initseq){
            comb[0]=initseq; // init as 123456789
            amount=combiner(initseq.size());
        }

        void out(long i=0)
        {
            for(auto c : comb)
                if(i<amount) cout << c << " : " << ++i << endl;
        }

};

int main()
{
    //setlocale(LC_ALL,"");
    cout << "Привет!";
//  VI nums{4,3,2,1};
    Combiner combs(VI{'A','B','C','D'});
//    Combiner combs(VI{'х','у','я','к','с'});
    //Combiner combs(VI{'A','B','C','D','E','F','G','H'});
    cout << combs.amount << endl;
    combs.out();
}
