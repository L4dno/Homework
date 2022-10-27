#include <iostream>

int main()
{
    
    int x = 0;
    std::cin>>x;
    
    int cnt = 0;
    while (x>0){
        if (x&1){
            cnt+=1;
        }
        x>>=1;
    }
    
    std::cout<<cnt;

    return 0;
}