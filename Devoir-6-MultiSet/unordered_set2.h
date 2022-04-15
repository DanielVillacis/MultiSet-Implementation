//
//  unordered_set_2.h
//  unordered_multiset
//
//  Jean Goulet
//  Copyleft 2017
//
//  Modifié par :   Carlos Reyes Marquez (reyc)
//                  Daniel Villacis (vild2705)

#ifndef unordered_multiset_2_h
#define unordered_multiset_2_h

/////////////////////////////////////////////////////////////////////
// rehash
template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::rehash(size_t nbalv){
    // A FAIRE
    unordered_multiset<TYPE> copieUM;
    copieUM.REP.resize(nbalv);
    copieUM.REP.back() = copieUM.REP[1];
    
    for(size_t i = 0; i < copieUM.REP.size() - 1; ++i){
        copieUM.REP[i] = nullptr;
    }
    for(size_t i = 0; i < copieUM.size(); i++) {
        for(auto& j : *this) {
            copieUM.insert(j);
        }
    }
    swap(copieUM);
}


///////////////////////////////////////////
// avancer et reculer un iterateur
template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE,classe_de_dispersion>::iterator::avancer(){
    // GOOD
    //plante si on essaie d'avancer apres la fin
    if (++POS != (*ALV)->end());
    else {
        do {
            ALV++;
        }
        while (*ALV == nullptr);
        POS = (*ALV)->begin();
    }
}

template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE,classe_de_dispersion>::iterator::reculer(){
    // GOOD
    //plante si on essaie de reculer avant le debut
    if (POS != (*ALV)->begin()) {
        POS--;
    }
    else {
        do {
            ALV--;
        }
        while ((*ALV) == nullptr);
        POS = --(*ALV)->end();
    }
}

/////////////////////////////////////////////////////////////////////
// fonctions generatrices
template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE,classe_de_dispersion>::insert(const TYPE& VAL){
    // A VERIFIER
    
    size_t size = REP.size() - 1;
    size_t alv = disperseur(VAL) % size;
    
    // if alveolus is empty, create new list with VAL
    if (REP[alv] == nullptr) {
        REP[alv] = new list<TYPE>();
        REP[alv]->push_back(VAL);
    }
    
    // increment SIZE
    SIZE++;
    
    // if (average alveolus size > max size), call rehash
    double avg = (double)SIZE / (double)size;
    if (avg > facteur_max) {
        size_t newSize = (size *2) +1;
        rehash(newSize);
    }
    return typename unordered_multiset<TYPE, classe_de_dispersion>::iterator(REP.begin() + alv, REP[alv]->end());
}


template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE,classe_de_dispersion>::erase(const TYPE& VAL){
    // A VERIFIER
    size_t retour=0;
    size_t size = REP.size() - 1;
    size_t alv = disperseur(VAL) % size;
    
    if (REP[alv] == nullptr) {
        return 0;
    }
    
    list<TYPE> *newList = new list<TYPE>();
    
    for (auto v : *REP[alv]) {
        if (v == VAL) retour++;
        else newList->push_back(v);
    }
    delete REP[alv];
    
    if (newList->size() > 0) {
            REP[alv] = newList;
    }
    else {
        REP[alv] = nullptr;
    }
    SIZE -= retour;

    double avg = (double)SIZE / (double)size;
    if (facteur_min > avg) {
        size_t newSize = (size -1) /2;
        rehash(newSize);
    }
    
    return retour;
}


template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE,classe_de_dispersion>::erase
(typename unordered_multiset<TYPE,classe_de_dispersion>::iterator i){
    // GOOD
    (*i.ALV)->erase(i.POS);
    return i;
}


/////////////////////////////////////////////////////////////////////
// count
template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE,classe_de_dispersion>::count(const TYPE& VAL)const{
    // GOOD
    size_t retour=0;
    size_t size = REP.size() - 1;
    size_t alv = disperseur(VAL) % size;
    
    if (REP[alv] == nullptr) {
        return retour;
    }
    return std::count(REP[alv]->begin(), REP[alv]->end(), VAL);
}


/////////////////////////////////////////////////////////////////////
// find
template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE,classe_de_dispersion>::find(const TYPE& VAL){
    iterator retour;
    return retour;
//    size_t size = REP.size() - 1;
//    size_t alveole = disperseur(VAL) % size;
//
//    for (auto i = REP[alveole]->begin(); i != REP[alveole]->end(); i++) {
//        if(*i == VAL){
//            return iterator(REP.begin() + alveole, i);
//        }
//    }
//    return end();
}




#endif /* unordered_multiset_2_h */
