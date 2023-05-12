#include <stdexcept>
#include <iostream>
using std::cout;
int Largest(int a, int b, int c) {
  int d = 0;
  if(a>0 && a>d){d = a;}
  if(b>0 && b>d){d = b;}
  if(c>0 && c>d){d = c;}
  if(a<0 && b<0 && c<0){
    d = INT32_MIN;
    if((a>d)){d = a;} 
   if((b>d)){d = b;}
    if((c>d)){d = c;}
  }
  return d;
}

bool SumIsEven(int a, int b) {
  if((a+b)%2 == 0){
    return true;
  }
  else{
    return false;
  }
}

int BoxesNeeded(int apples) {
  if(apples <= 0){return 0;}
  if(apples % 20 == 0){return apples/20;}
  return 1+ apples/20;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  if(A_correct > A_total || B_correct > B_total || A_correct < 0 || A_total <= 0 || B_correct < 0 || B_total <=0){throw std::invalid_argument("invalid argument");}
  return (float)A_correct/A_total > (float)B_correct/B_total;
}

bool GoodDinner(int pizzas, bool is_weekend){
  if (pizzas >= 10 && pizzas <= 20) {
    return true;
  }
  if (is_weekend && pizzas >= 10) {
    return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  if(low > high){throw std::invalid_argument("invalid argument");}
  else if(low == high){return low;}
  else if(low+high == 1){return high;}
  else if(low+high == -1){return low;}
  else if(low*-1==high){return 0;}

  int t = 0;
  if(high > 0 && low < 0)
  {
    low*=-1;
    if(high < low)
    {
      t = low;
      low = high;
      high = t;
    }
    low += 1;
  }

  int value = 0; 

  for (int n = low; n <= high; n++) {
  if((INT32_MAX - n < value && n > 0) || (n < 0 && value < 0 && INT32_MIN - n > value)){throw std::overflow_error("Overflow error");} 
    value += n;
  }
  return value;

}

int Product(int a, int b) {
  //if(INT32_MAX/a > b || INT32_MIN/a < b){throw std::overflow_error("Overflow error");}
  if(a == 0 || b == 0){return 0;}
  if(a == INT32_MAX && b == -1 || b == INT32_MAX && a == -1){throw std::overflow_error("Overflow error 1");}
  if(a < 0)
  {
    if(b < 0)
    {
      a *= -1;
      b *= -1;
    }    
  }

  if(b < 0)
  {
    if (a < INT32_MAX / b){throw std::overflow_error("Overflow error 1");}
    if (a > INT32_MIN / b){throw std::overflow_error("Overflow error 2");}
  }
  if (b > 0) 
  {
    if (a > INT32_MAX / b){throw std::overflow_error("Overflow error 3");}
    if (a < INT32_MIN / b){throw std::overflow_error("Overflow error 4");}
  }
  
  int prod = a*b;
  //cout << a << " " << b;
  return prod;
}