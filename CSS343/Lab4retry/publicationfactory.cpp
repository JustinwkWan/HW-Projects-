#include "publicationfactory.h"
#include "children.h"
#include "fiction.h"
#include "periodical.h"
PublicationFactory::PublicationFactory() {
    for(int i = 0; i < 26; i++) {
        pubFactory[i] = nullptr;
    }

    pubFactory['C' - 'A'] = new Children;
    pubFactory['F' - 'A'] = new Fiction;
    pubFactory['P' - 'A'] = new Periodical;
    
}

PublicationFactory::~PublicationFactory() {
   for (int i = 0; i < 26; i++) {
      delete pubFactory[i];
      pubFactory[i] = NULL;
    }
}

Publication* PublicationFactory::createPublication(const char& pubType) {
    int subscript = hash(pubType);
    return pubFactory[subscript]->create();
}