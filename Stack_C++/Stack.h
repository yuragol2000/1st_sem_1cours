#pragma once


////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//--------------------------------LIB-----------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

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

#define LEN_OF_CANARY 3

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

template <typename T>
class Stack
{
private:
    T *stackPtr;                      // указатель на стек
    int size;                         // максимальное количество элементов в стеке
    int top;                          // номер текущего элемента стека
    int errors[6]={};
    int canary[3]={1,2,3};
    int hash_sum;
public:
    Stack(int = 2);                  // пу
    Stack(const Stack<T> &);          // конструктор копирования
    ~Stack();                         // деструктор

    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline void printStack();         // вывод стека на экран
    inline const T &Peek(int ) const; // n-й элемент от вершины стека
    inline int getStackSize() const;  // получить размер стека
    inline T *getPtr() const;         // получить указатель на стек
    inline int getTop() const;        // получить номер текущего элемента в стеке
    inline void StackHash() ;       // проверяем стек на отсутствие изменений
    inline int getStackHash() const;        // получить номер текущего элемента в стеке
    inline void StackOK() ;       // проверяем стек на отсутствие изменений
    inline void DumpStack(string) const ;
};

//----------------------------------------------------------------------------//
/**
 *   @breaf pushing into stack
 *
 *   @function push
 *
 *   @param [in] (T) element for pushing
 *
 *   @return (void)
 *
 */
//----------------------------------------------------------------------------//
//    push();
//----------------------------------------------------------------------------//
/**
 *   @breaf remove an element from stack
 *
 *   @function pop
 *
 *   @param [void]
 *
 *   @return (T) Last element in stack
 *
 */
//----------------------------------------------------------------------------//
//   pop();
//----------------------------------------------------------------------------//
/**
 *   @breaf print into stdout main information about stack
 *
 *   @function printStack
 *
 *   @param [void]
 *
 *   @return (void)
 *
 */
//----------------------------------------------------------------------------//
//   printStack();
//----------------------------------------------------------------------------//
/**
 *   @breaf give us any element without removing
 *
 *   @function Peek
 *
 *   @param [in] (int) position
 *
 *   @return (T) element
 *
 */
//----------------------------------------------------------------------------//
//   Peek()
//----------------------------------------------------------------------------//
/**
 *   @breaf give CAPACITY
 *
 *   @function getStackSize
 *
 *   @param [void]
 *
 *   @return (long) Size of the file
 *
 */
//----------------------------------------------------------------------------//
//  getStackSize();
//----------------------------------------------------------------------------//
/**
 *   @breaf remove an element from stack
 *
 *   @function size_of_file
 *
 *   @param [in] (string) Name of the file
 *
 *   @return (long) Size of the file
 *
 */
//----------------------------------------------------------------------------//
// функция деструктора Стека


// функция добавления элемента в стек


// функция удаления элемента из стека


// функция возвращает n-й элемент от вершины стека

// вывод стека на экран


// вернуть размер стека

// вернуть указатель на стек (для конструктора копирования)


// вернуть размер стека


// вывод стека в файл
