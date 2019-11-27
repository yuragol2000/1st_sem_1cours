////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//--------------------------------LIB-----------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include "Onegin_sort.cpp"
#include "Unittest.cpp"

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//----------------------------------MAIN--------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

int main(){

  Unittest();

  string input_file  = "onegin.txt";
  string output_file = "onegin1.txt";
  string output_file1 = "onegin2.txt";

  int number_of_strings = 0;

  long Size_of_file = size_of_file(input_file);

  char* Buffer = get_full(Size_of_file,input_file);

  vector<char*> text_for_sort = make_array_of_pointers(Buffer,Size_of_file);
  vector<char*> text_for_sort2 = make_array_of_pointers(Buffer,Size_of_file);
  vector<char*> original_text = make_array_of_pointers(Buffer,Size_of_file);

  sort(text_for_sort.begin(),text_for_sort.end(),from_start_comp);
  sort(text_for_sort2.begin(),text_for_sort2.end(),from_finish_comp);

  print_to_file(text_for_sort,output_file);
  print_to_file(text_for_sort2,output_file1);

  my_free(Buffer);

  return 0;
}
