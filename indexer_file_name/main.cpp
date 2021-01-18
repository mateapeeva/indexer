#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int i=1;
    fstream myfile;
    myfile.open("fileName.txt", std::ofstream::out | std::ofstream::trunc);

    if(myfile.fail())
    {
        cout << "Error Opening File!";
    }else
    {
        myfile << argv[i] << '\n';
        myfile.close();
    }

    return 0;
}

