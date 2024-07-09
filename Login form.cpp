#include <iostream>
#include <fstream>
using namespace std;
class temp{
    private:
        string username, email, password;
        string searchname, searchemail, searchpassword;
        fstream file;
    public:
        void signup();
        void signin();
        void forgotpassword();
};

int main() {
    char choice;
    cout << "1. Sign up" ;
    cout << "2. Sign in";
    cout << "3. forgot password";
    cout << "4. exit";
    cin>>choice;
    switch(choice){
        case '1':
            cout << "Sign up";
            break;
        case '2':
            cout << "Sign in";
            break;
        case '3':
            cout << "forgot password";
            break;
        case '4':
            cout << "exit";
            break;
        default:
            cout << "Invalid choice";
    }
}
void temp :: signup(){
    cout<<"\nEnter your name :: ";
    getline(cin, username);
    cout<<"\nEnter yout email address ::"
    getline(cin, email);
    cout<<"\nEnter your password :: ";
    getline(cin, password);
    
    file.open("loginData.txt", ios :: out | ios :: app);
    file<<username<<" "<<email<<" "<<password<<endl;
    file.close();
}
void temp :: signin(){
    string searchname, searchpassword;
    cout<<"------LOGIN------"<<endl;
    cout<<"enter your username :: ";
    getline(cin, searchname);
    cout<<"enter your password :: ";
    getline(cin, searchpassword);

    file.open("loginData.txt", ios :: in);
    getline(file, username,"*");
    getline(file, email, "*");
    getline(file, password,'\n');
    while(!file.eof()){
        if(username == searchname){
            if(password == searchpassword){
                cout<<"Login successful"<<endl;
                cout<<"Username :: "<<username<<endl;
                cout<<"Email :: "<<email<<endl;
            }
            else{
                cout<<"Password is incorrect"<<endl;
            }
        }
        getline(file, username, "*");
        getline(file, email, "*");
        getline(file, password, '\n');
    }
    file.close();
}
void temp :: forgotpassword(){
    string searchname, searchemail;
    cout<<"------Forgot Password------"<<endl;
    cout<<"Enter your username :: ";
    getline(cin, searchname);
    cout<<"Enter your email :: ";
    getline(cin, searchemail);

    file.open("loginData.txt", ios :: in);
    getline(file, username, "*");
    getline(file, email, "*");
    getline(file, password, '\n');
    while(!file.eof()){
        if(username == searchname){
            if(email == searchemail){
                cout<<"Your password is :: "<<password<<endl;
            }
            else{
                cout<<"Email is incorrect"<<endl;
            }
        }
        getline(file, username, "*");
        getline(file, email, "*");
        getline(file, password, '\n');
    }
    file.close();
}
 void 