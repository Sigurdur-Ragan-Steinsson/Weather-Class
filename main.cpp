#include <iostream>
#include <string>

using namespace std;

class Weather{
  private:
    //store measurements in cm
    string weekDays[7] = {"mon", "tue", "wed", "thu", "fri", "sat", "sun"};
    float lastWeekRain[7];
    float todayHigh;
    float todayLow;

  public:
        Weather(){    
          todayHigh = 58;
          todayLow = 38;
          lastWeekRain[7] = {1, 2, 6, 0, 0, 3, 0};
  };
  float CelToF(float temp));
  float FToCel(float temp);
  void print();
  int highestRainFall();
  int lowestRainFall();
};

float Weather::CelToF(float temp){
  //Celsius -> Farenheit;
  temp *= 9/5;
  temp += 32;
  return temp;
}

float Weather::FToCel(float temp){
  temp -= 32;
  temp *= 5/9;
  return temp;
}

int Weather::highestRainFall(){
  float currMax = -1.;
  int indexMax;
  for(int i = 0; i < 7; i++){
    if(lastWeekRain[i] > currMax){
      currMax = lastWeekRain[i];
      indexMax = i;
      }
  }
  return indexMax;
}

int Weather::lowestRainFall(){
  float currMin = 100000000000;
  int indexMin;
  for(int i = 0; i < 7; i++){
      if(lastWeekRain[i] < currMin){
        currMin = lastWeekRain[i];
        indexMin = i;
    }
  }
  return indexMin;
}

void Weather::print(){
  cout << "Today's high is " << todayHigh << endl;
  cout << "Today's low is " << todayLow << endl;
  cout << "This week the lowest rain fall was " << lastWeekRain[lowestRainFall()] << " on " << weekDays[lowestRainFall()] << endl;
  cout << "This week the highes rain fall was " << lastWeekRain[highestRainFall()] << " on " << weekDays[highestRainFall()] << endl;
  
}

int main() {
  Weather today;
  today.print();
}