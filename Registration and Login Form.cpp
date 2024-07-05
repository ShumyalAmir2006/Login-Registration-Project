#include <iostream>
#include <fstream>
using namespace  std;

class temp {
    string searchname , searchpass , searchEmail;
    string username,Email,password;
    fstream file;
public:
    void login();
    void signup();
    void forgotpass();


}obj;

int main () {
    char choice;
    cout<<"1 - Login"<< endl;
    cout<<"2 - Sign - Up "<< endl;
    cout<<"3 - Forgot Password"<<endl;
    cout<<"4- Exit"<<endl;
    cout<<" Enter Your Choice :  "<<endl;
    cin>>choice;


    switch (choice) {
        case 1:
            obj.login();
            break;
        case 2:
            obj.signup();
            break;
        case 3:
            obj.forgotpass();
            break;
        case 4:
            return 0;
            break;
        default:
            cout<< "Invalit Selection...!"<<endl;


    }
}

void temp :: signup() {
    cout<<"Enter your user name : "<<endl;
    getline(cin,username);
    cout<<"Enter your Email : "<< endl;
    getline(cin,Email);
    cout<<"Enter your password : "<<endl;
    getline(cin,password);
    file.open("Logindata.txt", ios :: out | ios :: in );
    file<<username<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}

void temp::login() {
    cout<<"Enter your user name : \n";
    getline(cin,searchname);
    cout<<"Enter your password : \n";
    getline(cin,searchpass);
    file.open("Logindata.txt" , ios :: in);
    getline(file , username,'*');
    getline(file , Email , '*');
    getline(file, password , '\n');
    while (!file.eof()) {
        if (username == searchname) {
            if (password == searchpass) {
                cout<<"Logged in Successfully..!\n";
                cout<<"Email: "<< Email<<endl;
                cout<<"userrname: " <<username<<endl;


            }else {
                cout<<"Password in Incorrect..!"<<endl;

            }

        }
        getline(file , username,'*');
        getline(file , Email , '*');
        getline(file, password , '\n');
    }
    file.close();

}
void temp::forgotpass() {
    cout<<"Enter your username : \n";
    getline(cin , searchname);
    cout<<"Enter your Email : \n";
    getline(cin , searchEmail);

    file.open("Logindata.txt" , ios :: in);

    getline( file , username ,'*');
    getline( file , Email ,'*');
    getline( file , password ,'\n');

    while (!file.eof()) {
        if (username == searchname) {
            if (Email == searchEmail) {
                cout<< "Account Found...!\n";
                cout<<"Password"<<password<<endl;


            } else {
                cout<<"Not Found..!\n";

            }


        }else {
            cout<<"Not Found..!\n";
        }
    }
    file.close();




}


