#include <iostream>
#include <fstream>
using namespace std;
main()
{
    string line;
    fstream file;
    file.open("example.txt",ios::in);
    int count=0;
    while(!file.eof())
    {
        getline(file,line);
        cout << "The line is:";
        cout << line << endl;
        count++;
    }
    cout<<"NO of LInes are:"<< count;
    file.close();
    
}