#include <iostream>
const int MAX=100;
int main(){

    std::cout << "Hello World!" << std::endl;
    int tab[MAX];

    for (int i=9;i>=0;i--){

        if(tab[i] - tab[i-1]!= 1){
            std::cout c<< "probleme !" ;
        }
    }

    return 0;
}