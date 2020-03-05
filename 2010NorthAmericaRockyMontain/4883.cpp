// Contest - 2010 North American Rockey Mountain
// Problem 4883 - Ropes
// Vincent Cote - CPSC 3200
// Approach - As I take in the input I add it to a priority queue to easily have access to
// the highest climb in the list. I also keep a running total of the total climb (sum of pitches).
// For each size of rope, I check if the climb is less then half the rope length, if it is
// I get the total number of climbers by dividing the rope length by the highest pitch plus 1
// since the first climber doesn't use rope.
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