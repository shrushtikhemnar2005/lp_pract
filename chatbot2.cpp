#include<iostream>
#include<string>
using namespace std;

void chatbot(const string& UserInput){
    if(UserInput == "hi" || UserInput == "hello"){
        cout<<"Chatbot:hello how can i help you?"<<endl;
    }
    else if(UserInput == "price" || UserInput == "cost"){
        cout<<"Chatbot:our product price ranges from $10 to $100 "<<endl;
    }
    else if(UserInput == "bye" || UserInput == "exit"){
        cout<<"Chatbot:bye,have a great day"<<endl;
    }
    else if(UserInput == "help"){
        cout<<"Chatbot:how can i help you in our chatbot you can see product price, availability"<<endl;
    }
    else{
        cout<<"Chatbot:sorry i cant understand please type help to see available options";
    }
}
int main(){
    string UserInput;
    cout<<"welcome to our chatboat"<<endl;
    cout<<"please type help to see available options";
    cout<<"\n";
    while(true){
        cout<<"You:";
        getline(cin,UserInput);

        for(auto& c: UserInput) c=tolower(c);
        if(UserInput == "bye" || UserInput == "exit"){
            chatbot(UserInput);
            break;
        }

        chatbot(UserInput);
    }
}