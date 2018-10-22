//////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------//
//----------------------------------------------LIB---------------------------------------------//
//----------------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

//////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------//
//-------------------------------------------FUNCTIONS------------------------------------------//
//----------------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////


    void    sort0(char**);
    void    print0(char**, char**);
    long    size0(void);
    char*   get0(long);
    void    free0(char**, char**, char*);
    char**  put0(char*, long);
    int     reverse_comparator(const void*, const void*);
    int     comparator(const void*, const void*);
    char*   Remote_to_last_letter(char*, int);
    int     Remote_to_the_end(char**, int);

//////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------//
//----------------------------------------GLOBAL VARIABLE---------------------------------------//
//----------------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////

    char get_file[] = {"ONEGIN.txt" };
    char put_file[] = {"ONEGIN2.txt"};

    int number_of_strings = 1;

//////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------------------//
//--------------------------------------------MAIN----------------------------------------------//
//----------------------------------------------------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    long size_of_file = size0();

    char*  buffer          = get0(size_of_file       );
    char** array_for_sort  = put0(buffer,size_of_file);
    char** original_text   = put0(buffer,size_of_file);

    sort0(array_for_sort);

    print0(array_for_sort,original_text);

    free0(array_for_sort,original_text,buffer);

return 0;
}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf finding text size
 *
 *   @function size0
 *
 *
 *   @param [out] (long) Size of the text
 *
 */
//----------------------------------------------------------------------------------------------//
long size0(void){

    FILE * File2 = fopen( get_file , "rb" );

    if (File2 == NULL)
    {
      fputs("Ошибка файла", stderr);
      exit(1);
    }

    fseek(File2 , 0 , SEEK_END);                          // устанавливаем позицию в конец файла
    long lSize = ftell(File2);                            // получаем размер в байтах
    rewind (File2);                                       // устанавливаем указатель в конец файла;

return lSize;
}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf Reading TEXT from FILE [namefile0]
 *
 *   @function get0
 *
 *
 *   @param [in ] (long ) lSize Size of the text
 *   @param [out] (char*) buffer Whole original TEXT
 *
 */
//----------------------------------------------------------------------------------------------//
char * get0(long lSize){

    char * buffer = (char*) malloc(sizeof(char) * (lSize+1)); // выделить память для хранения содержимого файла

    FILE * in = fopen(get_file,"rb");

    assert(in);

        if (buffer == NULL)

        {
            printf("Error: %s\n", strerror(errno));
            fputs("Ошибка памяти", stderr);
            exit(2);
        }

    size_t result = fread(buffer, 1, lSize, in);// считываем файл в буфер

    buffer[lSize+1] = '\0';

    if (result != lSize)
    {

      fputs("Ошибка чтения", stderr);
      exit (3);

    }

    for (int i = 0; i <= lSize; i++ )// проставляем \n вместо \0
    {
        if (buffer[i] == '\n'){

            buffer[i] ='\0';

            number_of_strings++;

        }
    }

return buffer;
}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf fills the array
 *
 *   @function put0
 *
 *
 *
 *   @param [in ] (char* ) buffer Whole original TEXT
 *   @param [in ] (long  ) lSize  Size of the text
 *   @param [out] (char**) str2   pointer array
 */
//----------------------------------------------------------------------------------------------//
char ** put0(char* buffer,long lSize){

    assert(buffer);
    assert(lSize );

    char ** str2 = (char**) malloc(sizeof(char*) * (number_of_strings+1));//выделение памяти под массив указателей

    str2[0] = &(buffer[0]);

    int m = 1;

    for (int i = 1; i < lSize; ++i )
    {
        if (buffer[i-1] == '\0'){

            str2[m] = &buffer[i];
            m++;

        }
    }

return str2;
}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf sorts array
 *
 *   @function sort0
 *
 *   @param [in ] (char**) str2 pointer array
 */
//----------------------------------------------------------------------------------------------//


int comparator(const void* a, const void* b)
{
    char* str1 = *(char**) a;
    char* str2 = *(char**) b;

    while (isspace(*str1)||ispunct(*str1))
        str1++;

    while (isspace(*str2)||ispunct(*str2))
        str2++;

    return strcmp(str1, str2);
}

char* Remote_to_last_letter(char *str, int counter)
{
    while ((!isalpha(*str)||(*str == '\0'))
          &&(counter)-- >= 0)
        (str)--;
    return str;
}

int Remote_to_the_end(char **str, int counter)
{
    counter = *(str + 1) - *(str);

        return counter;
}

int reverse_comparator(const void* a, const void* b)
{
    char* str1 = *(char**) a;
    char* str2 = *(char**) b;

    int counter1 = 0;
    int counter2 = 0;

    counter1 = Remote_to_the_end(&str1, counter1);
    counter2 = Remote_to_the_end(&str2, counter2);

    str1 = Remote_to_last_letter(str1, counter1);
    str2 = Remote_to_last_letter(str2, counter2);

    while (1)
    {
        if (*str1 == '\0' && *str2 != '\0')
            return  1;
        if (*str2 == '\0' && *str1 != '\0')
            return -1;

        if (*str1 > *str2)
            return  1;
        if (*str1 < *str2)
            return -1;
        str1--;
        str2--;
    }
}
void sort0(char **str2){

    assert(str2);

    for (int i = 0; i < number_of_strings;++i){
    for (int j = 0; j < number_of_strings - i-1; ++j){

        for (int s1 = strlen(str2[j])-1, s2 = strlen(str2[j+1])-1; str2[j ][s1] != '\0' || str2[j+1][s2] != '\0';--s1, --s2){

            char a1 =  str2[j  ][s1];
            char a2 =  str2[j+1][s2];

            if (isalpha(a1) == 0 && isalpha(a2) == 0)
                continue;
                start1:
                if (isalpha(a1) == 0){
                --s1;
                a1 =  str2[j  ][s1];
                goto start1;
                }

                if (isalpha(a2) == 0 ){
                --s2;
                a2 =  str2[j+1  ][s2];
                goto start1;
                }

            if ('a' <= a1  && a1 <= 'number_of_strings'){//приводим все буквы к одному регистру

                a1 += 'A' - 'a';

            }

            if ('a' <= a2 && a2 <= 'number_of_strings'){

                a2 += 'A' - 'a';

            }

            if ((int)a1 > (int)a2){

                char ** b  = str2[j];

                str2[j] = str2[j+1];
                str2[j+1] = b;

                break;
            }

            else
			if ((int)a1 < (int)a2)
                break;
        }
    }
    }

}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf write text to file
 *
 *   @function print0
 *
 *
 *   @param [in] (char **) str2  pointer array
 *   @param [in] (char **) str3  pointer array
 *
 */
//----------------------------------------------------------------------------------------------//
void print0(char ** str2,char ** str3){

    assert(str2  );
    assert(str3  );

    FILE * out = fopen(put_file,"w");

    assert(out);

    for (int j = 0;j < number_of_strings ;++j)
        fprintf(out,"%s\r\n",(str2[j]));

    fprintf(out,"\r\n\r\n");

    for (int j = 0;j < number_of_strings;++j)
        fprintf(out,"%s\r\n",str3[j]);



    fclose (out);// завершение работы


}
//----------------------------------------------------------------------------------------------//
/**
 *   @breaf free arrays
 *
 *   @function free0
 *
 *   @param [in] (char **) str2    pointer array
 *   @param [in] (char **) str3    pointer array
 *   @param [in] (char **) buffer  Whole original text
 *
 */
//----------------------------------------------------------------------------------------------//
void free0(char ** str2,char **str3, char* buffer){

    assert(str2  );
    assert(str3  );
    assert(buffer);

    free(buffer);
    free(str3  );
    free(str2  );

}
//----------------------------------------------------------------------------------------------//
