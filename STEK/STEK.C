//
//#define MAX 100

const int MAX = 100;


struct stack {

  float elem[MAX];
  int top;

};
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf zeroing the top element
 *
 *   @function init
 *
 *
 *   @param [in] (struct)
 *
 */
//----------------------------------------------------------------------------------------------//
void init(struct stack *stk) {


    stk->top = 0;

}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf finding text size
 *
 *   @function push
 *
 *
 *   @param [in ] (struct)
 *
 */
//----------------------------------------------------------------------------------------------//
void push(struct stack *stk, float f) {

  if(stk->top < MAX){

    stk->elem[stk->top] = f;
    stk->top++;

  }
  else{

    printf("Стек полон, количество элементов: %d !\n", stk->top);
  }
}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf remove item from stack
 *
 *   @function pop
 *
 *
 *   @param [in ] (struct)
 *   @param [out] (float ) elem
 *
 */
//----------------------------------------------------------------------------------------------//
float pop(struct stack *stk) {

  float elem;

  if((stk->top) > 0){

    stk->top--;

    elem = stk->elem[stk->top];

    return(elem);
  }
  else{

    printf("Стек пуст!\n");

    return(0);
  }

}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf top element definition
 *
 *   @function stkTop
 *
 *
 *   @param [in ] (struct)
 *   @param [out] (long  ) top element definition
 */
//----------------------------------------------------------------------------------------------//
float stkTop(struct stack *stk) {

  if((stk->top) > 0) {

    return( stk->elem[stk->top-1]);
  }
  else {

    printf("Стек пуст!\n");

    return(0);
  }
}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf finding text size
 *
 *   @function gettop
 *
 *
 *   @param [in ] (struct)
 *   @param [out] (long) Number of items in the stack
 *
 */
//----------------------------------------------------------------------------------------------//
int gettop(struct stack *stk) {

 return(stk->top);

 }
 //----------------------------------------------------------------------------------------------//
/**
 *   @breaf check for emptiness
 *
 *   @function isempty
 *
 *
 *   @param [out] (int) 1 if empty 0 if not
 *
 */
//----------------------------------------------------------------------------------------------//
 int isempty(struct stack *stk) {

  if((stk->top) == 0)

    return(1);

  else

    return(0);
}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf finding text size
 *
 *   @function STK_PRINT
 *
 *   @param [in ] (struct)
 *   @param [out] (long) Size of the text
 *
 */
//----------------------------------------------------------------------------------------------//
void STK_PRINT(struct stack *stk) {

  int i = stk->top;
  if( isempty(stk) == 1)
  return;
  do {

    i--;
    printf("%f\n", stk->elem[i]);

  }
  while(i > 0);
}
void Double_stack()

void init(struct stack *stk);                 //инициализация
void push(struct stack *stk, float f);       //помещение элемента в стек
float pop(struct stack *stk);                 //удаление элемента из стека
float stkTop(struct stack *stk);              //определение верхнего элемента без его удаления
int gettop(struct stack *stk);                //получение вершины стека (количества элементов)
int isempty(struct stack *stk);               //печать стека
void STK_PRINT(struct stack *stk);             //определение пустоты стека
