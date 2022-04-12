//
//  unordered_set_2.h
//  unordered_multiset
//
//  Jean Goulet
//  Copyleft 2017
//

#ifndef unordered_multiset_2_h
#define unordered_multiset_2_h

/////////////////////////////////////////////////////////////////////
// rehash

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::rehash(size_t nbalv){
}


///////////////////////////////////////////
// avancer et reculer un iterateur

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE,classe_de_dispersion>::iterator::avancer(){
    //plante si on essaie d'avancer apres la fin
}

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE,classe_de_dispersion>::iterator::reculer(){
    //plante si on essaie de reculer avant le debut
}

/////////////////////////////////////////////////////////////////////
// fonctions generatrices

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE,classe_de_dispersion>::insert(const TYPE& VAL){
    iterator retour;
    return retour;
}

template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE,classe_de_dispersion>::erase(const TYPE& VAL){
    typename list<TYPE>::iterator p;
    size_t retour=0;
    return retour;
}

template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE,classe_de_dispersion>::erase
(typename unordered_multiset<TYPE,classe_de_dispersion>::iterator i){
    iterator retour;
    return retour;
}

/////////////////////////////////////////////////////////////////////
// count
template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE,classe_de_dispersion>::count(const TYPE& VAL)const{
    size_t retour=0;
    return retour;
}

/////////////////////////////////////////////////////////////////////
// find
template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator unordered_multiset<TYPE,classe_de_dispersion>::find(const TYPE& VAL){
    iterator retour;
    return retour;
}




#endif /* unordered_multiset_2_h */
