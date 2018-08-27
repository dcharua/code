#include <iostream>

void ByValue (int a){
  b += 2;
}
void ByPointer(int * c){
  *c +=2;
}
void ByReference(int & d) {
  d += 2;
}

int main(){
  int a=50;
  std::std::cout << "Original:" <<a << std::endl;
  Byvalue(a);
  std::cout << "By Value:" << a <<std::endl;
  ByPointer(&a);
  std::cout << "By Pointer:" << a <<std::endl;
  ByReference(a);
  std::cout << "Reference:" << a <<std::endl;
/*
  c= b =a = 15;
  //or
  a.operator=(15);
  b.operator=(a);
  c.operator=(b);
  //or
  c.operator=(b.operator=(a.operator=(15)));
  */
}
