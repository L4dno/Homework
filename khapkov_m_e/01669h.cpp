#include <iostream>
#include <vector>
#include <algorithm>

int Solve(){

    const int LEN = 31;
    int n = 0;
    int k = 0;

    std::cin>>n>>k;

    std::vector<int> cnt(LEN);

    int tmp =0;
    for (int i =0;i<n;++i) {
        std::cin >> tmp;
        for (int i = 0;i<LEN;++i){
            if ((1<<i)&tmp)
                ++cnt[i];
        }
    }

    int ans = 0;
    std::reverse(cnt.begin(), cnt.end());
    for (int i = 0;i<LEN;++i){
        if (cnt[i]==n)
            ans |= (1<<(LEN-i-1));
        else if (n-cnt[i]<=k){
            ans |= (1<<(LEN-i-1));
            k-=(n-cnt[i]);
        }
    }

    return ans;

}

int main(){

    int t =0;
    std::cin>>t;

    while (t-- > 0){
        std::cout<<Solve()<<"\n";
    }

    return 0;

}