////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//---------------------------------Onegin_sort--------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include "Onegin_sort.h"

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//----------------------------------FUNCTIONS---------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

long size_of_file(const std::string& get_file){

    std::ifstream Input_file;

    Input_file.open(get_file);

    if (!Input_file){

      std::cerr << "Error opening file\n";
      exit(1);
    }

    Input_file.seekg(0,std::ios_base::end);

    long lSize = Input_file.tellg();

    Input_file.close();

    return lSize;
}

char* get_full(const long& lSize,const std::string& get_file){

    char* buffer = new char[lSize+1] {};

    std::ifstream Input_file;

    Input_file.open(get_file);

    if (!Input_file){

      std::cerr << "Error opening get_file\n";
      exit(1);
    }

    if(!Input_file.read(buffer,lSize)){

      std::cerr << "Error reading get_file\n";
      exit(1);
    }

    buffer[lSize+1] = '\0';

    for (int i = 0; i <= lSize; i++ ){

        if (buffer[i] == '\n'){

            buffer[i] = '\0';

        }
    }

    Input_file.close();

    return buffer;
}

std::vector<char*> make_array_of_pointers (char* buffer,const long& lSize){

    assert(buffer);

    std::vector<char*> str2;

    str2.push_back(&(buffer[0]));

    for (int i = 1; i < lSize - 1; ++i){

      if(buffer[i-1] == '\0'){

        str2.push_back(&buffer[i]);
      }
    }

    return static_cast<std::vector<char*>>(str2);
}
void print_to_file(std::vector<char*> buffer,const std::string& put_file){

    assert(&buffer != NULL  );

    std::ofstream Output_file;

    Output_file.open(put_file);

    if (!Output_file){

      std::cerr << "Error opening Put_file\n";
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
void my_free(char* buffer){

  assert(buffer);

  free(buffer);
}
