// strutil.cpp
#include "strutil.h"

namespace pr {

size_t length(const char* s) {
    size_t cpt=0 ;
    const char *p=s;j
    while(*(++p)!='\0')
    cpt++;
    return cpt;
}

char* newcopy(const char* s) {
    size_t len= pr::length(s);
    char *copy=new char[length(s)+1];

    for (int i=0;i<len+1;i++){
        copy[i]=s[i];
    }

    return *copy;
}

int compare(const char* a, const char* b){
    while(*a && *b){
        if(*a != *b)
          return 0;
        ++a;
        ++b;
    }


    return *a==*b;
}

}
