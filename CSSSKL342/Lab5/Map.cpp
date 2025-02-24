#include <map>
#include <iostream> 

using namespace std; 


void printMap(const std::map<std::string, int>& m)
{
    cout << "Printing out elements in array" << endl; 
    for (const auto& element : m)
        cout << element.first << " " << element.second << " ";
    cout << '\n';
}
int main() {
    map<string, int> map;
    map["Hello world"] = 10; 
    map["Tissues"] = 20; 
    map["Coconut water"] = 30; 
    map["Differental equations"] = 40; 
    map["Notebook"] = 50; 

    printMap(map);

    map.insert({"Hello world", 60});
    printMap(map);

    map.insert({"Gatorade", 70});
    printMap(map);

    //Key does not exist on map
    map["Badminton"] = 10; 
    printMap(map);
    
    //Key does exist on map 
    map["Notebook"] = 20;
    printMap(map);

    map.insert({"Tennis", 30});
    printMap(map);

    map.insert({"Hello world", 40});
    printMap(map);
    //There are no runtime errors
    return 0; 
    
}