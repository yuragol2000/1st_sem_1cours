#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

long size_of_file(const string& get_file){

    ifstream Input_file;

    Input_file.open(get_file);

    if (!Input_file){

      cerr << "Error opening file\n";
      exit(1);
    }

    Input_file.seekg(0,ios_base::end);

    long lSize = Input_file.tellg();

    Input_file.close();

return lSize;
}

char* get_full(const long& lSize,const string& get_file,int& number_of_strings){

    char* buffer = new char[lSize+1];

    ifstream Input_file;

    Input_file.open(get_file);

    if (!Input_file){

      cerr << "Error opening get_file\n";
      exit(1);
    }

    if(!Input_file.read(buffer,lSize)){

      cerr << "Error reading get_file\n";
      exit(1);
    }

    buffer[lSize+1] = '\0';

    for (int i = 0; i <= lSize; i++ ){

        if (buffer[i] == '\n'){

            buffer[i] = '\0';

            number_of_strings++;
        }
    }

    Input_file.close();

return buffer;
}
vector<char*> make_array_of_pointers (char* buffer,const long& lSize,const int& number_of_strings){

    assert(buffer);

    vector<char*> str2;

    str2.push_back(&(buffer[0]));

    for (int i = 1; i < lSize - 1; ++i){

        if(buffer[i-1] == '\0'){

          str2.push_back(&buffer[i]);
        }
    }

return static_cast<vector<char*>>(str2);
}
void print_to_file(vector<char*> buffer,const string& put_file,int& number_of_strings){

    assert(&buffer != NULL  );

    ofstream Output_file;

    Output_file.open(put_file);

    if (!Output_file){

      cerr << "Error opening Put_file\n";
      exit(1);
    }

    for (auto it : buffer){

      Output_file  << it << "\r\n";
    }

    Output_file << "\r\n\r\n";

    Output_file.close();
}

bool from_start_comp(const char*  lhs, const char* rhs){

   for(int i = 0,j = 0; i < strlen(rhs),j < strlen(lhs);i++,j++){

      start1:

      char l = lhs[i];
      char r = rhs[j];


     if (isalpha(l) == 0 && isalpha(r) == 0){

        continue;
     }
     if (isalpha(l) && isalpha(r)){

       if(tolower(l) > tolower(r)){

         return 0;
       }
       else if(tolower(l) < tolower(r)){

         return 1;
       }
     }
     if (isalpha(l) == 0){

       for(;i < strlen(rhs);i++){

         char l1 = lhs[i];

         if(isalpha(l1) == 0)continue;

         else if(tolower(l1) == tolower(r)) {i++;j++;goto start1;}
         else if(tolower(l1) < tolower(r) ) return 1;
         else if(tolower(l1) > tolower(r) ) return 0;
       }
     }
     else if(isalpha(r) == 0){

       for(;j < strlen(lhs);j++){

         char l1 = rhs[j];

         if(isalpha(l1) == 0)continue;

         else if(tolower(l1) == tolower(l)) {i++;j++;goto start1;}
         else if(tolower(l1) < tolower(l) ) return 0;
         else if(tolower(l1) > tolower(l) ) return 1;
       }
     }


   }
}
bool from_finish_comp(const char*  lhs, const char* rhs){

   for(int j = strlen(rhs)-1,i = strlen(lhs)-1; i >= 0,j >= 0;--i,--j){

      start1:

      char l = lhs[i];
      char r = rhs[j];


     if (isalpha(l) == 0 && isalpha(r) == 0){

        continue;
     }
     if (isalpha(l) && isalpha(r)){

       if(tolower(l) > tolower(r)){

         return 0;

       }
       else if(tolower(l) < tolower(r)){

         return 1;
       }
     }


     if (isalpha(l) == 0){

       for(;i > 0;i--){

         char l1 = lhs[i];

         if(isalpha(l1) == 0)continue;

         else if(tolower(l1) == tolower(r)) {i--;j--;goto start1;}
         else if(tolower(l1) < tolower(r) ) return 1;
         else if(tolower(l1) > tolower(r) ) return 0;
       }
     }
     else if(isalpha(r) == 0){

       for(;j > 0;j--){

         char r1 = rhs[j];

         if(isalpha(r1) == 0)continue;

         else if(tolower(l) == tolower(r1)) {i--;j--;goto start1;}
         else if(tolower(l) < tolower(r1) ) return 1;
         else if(tolower(l) > tolower(r1) ) return 0;
       }
     }
   }
}
int main(){

  string input_file  = "onegin.txt";
  string output_file = "onegin1.txt";
  string output_file1 = "onegin2.txt";

  int number_of_strings = 0;

  long Size_of_file = size_of_file(input_file);

  char* Buffer = get_full(Size_of_file,input_file,number_of_strings);

  vector<char*> text_for_sort = make_array_of_pointers(Buffer,Size_of_file,number_of_strings);
  vector<char*> text_for_sort2 = make_array_of_pointers(Buffer,Size_of_file,number_of_strings);
  vector<char*> original_text = make_array_of_pointers(Buffer,Size_of_file,number_of_strings);

  sort(text_for_sort.begin(),text_for_sort.end(),from_start_comp);
  sort(text_for_sort2.begin(),text_for_sort2.end(),from_finish_comp);

  print_to_file(text_for_sort,output_file,number_of_strings);
  print_to_file(text_for_sort2,output_file1,number_of_strings);


  return 0;
}
