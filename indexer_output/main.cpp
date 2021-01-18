#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    fstream fin;
    fstream myfile;
    int rowIndex=0;
    string fileName, line, temp, word, query=argv[2], indexVector=argv[1], lineFName;
    vector<string>tag;
    vector<string>num;
    vector<string>searchVector;
    num.resize(rowIndex+1);
    tag.resize(rowIndex+1);
    searchVector.resize(rowIndex+1);

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

        fin.open(fileName, ios::in);

        if(fin.fail())
        {
            cout << "Error Opening File!";
        }
        else
        {
            while (fin >> line)
            {
                stringstream s(line);
                for(int colIndex=0; (getline(s, word, ',')); colIndex++  )
                {
                    if (colIndex==0)
                    {
                        num[rowIndex]=word;
                    }
                    else
                    {
                        tag[rowIndex]=word;
                    }
                }
                rowIndex++;
                num.resize(rowIndex+1);
                tag.resize(rowIndex+1);
                }


            if(indexVector=="page")
            {
                searchVector=num;
            }
            else if(indexVector=="tag")
            {
                searchVector=tag;
            }
            else
            {
                cout << "ERROR" << endl;
                return 0;
            }
            bool found = false;
            for(int i=0; i<rowIndex+1; i++)
            {
                if(query.compare(searchVector[i]) == 0)
                {
                    if(indexVector=="page")
                    {
                        cout<< tag[i] <<endl;
                    }else
                    {
                        cout<< num[i] <<endl;
                    }
                    found = true;
                }
            }
            if (!found)
            {
                cout<<"Element not found";
            }
        }
    }


    return 0;
}
