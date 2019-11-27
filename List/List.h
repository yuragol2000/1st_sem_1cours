#pragma once

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//--------------------------------LIB-----------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <sstream>
#include <exception>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//----------------------------------FUNCTIONS---------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

enum errors
    {
    BAD_SIZE = 1,
    BAD_SIZE_CAPACITY = 2,
    BAD_CAPACITY = 3,
    BAD_PROTACTION = 4,
    BAD_CANARY_DEAD = 5,
    NO_PROBLEM = 0,
    PROBLEMS = 6
};
// template <typename T> class List

const int POISON = -666;
const int InitSize = 20;
const int ElementNotFound = -999;



template <typename T>
class List
{
private:
  class ListElem {
    friend class List<T>;
  private:
      T data = POISON;
      ListElem* next = NULL;
      ListElem* prev = NULL;
      size_t order = 0;
  };
    ListElem *Element = nullptr;

    ListElem* head = NULL;
    ListElem* tale = NULL;

    int ErrorCode = POISON;
    size_t size = (size_t) POISON;
    size_t order_counter = 1;

public:
     List();                  // пу
  //  List(const Stack<T> &);          // конструктор копирования
    ~List(){cout << "I'm Destructed";};                         // деструктор

    inline int Push(const T &) ;    // поместить элемент в вершину стека
    inline int PushEnd(const T & ) ;    // поместить элемент в вершину стека
    inline void InsertBefore (const size_t index, const T &);
    inline void InsertAfter (const size_t index, const T &);
    inline size_t SearchElem (const T &) const;
    inline void PrintList() ;         // вывод стека на экран
    inline size_t getOrder(const size_t ) const;
    inline T getData(const size_t) const;
    inline size_t getSize() const;
    inline T getFront() const;
    inline T getBack() const;
    inline void Delete(const size_t) ;
    inline void Sort(void) ;
    inline void Swap(const size_t,const size_t) ;
};
template <typename T>
inline void List<T>::Swap(const size_t index1,const size_t index2){
  ListElem* current_1 = head;

  for (int ix = 1 ; ix < index1; ix++)
  {
    current_1 = current_1->next;
  }

  ListElem* current_2 = head;

  for (int ix = 1 ; ix < index2; ix++)
  {
    current_2 = current_2->next;
  }
  T data_for_swap = current_1->data;
  current_1->data = current_2->data;
  current_2->data = data_for_swap;

  size_t order_for_swap = current_1->order;
  current_1->order = current_2->order;
  current_2->order = data_for_swap;

  current_1->prev->next = current_2;
  current_2->prev->next = current_1;

  current_1->next->prev = current_2;
  current_2->next->prev = current_1;
 cout << "LOL";

}
// template <typename T>
// inline void List<T>::Sort(){
//
//   ListElem* current = head;
//   ListElem* current_t = tale;
//
//   size_t size2 = size
//
//
//   for(int ix = 1; ix < size;ix++){
//     for(int iy = ix; iy < size;iy++){
//       if (current->order < current->next->order){
//           current
//       }
//     }
//   }
//
// }
template <typename T>
inline void List<T>::InsertBefore(const size_t index,const T &data)
{


    ListElem* current_t = head;

    for (int ix = 1 ; ix < index; ix++)
    {
      current_t = current_t->next;
    }
    if(current_t == head || current_t == tale)
    {
      cout << "\n\t\tCan't Insert\n\t\tBe attentive\n";
    }
    else
    {
      ListElem* to_add = new ListElem;

      to_add->data = data;
      to_add->order=order_counter++;

      size++;

      to_add->prev = current_t->prev;
      to_add->next = current_t;

      current_t->prev = to_add;
      to_add->prev->next = to_add;
    }
}
template <typename T>
inline void List<T>::InsertAfter(const size_t index,const T &data)
{


    ListElem* current_t = head;

    for (int ix = 1 ; ix < index; ix++)
    {
      current_t = current_t->next;
    }
    {
      ListElem* to_add = new ListElem;

      to_add->data = data;
      to_add->order=order_counter++;

      size++;

      to_add->next = current_t->next;
      to_add->prev = current_t;

      current_t->next = to_add;
      to_add->next->prev = to_add;
    }
}
template <typename T>
inline void List<T>::Delete(const size_t elem)  //Возвращает данные из списка.
{

    ListElem* current_t = head;
    // if (elem> size)
    // return ElementNotFound;
    for (int ix = 1 ; ix < elem; ix++)
    {
      current_t = current_t->next;
    }
        if(current_t == head)
        {
          current_t->next->prev = NULL;
          head = current_t->next;
        }
        else if(current_t == tale)
        {
          current_t->prev->next = NULL;
          tale = current_t->prev;
        }
        else
        {
          current_t->prev->next = current_t->next;
          current_t->next->prev = current_t->prev;
        }

        current_t->data = POISON;
      size--;

}

template <typename T>
inline size_t List<T>::SearchElem(const T &elem) const //Возвращает данные из списка.
{
    ListElem* current_h = head;
    ListElem* current_t = tale;

    for (int ix = 0 ; ix < size; ix++){
      if(current_h.data == elem)
        return ix;
      else if(current_t.data == elem)
        return size-ix;
    }
    return ElementNotFound;
}

template <typename T>
inline size_t List<T>::getSize() const //Возвращает данные из списка.
{
  return size;
}
template <typename T>
inline size_t List<T>::getOrder(const size_t element) const //Возвращает данные из списка.
{
  ListElem* current;

  size_t x = element;
  for(current=head;x>0;x--)
    current=current->next;
  return current->order;
}
template <typename T>
inline T List<T>::getFront() const //Возвращает данные из списка.
{
  return head->data;
}
template <typename T>
inline T List<T>::getBack() const //Возвращает данные из списка.
{
  return tale->data;
}
template <typename T>
inline T List<T>::getData(const size_t element) const //Возвращает данные из списка.
{

  ListElem* current;

  size_t x = element;
  for(current=head;x>0;x--)
    current=current->next;
  return current->data;
}
template <typename T>
List<T>::List(){
   ListElem* Empty = new ListElem;

   Empty->next=NULL;
   Empty->prev=NULL;
   Empty->data=POISON;
   Empty->order=0;

   size = 0;

}
template <typename T>
inline void List<T>::PrintList()
{
  // StackOK();

  cout << "#----------------------------------------------------------\n";
  cout << "#    List  " << "\n";
  cout << "#\n";
  cout << "#            ----------date 08/10/2019--------------    \n";
  cout << "#\n";
  //cout << "#    capacity = " <<  getStackSize()  << " \n";
  cout << "#    size = "     <<  getSize()   << " \n";
  // cout << "#    hash_sum = " <<  getStackHash()  << " \n";
  cout << "#\n";
  cout << "#----------------------------------------------------------\n\n";
  cout << "  order\t\tvalue\t    next\tprev\n\n";

  ListElem* current;
  current = head;

  for (current = head; current != NULL;){
    cout << "|" << setw(4) <<"[" << current->order << "]  " << "  =   \t["
    <<  setw(4)<<  current->data << "]   | ";

    if (current->next != NULL)
      cout <<"["<<setw(4)<<  current->next->order<<"] |   ";
    else
      cout << setw(4)<< "[ 999] |   ";

    if (current->prev != NULL)
     cout<< "[" << setw(4)<< current->prev->order<<"] |   ";
    else
      cout << setw(4)<< "[-999] |";

      cout << endl;
  current = current->next;

}


  cout << endl;



  printf("#    ------------------------------------    #\n");
  printf("#    -----------NO_PROBLEM---------------    #\n");
  printf("#    ------------------------------------    #\n\n");

}

template <typename T>
inline int List<T>::PushEnd(const T &data)//Добавление элемента в конец списка. Возвращает количество элементов в списке
{
  ListElem* to_add = new ListElem;

  to_add->next=NULL;
  to_add->prev=tale;
  to_add->data=data;

  to_add->order=order_counter++;

  ListElem *current;


  if(tale==NULL) //Если в списке нет элементов
    tale=to_add;
  else{
    current = tale;
    current->next = to_add;
    tale = to_add;
  }

  if(head==NULL) //Если в списке нет элементов
    head=to_add;

  size++;
  return size;
}

template <typename T>
inline int List<T>::Push(const T &data)//Добавление элемента в конец списка. Возвращает количество элементов в списке
{
  ListElem* to_add = new ListElem;

  to_add->next=head;
  to_add->prev=NULL;
  to_add->data=data;

  to_add->order=order_counter++;

  ListElem *current;


  if(head==NULL) //Если в списке нет элементов
    head=to_add;
  else{
    current = head;
    current->prev = to_add;
    head = to_add;
  }

  if(tale==NULL) //Если в списке нет элементов
    tale=to_add;

  size++;
  return size;
}
