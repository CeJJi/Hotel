#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
int menu();
void case1(string Filename1, string Filename2);
void case2(string Filename1, string Filename2);
void case3(string Filename1, string Filename2);
void case4(string Filename1, string Filename2);
void checkroom(string date[][2], string room[], int num, string Filename2);
void checkroombook(string date[][2], string room[], int num, string dateinput[], string Filename2);
void checkid(string date[], string room[][11], string pid, int &roomcount, string Filename2);
void book(string room, string pid, string fname, string lname, string telephone, string people, string ratestr, string date[], string night, string dateafter[], string Filename2);
void countdisplaybookroom(string date[], string room[][11], string pid, int &roomcount, string Filename2);
void cancle(string arrayselect[], string Filename2);
int ratecal(int people, int night);
int main()
{
    int reselect;
    const string Filename1 = "allroom.dat";
    const string Filename2 = "allbook.dat";
    ifstream InFile;
    ofstream OutFile;
    do
    {
        system("cls");
        reselect = menu();
        if (reselect > 4)
        {
            cout << "Please select 1 - 4" << endl;
            char wait;
            cin.get(wait);
            cout << "Press Enter to continue";
            cin.get(wait);
        }
        if (reselect == 1)
        {
            case1(Filename1,Filename2);
        }
        if (reselect == 2)
        {
            case2(Filename1,Filename2);
        }
        if (reselect == 3)
        {
            case3(Filename1,Filename2);
        }
        if (reselect == 4)
        {
            case4(Filename1,Filename2);
        }
    } while (reselect != 0);
    cout << "End Program" << endl << endl;
}
int menu()
{
    
    int select = 0;
    cout << "=============================" << endl;
    cout << "|" << setw(20)<< "List of menu"<< setw(8) << "|" << endl;
    cout << "=============================" << endl;
    cout << "|"<< setw(1) << " 0. Exit" << setw(20) << " |" <<endl;
    cout << "|"<< setw(1) << " 1. Check Room"   << setw(14) << " |" <<endl;
    cout << "|"<< setw(1) << " 2. Book Room"   << setw(15) << " |" <<endl;
    cout << "|"<< setw(1) << " 3. Display Your Room"   << setw(7) << " |" <<endl;
    cout << "|"<< setw(1) << " 4. Cancle Your Room"   << setw(8) << " |" <<endl;
    cout << "=============================" << endl;
    cout << "Enter select : ";
    cin >> select;
    cout << endl;
    return select;
}
void case1(string Filename1, string Filename2)
{
    int num;
    string room[20], date[31][2];
    bool loop;
    ifstream InFile(Filename1.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id;
        int n = 0;
        cout << "===================" << endl;
        cout << "|" << setw(13)<< "List Room" << setw(5) << "|" << endl;
        cout << "===================" << endl;
        cout << "|" << setw(6) << "Number" << setw(2) << " : ";
        cout << setw(3)<< "Room ID" << setw(2) << " |" << endl;
        cout << "===================" << endl;
        InFile >> Id;
        while (!InFile.eof())
        {
            n = n + 1;
            cout << "|" << setw(5) << n << setw(4) << " : ";
            cout << setw(6)<< Id << setw(3) << " |" << endl;
            room[n-1] = Id;
            InFile >> Id;
        }
        cout << "===================" << endl;
        InFile.close();
    }
    else
    {
        cout << "File could not opened." << endl;
    }
    do
    {
        loop = true;
        cout << "* Enter 0 to go main menu" << endl;
        cout << "Enter number : ";
        cin >> num;
        if(num == 0)
        {
            loop = false;
        }
        if (num > 0 && num < 21)
        {
            loop = false;
            cout << endl;
            checkroom(date,room,num,Filename2);
            cout << "===============================" << endl;
            cout << "|" << setw(17)<< room[num-1] << setw(13) << "|" << endl;
            cout << "===============================" << endl;
            cout << "|" << setw(6) << "Number" << setw(2) << " : ";
            cout << setw(7) << "Date" << setw(6) << " : ";
            cout << setw(3)<< "Status" << setw(0) << " |" << endl;
            cout << "===============================" << endl;
            for (int i = 0; i < 31; i++)
            {
                cout << "|" << setw(5) << i+1 << setw(4) << " : ";
                cout << setw(10)<< date[i][0] << setw(3) << " : ";
                cout << setw(6)<< date[i][1] << setw(2) << " |" << endl;
            }
            cout << "===============================" << endl;
            char wait;
            cin.get(wait);
            cout << "Press Enter to continue";
            cin.get(wait);
        }
        else
        {
            cout << "Please enter 1 - 20" << endl << endl;
        }
    } while (loop);
}
void case2(string Filename1, string Filename2)
{
    int num, number, numeric;
    string room[20], date[31][2];
    bool loop, loopinloop, loopinloopinloop;
    ifstream InFile(Filename1.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id;
        int n = 0;
        cout << "===================" << endl;
        cout << "|" << setw(13)<< "List Room" << setw(5) << "|" << endl;
        cout << "===================" << endl;
        cout << "|" << setw(6) << "Number" << setw(2) << " : ";
        cout << setw(3)<< "Room ID" << setw(2) << " |" << endl;
        cout << "===================" << endl;
        InFile >> Id;
        while (!InFile.eof())
        {
            n = n + 1;
            cout << "|" << setw(5) << n << setw(4) << " : ";
            cout << setw(6)<< Id << setw(3) << " |" << endl;
            room[n-1] = Id;
            InFile >> Id;
        }
        cout << "===================" << endl;
        InFile.close();
    }
    else
    {
        cout << "File could not opened." << endl;
    }
    do
    {
        loop = true;
        cout << "* Enter 0 to go main menu" << endl;
        cout << "Enter number : ";
        cin >> num;
        if(num == 0)
        {
            loop = false;
        }
        if (num > 0 && num < 21)
        {
            loop = false;
            cout << endl;
            checkroom(date,room,num,Filename2);
            cout << "===============================" << endl;
            cout << "|" << setw(17)<< room[num-1] << setw(13) << "|" << endl;
            cout << "===============================" << endl;
            cout << "|" << setw(6) << "Number" << setw(2) << " : ";
            cout << setw(7) << "Date" << setw(6) << " : ";
            cout << setw(3)<< "Status" << setw(0) << " |" << endl;
            cout << "===============================" << endl;
            for (int i = 0; i < 31; i++)
            {
                cout << "|" << setw(5) << i+1 << setw(4) << " : ";
                cout << setw(10)<< date[i][0] << setw(3) << " : ";
                cout << setw(6)<< date[i][1] << setw(2) << " |" << endl;
            }
            cout << "===============================" << endl;
            do
            {
                loopinloop = true;
                cout << "* Enter 0 to go main menu" << endl;
                cout << "Enter number : ";
                cin >> number;
                if(number == 0)
                {
                    loopinloop = false;
                }
                if (number > 0 && number < 32)
                {
                    loopinloop = false;
                    if (date[number-1][1] == "Booked")
                    {
                        cout << "This room has already been booked" << endl << endl;
                        loopinloop = true;
                    }
                    else
                    {
                        string dateafter[32][2];
                        checkroombook(dateafter,room,num,date[number-1],Filename2);
                        cout << endl << "===============================" << endl;
                        cout << "|" << setw(17)<< room[num-1] << setw(13) << "|" << endl;
                        cout << "===============================" << endl;
                        cout << "|" << setw(6) << "Number" << setw(2) << " : ";
                        cout << setw(7) << "Date" << setw(6) << " : ";
                        cout << setw(3)<< "Status" << setw(0) << " |" << endl;
                        cout << "===============================" << endl;
                        for (int i = 0; i < 31; i++)
                        {
                            cout << "|" << setw(5) << i+1 << setw(4) << " : ";
                            cout << setw(10)<< dateafter[i][0] << setw(3) << " : ";
                            cout << setw(6)<< dateafter[i][1] << setw(2) << " |" << endl;
                        }
                        cout << "===============================" << endl;
                        do
                        {
                            loopinloopinloop = true;
                            cout << "* Enter 0 to go main menu" << endl;
                            cout << "Enter night : ";
                            cin >> numeric;
                            if(numeric == 0)
                            {
                                loopinloopinloop = false;
                            }
                            if (numeric > 0 && numeric < 32)
                            {
                                loopinloopinloop = false;
                                if (dateafter[numeric-1][1] == "Booked")
                                {
                                    cout << "This room has already been booked" << endl << endl;
                                    loopinloopinloop = true;
                                }
                                else
                                {
                                    int logic = 0;
                                    for (int xx = 0; xx < numeric; xx++)
                                    {
                                        if (dateafter[xx][1] == "Booked")
                                        {
                                            logic = 1;
                                            cout << "Some date has already been booked" << endl << endl;
                                            loopinloopinloop = true;
                                        }
                                    }
                                    if (logic != 1)
                                    {
                                        int roomidcount = 0, logicid = 0;
                                        int people;
                                        string pid, fname, lname, telephone;
                                        string temp01 = "A", temp02 = "A", temp03 = "A";
                                        string dateid[31];
                                        string roomid[60][11];
                                        cout << endl << "==============================================" << endl << endl;
                                        cout << setw(26) << "Enter ID Card : " << setw(25);
                                        cin >> pid;
                                        checkid(dateid,roomid,pid,roomidcount,Filename2);
                                        if (roomidcount != 0)
                                        {
                                            // cout << endl << "===============================================================================================================================================================" << endl;
                                            // cout << "|" << setw(79)<< "Your Room" << setw(79) << "|" << endl;
                                            // cout << "===============================================================================================================================================================" << endl;
                                            // cout << "|" << setw(6) << "Number" << setw(2) << " : ";
                                            // cout << setw(7) << "Room ID" << setw(3) << " : ";
                                            // cout << setw(10) << "ID Card" << setw(6) << " : ";
                                            // cout << setw(14) << "First Name" << setw(6) << " : ";
                                            // cout << setw(14) << "Last Name" << setw(6) << " : ";
                                            // cout << setw(13) << "Phone Number" << setw(3) << " : ";
                                            // cout << setw(6) << "People" << setw(1) << " : ";
                                            // cout << setw(7) << "Price" << setw(5) << " : ";
                                            // cout << setw(10) << "Book Date" << setw(3) << " : ";
                                            // cout << setw(10) << "Check In" << setw(3) << " : ";
                                            // cout << setw(5) << "Night" << setw(3) << " : ";
                                            // cout << setw(10)<< "Check Out" << setw(2) << " |" << endl;
                                            // cout << "===============================================================================================================================================================" << endl;
                                            for (int i = 0; i < roomidcount; i++)
                                            {
                                                // cout << "|" << setw(5) << i+1 << setw(4) << " : ";
                                                // cout << setw(6)<< roomid[i][0] << setw(4) << " : ";
                                                // cout << setw(10)<< roomid[i][1] << setw(3) << " : ";
                                                // cout << setw(15)<< roomid[i][2] << setw(5) << " : ";
                                                // cout << setw(15)<< roomid[i][3] << setw(5) << " : ";
                                                // cout << setw(13)<< roomid[i][4] << setw(3) << " : ";
                                                // cout << setw(4)<< roomid[i][5] << setw(5) << " : ";
                                                // cout << setw(7)<< roomid[i][6] << setw(5) << " : ";
                                                // cout << setw(10)<< roomid[i][7] << setw(2) << " : ";
                                                // cout << setw(10)<< roomid[i][8] << setw(2) << " : ";
                                                // cout << setw(3)<< roomid[i][9] << setw(5) << " : ";
                                                // cout << setw(10)<< roomid[i][10] << setw(2) << " |" << endl;
                                                temp01 = roomid[i][0];
                                                if (temp02 == "A")
                                                {
                                                    temp02 = temp01;
                                                }
                                                else
                                                {
                                                    if (temp03 == "A")
                                                    {
                                                        temp03 = temp01;
                                                    }
                                                    else
                                                    {
                                                        if (temp02 == temp03)
                                                        {
                                                            temp02 = temp01;
                                                        }
                                                        else
                                                        {
                                                            if (temp01 != temp02 && temp01 != temp03)
                                                            {
                                                                logicid = 3;
                                                            }
                                                        }
                                                    }
                                                }
                                                if (temp02 != "A" && temp03 != "A")
                                                {
                                                    if (temp02 != temp03)
                                                    {
                                                        if (temp02 != room[num-1])
                                                        {
                                                            if (temp03 != room[num-1])
                                                            {
                                                                logicid = 3;
                                                            }
                                                        }
                                                        if (temp03 != room[num-1])
                                                        {
                                                            if (temp02 != room[num-1])
                                                            {
                                                                logicid = 3;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                            //cout << "===============================================================================================================================================================" << endl;
                                        }
                                        if (logicid != 3)
                                        {
                                            cout << setw(26) << "Enter first name : " << setw(25);
                                            cin >> fname;
                                            cout << setw(26) << "Enter last name : " << setw(25);
                                            cin >> lname;
                                            cout << setw(26) << "Enter telephone number : " << setw(25);
                                            cin >> telephone;
                                            cout << setw(26) << "Enter number people : " << setw(25);
                                            cin >> people;
                                            cout << endl << "==============================================" << endl << endl;
                                            string ratestr = to_string(ratecal(people,numeric));
                                            string peoplestr = to_string(people);
                                            string numericstr = to_string(numeric);
                                            book(room[num-1],pid,fname,lname,telephone,peoplestr,ratestr,date[number-1],numericstr,dateafter[numeric],Filename2);
                                            cout << "Book success" << endl;
                                            char wait;
                                            cin.get(wait);
                                            cout << endl << "Press Enter to continue";
                                            cin.get(wait);
                                        }
                                        else
                                        {
                                            cout << endl << "==============================================" << endl << endl;
                                            cout << "You can't book more 2 room" << endl;
                                            char wait;
                                            cin.get(wait);
                                            cout << endl << "Press Enter to continue";
                                            cin.get(wait);
                                        }
                                    }
                                }
                            }
                            else
                            {
                                cout << "Please enter 1 - 31" << endl << endl;
                            }
                        } while (loopinloopinloop);
                    }
                }
                else
                {
                    cout << "Please enter 1 - 31" << endl << endl;
                }
            } while (loopinloop);
        }
        else
        {
            cout << "Please enter 1 - 20" << endl << endl;
        }
    } while (loop);
}
void case3(string Filename1, string Filename2)
{
    int roomcount = 0;
    string pid;
    string date[31];
    string room[60][11];
    bool loop;
    ifstream InFile(Filename1.c_str(), ios_base::in);
    cout << "===========================================" << endl << endl;
    cout << setw(22) << "Enter ID Card : " << setw(25);
    cin >> pid;
    countdisplaybookroom(date,room,pid,roomcount,Filename2);
    if (roomcount != 0)
    {
        cout << endl << "===========================================" << endl << endl;
        cout << endl << "===============================================================================================================================================================" << endl;
        cout << "|" << setw(79)<< "Your Room" << setw(79) << "|" << endl;
        cout << "===============================================================================================================================================================" << endl;
        cout << "|" << setw(6) << "Number" << setw(2) << " : ";
        cout << setw(7) << "Room ID" << setw(3) << " : ";
        cout << setw(10) << "ID Card" << setw(6) << " : ";
        cout << setw(14) << "First Name" << setw(6) << " : ";
        cout << setw(14) << "Last Name" << setw(6) << " : ";
        cout << setw(13) << "Phone Number" << setw(3) << " : ";
        cout << setw(6) << "People" << setw(1) << " : ";
        cout << setw(7) << "Price" << setw(5) << " : ";
        cout << setw(10) << "Book Date" << setw(3) << " : ";
        cout << setw(10) << "Check In" << setw(3) << " : ";
        cout << setw(5) << "Night" << setw(3) << " : ";
        cout << setw(10)<< "Check Out" << setw(2) << " |" << endl;
        cout << "===============================================================================================================================================================" << endl;
        for (int i = 0; i < roomcount; i++)
        {
            cout << "|" << setw(5) << i+1 << setw(4) << " : ";
            cout << setw(6)<< room[i][0] << setw(4) << " : ";
            cout << setw(10)<< room[i][1] << setw(3) << " : ";
            cout << setw(15)<< room[i][2] << setw(5) << " : ";
            cout << setw(15)<< room[i][3] << setw(5) << " : ";
            cout << setw(13)<< room[i][4] << setw(3) << " : ";
            cout << setw(4)<< room[i][5] << setw(5) << " : ";
            cout << setw(7)<< room[i][6] << setw(5) << " : ";
            cout << setw(10)<< room[i][7] << setw(2) << " : ";
            cout << setw(10)<< room[i][8] << setw(2) << " : ";
            cout << setw(3)<< room[i][9] << setw(5) << " : ";
            cout << setw(10)<< room[i][10] << setw(2) << " |" << endl;
        }
        cout << "===============================================================================================================================================================" << endl;
        char wait;
        cin.get(wait);
        cout << "Press Enter to continue";
        cin.get(wait);
    }
    else
    {
        cout << endl << "===========================================" << endl << endl;
        cout << "Not found your ID Card" << endl;
        char wait;
        cin.get(wait);
        cout << endl << "Press Enter to continue";
        cin.get(wait); 
    }
}
void case4(string Filename1, string Filename2)
{
    int roomcount = 0, num;
    string pid, wantcalcle;
    string date[31];
    string room[60][11];
    bool loop;
    ifstream InFile(Filename1.c_str(), ios_base::in);
    cout << "===========================================" << endl << endl;
    cout << setw(22) << "Enter ID Card : " << setw(25);
    cin >> pid;
    countdisplaybookroom(date,room,pid,roomcount,Filename2);
    if (roomcount != 0)
    {
        cout << endl << "===========================================" << endl << endl;
        cout << endl << "===============================================================================================================================================================" << endl;
        cout << "|" << setw(79)<< "Your Room" << setw(79) << "|" << endl;
        cout << "===============================================================================================================================================================" << endl;
        cout << "|" << setw(6) << "Number" << setw(2) << " : ";
        cout << setw(7) << "Room ID" << setw(3) << " : ";
        cout << setw(10) << "ID Card" << setw(6) << " : ";
        cout << setw(14) << "First Name" << setw(6) << " : ";
        cout << setw(14) << "Last Name" << setw(6) << " : ";
        cout << setw(13) << "Phone Number" << setw(3) << " : ";
        cout << setw(6) << "People" << setw(1) << " : ";
        cout << setw(7) << "Price" << setw(5) << " : ";
        cout << setw(10) << "Book Date" << setw(3) << " : ";
        cout << setw(10) << "Check In" << setw(3) << " : ";
        cout << setw(5) << "Night" << setw(3) << " : ";
        cout << setw(10)<< "Check Out" << setw(2) << " |" << endl;
        cout << "===============================================================================================================================================================" << endl;
        for (int i = 0; i < roomcount; i++)
        {
            cout << "|" << setw(5) << i+1 << setw(4) << " : ";
            cout << setw(6)<< room[i][0] << setw(4) << " : ";
            cout << setw(10)<< room[i][1] << setw(3) << " : ";
            cout << setw(15)<< room[i][2] << setw(5) << " : ";
            cout << setw(15)<< room[i][3] << setw(5) << " : ";
            cout << setw(13)<< room[i][4] << setw(3) << " : ";
            cout << setw(4)<< room[i][5] << setw(5) << " : ";
            cout << setw(7)<< room[i][6] << setw(5) << " : ";
            cout << setw(10)<< room[i][7] << setw(2) << " : ";
            cout << setw(10)<< room[i][8] << setw(2) << " : ";
            cout << setw(3)<< room[i][9] << setw(5) << " : ";
            cout << setw(10)<< room[i][10] << setw(2) << " |" << endl;
        }
        cout << "===============================================================================================================================================================" << endl;
        do
        {
            loop = true;
            cout << "* Enter 0 to go main menu" << endl;
            cout << "Enter number : ";
            cin >> num;
            if (num == 0)
            {
                loop = false;
            }
            if (num > 0 && num < roomcount+1)
            {
                do
                {
                    loop = true;
                    cout << "Do you want to cancle? ( Y / N ) : ";
                    cin >> wantcalcle;
                    if(wantcalcle == "Y" || wantcalcle == "y" || wantcalcle == "yes" || wantcalcle == "Yes" || wantcalcle == "YES")
                    {
                        loop = false;
                        cancle(room[num-1],Filename2);
                    }
                    else
                    {
                        loop = false;
                        cout << "Exit cancle room" << endl << endl;
                        char wait;
                        cin.get(wait);
                        cout << "Press Enter to continue";
                        cin.get(wait);
                    }
                } while (loop);
            }
            else
            {
                cout << "Please enter 1 - " << roomcount << endl << endl;
            }
        } while (loop);
    }
    else
    {
        cout << endl << "===========================================" << endl << endl;
        cout << "Not found your ID Card" << endl;
        char wait;
        cin.get(wait);
        cout << endl << "Press Enter to continue";
        cin.get(wait); 
    }
}
void checkroom(string date[][2], string room[], int num, string Filename2)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int daytime = 31;
    string tempday = to_string(day);
    string tempmonth = to_string(month);
    string tempyear = to_string(year);
    string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
    date[0][0] = tempdate;
    date[0][1] = "Empty";
    if (daytime > 0)
    {
        for (int i = 1; i < daytime; i++)
        {
            if( day==31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
            {
                day=0;
                month=month+1;
            }
            else if( day==30 && (month == 4 || month == 6 || month == 9 || month == 11))
            {
                day=0;
                month=month+1;
            }
            else if(month == 2)
            { 
                if ((year % 100) == 0)
                {
                    if ((year % 400) == 0 && (year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else 
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
                else 
                {
                    if ((year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
            }
            else{
            }
            day = day + 1;
            if (month == 13)
            {
                day = 1;
                month = 1;
                year = year + 1;
            }
            string tempday = to_string(day);
            string tempmonth = to_string(month);
            string tempyear = to_string(year);
            string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
            date[i][0] = tempdate;
            date[i][1] = "Empty";
        }
        ifstream InFile(Filename2.c_str(), ios_base::in);
        if (InFile.is_open())
        {
            string Id, bookpid, fname, lname, tele, people, rate, timebooked, checkin, night, checkout;
            while (!InFile.eof())
            {
                InFile >> Id >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> checkin >> night >> checkout;
                if(Id == room[num-1])
                {
                    for(int i = 0; i < daytime; i++)
                    {
                        if (date[i][0] == checkout)
                        {
                            if (i != 0)
                            {
                                for (int j = i; j > 0; j--)
                                {
                                    date[j-1][1] = "Booked";
                                    if (date[j-1][0] == checkin)
                                    {
                                        j = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (date[i][0] == checkin)
                            {
                                for (int j = i; j < daytime; j++)
                                {
                                    if (date[j][0] != checkout)
                                    {
                                        date[j][1] = "Booked";
                                    }
                                    if (date[j][0] == checkout)
                                    {
                                        j = 31;
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
            InFile.close();
        }
        else
        {
            cout << endl << "File could not opened." << endl;
        }
    }
}
void checkroombook(string date[][2], string room[], int num, string dateinput[], string Filename2)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int a, b, c;
    if ((dateinput[0].substr(1,1))=="/")
    {
        a = stoi(dateinput[0].substr(0, 1));
        if ((dateinput[0].substr(4,1))=="/")
        {
            b = stoi(dateinput[0].substr(2, 2));
            c = stoi(dateinput[0].substr(5, 4));
        }
        if ((dateinput[0].substr(3,1))=="/")
        {
            b = stoi(dateinput[0].substr(2, 1));
            c = stoi(dateinput[0].substr(4, 4));
        }
    }
    if ((dateinput[0].substr(2,1))=="/")
    {
        a = stoi(dateinput[0].substr(0, 2));
        if ((dateinput[0].substr(5,1))=="/")
        {
            b = stoi(dateinput[0].substr(3, 2));
            c = stoi(dateinput[0].substr(6, 4));
        }
        if ((dateinput[0].substr(4,1))=="/")
        {
            b = stoi(dateinput[0].substr(3, 1));
            c = stoi(dateinput[0].substr(5, 4));
        }
    }
    int year = c;
    int month = b;
    int day = a;
    int daytime = 32;

    date[0][0] = dateinput[0];
    date[0][1] = "Empty";
    if (daytime > 0)
    {
        for (int i = 1; i < daytime; i++)
        {
            if( day==31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
            {
                day=0;
                month=month+1;
            }
            else if( day==30 && (month == 4 || month == 6 || month == 9 || month == 11))
            {
                day=0;
                month=month+1;
            }
            else if(month == 2)
            { 
                if ((year % 100) == 0)
                {
                    if ((year % 400) == 0 && (year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else 
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
                else 
                {
                    if ((year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
            }
            else{
            }
            day = day + 1;
            if (month == 13)
            {
                day = 1;
                month = 1;
                year = year + 1;
            }
            string tempday = to_string(day);
            string tempmonth = to_string(month);
            string tempyear = to_string(year);
            string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
            date[i][0] = tempdate;
            date[i][1] = "Empty";
        }
        ifstream InFile(Filename2.c_str(), ios_base::in);
        if (InFile.is_open())
        {
            string Id, bookpid, fname, lname, tele, people, rate, timebooked, checkin, night, checkout;
            while (!InFile.eof())
            {
                InFile >> Id >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> checkin >> night >> checkout;
                if(Id == room[num-1])
                {
                    for(int i = 0; i < daytime; i++)
                    {
                        if (date[i][0] == checkout)
                        {
                            if (i != 0)
                            {
                                for (int j = i; j > 0; j--)
                                {
                                    date[j-1][1] = "Booked";
                                    if (date[j-1][0] == checkin)
                                    {
                                        j = 0;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (date[i][0] == checkin)
                            {
                                for (int j = i; j < daytime; j++)
                                {
                                    if (date[j][0] != checkout)
                                    {
                                        date[j][1] = "Booked";
                                    }
                                    if (date[j][0] == checkout)
                                    {
                                        j = 31;
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
            InFile.close();
        }
        else
        {
            cout << endl << "File could not opened." << endl;
        }
    }
}
void checkid(string date[], string room[][11], string pid, int &roomcount, string Filename2)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int daytime = 30, b = 0;
    string tempday = to_string(day);
    string tempmonth = to_string(month);
    string tempyear = to_string(year);
    string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
    if (daytime > 0)
    {
        for (int i = 0; i < daytime; i++)
        {
            if( day==31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
            {
                day=0;
                month=month+1;
            }
            else if( day==30 && (month == 4 || month == 6 || month == 9 || month == 11))
            {
                day=0;
                month=month+1;
            }
            else if(month == 2)
            { 
                if ((year % 100) == 0)
                {
                    if ((year % 400) == 0 && (year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else 
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
                else 
                {
                    if ((year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
            }
            else{
            }
            day = day + 1;
            if (month == 13)
            {
                day = 1;
                month = 1;
                year = year + 1;
            }
            string tempday = to_string(day);
            string tempmonth = to_string(month);
            string tempyear = to_string(year);
            string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
            date[i] = tempdate;
        }
        ifstream InFile(Filename2.c_str(), ios_base::in);
        if (InFile.is_open())
        {
            string Id, bookpid, fname, lname, tele, people, rate, timebooked, checkin, night, checkout;
            while (!InFile.eof())
            {
                InFile >> Id >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> checkin >> night >> checkout;
                if(bookpid == pid)
                {
                    for(int i = 0; i < daytime; i++)
                    {
                        if (date[i] == checkout)
                        {
                            b = 0;
                            room[roomcount][b] = Id;
                            b = 1;
                            room[roomcount][b] = bookpid;
                            b = 2;
                            room[roomcount][b] = fname;
                            b = 3;
                            room[roomcount][b] = lname;
                            b = 4;
                            room[roomcount][b] = tele;
                            b = 5;
                            room[roomcount][b] = people;
                            b = 6;
                            room[roomcount][b] = rate;
                            b = 7;
                            room[roomcount][b] = timebooked;
                            b = 8;
                            room[roomcount][b] = checkin;
                            b = 9;
                            room[roomcount][b] = night;
                            b = 10;
                            room[roomcount][b] = checkout;
                            roomcount = roomcount + 1;
                        }
                        else
                        {     
                            if (date[i] == checkin)
                            {
                                for (int j = 0; j < daytime; j++)
                                {
                                    if (date[j] == checkout)
                                    {
                                        j = 30;
                                    }
                                    if (j == 29)
                                    {
                                        b = 0;
                                        room[roomcount][b] = Id;
                                        b = 1;
                                        room[roomcount][b] = bookpid;
                                        b = 2;
                                        room[roomcount][b] = fname;
                                        b = 3;
                                        room[roomcount][b] = lname;
                                        b = 4;
                                        room[roomcount][b] = tele;
                                        b = 5;
                                        room[roomcount][b] = people;
                                        b = 6;
                                        room[roomcount][b] = rate;
                                        b = 7;
                                        room[roomcount][b] = timebooked;
                                        b = 8;
                                        room[roomcount][b] = checkin;
                                        b = 9;
                                        room[roomcount][b] = night;
                                        b = 10;
                                        room[roomcount][b] = checkout;
                                        roomcount = roomcount + 1;
                                        j = 30;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            InFile.close();
        }
        else
        {
            cout << endl << "File could not opened." << endl;
        }
    }
}
void book(string room, string pid, string fname, string lname, string telephone, string people, string ratestr, string date[], string night, string dateafter[], string Filename2)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int daytime = 31;
    string tempday = to_string(day);
    string tempmonth = to_string(month);
    string tempyear = to_string(year);
    string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
    ofstream OutFile(Filename2.c_str(), ios_base::app);
    if (OutFile.is_open())
    {
        OutFile << "\n";
        OutFile << room << " ";
        OutFile << pid << " ";
        OutFile << fname << " ";
        OutFile << lname << " ";
        OutFile << telephone << " ";
        OutFile << people << " ";
        OutFile << ratestr << " ";
        OutFile << tempdate << " ";
        OutFile << date[0] << " ";
        OutFile << night << " ";
        OutFile << dateafter[0];
    }
    else
    {
        cout << endl << "File could not opened." << endl;
    }
}
void countdisplaybookroom(string date[], string room[][11], string pid, int &roomcount, string Filename2)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int daytime = 30, b = 0;
    string tempday = to_string(day);
    string tempmonth = to_string(month);
    string tempyear = to_string(year);
    string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
    if (daytime > 0)
    {
        for (int i = 0; i < daytime; i++)
        {
            if( day==31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
            {
                day=0;
                month=month+1;
            }
            else if( day==30 && (month == 4 || month == 6 || month == 9 || month == 11))
            {
                day=0;
                month=month+1;
            }
            else if(month == 2)
            { 
                if ((year % 100) == 0)
                {
                    if ((year % 400) == 0 && (year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else 
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
                else 
                {
                    if ((year % 4) == 0) 
                    {
                        if(day==29)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                    else
                    {
                        if(day==28)
                        {
                            day=0;
                            month=month+1;
                        }
                    }
                }
            }
            else{
            }
            day = day + 1;
            if (month == 13)
            {
                day = 1;
                month = 1;
                year = year + 1;
            }
            string tempday = to_string(day);
            string tempmonth = to_string(month);
            string tempyear = to_string(year);
            string tempdate = tempday + "/" + tempmonth + "/" + tempyear;
            date[i] = tempdate;
        }
        ifstream InFile(Filename2.c_str(), ios_base::in);
        if (InFile.is_open())
        {
            string Id, bookpid, fname, lname, tele, people, rate, timebooked, checkin, night, checkout;
            while (!InFile.eof())
            {
                InFile >> Id >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> checkin >> night >> checkout;
                if(bookpid == pid)
                {
                    for(int i = 0; i < daytime; i++)
                    {
                        if (date[i] == checkout)
                        {
                            b = 0;
                            room[roomcount][b] = Id;
                            b = 1;
                            room[roomcount][b] = bookpid;
                            b = 2;
                            room[roomcount][b] = fname;
                            b = 3;
                            room[roomcount][b] = lname;
                            b = 4;
                            room[roomcount][b] = tele;
                            b = 5;
                            room[roomcount][b] = people;
                            b = 6;
                            room[roomcount][b] = rate;
                            b = 7;
                            room[roomcount][b] = timebooked;
                            b = 8;
                            room[roomcount][b] = checkin;
                            b = 9;
                            room[roomcount][b] = night;
                            b = 10;
                            room[roomcount][b] = checkout;
                            roomcount = roomcount + 1;
                        }
                        else
                        {     
                            if (date[i] == checkin)
                            {
                                for (int j = 0; j < daytime; j++)
                                {
                                    if (date[j] == checkout)
                                    {
                                        j = 30;
                                    }
                                    if (j == 29)
                                    {
                                        b = 0;
                                        room[roomcount][b] = Id;
                                        b = 1;
                                        room[roomcount][b] = bookpid;
                                        b = 2;
                                        room[roomcount][b] = fname;
                                        b = 3;
                                        room[roomcount][b] = lname;
                                        b = 4;
                                        room[roomcount][b] = tele;
                                        b = 5;
                                        room[roomcount][b] = people;
                                        b = 6;
                                        room[roomcount][b] = rate;
                                        b = 7;
                                        room[roomcount][b] = timebooked;
                                        b = 8;
                                        room[roomcount][b] = checkin;
                                        b = 9;
                                        room[roomcount][b] = night;
                                        b = 10;
                                        room[roomcount][b] = checkout;
                                        roomcount = roomcount + 1;
                                        j = 30;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            InFile.close();
        }
        else
        {
            cout << endl << "File could not opened." << endl;
        }
    }
}
void cancle(string arrayselect[], string Filename2)
{
    int amount = 0, a = 0, b;
    ifstream InFile(Filename2.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id, bookpid, fname, lname, tele, people, rate, timebooked, checkin, night, checkout;
        while (!InFile.eof())
        {
            InFile >> Id >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> checkin >> night >> checkout;
            amount = amount + 1;
        }
        InFile.close(); 
    }
    else
    {
        cout << endl << "File could not opened." << endl;
    }
    if (amount != 0)
    {
        string arraytemp[amount][11];
        ifstream InFile(Filename2.c_str(), ios_base::in);
        if (InFile.is_open())
        {
            string Id, bookpid, fname, lname, tele, people, rate, timebooked, checkin, night, checkout;
            while (!InFile.eof())
            {
                InFile >> Id >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> checkin >> night >> checkout;
                b = 0;
                arraytemp[a][b] = Id;
                b = b + 1;
                arraytemp[a][b] = bookpid;
                b = b + 1;
                arraytemp[a][b] = fname;
                b = b + 1;
                arraytemp[a][b] = lname;
                b = b + 1;
                arraytemp[a][b] = tele;
                b = b + 1;
                arraytemp[a][b] = people;
                b = b + 1;
                arraytemp[a][b] = rate;
                b = b + 1;
                arraytemp[a][b] = timebooked;
                b = b + 1;
                arraytemp[a][b] = checkin;
                b = b + 1;
                arraytemp[a][b] = night;
                b = b + 1;
                arraytemp[a][b] = checkout;
                a = a + 1;
            }
            InFile.close();
        }
        else
        {
            cout << endl << "File could not opened." << endl;
        }
        ofstream OutFile1(Filename2.c_str(), ios_base::out);
        OutFile1.close();
        ofstream OutFile(Filename2.c_str(), ios_base::out | ios_base::app);
        if (OutFile.is_open())
        {
            for ( a = 0; a < amount; a++)
            {
                if (arraytemp[a][0] == arrayselect[0] && arraytemp[a][1] == arrayselect[1] && arraytemp[a][7] == arrayselect[7] && arraytemp[a][8] == arrayselect[8] && arraytemp[a][10] == arrayselect[10])
                {

                }
                else
                {
                    if (a!=0)
                    {
                        if (a != amount)
                        {
                            OutFile << "\n";
                        }
                    }
                    for ( b = 0; b < 11; b++)
                    {  
                        OutFile << arraytemp[a][b];
                        if (b != 10)
                        {
                            OutFile << " ";
                        }
                    }
                }
            }
            OutFile.close();
            cout << endl << "Cancle your room complete" << endl;

        }
        else
        {
            cout << endl << "File could not opened." << endl;
        }
        char wait;
        cin.get(wait);
        cout << endl << "Press Enter to continue";
        cin.get(wait);
    }
}
int ratecal(int people, int night)
{
    int ratemul;
    if(people < 3)
    {
        ratemul = 300 * night;
        return ratemul;
    }
    if(people > 2)
    {
        people = people - 2;
        int mul = 50 * people;
        ratemul = mul + (300 * night);
        return ratemul;
    }
    else
    {
        return 0;
    }
}
