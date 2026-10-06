// strutil.cpp
#include "strutil.h"

namespace pr {

size_t length(const char* s) {
    size_t cpt=0 ;
    while(*s++!='\0'){
    cpt++;
}
    return cpt;

}

char* newcopy(const char* s) {
    size_t len= pr::length(s);
    char *copy=new char[len+1];

    for (size_t i=0;i<len+1;i++){
        copy[i]=s[i];
    }

    return copy;
}

int compare(const char* a, const char* b) {
    while (*a && *b) {
        if (*a != *b)
            return *a - *b;   // négatif si a < b, positif si a > b
        ++a;
        ++b;
    }
    return *a - *b;           // 0 si égales, sinon la plus courte est la plus petite
}
char* newcat(const char* a, const char* b)
{
    size_t la = length(a);
    size_t lb = length(b);
    char* res = new char[la + lb + 1];
    for (size_t i = 0; i < la; i++)
        res[i] = a[i];
    for (size_t i = 0; i <= lb; i++)   // <= lb pour copier le '\0'
        res[la + i] = b[i];
    return res;
}
}
