////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//----------------------------------MAIN--------------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

int main(){

  Unittest();

  std::string input_file  = "onegin.txt";
  std::string output_file = "onegin1.txt";
  std::string output_file1 = "onegin2.txt";

  int number_of_strings = 0;

  long Size_of_file = size_of_file(input_file);

  char* Buffer = get_full(Size_of_file,input_file);

  std::vector<char*> text_for_sort  = {},
                     text_for_sort2 = {},
                     original_text  = {};

  text_for_sort = make_array_of_pointers(Buffer,Size_of_file);
  text_for_sort2= text_for_sort;
  original_text = text_for_sort;
  
  print_to_file(text_for_sort,output_file);
  print_to_file(text_for_sort2,output_file1);

  my_free(Buffer);

  return 0;
}
