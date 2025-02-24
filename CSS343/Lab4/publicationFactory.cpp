#include "publicationFactory.h"
using namespace std;
class Children;
class Fiction;
class Periodical; 
PublicationFactory::PublicationFactory() {
    for(int i = 0; i < 26; i++) {
        pubFactory[i] = nullptr;
    }
    pubFactory['C' - 'A'] = new Children;
    pubFactory['F' - 'A'] = new Fiction;
    pubFactory['P' - 'A'] = new Periodical;
    
}

Publication* PublicationFactory::createPublication(const char& pubType) {
    int subscript = hash(pubType);
    return pubFactory[subscript]->create();
}