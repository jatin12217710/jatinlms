#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

#define FILE "lms.txt"

namespace variables
{
    std::ofstream fout;
    std::ifstream fin;

    vector<string> name_books;
    vector<int> quantity_books;

    vector<string> names_student={"Vanshraj","Likita","Gagan","Harsh","Satyam"};
    vector<int> reg_no_students={12217,12210,12218,12219,12220};
    vector<int> no_issue_books_students={2,5,1,4,3};

class LMS
{
    public:
    void main_fucn()
    {
    int n;
    cout<<"Enter 1 for Librarian and 2 for User : ";
    cin>>n;
    switch(n)
    {
    case 1:
        {
            static string pass_librarian="librarian1";
            string pass_entered;
            cout<<endl<<"         LIBRARIAN selected...  "<<endl<<endl;
            cout<<"    ENTER PASSWORD : ";

            case1(pass_entered,pass_librarian);

            break;
        }

    case 2:
        {
            char user_choice;
            cout<<endl<<"        USER selected... "<<endl;
            cout<<endl<<"    AVAILABLE STOCK..... "<<endl;
            print_stock();
            cout<<endl<<" A -- Only Issue & B -- only Return "<<endl;

            case2(user_choice);

            break;
        }
    default:
        cout<<endl<<"* WRONG INPUT *"<<" Please select only 1(one) or 2(two)..."<<endl<<endl;
        main_fucn();

        break;
    }
}

void case1(string pass_entered,string pass_librarian)
{
     cin>>pass_entered;
            if(pass_entered=="0"){
                    cout<<endl<<"BACK TO MAIN MENU..."<<endl;
                    main_fucn();
                }
            if(pass_entered==pass_librarian)
            {
                cout<<endl<<"Hello Librarian welcome to LMS..."<<endl;
                librarian();
            }
            else
            {
                cout<<"  ** Entered wrong password ** "<<endl<<endl<<"Enter again OR to go back press 0 : ";
                case1(pass_entered,pass_librarian);
            }
}

void case2(char user_choice)
{
            cout<<" Enter choice : ";
            cin>>user_choice;
            if(user_choice=='0'){
                    cout<<endl<<"BACK TO MAIN MENU..."<<endl;
                    main_fucn();
                }
            if(user_choice=='A')
            {
                cout<<endl<<" USER SELECTED -- A"<<endl;
                User_A();
            }
            else if(user_choice=='B')
            {
                cout<<endl<<" USER SELECTED -- B"<<endl;
                User_B();
            }
            else
            {
                cout<<endl<<"* WRONG CHOICE * Choose only A or B and 0 to go back "<<endl;
                case2(user_choice);
            }
}

void librarian()
{


    int lib_choice;
    cout<<endl<<" -- Available Options are -- "<<endl;
    cout<<"      Add Book  -- press 1 "<<endl;
    cout<<"    Remove Book -- press 2 "<<endl;
    cout<<"    Modify Book -- press 3 "<<endl;
    cout<<"  -------- ---- ---- --------"<<endl;
    cout<<" Enter choice : ";
    cin>>lib_choice;
    cout<<endl;
    if(lib_choice==0)
    {
        main_fucn();

    }
    else
    {
    switch(lib_choice)
    {
    case 1:
        {
            int v;
            cout<<endl<<" Here you can Add Book "<<endl;
            Add_book(name_books , quantity_books);
            cout<<endl<<"Want to do more functions(press 1) for Main menu(0) and to end press(-1) : ";
            cin>>v;
            switch(v)
            {
        case 1:{
            librarian();
            break;
            }
        case 0:{
            main_fucn();
            break;
            }
        case -1:{
            write_file();
            break;
            }
        default:
            {
            main_fucn();
            break;
            }
            }
            break;
        }
    case 2:
        {
            int v;
            cout<<endl<<" Here you can Remove Book "<<endl;
            Remove_book(name_books,quantity_books);
            cout<<endl<<"Want to do more functions(press 1) for Main menu(0) and to end press(-1) : ";
            cin>>v;
            switch(v)
            {
        case 1:{
            librarian();
            break;
            }
        case 0:{
            main_fucn();
            break;
            }
        case -1:{
            write_file();
            break;
            }
        default:
            {
            main_fucn();
            break;
            }
            }
            break;
        }
    case 3:
        {
            int v;
            cout<<endl<<" Here you can Modify Book "<<endl;
            Modify_book(name_books,quantity_books);
            cout<<endl<<"Want to do more functions(press 1) for Main menu(0) and to end press(-1) : ";
            cin>>v;
            switch(v)
            {
        case 1:{
            librarian();
            break;
            }
        case 0:{
            main_fucn();
            break;
            }
        case -1:{
            write_file();
            break;
            }
        default:
            {
            main_fucn();
            break;
            }
            }
            break;
        }
    default:
        {
            cout<<endl<<"* Wrong Choice * Enter again... OR press 0 for Main menu "<<endl<<endl;
            librarian();
            break;
        }
    }}
}

void User_A()
{
    static string user_A_pass="user1";
    string user_A_entry;
    cout<<endl<<"  Enter passWord for User 'A' : ";
    cin>>user_A_entry;


    if(user_A_entry==user_A_pass)
    {
        int ch;
        cout<<endl<<"  Welcome USER -- 'A' to LMS...."<<endl<<endl;
        cout<<" You can Issue Books for Students "<<endl;
        cout<<" Enter 1 -- (Issue Books) and 2 -- (Registered Students Details) or 3 -- (Register any Student) default -- (Main menu)(0) :";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                user_A_issue();
                break;
            }
        case 2:
            {
                registered_students();
                User_A();
                break;
            }
        case 3:
            {
                student_registration();
                break;
            }
        default:
            {
                main_fucn();
                break;
            }
        }

    }
    else
    {
        cout<<endl<<"* Entered Wrong Password * please enter again..."<<endl<<endl;
        User_A();
    }
}

void user_A_issue()
{
    int reg_no;
    cout<<"Enter Registration Number of a student : ";
    cin>>reg_no;

    bool fl=true;
    for(int i=0;i<reg_no_students.size();i++)
    {
        if(reg_no==reg_no_students[i])
        {
            fl=false;
            print_stu_details(i);
            issue_main(i);
            break;
        }
    }
    if(fl)
    {
        int ch;
        cout<<"There is no student registered with this -- "<<reg_no<<endl;
        cout<<"To register press(1) and for main menu(0) : ";
        cin>>ch;
        if(ch==1) student_registration();
        else if(ch==0) main_fucn();
        else User_A();
    }

}
 void issue_main(int index)
 {
     string name;
     int number;
     cout<<endl<<"    AVAILABLE STOCK..... "<<endl;
     print_stock();
     cout<<endl<<"Enter Name and Quantity of books want to issue from ABOVE AVAILABLE STOCK "<<endl;
     cin>>name>>number;
     bool fl=true;
     for(int i=0;i<name_books.size();i++)
     {
         if(name==name_books[i]&&number<=quantity_books[i])
         {
             quantity_books[i]=quantity_books[i]-number;
             cout<<"Successfully added "<<number<<" books of "<<name<<" are issued on the student.."<<endl;
             no_issue_books_students[index]=no_issue_books_students[index]+number;
             print_stu_details(index);
             cout<<endl;
             fl=false;
             cout<<"Updated stock is ..."<<endl;
             print_stock();

             if(quantity_books[i]==0)
             {
                 cout<<endl<<" **** "<<name<<" book is out of stock ****"<<endl;
                 name_books.erase(name_books.begin()+i);
                 quantity_books.erase(quantity_books.begin()+i);
                 cout<<"Updated stock is ..."<<endl;
                 print_stock();
             }
             break;
         }
         if(name_books[i]==name&&number>quantity_books[i])
         {
             cout<<number<<" books of "<<name<<" is not Available in stock.."<<endl;
             fl=false;
             break;
         }
     }
     if(fl)
     {
         cout<<"Entered book name is not Available in our stock please Enter carefully after seeing Available Stock.."<<endl;
         issue_main(index);
     }
     int choice;
     cout<<"Want to Issue more books press(1) or 2 -- (User A), and 3 -- (Registered Students Details) and default or 0(main menu) and to end press(-1): ";
     cin>>choice;
     switch(choice)
    {
    case 1:{
        issue_main(index);
        break;}
    case 2:{
        User_A();
        break;
        }
    case 3:{
        registered_students();
        break;
        }
    case 0:{
        main_fucn();
        break;
        }
    case -1:{
        write_file();
        break;
        }
    default:
        {
            main_fucn();
            break;
        }
    }

 }

void print_stu_details(int i)
{

    cout<<"              USER DETAILS "<<endl;
    cout<<"             --------------"<<endl;
    cout<<"  REGISTRATION NO.   -- "<<reg_no_students[i]<<endl;
    cout<<"   NAME OF STUDENT   -- "<<names_student[i]<<endl;
    cout<<" NO. OF BOOKS ISSUED -- "<<no_issue_books_students[i]<<endl;
}

void registered_students()
{
    cout<<endl<<" Here is the Details of Registered Students ...."<<endl<<endl;
    cout<<" REG: NO.    BOOKS ISSUED    STU: NAME "<<endl;
    cout<<"----------  --------------  -----------"<<endl;
    for(int i=0;i<names_student.size();i++)
    {
        cout<<"  "<<reg_no_students[i]<<"            "<<no_issue_books_students[i]<<"          "<<names_student[i]<<endl;
    }
}

void student_registration()
{
    cout<<"   ENTER DETAILS OF STUDENT  "<<endl;
    cout<<"  -------------------------- "<<endl;

    int r_no;
    cout<<"  REGISTRATION NO.   -- ";
    cin>>r_no;
    reg_no_students.push_back(r_no);

    string name;
    cout<<"   NAME OF STUDENT   -- ";
    cin>>name;
    names_student.push_back(name);

    int no_books;
    cout<<" NO. OF BOOKS ISSUED -- ";
    cin>>no_books;
    no_issue_books_students.push_back(no_books);

    cout<<endl<<" ----- STUDENT "<<name<<" ADDED SUCCESFULLY ------"<<endl;

    cout<<endl<<"Want to do more functions(press 1) for Main menu(0): ";
    int v;
            cin>>v;
            switch(v)
            {
        case 1:{
            User_A();
            break;
            }
        case 0:{
            main_fucn();
            break;
            }
        default:
            {
            main_fucn();
            break;
            }
            }

}

void User_B()
{
    static string user_B_pass="user2";
    string user_B_entry;
    cout<<endl<<"  Enter passWord for User 'B' : ";
    cin>>user_B_entry;


    if(user_B_entry==user_B_pass)
    {
        int ch;
        cout<<endl<<"  Welcome USER -- 'B' to LMS...."<<endl<<endl;
        cout<<" You can Return Books for Students "<<endl;
        cout<<" Enter 1 -- (Return Books) and 2 -- (Registered Students Details) default -- (Main menu) :";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                user_B_return();
                break;
            }
        case 2:
            {
                registered_students();
                User_B();
                break;
            }
        default:
            {
                main_fucn();
                break;
            }
        }

    }
    else
    {
        cout<<endl<<"* Entered Wrong Password * please enter again..."<<endl<<endl;
        User_B();
    }
}

void user_B_return()
{

    int reg_no;
    cout<<"Enter Registration Number of a student : ";
    cin>>reg_no;

    bool fl=true;
    for(int i=0;i<reg_no_students.size();i++)
    {
        if(reg_no==reg_no_students[i])
        {
            fl=false;
            print_stu_details(i);
            return_main(i);
            break;
        }
    }
    if(fl)
    {
        int ch;
        cout<<"There is no student registered with this -- "<<reg_no<<endl;
        cout<<"Try Another Registration no -- press(1) and for main menu(0) : ";
        cin>>ch;
        if(ch==1) user_B_return();
        else if(ch==0) main_fucn();
        else User_B();
    }

}

void return_main(int index)
{
    string name;
     int number;
     print_stock();
     cout<<endl<<"Enter Name and Quantity of books want to return from Student "<<names_student[index]<<endl;
     cin>>name>>number;
     bool fl=true;
     for(int i=0;i<name_books.size();i++)
     {
         if(name==name_books[i]&&no_issue_books_students[index]>=number)
         {
             quantity_books[i]=quantity_books[i]+number;
             cout<<"Successfully returned "<<number<<" books of "<<name<<" from the student.."<<endl;
             no_issue_books_students[index]=no_issue_books_students[index]-number;
             print_stu_details(index);
             cout<<endl;
             fl=false;
             cout<<"Updated stock is ..."<<endl;
             print_stock();
             break;
         }
         if(name_books[i]==name&&number>no_issue_books_students[index])
         {
             cout<<number<<" books of "<<name<<" are not Issued by this student according to records.."<<endl;
             print_stu_details(index);
             fl=false;
             break;
         }
     }
     if(fl)
     {
         if(number<=no_issue_books_students[index])
         {
         name_books.push_back(name);
         quantity_books.push_back(number);
            cout<<"Successfully returned "<<number<<" books of "<<name<<" from the student.."<<endl;
            no_issue_books_students[index]=no_issue_books_students[index]-number;
            print_stu_details(index);
            cout<<endl;
            fl=false;
            cout<<"Updated stock is ..."<<endl;
            print_stock();
            cout<<endl;
        }
        else
        {
            cout<<number<<" books of "<<name<<" are not Issued by this student according to records.."<<endl;
            print_stu_details(index);
            cout<<endl;
        }
     }
     int choice;
     cout<<"Want to Return more books press(1) or 2 -- (User B), and 3 -- (Registered Students Details) and default or 0(main menu) to end press(-1): ";
     cin>>choice;
     switch(choice)
    {
    case 1:{
        return_main(index);
        break;}
    case 2:{
        User_B();
        break;
        }
    case 3:{
        registered_students();
        break;
        }
    case 0:{
        main_fucn();
        break;
        }
    case -1:{
        write_file();
        break;
        }
    default:
        {
            main_fucn();
            break;
        }
    }
}

void Add_book(vector<string> &name_books,vector<int> &quantity_books)
    {

        string name_book;
        int quantity_book;
        cout<<"Enter the Name and Quantity of Books with space ---"<<endl;

        cin>>name_book>>quantity_book;

        name_books.push_back(name_book);
        quantity_books.push_back(quantity_book);

        cout<<endl<<"     Added Books Detail..."<<endl;

        print_stock();

    }

     void Remove_book(vector<string> &name_books,vector<int> &quantity_books)
    {
        string name;
        int quantity;

        int n=sizeof(name_books)/sizeof(name_books[0]);

        cout<<endl<<"Here is Details of Books Available..."<<endl;

        print_stock();

        cout<<"Enter the Name and Quantity of Book want to Remove --- "<<endl;
        cin>>name>>quantity;
        cout<<"Entered Book Name is "<<name<<" and Quantity is "<<quantity<<endl;
        int index=-1;
        for(int i=0;i<name_books.size();i++)
        {
            if(name==name_books[i])
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            int ch;
            cout<<"Book you entered is not Available in stock.."<<endl;
            cout<<"To Try again press(1) for Main menu(0) : ";
            cin>>ch;
            if(ch==0) main_fucn();
            else if(ch==1) Remove_book(name_books,quantity_books);
        }
        else
        {
            if(quantity_books[index]>quantity)
            {
                quantity_books[index]=quantity_books[index]-quantity;
                cout<<"Updated stock is ..."<<endl;
                print_stock();
            }
            else if(quantity_books[index]==quantity)
            {
                name_books.erase(name_books.begin()+index);
                quantity_books.erase(quantity_books.begin()+index);
                cout<<"Updated stock is ..."<<endl;
                print_stock();
            }
            else
            {
                cout<<endl<<"Quantity of books entered by you is more than Available stock..."<<endl;
                cout<<"Enter quantity according to stock "<<endl;
                Remove_book(name_books,quantity_books);
            }
        }


    }

     void Modify_book(vector<string> &name_books,vector<int> &quantity_books)
    {

        string name;
        int quantity;

        int n=sizeof(name_books)/sizeof(name_books[0]);

        cout<<endl<<"Here is Details of Books Available..."<<endl;
        print_stock();

        cout<<"Enter the Name and Quantity of Book want to Modify --- "<<endl;
        cin>>name>>quantity;
        cout<<"Entered Book Name is "<<name<<" and Quantity is "<<quantity<<endl;

        int index=-1;
        for(int i=0;i<name_books.size();i++)
        {
            if(name==name_books[i])
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            int ch;
            cout<<"Book you entered is not Available in stock so you can't modify it..."<<endl;
            cout<<"To Try again press(1) for Main menu(0) : ";
            cin>>ch;
            if(ch==0)
            {main_fucn();
            }
            else if(ch==1) Remove_book(name_books,quantity_books);
        }
        else
        {
                quantity_books[index]=quantity_books[index]+quantity;
                cout<<"Updated stock is ..."<<endl;
                print_stock();
        }

    }

    void write_file()
    {
        fout.open(FILE,std::ios::app);
        if (!fout)
        {
            cout<<"\nERROR\n";
            return;
        }
        logToFile();

        fout<<endl<<"TODAY'S DETAILS..."<<endl;
        fout<<endl<<"BOOKS'S DETAILS..."<<endl;
        fout<<"  QUANTITY   NAME OF BOOK"<<endl;
        for(int i=0;i<name_books.size();i++)
        {
            fout<<i+1<<")  "<<quantity_books[i]<<"  -->   " <<name_books[i]<<endl;
        }
        fout<<endl;

        fout<<endl<<" Here is the Details of Registered Students ...."<<endl<<endl;
        fout<<" REG: NO.    BOOKS ISSUED    STU: NAME "<<endl;
        fout<<"----------  --------------  -----------"<<endl;
        for(int i=0;i<names_student.size();i++)
        {
            fout<<"  "<<reg_no_students[i]<<"            "<<no_issue_books_students[i]<<"          "<<names_student[i]<<endl;
        }

        fout<<endl;

        fout.close();
        finish();
    }

    void print_stock()
    {

       cout<<"  QUANTITY   NAME OF BOOK"<<endl;
        for(int i=0;i<name_books.size();i++)
        {
            cout<<i+1<<")  "<<quantity_books[i]<<"  -->   " <<name_books[i]<<endl;
        }
    }


    string getCurrentDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&now_time);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");  // Format: YYYY-MM-DD HH:MM:SS
    return oss.str();
    }

    void logToFile() {
    std::ofstream logFile(FILE, std::ios::app);
    if (logFile) {
        logFile <<"Updated stock on -- "<<getCurrentDateTime()<<endl;
        logFile.close();
        cout <<"File written successfully!"<<endl;
    } else {
        std::cerr<<"Error opening log file!"<<endl;
    }
    }

    int finish()
    {
        return 0;
    }

};
}

int main()
{
    cout<<"     WELCOME TO LIBRARY MANAGEMENT SYSTEM [LMS].."<<endl;
    cout<<"      -------  -------  -------  --------  ------  "<<endl ;
    variables::LMS l1;

    l1.main_fucn();

    return 0;
}
