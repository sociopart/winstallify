#ifndef CLI_H
#define CLI_H
#include <stdinc.h>
//typedef struct _cli_menu_page{
//	const char* page_name;
//	int (*func_name) (int, char**);
//} cli_menu_page;

///////////////////////////////////////////////////////////////////////////////////////////
static
int
cli_parse_ext(int argc, char** argv, void* cli_argtable[][2], bool handle_qsymbol) {
    int endindex = 0;
    int i = 0;
    while (cli_argtable[endindex][0] != NULL){
        endindex++;
    }

    void* argtable[endindex];
    for (i = 0; i < endindex; i++){
        argtable[i] = cli_argtable[i][0];
    }

	if (arg_nullcheck(argtable) != 0) {
		printf("error: insufficient memory\n");
		return -1;
	}

	if (handle_qsymbol == true){
        for (i = 0; i < argc; i++) {
            if (strcmp(argv[i], "-?") == 0) {
                strreplace(argv[i], "-?", "--help");
            }
        }
	}

	//if (nerrors > 0) return;
	int nerrors = arg_parse(argc, argv, argtable);
	endindex--;

	for (i = 0; i < endindex; i++){
        struct arg_hdr* current_hdr = (struct arg_hdr*)(argtable[i]);
        // arg_litn is present
        if (current_hdr->datatype == NULL){
            struct arg_lit* data = (struct arg_lit*)(argtable[i]);
            bool* result_value = cli_argtable[i][1];
            *result_value = data->count;
            //printf("i = %d | Type: BOOL | Value: %d\n", i, data->count);
        }
        // arg_intn is present
        else if (strcmp(current_hdr->datatype, "<int>") == 0){
            struct arg_int* data = (struct arg_int*)(argtable[i]);
            int* result_value = cli_argtable[i][1];
            *result_value = data->ival[0];
            //printf("i = %d | Type: INT  | Value: %d\n", i, data->ival[0]);
        }
        // arg_strn is present
        else if (strcmp(current_hdr->datatype, "<char>") == 0){
            struct arg_str* data = (struct arg_str*)(argtable[i]);
            char** result_value = cli_argtable[i][1];
            *result_value = data->sval[0];
            //printf("i = %d | Type: CHAR | Value: %s\n", i, data->sval[0]);
        }
	}

	return 0;
}


#endif // CLI_H

