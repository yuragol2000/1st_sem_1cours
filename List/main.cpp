#include "List.h"



int main() {

  List<int> List1 ;
  List1.PushEnd(8);
  List1.PushEnd(7);
  List1.PushEnd(6);
  List1.PushEnd(5);
  List1.PushEnd(4);
  List1.PushEnd(3);
  List1.PushEnd(2);
  List1.PrintList();
  List1.PrintList();
  List1.Swap(3,4);

  List1.PushEnd(3);


  return 0;
}
