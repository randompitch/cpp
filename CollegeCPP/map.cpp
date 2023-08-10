#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main()
{
    map<int, string> Students;
    Students.insert(pair<int,string>(200, "Alice"));
    Students.insert(pair<int,string>(201, "John"));
    cout << Students.size() << endl;
    map<int,string> :: iterator it;
    cout << "Values in student map: " << endl;
    cout << "Key " << " \t " << "Value " << endl;
    for(it = Students.begin(); it != Students.end(); it++){
        cout <<  it -> first << " \t " << it -> second << endl;
    }
    //map<int,string> :: iterator it;
    it = Students.find(201);
    if (it != Students.end()){
        cout << "Value is " << it -> second;
    }
    else 
    cout << "Key not in map.";

    return 0;
}