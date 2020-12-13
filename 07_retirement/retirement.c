#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int month;              //the number of months it is applicable to
  double contribution;    //how many dollars are contributed (or spent if negative) from the account per month
  double rate_of_return;  //for the rate of returns (после инфляции)
};

typedef struct _retire_info retire_info;

double print_the_calculation (int startAge, double initial, retire_info name){
  for(int i = 0; i < name.month; i++){
    printf("Age %3d month %2d you have $%.2lf\n", startAge / 12, startAge % 12, initial);
    initial += name.contribution + initial * name.rate_of_return;
    startAge++;
  }
  return initial;
}

void retirement(int startAge,         //in months
		double initial,       //initial savings in dollars
		retire_info working,  //info about working
		retire_info retired) //info about being retired
{
  double new_initial;

  new_initial = print_the_calculation(startAge, initial, working);

  startAge += working.month;

  print_the_calculation(startAge, new_initial, retired);
}

int main(){
  retire_info working;
  retire_info retired;

  working.month = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.month = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(327, 21345, working, retired);

  return 0;
}
