#include <iostream>
#include <vector>

int Solve(){

    int n = 0;
    std::cin>>n;

    int res = (1<<31)-1;
    int tmp = 0;

    for (int i = 0;i<n;++i){
        std::cin>>tmp;
        if (tmp!=i){
            res&=tmp;
            res&=i;
        }
    }

    return res;

}

int main(){

    int t = 0;
    std::cin>>t;

    while (t-- > 0){
        std::cout<<Solve()<<std::endl;
    }

    return 0;

}