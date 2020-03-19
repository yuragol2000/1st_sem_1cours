
////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//--------------------------------LIB-----------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<assert.h>
#include <math.h>

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//----------------------------------FUNCTIONS---------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
char **create_buffer_without_empty_lines(char **buffer, long int *nlines);
//----------------------------------------------------------------------------//
/**
* Function removes empty lines from array of strings created by create_arr_of_str2. Creates new buffer without empty lines
* with the same structure as original.
*
* @param [in] buffer - a pointer to array of strings
* @param [out] nlines - a pointer at which the new number of strings(non empty) is stored.
*
*	@note Uses memory allocation!Do not forget to free memory by delete_buffer function.
*
* @return In success returns a pointer to array of strings with no empty lines and NULL in other cases.
*/
//----------------------------------------------------------------------------//
void append_text(const char *filename, char **buffer);
//----------------------------------------------------------------------------//
/**
* Function appends lines from array of strings into file.
*
* @param [in] filename - name of the file
* @param [in] buffer - a pointer to array of strings
*
* @return Nothing
*/
//----------------------------------------------------------------------------//
char **create_arr_of_str2(char *buff, long int buf_size);
//----------------------------------------------------------------------------//
/**
* Function separates buffer of chars created by create_text_buffer into strings. Pointers to strings are stored in
* array that will be returned. Changes '\n' to '\0', the last element in array is set to NULL
* (it may be used as a barier to find out the size of array).
*
* @note 1) Uses memory allocation! Don't forget to free memory by delete_buffer function.
* @note 2) Changes buffer: '\n' are replaced with '\0'.
*
* @param [in] buffer - a pointer to buffer of chars
* @param [in] buf_size - size of the buffer
*
* @return Returns pointer to created array of strings on success. In other cases returns NULL.
*/
//----------------------------------------------------------------------------//
void delete_buffer(void *buffer);
//----------------------------------------------------------------------------//
/**
* Function frees allocated buffer
*
* @param [in] buffer - a pointer to buffer
*
* @return Nothing
*/
//----------------------------------------------------------------------------//
long int count_lines_in_buf(char *buffer, long int buf_size);
//----------------------------------------------------------------------------//
/**
* Function counts number of '\n' in buffer (equal to number of lines).
*
* @param [in] buffer - a pointer to buffer of char
* @param [in] buf_size - size of the buffer
*
* @return The number of '\n' in buffer
*/
//----------------------------------------------------------------------------//
char *create_text_buffer(const char *filename, long int *nsym);
//----------------------------------------------------------------------------//
/**
* Function reads data from the file filename, and store it into buffer. Buffer is one larger than the number of symbols in
* file and the last element in buffer is set to '\n'.
*
* @param [in] filename - name of the file
* @param [out] nsym - a pointer at which the number of read symbols is stored
*
* @note Uses memory allocation! Don't forget to free memory by delete_buffer function.
*
* @return In success return a ponter to created buffer. In other cases returns NULL.
*/
