#include <iostream>

using namespace std;

// for_each example
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <array>

typedef std::vector<char> VI;

ostream& operator<<(ostream& os, VI vi)
{
    for(auto n : vi) os << n << "";
    return os;
}

int factorial(int n) {
    if (n>0) return factorial(n-1)*n;
    return 1;
}

VI nums{'A','B','C','D'}; // ,'G','H','I'
//VI nums{4,3,2,1};

// VI comb[factorial(n)];
VI comb[1*2*3*4]; // *7*8*9

VI swap(VI vi,int a,int b){
    swap(vi[a],vi[b]);
    return vi;
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
    /*
    // N=3
    comb[2]=swap(comb[0],1,2);
    comb[3]=swap(comb[1],1,2);
    comb[4]=swap(comb[2],0,1);
    comb[5]=swap(comb[3],0,1);
    */
    return 2;
}

int main()
{
    comb[0]=nums; // init as 123456789
    std::cout << combiner(nums.size()) << endl;
    int i=0;
    for(auto c : comb) std::cout << c << " : " << ++i << endl;
}
