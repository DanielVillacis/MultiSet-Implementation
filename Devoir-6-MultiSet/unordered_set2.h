//
//  unordered_set_2.h
//  unordered_multiset
//
//  Jean Goulet
//  Copyleft 2017
//
//  Modifié par : Daniel Villacis (vild2705)

#ifndef unordered_multiset_2_h
#define unordered_multiset_2_h

/////////////////////////////////////////////////////////////////////
// rehash
template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE, classe_de_dispersion>::rehash(size_t nbalv){
    size_t size = REP.size();
    unordered_multiset<TYPE> copyUM;
    copyUM.REP.resize(nbalv);
    copyUM.REP.back() = copyUM.REP[1];
    
    // Creer une copie de unordered_multiset (copyUM) vide
    for(size_t i = 0; i < copyUM.REP.size() - 1; ++i){
        copyUM.REP[i] = nullptr;
    }
    // Rehasher : mise a jour du nombre d'alveoles a N ou plus.
    // Rehash sets the number of buckets in the container to N or more.
    // If N is greater than the current number of buckets in the container (bucket_count), a rehash is forced.
    if (size < copyUM.REP.size()){
        for(size_t i = 0; i < REP.size(); i++) {
            if(REP[i] != nullptr) {
                for(std::list<double>::iterator j = REP[i]->begin(); j != REP[i]->end(); j++) {
                    copyUM.insert(*j);
                }
            }
        }
    }
    swap(copyUM);
}


///////////////////////////////////////////
// avancer et reculer un iterateur
template <typename TYPE,typename classe_de_dispersion>
void unordered_multiset<TYPE,classe_de_dispersion>::iterator::avancer(){
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
    size_t size = REP.size() - 1;
    size_t alv = disperseur(VAL) % size;

    // Si le nouveau nombre d'elements > facteur_max, un rehash est nécessaire.
    double load_factor = (double)SIZE / (double)size;
    if (load_factor > facteur_max) {
        rehash((size *2) + 1);
    }

    if (REP[alv] == nullptr) {
        // Creer une nouvelle liste si l'aveole est vide.
        REP[alv] = new list<TYPE>();
    }
    REP[alv]->push_back(VAL);

    SIZE++;
    return iterator(REP.begin() + alv, REP[alv]->end());
}


template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE,classe_de_dispersion>::erase(const TYPE& VAL){
    // GOOD
    // Takes a key value as argument and erases all elements of that value in the multiset.
    size_t retour=0; // key value : retour
    size_t size = REP.size() - 1;
    size_t alv = disperseur(VAL) % size;

    if (REP[alv] == nullptr) {
        return 0;
    }
    
    list<TYPE>*newListe = new list<TYPE>();

    for (auto i : *REP[alv]) {
        if (i == VAL) {
            // Augmenter le compteur des mêmes elements effacés
            retour++;
        }
        else {
            newListe->push_back(i);
        }
    }
    delete REP[alv];

    if (newListe->size() > 0) {
            REP[alv] = newListe;
    }
    else {
        REP[alv] = nullptr;
    }
    SIZE -= retour;
    // Si facteur_min > que le nouveau nombre d'éléments, un rehash est nécessaire.
    double load_factor = (double)SIZE / (double)size;
    if (facteur_min > load_factor) {
        rehash((size -1) /2);
    }
    // returns the number of elements erased.
    return retour;
}


template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE,classe_de_dispersion>::erase
(typename unordered_multiset<TYPE,classe_de_dispersion>::iterator i){
    (*i.ALV)->erase(i.POS);
    return i;
}


/////////////////////////////////////////////////////////////////////
// count
template <typename TYPE,typename classe_de_dispersion>
size_t unordered_multiset<TYPE,classe_de_dispersion>::count(const TYPE& VAL)const{
    size_t size = REP.size() - 1;
    size_t alv = disperseur(VAL) % size;
    
    if (REP[alv] == nullptr) {
        return 0;
    }
    return std::count(REP[alv]->begin(), REP[alv]->end(), VAL);
}


/////////////////////////////////////////////////////////////////////
// find
template <typename TYPE,typename classe_de_dispersion>
typename unordered_multiset<TYPE,classe_de_dispersion>::iterator
unordered_multiset<TYPE,classe_de_dispersion>::find(const TYPE& VAL){
    size_t size = REP.size() - 1;
    size_t alv = disperseur(VAL) % size;

    for (std::list<double>::iterator i = REP[alv]->begin(); i != REP[alv]->end(); i++) {
        if(*i == VAL){
            return iterator(REP.begin() + alv, i);
        }
    }
    return end();
}

#endif /* unordered_multiset_2_h */
