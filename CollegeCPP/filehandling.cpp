#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  
    char name[100];
    cout << "Enter name: "; cin.getline(name,100);

    ofstream myf("file.txt" , ios :: app);
    //myf.open("file.txt", ios :: app);
    myf << name;
    myf.close();
    cout << "Done ";

    char names[100];
    ifstream myfile;//("file.txt");
    myfile.open("file.txt");
    myfile.getline(names, 100);
    cout << "Array content: " << names << endl;
    myfile.close();

/*
    char ch, a[50],b[50], bt;
    cout << "Enter file 1 name: "; cin >> a;
    cout << "Enter file 2 name: "; cin >> b;
    
    ifstream readf;
    ofstream writef;
    readf.open(a);
    writef.open(b, ios :: app);
    while (readf.eof() == 0){
        readf >> ch;
        writef << ch;
    }

    readf.close();
    writef.close();

    cout << "Files merged" << endl;
    
    ifstream tef;
    tef.open(b);
    char names[100];
    //writef.getline(names,100);
    tef >> names;
    for(auto x : names)
        cout << x;
    //cout << "Array content: " << names << endl;
    tef.close();
 */   
    return 0;
}