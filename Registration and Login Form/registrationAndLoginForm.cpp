#include<iostream>
#include<vector>
using namespace std;

class User{
    private: 
        string username, password;

    public: 
        User(string username, string password){
            this->username = username;
            this->password = password;
        }

        string getUsername(){
            return username;
        }

        string getPassword(){
            return password; 
        }
};

class UserManager {
    private:
        vector<User> users;

    public: 
        void RegisterUser(){
            string username , password ;
            cout << "\t\tEnter your username: ";
            cin>>username ;
            cout << "\t\tEnter your password: ";
            cin>> password;

            User newUser(username, password);
            users.push_back(newUser);

            cout<< "\t\tUser Register Successfully ...."<<endl;
        }    

        bool LoginUser(string name, string password){
            for (int i = 0; i < users.size(); i++) {
                if (users[i].getUsername() == name && users[i].getPassword() == password){
                    cout<<"\t\tLogin Successfully ...."<<endl;
                    return true;
                }
            }
            cout<<"\t\tInvalid User Name or Password ...."<<endl;
            return false;
        }

        void showUser(){
            cout<<"\t\t---Users List---"<<endl;
            for(int i=0; i<users.size(); i++){
                cout<<"\t\tUsername: "<<users[i].getUsername()<<endl;
            }
        }

        void searchUser(string username){
            for(int i=0; i<users.size(); i++){
                if(users[i].getUsername() == username){
                    cout<<"\t\tUser Found"<<endl;
                }
            }
            cout<<"\t\tUser Not Found"<<endl;
        }

        void deleteUser(string username){
            for(int i=0; i<users.size(); i++){
                if(users[i].getUsername() == username){
                    users.erase(users.begin()+i);
                    cout<<"\t\tUser Remove Successfully"<<endl;
                }
            }
        }
};


int main(){
    UserManager userManage;

    int option;
    char choice;
    do{
        system("cls");
        cout<<"\n\n\t\t1. Regidter User"<<endl;
        cout<<"\t\t2. Login"<<endl;
        cout<<"\t\t3. Show user list"<<endl;
        cout<<"\t\t4. Search user"<<endl;
        cout<<"\t\t5. Delete user"<<endl;
        cout<<"\t\t6. Exit"<<endl;

        cout<<"\t\tEnter Your Choice : ";
        cin>>option;

        switch(option){
            case 1:  {
                userManage.RegisterUser();
                break;
            }
            case 2:  {
                string username, password;
                cout<<"\t\tEnter Username : ";
                cin>>username;
                cout<<"\t\tEnter Password :";
                cin>>password;
                userManage.LoginUser(username,password);
                break;
            }
            case 3: {
                userManage.showUser();
                break;
            }
            case 4: {
                string username ;
                cout<<"\t\tEnter User Name : ";
                cin>>username;
                userManage.searchUser(username);
                break;
            }
            case 5: {
                string username ;
                cout<<"\t\tEnter User Name : ";
                cin>>username;
                userManage.deleteUser(username);
                break;
            }
            case 6:
                exit(1);
        }
        cout<<"\t\tDo You Want to Continue [Yes/No] ? :";
        cin>>choice;
    }while(choice=='y' || choice=='Y');

    return 0;
    
}

