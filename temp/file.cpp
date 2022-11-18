#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;
int menu();
void case1(string Filename1);
void case2(string Filename1, string Filename009);
void case3(string Filename1);
void case4(string Filename1);
void time(int daytime, int &logicloop, int &dday, int &mmonth, int &yyear);
int ratecal(int ppl, int daystay);
int main()
{
    int reselect;
    const string Filename1 = "book.dat";
    const string Filename009 = "allbook.dat";
    ifstream InFile;
    ofstream OutFile;
    do
    {
        system("cls");
        reselect = menu();
        switch (reselect)
        {
        case 1 :
            case1(Filename1);
            break;
        case 2 :
            case2(Filename1, Filename009);
            break;
        case 3 :
            case3(Filename1);
            break;
        case 4 :
            case4(Filename1);
            break;
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
    cout << "Enter Select : ";
    cin >> select;
    cout << endl;
    return select;
}
void case1(string Filename1)
{
    ifstream InFile(Filename1.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id, status, bookpid, fname, lname, tele, people, rate, timebooked, timestay, timeend;
        int n = 0;
        cout << "=========================" << endl;
        cout << "|" << setw(16)<< "List Room" << setw(8) << "|" << endl;
        cout << "=========================" << endl;
        InFile >> Id >> status >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> timestay >> timeend;
        while (!InFile.eof())
        {
            n = n + 1;
            cout << "|" << setw(4) << n << " : ";
            cout << setw(3)<< Id << setw(4);
            cout << " : " << setw(6) << status << " |" << endl;
            InFile >> Id >> status >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> timestay >> timeend;
        }
        cout << "=========================" << endl;
        cout << endl << "Enter Number : ";
        InFile.close();
        char wait;
        cin.get(wait);
        cout << endl << "Press Enter to continue";
        cin.get(wait);
    }
    else
    {
        cout << "File could not opened." << endl;
    }
}
void case2(string Filename1, string Filename009)
{
    ifstream InFile(Filename1.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id, status, bookpid, fname, lname, tele, people, rate, timebooked, timestay, timeend;
        int n = 0, m = 0, x = 0, a, b, num, logic = 0;
        string arraystr[22];
        string arraykeep[22][13];
        int arraynum[22];
        cout << "=========================" << endl;
        cout << "|" << setw(16)<< "List Room" << setw(8) << "|" << endl;
        cout << "=========================" << endl;
        while (!InFile.eof())
        {
            InFile >> Id >> status >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> timestay >> timeend;
            x = x + 1;
            m = 1;
            arraykeep[x][m] = Id;
            m = m + 1;
            arraykeep[x][m] = status;
            m = m + 1;
            arraykeep[x][m] = bookpid;
            m = m + 1;
            arraykeep[x][m] = fname;
            m = m + 1;
            arraykeep[x][m] = lname;
            m = m + 1;
            arraykeep[x][m] = tele;
            m = m + 1;
            arraykeep[x][m] = people;
            m = m + 1;
            arraykeep[x][m] = rate;
            m = m + 1;
            arraykeep[x][m] = timebooked;
            m = m + 1;
            arraykeep[x][m] = timestay;
            m = m + 1;
            arraykeep[x][m] = timeend;
            if(status == "Empty")
            {
                n = n + 1;
                cout << "|" << setw(4) << n << " : ";
                cout << setw(3)<< Id << setw(4);
                cout << " : " << setw(6) << status << " |" << endl;
                arraystr[n] = Id;
                arraynum[n] = n;
                if(Id == "A1020")
                {
                    break;
                }
            }
        }
        cout << "=========================" << endl;
        InFile.close();
        cout << endl << "Add Book Room" << endl;
        cout << "Enter Number : ";
        cin >> num;
        for (int nn = 1; nn <= n; nn++)
        {
            if(num == arraynum[nn]){
                logic = 1;
                cout << endl << "Found " << arraystr[num] << endl;
                string arrayinput[13];
                arrayinput[1] = arraystr[num];
                arrayinput[2] = "Booked";
                int logicid;
                string temp;
                do
                {
                    logicid = 0;
                    cout << "Enter Person ID : ";
                    cin >> temp;
                    for (int xyz = 0; xyz < 22; xyz++)
                    {
                        if(arraykeep[xyz][3] == temp)
                        {
                            logicid = logicid + 1;
                        }
                    }
                    if (logicid > 1)
                    {
                        cout << "You Can't Book More 2 Room" << endl << endl;
                    }
                } while (logicid > 1);
                
                arrayinput[3] = temp;
                cout << "Enter First name : ";
                cin >> arrayinput[4];
                cout << "Enter Last name : ";
                cin >> arrayinput[5];
                cout << "Enter Telephone : ";
                cin >> arrayinput[6];
                cout << "Enter People : ";
                cin >> arrayinput[7];
                    time_t now = time(0);
                    tm *ltm = localtime(&now);
                    int year = 1900 + ltm->tm_year;
                    int month = 1 + ltm->tm_mon;
                    int day = ltm->tm_mday;
                    int maxday, inpdaytime;
                    int dd,mm,yy;
                    string todaybook = to_string(day) + "/" + to_string(month) + "/" + to_string(year) ;
                //cout << "Enter Time Booked : ";
                arrayinput[9] = todaybook;
                int logicloop = 0, daystay = 0, monthstay = 0;
                do
                {
                    cout << endl << "Now Day " << day << " Month " << month << " Year " << year << endl;
                    cout << "Enter Day Stay : ";
                    cin >> daystay;
                    cout << "Enter Month Stay : ";
                    cin >> monthstay;
                    yy=year;
                    if (daystay == day && monthstay == month)
                    {
                        cout << endl << "You Must Book Pre 1 Day" << endl;
                    }
                    else
                    {
                        time(inpdaytime,logicloop,daystay,monthstay,yy);
                    }
                } while (logicloop == 0);
                string staydaybook = to_string(daystay) + "/" + to_string(monthstay) + "/" + to_string(yy) ;

                arrayinput[10] = staydaybook;
                cout << "Enter Time End : ";
                cin >> inpdaytime;
                    logicloop = 2;
                    time(inpdaytime,logicloop,daystay,monthstay,yy);
                    string endbook = to_string(daystay) + "/" + to_string(monthstay) + "/" + to_string(yy) ;
                arrayinput[11] = endbook;

                int tempp = stoi(arrayinput[7]);
                int tempp1 = ratecal(tempp,inpdaytime);
                string tempp2 = to_string(tempp1);
                arrayinput[8] = tempp2;

                ofstream OutFile1(Filename1.c_str(), ios_base::out);
                OutFile1.close();
                ofstream OutFile(Filename1.c_str(), ios_base::out | ios_base::app);
                if (OutFile.is_open())
                {
                    for ( a = 1; a <= x; a++)
                    {
                        for ( b = 1; b <= m; b++)
                        {
                            if(arraykeep[a][1] == arraystr[num])
                            {
                                OutFile << arrayinput[b] << " ";
                            }
                            else
                            {
                                OutFile << arraykeep[a][b] << " ";
                            }
                        }
                        OutFile << "\n";
                    }
                }
                else
                {
                    cout << endl << "File could not opened." << endl;
                }
                OutFile.close();
                cout << endl << "Book Room Complete" << endl;

                ofstream OutFile2(Filename009.c_str(), ios_base::out | ios_base::app);
                if (OutFile2.is_open())
                {
                    for ( b = 1; b <= m; b++)
                    {
                        OutFile2 << arrayinput[b] << " ";
                    }
                    OutFile2 << "\n";
                }
                else
                {
                    cout << endl << "File could not opened." << endl;
                }
            }
            else
            {

            }
        }
        if(logic == 0)
        {
            cout << endl << "Not Found Room" << endl;
        }
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
void case3(string Filename1)
{
    string pid;
    cout << "Enter Your Person ID : ";
    cin >> pid;

    ifstream InFile(Filename1.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id, status, bookpid, fname, lname, tele, people, rate, timebooked, timestay, timeend;
        int n = 0;
        cout << endl << "List Room";
        cout << "  " << endl;
        InFile >> Id >> status >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> timestay >> timeend;
        while (!InFile.eof())
        {
            if(bookpid == pid)
            {
                n = n + 1;
                cout << n << " : ";
                cout << Id << " : " << status << " : " << bookpid << " : " << fname << " : " << lname << " : " << tele;
                cout << " : " << people << " : " << rate << " : " << timebooked << " : " << timestay << " : " << timeend << endl;
            }
            InFile >> Id >> status >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> timestay >> timeend;
        }
        if(n == 0)
        {
            cout << "No Found Your Book Room" << endl;
        }
        InFile.close();
    }
    else
    {
        cout << "File could not opened." << endl;
    }
    char wait;
    cin.get(wait);
    cout << endl << "Press Enter to continue";
    cin.get(wait);
}
void case4(string Filename1)
{
    ifstream InFile(Filename1.c_str(), ios_base::in);
    if (InFile.is_open())
    {
        string Id, status, bookpid, fname, lname, tele, people, rate, timebooked, timestay, timeend, inputlogic;
        int n = 0, m = 0, x = 0, a, b, num, logic = 0;
        string arraystr[22];
        string arraykeep[22][13];
        int arraynum[22];
        string pid;
        bool loop = true;
        do
        {
            cout << "Enter Your Person ID : ";
            cin >> pid;
            cout << endl << "List Room";
            cout << "  " << endl;
            while (!InFile.eof())
            {
                InFile >> Id >> status >> bookpid >> fname >> lname >> tele >> people >> rate >> timebooked >> timestay >> timeend;
                x = x + 1;
                m = 1;
                arraykeep[x][m] = Id;
                m = m + 1;
                arraykeep[x][m] = status;
                m = m + 1;
                arraykeep[x][m] = bookpid;
                m = m + 1;
                arraykeep[x][m] = fname;
                m = m + 1;
                arraykeep[x][m] = lname;
                m = m + 1;
                arraykeep[x][m] = tele;
                m = m + 1;
                arraykeep[x][m] = people;
                m = m + 1;
                arraykeep[x][m] = rate;
                m = m + 1;
                arraykeep[x][m] = timebooked;
                m = m + 1;
                arraykeep[x][m] = timestay;
                m = m + 1;
                arraykeep[x][m] = timeend;
                if(bookpid == pid)
                {
                    n = n + 1;
                    cout << n << " : ";
                    cout << Id << " : " << status << " : " << bookpid << " : " << fname << " : " << lname << " : " << tele;
                    cout << " : " << people << " : " << rate << " : " << timebooked << " : " << timestay << " : " << timeend << endl;
                    arraystr[n] = Id;
                    arraynum[n] = n;
                    loop = false;
                    logic = 1;
                }
            }
            if(logic == 0)
            {
                cout << "Not Found Your Book Room" << endl;
                char wait;
                cin.get(wait);
                cout << endl << "Press Enter to continue";
                cin.get(wait);
                main();
            }
        } while (loop);
        InFile.close();
        cout << endl << "Cancle Book Room" << endl;
        cout << "Enter Number : ";
        cin >> num;
        logic = 0;
        for (int nn = 1; nn <= n; nn++)
        {
            if(num == arraynum[nn]){
                cout << "Do You Want To Cancle? ( Y / N ) : ";
                cin >> inputlogic;
                if(inputlogic == "Y" || inputlogic == "y" || inputlogic == "yes" || inputlogic == "Yes" || inputlogic == "YES")
                {
                    logic = 1;
                    //cout << endl << "Found " << arraystr[num] << endl;
                    string arrayinput[12];
                    arrayinput[1] = arraystr[num];
                    arrayinput[2] = "Empty";
                    arrayinput[3] = "NULL";
                    arrayinput[4] = "NULL";
                    arrayinput[5] = "NULL";
                    arrayinput[6] = "NULL";
                    arrayinput[7] = "NULL";
                    arrayinput[8] = "NULL";
                    arrayinput[9] = "NULL";
                    arrayinput[10] = "NULL";
                    arrayinput[11] = "NULL";
                        ofstream OutFile1(Filename1.c_str(), ios_base::out);
                        OutFile1.close();
                        ofstream OutFile(Filename1.c_str(), ios_base::out | ios_base::app);
                        if (OutFile.is_open())
                        {
                            for ( a = 1; a <= x-1; a++)
                            {
                                for ( b = 1; b <= m; b++)
                                {
                                    if(arraykeep[a][1] == arraystr[num])
                                    {
                                        OutFile << arrayinput[b] << " ";
                                    }
                                    else
                                    {
                                        OutFile << arraykeep[a][b] << " ";
                                    }
                                }
                                OutFile << "\n";
                            }
                            OutFile.close();
                            cout << endl << "Cancle Your Room Complete" << endl;
                        }
                        else
                        {
                            cout << endl << "File could not opened." << endl;
                        }
                }
                else
                {
                    logic = 1;
                    cout << endl << "Cancle Your Room Failed" << endl;
                }
            }
            else
            {

            }
        }
        if(logic == 0)
        {
            cout << endl << "Not Found Your Book Room" << endl;
            char wait;
            cin.get(wait);
            cout << endl << "Press Enter to continue";
            cin.get(wait);
            main();
        }
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
void time(int daytime, int &logicloop, int &dday, int &mmonth, int &yyear)
{
    if (logicloop == 0)
    {
        daytime = 30;
    }
    // current date/time based on current system
    time_t now = time(0);
    // cout << "Number of sec since January 1,1970 is:: " << now << endl;
    tm *ltm = localtime(&now);
    // print various components of tm structure.
    int yearorigin = 1900 + ltm->tm_year;
    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int maxday;
    // cout << daytime << endl;
    // cout << daytime + 5 << endl;
    if (logicloop == 2)
    {
        day = dday;
        month = mmonth;
        year = yyear;
    }
    
    for (int i=0; daytime > i; i++)
    {
        if(logicloop == 0)
        {
            if (mmonth == month)
            {
                if (dday == day)
                {
                    logicloop = 1;
                }
            }
        }
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
        else
        {

        }
        day = day + 1;
        if (month == 13)
        {
            day = 1;
            month = 1;
            year = year + 1;
        }
        // cout << day << endl; //อย่าลืมปิดไม่งั้นคอมไฟแล่บ
    }
    cout << endl;
    //cout << "Function Next Day " << day << " Month " << month << " Year " << year << " " << endl;
    if (logicloop == 2)
    {
        dday = day;
        mmonth = month;
        yyear = year;
    }
}
int ratecal(int ppl, int daystay)
{
    int ratemul;
    if(ppl < 3)
    {
        ratemul = 300 * daystay;
        return ratemul;
    }
    if(ppl > 2)
    {
        ppl = ppl - 2;
        int mul = 50 * ppl;
        ratemul = mul + (300 * daystay);
        return ratemul;
    }
    else
    {
        return 0;
    }
}