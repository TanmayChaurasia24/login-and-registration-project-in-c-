#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

using namespace std;

void registration();
void forgot();
void login();

int main()
{
    int c;

    cout << "\t\t\t_____________________________________________________________\n\n\n";
    cout << "\t\t\t                Welcome To The Login Page                     \n\n\n";
    cout << "\t\t\t___________________       MENU      ___________________________\n\n\n";

    cout<<"\t| press 1 to login                                        |" << endl;
    cout<<"\t| press 2 to register                                     |" << endl;
    cout<<"\t| press 3 if you forgot your password                     |" << endl;
    cout<<"\t| press 4 to EXIT                                         |" << endl;
    cout << endl;

    cout << "\tPlease Enter Your choice: ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            login();
            break;

        case 2:
            registration();
            break;

        case 3:
            forgot();
            break;

        case 4:
            cout<<"\t\t\t______________      THANK YOU        _________________"<<endl;
            break;

        default:
            system("cls");
            cout << "\t\t\t Please Enter the right choice, select from the options given above" << endl;
            main();
    }
}

void login()
{
    int count;
    string userid,password,id,pas;
    system("cls");
    cout<<"\t\t\tplease enter the username and password"<<endl;
    cout << "\t\t\tusername: ";
    cin >> userid;
    cout << endl;

    cout << "\t\t\tpassword: ";
    cin>>password;
    cout << endl;

    ifstream input("record.txt");

    while(input>>id>>pas)
    {
        if(id == userid && pas == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if(count == 1)
    {
         cout << "\t\t\t" << userid <<endl;
        cout << "\t\t\t______________You Have Sucessfully login_______________"<<endl<<endl;
        main();
    }
    else{
        cout << "\t\t\t______________please register first or please check your password or username______________"<<endl<<endl;
    }
}

void registration()
{
    string ruserid,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Please Enter the username: ";
    cin>>ruserid;
    cout<<endl;
    cout<<"\t\t\t Please enter the password: ";
    cin>>rpassword;
    cout<<endl;

    ofstream f1("record.txt", ios::app);
    f1<<ruserid<<' '<<rpassword<<endl;
    system("cls");

    cout<<"\n\t\t\t Registration is sucessfull "<<endl;
    main();
}

void forgot()
{
    int option;
    cout<<"\t\t\t You forgot your password, No Worries "<<endl;
    cout << "\t\t\tEnter 1 to search your id by your username "<<endl;
    cout<<"\t\t\tenter 2 to return back to main menu " << endl;
    cout<<endl;
    cout<<"\t\t\t Enter you choice " << endl;
    cin>>option;

    switch(option)
    {
        case 1: {
            int count = 0;
            string suserid,sid,spass;
            cout<<"\t\t\t enter the username for which you want the password: "<<endl;
            cin>>suserid;

            ifstream f2("record.txt");

            while(f2>>sid>>spass)
            {
                if(sid == suserid)
                {
                    count = 1;
                }
            }

            if(count == 1)
            {
                cout << "\t\t\t Yout account is there, dont worry i will tell you the password: " << endl;
                cout<<"\t\t\t your password is: " << spass << endl;
                main();
            }
            else{
                cout << "\t\t\t sorry your account has been not found " << endl;
            }

            break;
        }

        case 2:
            main();
        

        default:
        {
             cout << "\t\t\t please enter the correct option from the options given above " << endl;
             forgot();
        }
           

    }

}































