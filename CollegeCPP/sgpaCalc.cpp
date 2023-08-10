#include <iostream>
using namespace std;

int main()
{
    cout << "Hello" << endl;
    float os      =     9*4;     //Operating Systems & Systems Programming
    float osL     =     9*1;     //Operating Systems Lab
    float cns     =     10*3;    //Computer Networks & Security
    float cnsL    =     9*1;     //Computer Networks Lab
    float opSrc   =     10*1;    //Open Source Software Lab
    float mmL     =     10*1;    //Multimedia Lab
    float mp      =     8*2;     //Minor Project
    float de      =     9*3;     //Discipline Elective
    float hss     =     8*3;     //HSS Elective
    float se      =     8*3;     //Science Elective
    int totCreds = 4+1+3+1+1+1+2+3+3+3;    
    float gp = os + cns + opSrc + mmL + osL + cnsL + mp + de + hss + se;
    float sgpa = gp/totCreds;
    cout << "SGPA: " << sgpa << endl;   
    float cg = (7.8 + 7.2 + 7.3 + +7.3+ sgpa);
    cout << "CGPA: " << cg/5 << endl;
    return 0;
}