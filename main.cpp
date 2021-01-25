#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void file_name(string name)
{
    fstream myfile;
    myfile.open("fileName.txt", std::ofstream::out | std::ofstream::trunc);

    if(myfile.fail())
    {
        cout << "Error Opening File!";
        return ;
    }else
    {
        myfile << name << '\n';
        myfile.close();
    }
}

void input(string page, string tag)
{
    string lineFName,fileName;
    fstream myfile;
    fstream fin;

    myfile.open("fileName.txt", ios::in);

    if(myfile.fail())
    {
        cout << "Error Opening File!";
        return ;
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
            return ;
        }
        else
        {
            fin << page << "," << tag << '\n';

        }

    }


    myfile.close();
}

void output(string indexVector, string query )
{
    fstream fin;
    fstream myfile;
    int rowIndex=0;
    string fileName, line, temp, word, lineFName;
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
        return ;
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
            return ;
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
                return ;
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

}

int main(int argc, char *argv[])
{
    string x=argv[1], f="file", i="input", o="output";
    if(x.compare(f) == 0)
    {
        string name;
        name=argv[2];
        file_name(name);
    }
    else if(x.compare(i) == 0)
    {
            string page=argv[2];
            string tag=argv[3];
            input(page,tag);
    }
    else if(x.compare(o) == 0)
    {
        string indexVector=argv[2];
        string query=argv[3];
        output(indexVector, query);
    }
    else
    {
        cout << "Error! Input file, input or find!" << endl;
    }
    return 0;
}
