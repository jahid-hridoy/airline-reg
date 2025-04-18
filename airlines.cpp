#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<vector>
#include<algorithm>

using namespace std;

void login();
void reg();
void choose();
void main_choose();
void main_menu();
void flights();
void my_flights();
string take_pass();
string username;

int main()
{

    cout << '\n' << '\n';

    cout << "\t\t\t *******************************************\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t** \t\t   HOMEPAGE\t\t   **\n";
    cout << "\t\t\t**\t\t ===========\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**   1.  LOGIN\t\t\t\t   **\n";
    cout << "\t\t\t**   2.  REGISTER   \t\t\t   **\n";
    cout << "\t\t\t**   3.  EXIT \t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t *******************************************\n\n";

    choose();

    getch();
}

void choose()
{

again_choose:
    cout << "\t\t\t\t Please enter your choice :: ";

    char choice;
    cin >> choice;

    switch(choice)
    {

    case '1':
        system("cls");
        login();
        break;
    case '2':
        system("cls");
        cin.ignore();
        reg();
        break;
    case '3':
        cout << "\n\t\t\t\t       ### THANK YOU ###\n\n";
        getch();

    default:
        cout << "\n\t\t\t\t Invalid input!!\n\n";
        goto again_choose;
    }

}

void main_choose()
{
again_choose:
    cout << "\t\t\t\t Please enter your choice :: ";

    char choice;
    cin >> choice;

    switch(choice)
    {

    case '1':
        system("cls");
        flights();
        break;
    case '2':
        system("cls");
        my_flights();
        break;
    case '3':
        system("cls");
        main();
        break;

    default:
        cout << "\n\t\t\t\t Invalid input!!\n\n";
        goto again_choose;
    }

}

void login()
{
again_choose:
    string password;

    cout << '\n' << '\n';

    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t * \t\t  LOGIN!  \t       *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n";
    cout << "\n";
    cout << "\t\t\t   1. ENTER YOUR USERNAME :\n";
    cout << "\t\t\t      ";
    cin >> username;
    password = take_pass();

    ifstream in;
    in.open("security.txt");

    if(in.is_open())
    {

        string userID, pass;
        bool check = false;
        int cnt = 0;

        while(in.eof()==0)
        {
            in >> userID >> pass;
            if( (userID == username) && (pass == password))
            {
                check = true;
                break;
            }
        }

        in.close();

        if(check)
        {
            system("cls");
            cout << "\n\n\t\t\t\t  ** Login Successful!! **\n";
            main_menu();
        }
        else
        {
            system("cls");
            cout << "\n\n\t\t\t     ** Wrong Username or Password!! **\n";
            goto again_choose;
        }
    }
    else
    {
        system("cls");
        cout << "\n\n\t\t\t     ** Wrong Username or Password!! **\n";
        goto again_choose;
    }


}

void reg()
{

    string name, userID, password, address, Number, Gender, ig;

    cout << '\n' << '\n';

    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t *\t       REGISTRATION!           *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t   1. ENTER YOUR NAME :  \n";
    cout << "\t\t\t      ";
    getline(cin, name);
    cout << "\t\t\t   2. ENTER YOUR ADDRESS : \n";
    cout << "\t\t\t      ";
    getline(cin, address);
    cout << "\t\t\t   3. ENTER YOUR CONTACT NUMBER :   \n";
    cout << "\t\t\t      ";
    getline(cin, Number);
    cout << "\t\t\t   4. ENTER YOUR GENDER :   \n";
    cout << "\t\t\t      ";
    getline(cin, Gender);
again:
    cout << "\t\t\t   5. ENTER YOUR USERNAME :   \n";
    cout << "\t\t\t      ";
    cin >> userID;
    cout << "\t\t\t   6. ENTER YOUR PASSWORD :  \n";
    cout << "\t\t\t      ";
    cin >> password;

    bool  checker = false;

    ifstream in;
    in.open("security.txt");

    if(in.is_open())
    {
        string id_check, pass_check;
        while(in.eof()==0)
        {
            in >> id_check >> pass_check;
            if(userID == id_check)
            {
                checker = true;
                break;
            }
        }
        in.close();
    }

    if(checker)
    {
        cout << "\n\n\t\t\t         ** This username has already been used!! **\n\n";
        goto again;

    }

    ofstream out;
    out.open("info.txt", ios::out | ios::app);

    out << "@Username-" + userID << '\n';
    out << name << '\n';
    out << address << '\n';
    out << Number << '\n';
    out << Gender << '\n';
    out << "###" << '\n';

    out.close();

    ofstream put;
    put.open("security.txt", ios::out | ios::app);
    put << userID << ' ' << password << '\n';

    put.close();

    char x;

    cout << "\n\n\t\t\t  ** Registration Successful!! **";
    cout << "\n\t\t\t  Go to Home page?";
    cout << "\n\t\t\t  Press 1 to proceed, others for exit";
    cout << "\n\t\t\t  :: ";
    cin >> x;

    if(x=='1')
    {
        system("cls");
        main();
    }
    else
    {
        cout << "\n\t\t\t\t      ### THANK YOU ### ";
    }

}

string take_pass()
{

    cout << "\t\t\t   2. ENTER YOUR PASSWORD :   \t\t\t   \n";
    cout << "\t\t\t      ";

    string TakenPass;

    while(true)
    {
        char ch;
        ch = getch();
        if(ch<32)
        {
            return TakenPass;
        }
        cout << "*";
        TakenPass.push_back(ch);
    }

}

void main_menu()
{

    cout << '\n' << '\n';

    cout << "\t\t\t *******************************************\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t** \t\t  Main Menu\t\t   **\n";
    cout << "\t\t\t**\t\t ===========\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**   1. TICKET COUNTER \t\t           **\n";
    cout << "\t\t\t**   2. MY FLIGHTS & TICKETS  \t\t   **\n";
    cout << "\t\t\t**   3. LOGOUT \t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t**\t\t\t\t\t   **\n";
    cout << "\t\t\t *******************************************\n\n";

    main_choose();

}

void flights()
{
    cout << '\n' << '\n';
    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t *\t         Airlines              *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n\n";

    int choice, choice1;
    string get;
    string flightN[]= {"Bangladesh", "Dubai", "UK", "USA"};
    for(int a=0; a<4; a++)
    {
        cout << "\t\t\t    " << (a+1)<<".Flight to "<<flightN[a]<<"\n";
    }

    cout << "\n\t\t\t Press the number of the country of which\n\t\t\t you want to book the flight:: ";
    cin >> choice;
    switch(choice)
    {
    case 1:
    {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t Welcome to Bangladesh Airlines!      *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        cout<<"\n\t\t\t 1. Bang - 478"<<"\n";
        cout<<"\t\t\t \t08-04-2022 8:00AM 10hrs Tk. 20000"<<"\n";
        cout<<"\n\t\t\t 2. Bang - 563"<<"\n";
        cout<<"\t\t\t \t09-04-2022 4:00AM 12hrs Tk. 15000"<<"\n";
        cout<<"\n\t\t\t 3. Bang - 944"<<"\n";
        cout<<"\t\t\t \t11-04-2022 11:00AM 11hrs Tk. 17000"<<"\n";

        cout<<"\n\t\t\t Select the flight you want to book : ";

        cin>>choice1;

        if(choice1==1)
        {
            long long charges;
            charges = 20000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("bang478.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("bang478.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan:

            cout << "\n\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight Bang - 478.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("bang478.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "Bang - 478" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();
            }
        }

        else if(choice1==2)
        {
            long long charges;
            charges = 15000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("bang563.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("bang563.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan2:

            cout << "\n\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan2;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan2;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan2;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan2;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight Bang - 563.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("bang563.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "Bang - 563" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();

            }
        }
        else if(choice1==3)
        {
            long long charges;
            charges = 40000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("bang944.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("bang944.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan3:

            cout << "\n\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan3;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan3;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan3;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan3;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight Bang - 944.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("bang944.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "Bang - 944" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();
            }
        }
        else
        {
            cout<<"\n\t\t\t Invalid input, shifting to the previous menu \n";
            system("cls");
            flights();
        }

        cout << "\t\t\t Press any key to go back to main menu: ";
        cout << "\n\t\t\t :: ";
        cin >> get;

        if(get=="1")
        {
            system("cls");
            main_menu();
        }
        else
        {
            system("cls");
            main_menu();
        }
        break;
    }
    case 2:
    {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t Welcome to Dubai Airlines!           *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        cout<<"\n\t\t\t 1. DUB - 878"<<"\n";
        cout<<"\t\t\t \t09-04-2022 2:00PM 20hrs Tk. 340000"<<"\n";
        cout<<"\n\t\t\t 2. DUB - 533"<<"\n";
        cout<<"\t\t\t \t11-01-2022 6:00AM 23hrs Tk. 29000"<<"\n";
        cout<<"\n\t\t\t 3. DUB - 345"<<"\n";
        cout<<"\t\t\t \t14-01-2022 12:00AM 21hrs Tk. 40000"<<"\n";

        cout<<"\n\t\t\t Select the flight you want to book : ";

        cin>>choice1;

        if(choice1==1)
        {
            long long charges;
            charges = 340000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("dub878.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("dub878.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan4:

            cout << "\n\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan4;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan4;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan4;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan4;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight DUB - 878.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("dub878.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

               ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "DUB - 878" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();
            }
        }

        else if(choice1==2)
        {
            long long charges;
            charges = 29000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("dub533.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("dub533.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan5:

            cout << "\n\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan5;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan5;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan5;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan5;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight DUB - 533.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("dub533.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "DUB - 533" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();
            }
        }
        else if(choice1==3)
        {
            long long charges;
            charges = 17000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("dub345.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("bang345.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan6:

            cout << "\n\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan6;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan6;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan6;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan6;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight DUB - 345.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("dub345.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "DUB - 345" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();

            }
        }
        else
        {
            cout<<"\n\t\t\t Invalid input, shifting to the previous menu \n";
            system("cls");
            flights();
        }

        cout << "\t Press any key to go back to main menu: ";
        cout << "\n\t\t\t :: ";
        cin >> get;

        if(get=="1")
        {
            system("cls");
            main_menu();
        }
        else
        {
            system("cls");
            main_menu();
        }
        break;
    }
    case 3:
    {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t   Welcome to UK Airlines!            *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        cout<<"\n\t\t\t 1. UK - 797"<<"\n";
        cout<<"\t\t\t \t12-01-2022 10:00PM 14hrs Tk. 440000"<<"\n";

        cout<<"\n\t\t\t Select the flight you want to book : ";

        cin>>choice1;

        if(choice1==1)
        {
            long long charges;
            charges = 440000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("uk797.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("uk797.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan7:

            cout << "\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan7;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan7;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan7;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan7;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight UK - 797.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("uk797.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "UK - 797" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();

            }
        }
        else
        {
            cout<<"\n\t\t\t Invalid input, shifting to the previous menu \n";
            system("cls");
            flights();
        }

        cout << "\t Press any key to go back to main menu: ";
        cout << "\n\t\t\t :: ";
        cin >> get;

        if(get=="1")
        {
            system("cls");
            main_menu();
        }
        else
        {
            system("cls");
            main_menu();
        }
        break;
    }
    case 4:
    {
        system("cls");
        cout << '\n' << '\n';
        cout << "\t\t\t **********************************************\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t *\t    Welcome to US Airlines!           *\n";
        cout << "\t\t\t *\t\t\t\t              *\n";
        cout << "\t\t\t **********************************************\n\n";
        cout<<"\n\t\t\t Your comofort is our priority. Enjoy the journey!"<<"\n";
        cout<<"\t\t\t Following are the flights : \n"<<"\n";

        cout<<"\n\t\t\t 1. US - 565"<<"\n";
        cout<<"\t\t\t \t10-01-2022 9:00PM 22hrs Tk. 370000"<<"\n";
        cout<<"\n\t\t\t 2. US - 536"<<"\n";
        cout<<"\t\t\t \t09-01-2022 6:00AM 22hrs Tk. 39000"<<"\n";
        cout<<"\n\t\t\t 3. US- 654"<<"\n";
        cout<<"\t\t\t \t12-01-2022 10:00AM 21hrs Tk. 42000"<<"\n";

        cout<<"\n\t\t\t Select the flight you want to book : ";

        cin>>choice1;

        if(choice1==1)
        {
            long long charges;
            charges = 370000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("us565.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("us565.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan8:

            cout << "\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan8;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan8;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan8;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan8;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight US - 565.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("us565.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "US - 565" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();
            }
        }

        else if(choice1==2)
        {
            long long charges;
            charges = 39000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("us536.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("us536.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan9:

            cout << "\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan9;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan9;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan9;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan9;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight US - 536.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("us536.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "US - 536" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();
            }
        }
        else if(choice1==3)
        {
            long long charges;
            charges = 42000;

            cout<<"\n\t\t\t Available Seats :: \n\n";

            ifstream in;
            in.open("us654.txt");

            int seat[10][4];

            if(in.is_open())
            {


                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        in >> seat[i][j];

                        if(seat[i][j])
                        {
                            cout << (i+1) << (char) ('A'+j) ;
                            if(i<9)cout << "   ";
                            else cout << "  ";
                        }
                        else
                        {
                            cout << "N/A  ";
                        }
                    }
                    cout << '\n';
                }

                in.close();
            }
            else
            {

                ofstream out;
                out.open("us654.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {
                        seat[i][j] = 1;
                        out << 1 << ' ';

                        cout << (i+1) << (char)('A'+j);
                        if(i<9)cout << "   ";
                        else cout << "  ";
                    }
                    out << '\n';
                    cout << '\n';
                }
                out.close();
            }

            string seat_num;

seat_plan10:

            cout << "\n\t\t\t Enter your seat number : ";

            cin >> seat_num;

            if(seat_num.size()==3)
            {
                if(seat_num != "10A" && seat_num != "10B" && seat_num != "10C" && seat_num != "10D")
                {
                    cout << "\n\t\t\t Wrong input!\n";
                    goto seat_plan10;
                }
            }

            else if(seat_num.size()!=2)
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan10;
            }

            int digit;
            if(seat_num.size()==3)
            {
                digit = 9;
            }
            else
            {
                digit = seat_num[0] - '0' - 1;
            }
            int ch = seat_num.back() - 'A';

            if(!(digit >= 0 && digit <= 9) || !(ch <= 3 && ch >= 0))
            {
                cout << "\n\t\t\t Wrong input!\n";
                goto seat_plan10;
            }
            else if(seat[digit][ch]==0)
            {
                cout << "\n\t\t\t This seat is already booked, Please select another one!!\n";
                goto seat_plan10;
            }
            else
            {

                cout << "\n\t\t\t Congratulation! You have successfully";
                cout << "\n\t\t\t booked the flight US - 654.";
                cout << "\n\t\t\t You can go back to menu and take the ticket.";

                seat[digit][ch] = 0 ;

                ofstream out;
                out.open("us654.txt");

                for(int i=0; i<10; i++)
                {
                    cout << "\t\t\t ";
                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();

                ofstream newout;
                newout.open("seats.txt", ios::out | ios::app);

                newout << "@Username-"+username << '\n';;
                newout << seat_num << '\n';
                newout << "US - 654" << '\n';
                newout << "08-04-2022" << '\n';
                newout << "8:00 AM" << '\n';
                newout << charges << '\n';
                newout << "###" << '\n';

                newout.close();

            }
        }
        else
        {
            cout<<"\n\n\t\t\t Invalid input, shifting to the previous menu \n";
            system("cls");
            flights();
        }

        cout << "\t Press any key to go back to main menu: ";
        cout << "\n\t\t\t :: ";
        cin >> get;

        if(get=="1")
        {
            system("cls");
            main_menu();
        }
        else
        {
            system("cls");
            main_menu();
        }
        break;
    }

    }
}

void my_flights(){

    cout << '\n' << '\n';
    cout << "\t\t\t ***************************************\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t *\t      Your Tickets             *\n";
    cout << "\t\t\t *\t\t\t\t       *\n";
    cout << "\t\t\t ***************************************\n\n";

    string NAME, ADDRESS, PHONE, GENDER, ss;
    string current_user = "@Username-"+username;

    ifstream in;
    in.open("info.txt");

    while(in.eof()==0){
        in >> ss;
        if(ss==current_user){
            getline(in, NAME);
            getline(in, NAME);
            getline(in, ADDRESS);
            getline(in, PHONE);
            getline(in, GENDER);
            break;
        }
    }

    in.close();

    cout << "\t\t\t\t      :: Profile :: ";
    cout << "\n\n\t\t\t    Name: " << NAME << '\n';
    cout << "\t\t\t    Address: " << ADDRESS << '\n';
    cout << "\t\t\t    Phone: " << PHONE << '\n';
    cout << "\t\t\t    Gender: " << GENDER << '\n' << '\n';

    string temp;
    vector<string>userID;
    vector<string>seat_no;
    vector<string>plane_name;
    vector<string>Date;
    vector<string>Time;
    vector<string>cost;

    int cnt = 0;

    in.open("seats.txt");

    while(true){
        in >> temp;
        if(in.eof())break;
        if(temp==current_user){
            cnt++;
        }
            string inf;
            userID.push_back(temp);
            getline(in, inf);

            getline(in, inf);
            seat_no.push_back(inf);

            getline(in, inf);
            plane_name.push_back(inf);

            getline(in, inf);
            Date.push_back(inf);

            getline(in, inf);
            Time.push_back(inf);

            getline(in, inf);
            cost.push_back(inf);

            getline(in, inf);
    }
    in.close();

    if(cnt==0){
        string s;
        cout << "\t\t\t No Booking Tickets!\n\n";
        cout << "\t\t\t Press 1 to go to main menu, others for exit.";
        cout << "\n\t\t\t :: ";
        cin >> s;
        if(s=="1"){
            system("cls");
            main_menu();
        }
        else{
            cout << "\t\t\t\t  ***Thank You***\n";
            getch();
        }
    }

    int num = 1;

    vector<int>ticket_count;

    for(int i=0; num<=cnt; i++){
            if(userID[i]==current_user){
                ticket_count.push_back(i);
                cout <<"\t\t\t #Ticket: " << num << '\n';
                cout << "\t\t\t Flight : " << plane_name[i] << '\n';
                cout << "\t\t\t Seat No: " << seat_no[i] << '\n';
                cout << "\t\t\t Date: " << Date[i] << '\n';
                cout <<  "\t\t\t Time: " << Time[i] << '\n';
                cout << "\t\t\t Charge: " << cost[i] << '\n' << '\n';
                num++;
            }
    }

    cout << '\n';

    string x;
    cout << "\t\t\tDo you want to cancel any flight? You will get only 60% return\n";
    cout << "\t\t\tIf yes, press 1, others to print tickets\n";
    cout << "\t\t\t::";
    cin >> x;

    if(x=="1"){
        tick:
        int tickets;
        cout << "\n\t\t\tEnter the Tickets No.: ";
        cin >> tickets;

        if(!(tickets<=cnt && tickets >= 1)){
            cout << "\n\t\t\tInvalid input!";
            goto tick;
        }

        string st = seat_no[ticket_count[tickets-1]];
        string fly = plane_name[ticket_count[tickets-1]];

        if(fly.front()=='B' && fly.back()=='8'){

                ifstream in;
                in.open("bang478.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("bang478.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='B' && fly.back()=='3'){
                ifstream in;
                in.open("bang563.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("bang563.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='B' && fly.back()=='4'){
                ifstream in;
                in.open("bang944.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("bang944.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='D' && fly.back()=='8'){
                ifstream in;
                in.open("dub878.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("dub878.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='D' && fly.back()=='3'){
                ifstream in;
                in.open("dub533.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("dub533.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='D' && fly.back()=='5'){
                ifstream in;
                in.open("dub345.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("dub345.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='U' && fly.back()=='7'){
                    ifstream in;
                in.open("uk797.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("uk797.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='U' && fly.back()=='5'){
                ifstream in;
                in.open("us565.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("us565.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='U' && fly.back()=='6'){
                ifstream in;
                in.open("us536.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("us536.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }
        else if(fly.front()=='U' && fly.back()=='4'){
                ifstream in;
                in.open("us654.txt");

                int seat[10][4];

                    for(int i=0; i<10; i++)
                    {
                        for(int j=0; j<4; j++)
                        {
                            in >> seat[i][j];

                        }
                    }

                    in.close();

                int digit;
                if(st.size()==3)
                {
                    digit = 9;
                }
                else
                {
                    digit = st[0] - '0' - 1;
                }
                int ch = st.back() - 'A';

                seat[digit][ch] = 1 ;

                ofstream out;
                out.open("us654.txt");

                for(int i=0; i<10; i++)
                {

                    for(int j=0; j<4; j++)
                    {

                        out << seat[i][j] << ' ';

                    }
                    out << '\n';

                }
                out.close();
        }

        ofstream out;
        out.open("seats.txt");

        int i = 0;

        while(i<userID.size()){
            if(i==ticket_count[tickets-1]){
                i++;
                continue;
            }

            out << userID[i] << '\n';
            out << seat_no[i] << '\n';
            out << plane_name[i] << '\n';
            out << Date[i] << '\n';
            out << Time[i] << '\n';
            out << cost[i] << '\n';
            out << "###" << '\n';
            i++;
        }

        out.close();

        cout << "\t\t\tYou will get your refund soon...\n";
        cout << "\t\t\tPress 1 to go to main menu, others for exit.\n\n";
        cout << "\t\t\t:::";
        cin >> x;
        if(x=="1"){
            system("cls");
            main_menu();
        }
        else{
           cout << "\n\t\t\t***Happy Flying!***" << '\n';
           getch();
        }
        getch();

    }
    else{
        cout << "\n\t\t\t***Happy Flying!***" << '\n';
        exit(0);
    }



}
