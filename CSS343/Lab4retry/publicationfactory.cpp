#include "publicationfactory.h"

//----------------------------------------------------------------------------
// constructor
// iniltlizes the hashtable we are using to create publications
// any char we are not using is set to nullptr
PublicationFactory::PublicationFactory() {
    for(int i = 0; i < 26; i++) {
        pubFactory[i] = nullptr;
    }
    
    pubFactory['C' - 'A'] = new Children;
    pubFactory['F' - 'A'] = new Fiction;
    pubFactory['P' - 'A'] = new Periodical;
    
}

//----------------------------------------------------------------------------
// deconstructor
// deletes all publications and sets to nullptr
PublicationFactory::~PublicationFactory() {
   for (int i = 0; i < 26; i++) {
      delete pubFactory[i];
      pubFactory[i] = NULL;
    }
}

//----------------------------------------------------------------------------
// createPublication
// checks if input is a valid command type
// if valid, return the command 
NodeData* PublicationFactory::createPublication(const char& pubType) {
    // Make sure the character is a letter 
    if(pubType < 'A' || pubType > 'Z') { return nullptr;} 
    int subscript = hash(pubType);
    
    // Checking if the char is a fiction, children, or periodical
    if(pubFactory[subscript] == nullptr) { return nullptr; } 
    return pubFactory[subscript]->create();
}