#include "List.h"
#include <string>
#include <iostream>
#include <cstring>

int main () {

	std::string abc = "abc";
	char * str = new char [4];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';  
	str[3] ='\0';    // FAUTE: le new char[3] non initialisé ne met pas de \0 a la fin,il contient ce qu'on initialise et des restes de mémoires ailleurs
	



	int i = 0;

	if (! strcmp (str, abc.c_str())) {
		std::cout << "Equal !" << std::endl;
	}

	pr::List list;
	list.push_front(abc);
	list.push_front(abc);

	std::cout << "Liste : " << list << std::endl;
	std::cout << "Taille : " << list.size() << std::endl;

	// Affiche à l'envers
	for (i= int(list.size()) - 1 ; i >= 0 ; i--) {    //FAUTE: list.size() est de type size_t , donc la condition sera toujours verifiée -> boucle infinie
		std::cout << "elt " << i << ": " << list[i] << std::endl;
	}

	// liberer les char de la chaine
	//for (char *cp = str ; *cp ; cp++) {
	//	delete [] cp; //FAUTE: on ne peut delete que ce qui a ete crée avec new

	//}
	// et la chaine elle meme
	delete [] str; //faute: delete[] au lieu de delete , ça declanche un comportement indéfini

}
