#ifndef UTILS_H
#define UTILS_H
#pragma warning(disable : 4996)

static void strreplace(char* string, const char* find, const char* replaceWith);
static inline void strreplace(char* string, const char* find, const char* replaceWith) {
    if (strstr(string, replaceWith) != NULL) {
        char* temporaryString = malloc(strlen(strstr(string, find) + strlen(find)) + 1);
        strcpy(temporaryString, strstr(string, find) + strlen(find));    //Create a string with what's after the replaced part
        *strstr(string, find) = '\0';    //Take away the part to replace and the part after it in the initial string
        strcat(string, replaceWith);    //Concat the first part of the string with the part to replace with
        strcat(string, temporaryString);    //Concat the first part of the string with the part after the replaced part
        free(temporaryString);    //Free the memory to avoid memory leaks
    }
}
#endif
