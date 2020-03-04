#include <iostream>
#include <queue>

int main(void) {
  while (true) {
    int ropes[3] = {50, 60, 70};
    int n;
    std::cin>>n;
    if (n == 0)
      return 0;
    std::priority_queue<int> pitches;
    int totalClimb = 0;
    int result[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
      int tmp;
      std::cin>>tmp;
      pitches.push(tmp);
      totalClimb += tmp;
    }
    for (int r = 0; r < 3; r++) {
      if (totalClimb <= ropes[r]/2) {
        int climbers = 1;
        climbers += ropes[r]/pitches.top();
        if (climbers > 1)
          result[r] = climbers;
      }
    }
    std::cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<std::endl;
  }
}