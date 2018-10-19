#include <iostream>

using namespace std;

// for_each example
#include <iostream>     // std::cout
#include <algorithm>    // std::for_each
#include <vector>       // std::vector
#include <array>

typedef std::vector<int> VI;

    /*
    comb[0]=swap(nums,0,0);
    comb[1]=swap(nums,0,1);
    comb[2]=swap(nums,0,2);

    comb[3]=swap(comb[0],1,2);
    comb[4]=swap(comb[1],1,2);
    comb[5]=swap(comb[2],1,2);
    */

    /*
    comb[ 6]=swap(comb[0],3,0);
    comb[ 7]=swap(comb[1],3,0);
    comb[ 8]=swap(comb[2],3,0);
    comb[ 9]=swap(comb[3],3,0);
    comb[10]=swap(comb[4],3,0);
    comb[11]=swap(comb[5],3,0);

    comb[12]=swap(comb[0],3,1);
    comb[13]=swap(comb[1],3,1);
    comb[14]=swap(comb[2],3,1);
    comb[15]=swap(comb[3],3,1);
    comb[16]=swap(comb[4],3,1);
    comb[17]=swap(comb[5],3,1);

    comb[18]=swap(comb[0],3,2);
    comb[19]=swap(comb[1],3,2);
    comb[20]=swap(comb[2],3,2);
    comb[21]=swap(comb[3],3,2);
    comb[22]=swap(comb[4],3,2);
    comb[23]=swap(comb[5],3,2);
    */

struct Sum {
    Sum() { sum = 0; }
    void operator()(int n) { sum += n; }
    int sum;
};

VI swap(VI vi,int a,int b){
    swap(vi[a],vi[b]);
    return vi;
}

void out(string s,VI nums){
    std::cout << s;
    for(auto n : nums) std::cout << n << "";
    //std::cout << '\n';
}

int factorial(int n) {
    if (n>0) return factorial(n-1)*n;
    return 1;
}

int main()
{
    // VI nums{1,2,3,4,5};
    VI nums{4,3,2,1};
//    VI nums{'A','B','C','D'};
    int n=nums.size();
    VI comb[factorial(n)];

//    cout << n << " : " << sizeof(comb)/sizeof(VI) << '\n';
    for(int i=0;i<n;i++) comb[i]=swap(nums,0,i); // 2!
    int z=factorial(n-1)*2; // beginning of second part of combine
    // cout << z << '\n';
    for(int i=0;i<n;i++) { // 3!
        comb[n+i]=swap(comb[i],1,2);
        comb[n*2+i]=swap(comb[n+i],2,3);
        // 4!
        comb[z+i]=swap(comb[i],1,3);
        comb[z+n+i]=swap(comb[n+i],1,3);
        comb[z+n*2+i]=swap(comb[n*2+i],1,3);
    }

    /*
    int i=0;
    std::cout << "после:  "<< '\n';
        for(auto c : comb) {
            out("",c);
            std::cout << " : " << ++i+1000;
            std::cout << '\n'; // out(n); //
        }
*/
    int k;
    int m=factorial(k=n-1);
    // cout << k << " : " << m << '\n';
    if (k>9) {
        for(int i=0;i<m;i++) {
            comb[m*1+i]=swap(comb[i],0,1);
            comb[m*2+i]=swap(comb[i],1,2);
            comb[m*3+i]=swap(comb[i],2,3);
        }
/*
        for(int j=1;j<=k;j++)
            for(int i=0;i<m;i++)
                comb[m*j+i]=swap(comb[i],k,j-1);
                */
    }

    int i=0;
    std::cout << "после:  "<< endl;
        for(auto c : comb) {
            out("",c);
            std::cout << " : " << ++i+1000;
            std::cout << endl; // out(n); //
        }
}

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

struct myclass {           // function object type:
  void operator() (int i) {std::cout << ' ' << i;}
} myobject;
