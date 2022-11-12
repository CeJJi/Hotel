// #include <iostream>
// using namespace std;
// int main()
// {
//     int logic = 0;
//     string temp01, temp02 = "A" , temp03 = "A";
//     char wait;
//     // temp01 = "A1001";
//     // if (temp01 != temp02)
//     // {
//     //     temp02 = temp01;
//     //     if (temp01 != temp03)
//     //     {
//     //         temp03 = temp01;
//     //     }
//     //     else
//     //     {
//     //         logic = logic + 1;
//     //     }
//     // }
//     // cout << temp01 << " " << temp02 << " " << temp03 << " " << endl;
//     // cin.get(wait);
//     // cout << "Press Enter to continue" << endl;
//     // cin.get(wait);
//     // temp01 = "A1002";
//     // if (temp01 != temp02)
//     // {
//     //     temp02 = temp01;
//     //     if (temp01 != temp03)
//     //     {
//     //         temp03 = temp01;
//     //     }
//     //     else
//     //     {
//     //         logic = logic + 1;
//     //     }
//     // }
//     // cout << temp01 << " " << temp02 << " " << temp03 << " " << endl;
//     // cin.get(wait);
//     // cout << "Press Enter to continue" << endl;
//     // cin.get(wait);
//     temp01 = "A1002";
//     if (temp02 == "A")
//     {
//         temp02 = temp01;
//     }
//     else
//     {
//         if (temp03 == "A")
//         {
//             temp03 = temp01;
//         }
//         else
//         {
//             if (temp02 == temp03)
//             {
//                 temp02 = temp01;
//             }
//             else
//             {
//                 if (temp01 != temp02 && temp01 != temp03)
//                 {
//                     logic = 3;
//                 }
//             }
//         }
//     }
//     cout << temp01 << " " << temp02 << " " << temp03 << " " << logic << endl;
//     cin.get(wait);
//     cout << "Press Enter to continue" << endl;
//     cin.get(wait);

//     temp01 = "A1003";
//     if (temp02 == "A")
//     {
//         temp02 = temp01;
//     }
//     else
//     {
//         if (temp03 == "A")
//         {
//             temp03 = temp01;
//         }
//         else
//         {
//             if (temp02 == temp03)
//             {
//                 temp02 = temp01;
//             }
//             else
//             {
//                 if (temp01 != temp02 && temp01 != temp03)
//                 {
//                     logic = 3;
//                 }
//             }
//         }
//     }
//     cout << temp01 << " " << temp02 << " " << temp03 << " " << logic << endl;
//     cin.get(wait);
//     cout << "Press Enter to continue" << endl;
//     cin.get(wait);

//     temp01 = "A1001";
//     if (temp02 == "A")
//     {
//         temp02 = temp01;
//     }
//     else
//     {
//         if (temp03 == "A")
//         {
//             temp03 = temp01;
//         }
//         else
//         {
//             if (temp02 == temp03)
//             {
//                 temp02 = temp01;
//             }
//             else
//             {
//                 if (temp01 != temp02 && temp01 != temp03)
//                 {
//                     logic = 3;
//                 }
//             }
//         }
//     }
//     cout << temp01 << " " << temp02 << " " << temp03 << " " << logic << endl;
//     cin.get(wait);
//     cout << "Press Enter to continue" << endl;
//     cin.get(wait);

//     temp01 = "A1002";
//     if (temp02 == "A")
//     {
//         temp02 = temp01;
//     }
//     else
//     {
//         if (temp03 == "A")
//         {
//             temp03 = temp01;
//         }
//         else
//         {
//             if (temp02 == temp03)
//             {
//                 temp02 = temp01;
//             }
//             else
//             {
//                 if (temp01 != temp02 && temp01 != temp03)
//                 {
//                     logic = 3;
//                 }
//             }
//         }
//     }
//     cout << temp01 << " " << temp02 << " " << temp03 << " " << logic << endl;
//     cin.get(wait);
//     cout << "Press Enter to continue" << endl;
//     cin.get(wait);
//     if (logic = 3)
//     {
//         cout << "Can more than 2 room";
//     }
// }
// for _getch
#include <iostream> 
#include <conio.h> 
using namespace std;
string get_word();
int main()
{
    get_word();

}
string get_word()
{
    string word;
    cout << "grgr";
    cin >> word;
    char c = _getch();
    while (!isspace(c))
    {
        word.push_back(c);
        cout << c;
        c = _getch();
    }
    cout << c;
    return word;
}