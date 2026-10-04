#include "List.h"
namespace pr {

// ******************* Chainon
Chainon::Chainon (const std::string & data, Chainon * next):data(data),next(next) {};

size_t Chainon::length() {
	size_t len = 1;
	if (next != nullptr) {
		len += next->length();
	}
	return len; //FAUTE: recursion infinie
}

void Chainon::print(std::ostream & os) const { //FAUTE: il manque le const
	os << data ; 
	if (next != nullptr) {
		os << ", ";
		next->print(os);
	}
	//next->print(os);// FAUTE  il doit etre à l'interieur du if , sinnd on il s'executera toujours
}

// ******************  List
const std::string & List::operator[] (size_t index) const  {
	Chainon * it = tete;
	for (size_t i=0; i < index ; i++) {
		it = it->next;
	}
	return it->data;
}

void List::push_back (const std::string& val) {
	if (tete == nullptr) {
		tete = new Chainon(val);
	} else {
		Chainon * fin = tete;
		while (fin->next) {
			fin = fin->next;
		}
		fin->next = new Chainon(val);
	}}

void List::push_front(const std::string& val) {
	tete = new Chainon(val,tete);
}

bool List::empty() {   //FAute: le compilateur considere empty comme une funct independante , donc il reconnait pas l'attribut tete

	return tete == nullptr;  
}

size_t List::size() const {
	if (tete == nullptr) {
		return 0;
	} else {
		return tete->length();
	}
}



std::ostream & operator<< (std::ostream & os, const pr::List & vec)  // FAUTE : definition à l'exterireur du namespace
{
	os << "[";
	if (vec.tete != nullptr) {
		vec.tete->print (os) ;
	}
	os << "]";
	return os;
}


} // namespace pr
