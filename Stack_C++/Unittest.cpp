////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//--------------------------------LIB-----------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include "Unittest.h"

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//---------------------------------Unittests----------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////
void Test_Create() {

    Stack<int> UNIT_Stack;

    AssertEqual(UNIT_Stack.Peek(0), 0);
    AssertEqual(UNIT_Stack.Peek(1), 2);
    AssertEqual(UNIT_Stack.Peek(2), 4);
    AssertEqual(UNIT_Stack.Peek(3), 4);
    AssertEqual(UNIT_Stack.Peek(4), 2);
    AssertEqual(UNIT_Stack.Peek(5), 0);

    AssertEqual(UNIT_Stack.getStackSize(), 2);
    AssertEqual(UNIT_Stack.getTop(), 0);

    UNIT_Stack.StackOK();

    UNIT_Stack.printStack();
    UNIT_Stack.DumpStack("Dump.txt");

}
void Test_Create1() {

    Stack<char> UNIT_Stack;

    AssertEqual(UNIT_Stack.Peek(0), 0);
    AssertEqual(UNIT_Stack.Peek(1), 2);
    AssertEqual(UNIT_Stack.Peek(2), 4);

      UNIT_Stack.push('D');
      UNIT_Stack.push('A');
      UNIT_Stack.push('F');
      UNIT_Stack.push('N');


     AssertEqual(UNIT_Stack.getStackSize(), 4);
    // AssertEqual(UNIT_Stack.pop(), 'D');

       // UNIT_Stack.printStack();

      UNIT_Stack.DumpStack("Dump1.txt");


}

void Test_push() {
{
      Stack<int> UNIT_Stack;
      UNIT_Stack.DumpStack("Dump.txt");

      UNIT_Stack.push(10);
      UNIT_Stack.push(11);
      UNIT_Stack.push(12);

      AssertEqual(UNIT_Stack.getStackSize(), 4);
      AssertEqual(UNIT_Stack.getTop(), 3);

      UNIT_Stack.push(13);
      UNIT_Stack.push(14);

      AssertEqual(UNIT_Stack.getStackSize(), 8);

      UNIT_Stack.push(15);
      UNIT_Stack.push(13);
      UNIT_Stack.push(14);
      UNIT_Stack.push(15);

      AssertEqual(UNIT_Stack.getStackSize(), 16);
      UNIT_Stack.push(13);
      UNIT_Stack.push(14);
      UNIT_Stack.push(15);
      UNIT_Stack.push(13);
      UNIT_Stack.push(14);
      UNIT_Stack.push(15);
      UNIT_Stack.push(13);
      UNIT_Stack.push(14);
      UNIT_Stack.push(15);

      AssertEqual(UNIT_Stack.Peek(3), 10);
      AssertEqual(UNIT_Stack.Peek(4), 11);
      AssertEqual(UNIT_Stack.Peek(5), 12);
      AssertEqual(UNIT_Stack.Peek(6), 13);
      AssertEqual(UNIT_Stack.Peek(7), 14);
      AssertEqual(UNIT_Stack.Peek(8), 15);


      Stack<int> newStack(UNIT_Stack);

      UNIT_Stack.printStack();
      newStack.printStack();

      AssertEqual(UNIT_Stack.Peek(0), UNIT_Stack.Peek(0));
      AssertEqual(UNIT_Stack.Peek(1), UNIT_Stack.Peek(1));
      AssertEqual(UNIT_Stack.Peek(2), UNIT_Stack.Peek(2));
      AssertEqual(UNIT_Stack.Peek(3), UNIT_Stack.Peek(3));
      AssertEqual(UNIT_Stack.Peek(4), UNIT_Stack.Peek(4));
      AssertEqual(UNIT_Stack.Peek(5), UNIT_Stack.Peek(5));
      AssertEqual(UNIT_Stack.Peek(6), UNIT_Stack.Peek(6));
      AssertEqual(UNIT_Stack.Peek(7), UNIT_Stack.Peek(7));
      AssertEqual(UNIT_Stack.Peek(8), UNIT_Stack.Peek(8));
      AssertEqual(UNIT_Stack.Peek(9), UNIT_Stack.Peek(9));
      AssertEqual(UNIT_Stack.Peek(10), UNIT_Stack.Peek(10));
      AssertEqual(UNIT_Stack.Peek(11), UNIT_Stack.Peek(11));
      AssertEqual(UNIT_Stack.Peek(12), UNIT_Stack.Peek(12));
      AssertEqual(UNIT_Stack.Peek(13), UNIT_Stack.Peek(13));
      AssertEqual(UNIT_Stack.Peek(14), UNIT_Stack.Peek(14));
      AssertEqual(UNIT_Stack.Peek(15), UNIT_Stack.Peek(15));
      AssertEqual(UNIT_Stack.Peek(16), UNIT_Stack.Peek(16));
      AssertEqual(UNIT_Stack.Peek(17), UNIT_Stack.Peek(17));
      AssertEqual(UNIT_Stack.Peek(18), UNIT_Stack.Peek(18));

  UNIT_Stack.StackOK();
    UNIT_Stack.DumpStack("Dump2.txt");
}

}
void Test_pop() {

      Stack<int> UNIT_Stack;

      //UNIT_Stack.printStack();

      UNIT_Stack.push(10);
      UNIT_Stack.push(11);
      UNIT_Stack.push(12);

      AssertEqual(UNIT_Stack.getStackSize(), 4);
      AssertEqual(UNIT_Stack.getTop(), 3);

      UNIT_Stack.push(13);
      UNIT_Stack.push(14);
      UNIT_Stack.push(15);

      AssertEqual(UNIT_Stack.getStackSize(), 8);
      AssertEqual(UNIT_Stack.getTop(), 6);


      AssertEqual(UNIT_Stack.pop(), 15);
      AssertEqual(UNIT_Stack.pop(), 14);
      AssertEqual(UNIT_Stack.pop(), 13);
      AssertEqual(UNIT_Stack.pop(), 12);
      AssertEqual(UNIT_Stack.pop(), 11);
      AssertEqual(UNIT_Stack.pop(), 10);


}
void Test_Stack_COPY() {

}

void Unittest(void){



  TestRunner tr;
  tr.RunTest(Test_Create, "Test_Create");
  tr.RunTest(Test_Create1, "Test_Create1");
  tr.RunTest(Test_push, "Test_push");
  tr.RunTest(Test_pop, "Test_pop");
}
