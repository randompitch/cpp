#include<iostream>
#include<fstream>

using namespace std; 

int main()
{
fstream fp; char buf[100]; int pos; 
fp.open("file.txt", ios::out | ios::ate);

fp << "This Vacation work at an NGO"; 
pos = fp.tellp(); 
std::cout<<"Current position of put pointer: "<<pos<<endl;

fp.seekp(-6, ios::cur); fp << "Temple ";

fp.seekg(0);
fp.seekp(5, ios::beg);

fp << "Summer  ";

fp.close();

fp.open("file.txt", ios::in | ios::ate);

fp.seekg(0, ios::beg); 
while (!fp.eof()){

fp.getline(buf, 100); cout << buf << endl;

} 
pos = fp.tellg();

cout << "\nCurrent Position of get pointer : " << pos << endl;

return 0; }