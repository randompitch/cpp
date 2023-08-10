#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main()
{
    char data[100];
    ofstream myfile("tutfile.txt");
    cout << "Enter content:   "; cin.getline(data,100);
    for(int i=0; i<strlen(data); i++){
        if (data[i] >= 65 || data[i] <= 90 || data[i] >= 97 || data[i] <= 122){
            data[i]+=3;
            myfile << data[i];
        }
    }
    //myfile << data+3;
    myfile.close();

    char data1[100];
    ifstream obj("tutfile.txt");
    obj.getline(data1, 100);
    cout << "Encrypted: \t " << data1 << endl;
    cout << "Decrypted: \t ";
    for(int i=0; i<strlen(data); i++){
        if (data[i] >= 65 || data[i] <= 90 || data[i] >= 97 || data[i] <= 122){
            data[i]-=3;
            cout << data[i];
        }
    }
    obj.close();
  
    return 0;
}