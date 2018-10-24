using namespace std;
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <array>
#include <string>
#include <sstream>
#include <iterator>

typedef vector<string> VI;

ostream& operator<<(ostream& os, VI vi)
{
    for(auto n : vi) os << n << " ";
    return os;
}

int factorial(int n) {
    if (n>0) return factorial(n-1)*n;
    return 1;
}

class Combiner {
    int amount=0;
    VI comb[1*2*3*4*5*6*7]; //
    VI swap(VI vi,int a,int b){
        ::swap(vi[a],vi[b]);
        return vi;
    }
    VI split(string str){
        istringstream buf(str);
        istream_iterator<string> beg(buf), end;
        vector<string> tokens(beg, end); // done!
        // for(auto& s: tokens) cout << s << '\t';
        // return VI{str,str,str};
        return tokens;
    }
    int combiner(int n){
        if (n>2) {
            int nf=combiner(n-1);
            for(int i=0;i<nf;i++)
                for(int j=1;j<n;j++)
                    comb[nf*j+i]=swap(comb[nf*(j-1)+i],n-j,n-j-1);
            return nf*n;
        }
        comb[1]=swap(comb[0],0,1); // N=2
        return 2;
    }

    public:
        Combiner(){}
        Combiner(VI initseq){
            // cout << initseq << " :  " << initseq.size() << endl;
            comb[0]=initseq; // init as 123456789
            amount=combiner(initseq.size());
        }
        Combiner(string str){
            VI initseq=split(str);
            comb[0]=initseq;
            amount=combiner(initseq.size());
        }
        void randomOut(){
            int r=random()%amount;
            cout.width(2);
            cout << r << " : " << comb[r] << endl;
        }
        void out()
        {
            int i=0;
            for(auto c : comb)
                if(i<amount) cout << c << " : " << ++i << endl;
            // cout << combs.amount << endl;
        }
};

int main()
{
    string text[]={
        "у попа была собака",
        "он её любил",
        "она съела кусок мяса",
        "он её убил",
        "в землю закопал",
        "надпись написал"
    };

    //cout << split("мы не рабы");
    // Combiner combs(VI{'A','B','C','D'});
    //Combiner combs1("мама мыла раму");combs1.out();
    //Combiner combs2("мы не рабы");combs2.out();
    //Combiner combs3("нас не догонят");combs3.out();
    vector<Combiner> combs; //{"","","","",""};
    //combs=new Combiner("у попа была собака"); combs->out();

    for(auto a:text) {
        cout << a << endl;
        combs.push_back(Combiner(a));
    }

    int n=1;do{
        cout << n++ << endl;
        for(auto a:combs) a.randomOut();
    }while(getchar()!=27);
}
