#include <iostream> 
#include <cstdio>
using namespace std ;

int main (){
  int array_def[3] = {1,2,3};
  int array_for[3];
  for (int i =0 ;i <3 ;i++){
    array_for[i] = i+1;
  }
  for (int i =0 ;i <3 ;i++){
    printf("This is the array_def[%d]: %d\n",i,array_def[i]);
  }
  for (int i =0 ;i <3 ;i++){
    printf("This is the array_for[%d]: %d\n",i,array_for[i]);
  }
}

