#include <iostream>
#include "../../spinnercpp.h"

using namespace std;

int main() {
  // auto spin = std::make_unique<spinnercpp::spinner>();
  auto spin = std::make_unique<spinnercpp::spinner>(100ms, 1, "> ", " |");
  spin->start();
  std::this_thread::sleep_for(std::chrono::milliseconds(3000)); 
  spin->stop();

  cout << "Stop" << endl;
  
  return 0;
}
