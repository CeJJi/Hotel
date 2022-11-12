#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    // current date/time based on current system
    time_t now = time(0);

    // cout << "Number of sec since January 1,1970 is:: " << now << endl;

    tm *ltm = localtime(&now);

    // print various components of tm structure.

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int maxday, daytime, num_leap_year29 = 0,num_leap_year28 = 0;

    cout << "วันที่ปัจจุบัน " << day << " เดือน " << month << " ค.ศ. " << year << endl;
    cout << "*** ถ้าย้อนกลับไปอดีตให้กรอกลบนำหน้าตัวเลข ***"<<endl;
    cout << "*** ถ้าไปอนาคตให้กรอกตัวเลขจำนวนเเต็มบวก ***"<<endl;
    cout << "กรุณากรอกตัวเลข : ";
    cin >> daytime;
    // cout << daytime << endl;
    // cout << daytime + 5 << endl;

    if (daytime < 0) //เดินทางย้อนกลับ
    {

        for (daytime; daytime < 0; daytime++)
        {
            // 27/9/2002

            if (day == 1)
            {
                //ปี ค.ศ. ที่หารด้วย 4 ลงตัว แต่มีข้อยกเว้นว่าบางปีที่ลงท้ายด้วย 00 เช่น 400 800 1200 1600 2000 2400 จะต้องหาร 400 ลงตัวเดือนกุมภาปีนั้นจะมี 29 วัน
                if ((year % 100) == 0) //เช็คปีที่ลงท้ายด้วย 00
                {
                    if ((year % 400) == 0 && (year % 4) == 0) //หารด้วย 400 และ 4 ลงตัว กำหนดให้เดือนกุมภาปีนั้นมี 29 วัน
                    {
                        maxday = 29;
                    }
                    else //ถ้าต่างจากนั้นให้มี 28
                    {
                        maxday = 28;
                    }
                }
                else //เช็คปีที่ไม่ลงท้ายด้วย 00
                {
                    if ((year % 4) == 0) //หารด้วย 4 ลงตัว
                    {

                        maxday = 29;
                    }
                    else
                    {
                        maxday = 28;
                    }
                }
                month = month - 1;
                if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    day = day + 31;
                }
                else if (month == 4 || month == 6 || month == 9 || month == 11)
                {
                    day = day + 30;
                }
                else if (month == 2)
                {
                    if (maxday == 29)
                    {
                        num_leap_year29 = num_leap_year29 + 1;
                    }else if (maxday == 28)
                    {
                        num_leap_year28 = num_leap_year28 + 1;
                    }else{

                    }
                    

                    day = day + maxday;
                }
                else
                {
                }

                if (month == 0)
                {
                    day = 32;
                    month = 12;
                    year = year - 1;
                }
            }

            day = day - 1;
            // cout << day << endl; //อย่าลืมปิดไม่งั้นคอมไฟแล่บ
        }
        cout << endl;
        cout << "วันที่ย้อนไป คือ วันที่ " << day << " เดือน " << month << " ค.ศ. " << year << " " << endl;
        cout << "ผ่านเดือนกุมภาพันธ์ที่มี 28 วัน " << num_leap_year28 << " ครั้ง "<<endl;
        cout << "ผ่านเดือนกุมภาพันธ์ที่มี 29 วัน " << num_leap_year29 << " ครั้ง ";
    }
    if (daytime > 0) //เดินทางไปอนาคต
    {
        
            for (int i=0; daytime > i; i++)
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
                                num_leap_year29=num_leap_year29+1;
                                day=0;
                                month=month+1;
                            }
                        }
                        else 
                        {
                            if(day==28)
                            {
                                num_leap_year28=num_leap_year28+1;
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
                                num_leap_year29=num_leap_year29+1;
                                day=0;
                                month=month+1;
                            }
                        }
                        else
                        {
                            if(day==28)
                            {
                                num_leap_year28=num_leap_year28+1;
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
            
                // cout << day << endl; //อย่าลืมปิดไม่งั้นคอมไฟแล่บ
            }
            cout << endl;
            cout << "วันที่ไป คือ วันที่ " << day << " เดือน " << month << " ค.ศ. " << year << " " << endl;
            cout << "ผ่านเดือนกุมภาพันธ์ที่มี 29 วัน " << num_leap_year29 << " ครั้ง "<<endl;
            cout << "ผ่านเดือนกุมภาพันธ์ที่มี 28 วัน " << num_leap_year28 << " ครั้ง ";
    }

    return 0;
}