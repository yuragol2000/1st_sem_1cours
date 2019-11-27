////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//---------------------------------Onegin_sort--------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include "Stack.h"

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//----------------------------------FUNCTIONS---------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

template <typename T>
Stack<T>::Stack(int maxSize) :
   size(maxSize),
   hash_sum(0)
{
   stackPtr = new T[size + 2*LEN_OF_CANARY];

   for (int i = 0; i < LEN_OF_CANARY;i++)
   {
       stackPtr[i] = i*2;
   }

   for (int i = 2*LEN_OF_CANARY - 1 ,z = 0;z < LEN_OF_CANARY;i--,z++)
   {
       stackPtr[i] = z*2;

   }
   top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
   size(otherStack.getStackSize()),
   hash_sum(otherStack.getStackHash()),
   top(otherStack.getTop())
{
   stackPtr = new T[size+2*LEN_OF_CANARY];

   for(int ix = 0; ix < top+2*LEN_OF_CANARY; ix++)
       stackPtr[ix] = otherStack.getPtr()[ix];

   StackOK();
}

template <typename T>
Stack<T>::~Stack()
{
   delete [] stackPtr;
}

template <typename T>
inline void Stack<T>::push(const T &value)
{
   assert(top <= size);
   if (top == size)
   {
       size  = 2*top;
       stackPtr = (T*)realloc(stackPtr,(size+2*LEN_OF_CANARY)*sizeof(T));
   }
   stackPtr[LEN_OF_CANARY+top] = value;
   top++;

   for (int i = top+2*LEN_OF_CANARY - 1 ,z = 0;z < LEN_OF_CANARY;i--,z++)
   {
       stackPtr[i] = z*2;

   }
   StackHash();
   StackOK();
}

template <typename T>
inline T Stack<T>::pop()
{
   assert(top > 0);
   if (top == size/4)
   {
       size  = top;
       stackPtr = (T*)realloc(stackPtr,size*sizeof(T));
   }

   T poped = stackPtr[top+LEN_OF_CANARY-1];
   top--;
   for (int i = top+2*LEN_OF_CANARY - 1 ,z = 0;z < LEN_OF_CANARY;i--,z++)
   {
       stackPtr[i] = z*2;

   }
   StackHash();
   StackOK();

   return poped;
}

template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
  assert(nom <= size+2*LEN_OF_CANARY);

  return stackPtr[nom];
}

template <typename T>
inline void Stack<T>::printStack()
{
  StackOK();

  cout << "#----------------------------------------------------------\n";
  cout << "#    Stack  " <<  &stackPtr[0] << "\n";
  cout << "#\n";
  cout << "#            ----------date 08/10/2019--------------    \n";
  cout << "#\n";
  cout << "#    capacity = " <<  getStackSize()  << " \n";
  cout << "#    size = "     <<  getTop()   << " \n";
  cout << "#    hash_sum = " <<  getStackHash()  << " \n";
  cout << "#\n";
  cout << "#----------------------------------------------------------\n\n";

  for (int ix = top + 2*LEN_OF_CANARY - 1; ix >= 0; ix--)
      cout << "|" << setw(4) <<"\t[" << ix <<"]\t =  "<<   stackPtr[ix] << "\t|"<< endl;

  cout << endl;



  printf("#    ------------------------------------    #\n");
  printf("#    -----------NO_PROBLEM---------------    #\n");
  printf("#    ------------------------------------    #\n\n");

}

template <typename T>
inline int Stack<T>::getStackSize() const
{
  return size;
}

template <typename T>
inline void Stack<T>::StackHash()
{
  int sum = 0;

  for(int i = 0;i < top;i += 2){

    int mul = stackPtr[LEN_OF_CANARY+i]*stackPtr[LEN_OF_CANARY+i+1];
    int div = stackPtr[LEN_OF_CANARY+i]/stackPtr[LEN_OF_CANARY+i+1];

    sum += mul;
    sum += div;

  }
  hash_sum = sum;
}

template <typename T>
inline int Stack<T>::getStackHash() const
{
  return hash_sum;
}
template <typename T>
inline void Stack<T>::DumpStack(string put_file) const
{

  ofstream Dump;

  Dump.open(put_file);

  if (!Dump){

    cerr << "Error opening Put_file\n";
    exit(1);
  }

  Dump << "#----------------------------------------------------------\n";
  Dump << "#    Stack  " <<  &stackPtr[0] << "\n";
  Dump << "#    ----------date 08/10/2019--------------    #\n";





    for (int ix = top + 2*LEN_OF_CANARY - 1; ix >= 0; ix--)
        Dump << "|" << setw(4) <<"\t[" << ix <<"]\t =  "<<   stackPtr[ix] << "\t|"<< endl;

    Dump << endl;

    Dump << "#    capacity = " << size << endl;
    Dump << "#    size =  " << top << endl;
    Dump << "#    hash_sum = " << hash_sum << endl;
    Dump << "#    ------------------------------------    #\n\n";

for (int i = 0; i < 7;i++)
  {
      if (errors[i] == 1)
          switch (i)
          {
              case BAD_SIZE:
                  Dump << "#    ----------ERROR with SIZE-----------    #\n";
                  Dump << "#    size = " << top;
                  Dump << "#    ------------------------------------    #\n";
                  break;

              case BAD_SIZE_CAPACITY:
                  Dump << "#     --------ERROR SIZE&CAPACITY------    #\n";
                  Dump << "#    capacity = " << size << endl;
                  Dump << "#    size = " << top << endl;
                  Dump << "#    ------------------------------------    #\n";
                  break;

              case BAD_CAPACITY:
                  Dump << "#    ------ERROR with CAPACITY-----------    #\n";
                  Dump << "#    capacity = " << size << endl;
                  Dump << "#    ------------------------------------    #\n";
                  break;

              case BAD_PROTACTION:
                  Dump << "#    --------ERROR with PROTACTION-------    #\n";
                  Dump << "#    hash_sum = " << hash_sum << endl;
                  Dump << "#    Stack_hash = " <<  getStackHash() << endl;
                  Dump << "#    ------------------------------------    #\n";
                  break;

              case BAD_CANARY_DEAD:
                  Dump << "#    --------ERROR with SIZE-------------    #\n";
                  Dump << "#    capacity = " << size << endl;
                  Dump << "#    size =  " << top << endl;
                  Dump << "#    ------------------------------------    #\n";
                  break;

              case NO_PROBLEM:

                Dump << "#    ------------------------------------    #\n";
                Dump << "#    -----------NO_PROBLEM---------------    #\n";
                Dump << "#    ------------------------------------    #\n\n";
                break;

              default :
                  break;
          }
  }
  Dump.close();

}
template <typename T>
inline int Stack<T>::getTop() const
{
  return top;
}

template <typename T>
inline void Stack<T>::StackOK()
{
  assert(stackPtr);

  int problems  = 0;


  if(top < 0)
  {
      errors[BAD_SIZE] = 1;
      problems++;
  }


  if(top > size)
  {
      errors[BAD_SIZE_CAPACITY] = 1;
      problems++;
  }


  if(size < 0)
  {
      errors[BAD_CAPACITY] = 1;
      problems++;
  }


  int sum = 0;

  for(int i = 0;i < top;i += 2){

    int mul = stackPtr[LEN_OF_CANARY+i]*stackPtr[LEN_OF_CANARY+i+1];
    int div = stackPtr[LEN_OF_CANARY+i]/stackPtr[LEN_OF_CANARY+i+1];

    sum += mul;
    sum += div;

  }
  if(sum != getStackHash())
    errors[BAD_PROTACTION];



  // for(int i = 0; i < LEN_OF_CANARY; ++i)
  //
  //     if(stackPtr[i] != canary[i] || stackPtr[top +  2* LEN_OF_CANARY   - i] != canary[LEN_OF_CANARY  i])
  //     {
  //
  //         errors[BAD_CANARY_DEAD] = 1;
  //         problems++;
  //
  //     }

  if (problems == 0)
      errors[NO_PROBLEM] = 1;
  else{
    errors[PROBLEMS] = problems;
    cout  << "\n|||| ERROR, CHECK DUMP !!!!!!!\n";

  }

}
template <typename T>
inline T *Stack<T>::getPtr() const
{
  return stackPtr;
}
