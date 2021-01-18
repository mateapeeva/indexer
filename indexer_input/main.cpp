#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    string page,tag,lineFName,fileName;
    fstream myfile;
    fstream fin;

    myfile.open("fileName.txt", ios::in);

    if(myfile.fail())
    {
        cout << "Error Opening File!";
    }
    else
    {
        while (myfile >> lineFName)
        {
                fileName=lineFName;
        }

        fin.open(fileName, fstream::out | fstream::app);

        if(fin.fail())
        {
            cout << "Error Opening File!";
        }
        else
        {
            if(argc%2==1)
            {
                for(int i=1; i<argc; i+=2)
                {
                    page=argv[i];
                    tag=argv[i+1];
                    fin << page << "," << tag << '\n';
                }

            }
            else
            {
                cout << "ERROR" << endl;
            }
        }

    }


    myfile.close();
    return 0;
}

