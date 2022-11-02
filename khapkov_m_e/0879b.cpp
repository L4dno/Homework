#include <iostream>
#include <queue>

int main()
{
  
  int n = 0;
  long long k =0;
  
  std::cin>>n>>k;
  
  std::queue<int> players;
  int tmp = 0;
  
  for (int i =0;i<n;++i){
    std::cin>>tmp;  
    players.push(tmp);
  }
  
  int cnt = 0;
  int cur_player = players.front();
  players.pop();
  int new_player = 0;
  
  while (cnt < k && cnt < 2*n){
      new_player = players.front();
      players.pop();
      if (cur_player > new_player){
        players.push(new_player);
        ++cnt;
        //std::cout<<cnt<<std::endl;
      }
      else{
        cnt = 1;
       // std::cout<<cnt<<std::endl;
        players.push(cur_player);
        cur_player = new_player;
      }
  }
  
  std::cout<<cur_player;
  
}