#include <iostream>
#include <queue>

void print( std::priority_queue<int, std::vector<int>, std::greater<int>> q){
    std::cout<<std::endl;
    
    while (!q.empty()){
        std::cout<<q.top()<<" ";
        q.pop();
        }
        
        std::cout<<std::endl;
}

int main(){
    
    int n = 0;
    std::cin>>n;
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> a;
    
    int tmp = 0;
    for (int i = 0;i<n;++i){
        std::cin>>tmp;
        a.push(tmp);
    }
    
    int k = 1;
    for (;k<=n;++k){
    
       a.pop();
       
       while (!a.empty() && k==a.top()){
        a.pop();
       }
       
       if (a.empty()){
           break;
           }
           
         // print(a);
    
    }
    
    std::cout<<k;
 
 return 0;
    
}