
////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//--------------------------------LIB-----------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
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

//----------------------------------------------------------------------------//
/**
 *   @breaf finding file size
 *
 *   @function size_of_file
 *
 *   @param [in] (string) Name of the file
 *
 *   @return (long) Size of the file
 *
 */
//----------------------------------------------------------------------------//
    long    size_of_file(const string& get_file);
//----------------------------------------------------------------------------//
/**
 *   @breaf Reading TEXT from FILE [namefile0]
 *
 *   @function get0
 *
 *   @param [in ] (long ) lSize Size of the text
 *   @param [in ] (string ) get_file Name of the file
 *   @param [in ] (int ) number_of_strings number of strings
 *
 *   @return (char*) buffer Whole original TEXT
 */
//----------------------------------------------------------------------------//
    char*   get_full(const long& lSize,const string& get_file);
//----------------------------------------------------------------------------//
/**
 *   @breaf fills the array
 *
 *   @function make_array_of_pointers
 *
 *
 *
 *   @param [in] (char* ) buffer Whole original TEXT
 *   @param [in] (long  ) lSize  Size of the text
 *   @param [in] (int  ) number_of_strings number of strings
 *
 *   @return (vector<char*>) str2 pointer vector
 */
//----------------------------------------------------------------------------//
    vector<char*> make_array_of_pointers (char* buffer,const long& lSize);
//----------------------------------------------------------------------------//
/**
 *   @breaf write text to file
 *
 *   @function print_to_file
 *
 *
 *   @param [in] (char **) str2  pointer array
 *   @param [in] (int   ) number_of_strings Number of strings
 *   @param [in] (long  ) lSize Size of the text
 *
 *
 */
//----------------------------------------------------------------------------//
    void    print_to_file(vector<char*> buffer,const string& put_file);
//----------------------------------------------------------------------------//
/**
 *   @breaf free arrays
 *
 *   @function my_free
 *
 *   @param [in] (vector<char*>) buffer Whole original text
 *
 */
//----------------------------------------------------------------------------//
    void    my_free(char* buffer);
//----------------------------------------------------------------------------//
/**
 *   @breaf comparator for sorting text from start to end
 *
 *   @function from_start_comp
 *
 */
//----------------------------------------------------------------------------//
    bool from_start_comp(const char*  lhs, const char* rhs);
//----------------------------------------------------------------------------//
/**
 *   @breaf comparator for sorting text from end to start
 *
 *   @function from_start_comp
 *
 */
//----------------------------------------------------------------------------//
    bool from_finish_comp(const char*  lhs, const char* rhs);
