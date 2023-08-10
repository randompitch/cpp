#include <iostream>

#include <fstream>

using namespace std;

int main () {

streampos begin, end;

ifstream myfile ("file.txt");

begin = myfile.tellg();

myfile.seekg (-3, ios::end);

end = myfile.tellg();

myfile.close();

cout << "size is: " << (end-begin) << " bytes.\n";
return 0;
}