////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//-----------------------------File_functions---------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

#include "file_functions.h"

////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------//
//----------------------------------FUNCTIONS---------------------------------//
//----------------------------------------------------------------------------//
////////////////////////////////////////////////////////////////////////////////

char **create_buffer_without_empty_lines(char **buffer, long int *nlines){

	long int index = 0;
	*nlines = 0;
	//counting non-empty lines
	for(index = 0; buffer[index]; index++){
		if(buffer[index][0])
			(*nlines)++;
	}

	char **new_buf = calloc(*nlines + 1, sizeof(char*));
	new_buf[*nlines] = NULL; //as a barier element;

	if(!new_buf){
		printf("remove_empty_lines: can't allocate memory\n");
		return NULL;
	}

	long int new_index;
	for(index = 0, new_index = 0; buffer[index]; index++){
		if(buffer[index][0])
			new_buf[new_index++] = buffer[index];
	}

	return new_buf;
}


void append_text(const char *filename, char **buffer){
	assert(filename != NULL);
	assert(buffer != NULL);

	FILE *file = fopen(filename, "a");

	long int index;

	for(index = 0; buffer[index]; index++){
		fwrite(buffer[index], sizeof(char), strlen(buffer[index]), file);
		fwrite("\n", sizeof(char), 1, file);
//		fprintf(file, "%s\n", buffer[index]);
	}
	fclose(file);
}


char **create_arr_of_str2(char *buff, long int buf_size){
	assert(buff != NULL);
	assert(buf_size >= 0);

	long int nlines = count_lines_in_buf(buff, buf_size);

	//one more byte for NULL element as a barier
	char **arr_of_str = calloc(nlines + 1, sizeof(char*));
	if(!arr_of_str){
		printf("create_arr_of_str: can't allocate memory\n");
		return NULL;
	}
	arr_of_str[nlines] = NULL; //end in NULL (instead of size)

	long int index = 0;
	arr_of_str[index++] = buff;

	for(char *sym = memchr(buff, '\n', buf_size); sym; sym = memchr(sym + 1, '\n', buf_size - (sym - buff + 1))){
		*sym = '\0';
		if(nlines != index){ //if not last '\n'
			arr_of_str[index] = sym + 1;
			index++;
		}
	}

	if(nlines != index){
		printf("create_arr_of_str1: nlines != index \n");
		return NULL;
	}
	return arr_of_str;
}



void delete_buffer(void *buffer){
	assert(buffer != NULL);
	free(buffer);
}



long int count_lines_in_buf(char *buffer, long int buf_size){
	assert(buffer != NULL);
	assert(buf_size >= 0);

	char *sym;
	long int count = 0;

	for(sym = memchr(buffer, '\n', buf_size); sym; sym = memchr(sym + 1, '\n', buf_size - (sym - buffer + 1))){
		count++;
	}
	return count;
}


char *create_text_buffer(const char *filename, long int *nsym){

	assert(filename != NULL);
	assert(nsym != NULL);

	FILE *file = fopen(filename, "r");

	if(!file){
//		printf("Can't open file!\n");
		return NULL;
	}

	if (fseek(file, 0, SEEK_END)){
		printf("Can't fseek file!\n");
		fclose(file);
		return NULL;
	}

	*nsym = ftell(file); //number of sym in file
	fseek(file, 0, SEEK_SET);

	char *buffer = calloc(*nsym + 1, sizeof(char));
	if (!buffer){
		printf("can't allocate buffer\n");
		fclose(file);
		return NULL;
	}
	buffer[*nsym] = '\n';

	long int buff_size = fread((void*)buffer, sizeof(char),*nsym, file);

	if(buff_size != *nsym){
		printf("buff_size != *nsym; buff_size = %ld,"
				"*nsym = %ld\n", buff_size, *nsym);
		free(buffer);
		fclose(file);
		return NULL;
	}

	fclose(file);
	return buffer;
}
