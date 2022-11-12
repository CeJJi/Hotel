#include <iostream>
#include <stdio.h>
#include <string>
using	namespace	std;

int	main()
{

    int a = 0, b = 0, c = 0;
    string s1 = "2/1/2022";
    if ((s1.substr(1,1))=="/")
    {
        a = stoi(s1.substr(0, 1));
        if ((s1.substr(4,1))=="/")
        {
            b = stoi(s1.substr(2, 2));
            c = stoi(s1.substr(5, 4));
        }
        if ((s1.substr(3,1))=="/")
        {
            b = stoi(s1.substr(2, 1));
            c = stoi(s1.substr(4, 4));
        }
    }
    if ((s1.substr(2,1))=="/")
    {
        a = stoi(s1.substr(0, 2));
        if ((s1.substr(5,1))=="/")
        {
            b = stoi(s1.substr(3, 2));
            c = stoi(s1.substr(6, 4));
        }
        if ((s1.substr(4,1))=="/")
        {
            b = stoi(s1.substr(3, 1));
            c = stoi(s1.substr(5, 4));
        }
    }
    // if ((s1.substr(2,1))=="/")
    // {
    //     a = stoi(s1.substr(0, 2));
    // }


    cout << endl << s1 << endl;
    cout << "Int is: " << a << " " << b << " " << c << endl << endl;
}