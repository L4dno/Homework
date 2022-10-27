#include <iostream>

void Solve(){
    
    int n = 0;
    int m = 0;
    std::cin>>n>>m;
    
    for (int i = 0, big_i = 0;i<n;++i, big_i=i/2){
        
        for (int j = 0, big_j=0;j<m;++j, big_j=j/2){
            
            //четный блок - шахматная раскраска
            if (big_i%2==big_j%2){
                if (i%2==j%2){
                    std::cout<<1<<" ";
                }
                else{
                    std::cout<<0<<" ";
                }
            }
            else{
                if (i%2==j%2){
                    std::cout<<0<<" ";
                }
                else{
                    std::cout<<1<<" ";
                }
            }
            
        }
        std::cout<<std::endl;
        
    }
    
}

int main()
{
    
    int t = 0;
    std::cin>>t;
    
    while (t-- > 0){
        Solve();
    }

    return 0;
}