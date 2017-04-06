//============================================================================
//Author      : Aaron Neidlinger,
// Description : Lab 8 - Morse Code Generator
//============================================================================

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

class Message{
     protected:
	//private data
        string message;
	//private functions
		
	public:
	//constructors
	    Message();
	    Message(string input);
	//destructor
	    ~Message();
	//public functions
        virtual void print();		
};

class MorseCodeMessage : public Message{
     private:
          string morse;
     public:
		//constructors
	    MorseCodeMessage();
	    MorseCodeMessage(string input) : Message(input){} //explicit call to base class parametric constructor
        //public methods
	    void translate();
        void print();
};

class MessageStack{
	private:
		//private data
		vector<Message> stack;
	public:
		//public constructors
		MessageStack();
		MessageStack(Message);
		//deconstructor
		~MessageStack();
		//public methods
		void push(Message);
		void pop();
		void printStack();
};

Message::Message(){
    cout << "Please input a string for the Message default constructor:"; 
    getline(cin,message);	//gets the user message
}

Message::Message(string input){
    message = input;	//setups message
}

Message::~Message(){

}

MorseCodeMessage::MorseCodeMessage(){
 
}

MessageStack::MessageStack(Message mes){
	stack.push_back(mes);	//uses vector method for creation
}

MessageStack::~MessageStack(){
	while(!stack.size()){
		stack.pop_back();
	}
}

void MessageStack::push(Message mes){
	stack.push_back(mes);	//uses vector method for lifo
}
void MessageStack::pop(){
	stack.pop_back();		//uses vector method for lifo
}
void MessageStack::printStack(){
	int i = stack.size() - 1;
	string tempst = " ";
	Message temp(tempst);
	
	while(i >= 0){
		temp = stack[i];
		temp.print();
		i--;
	}
}

void Message::print(){
    cout << "Message class message: " << message << endl;
}

void MorseCodeMessage::print(){
    cout << "MorseCodeMessage class message: " << message << endl;
    cout << "MorseCodeMessage class translation: " << morse << endl;
}

void MorseCodeMessage::translate(){
    stringstream morsestream;
    string word;
    char ch;
	//a - z in morse code
	string morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.",      "---",".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-","-.--", "--.."};
	
	//converts the string message into a stringstream
    morsestream << message;
     
	//breaks up the string into words by using stringstream
    while( morsestream >> word){
		//runs through every letter of a word
        for(int i = 0; i < word.length(); i++){
			//checks to make sure the character is a alphabetical letter
                if(isalpha(word[i])){
                    ch = word[i];	//assigns the letter to ch
                    ch = toupper(ch);	//converts to upper case for calculation
                    morse += morseCode[ch - 'A'];	//subtracts A from ch to result in the proper index
					//i.e. D = 68 A = 65 68-65=3 morseCode[3] = the morse code for d
                    morse += " ";	//appends a space
                }
        }
        morse += "/ ";	//seperates words
    }
}

int main(void){
    string mess;
	string stackable1;
	string stackable2;
	string stackable3;
	string stackable4;
    string morsmess;
     
     
       
    cout << "<------------------Message Class default constructor------------------>" << endl << endl;
	
    Message message1;
     
    cout << endl;
     
    cout << "<------------------Message Class parametric constructor:-------------->" << endl << endl;
	 
    cout << "Please input a string for initialization: ";
    getline(cin,mess);
    cout << endl << endl;
    Message message2(mess);
     
	cout << "<------------------Message Class Results:----------------------------->" << endl << endl;
	 
    cout << "The message for message1: " << endl;
    message1.print();
     
    cout << endl;
     
    cout << "The message for message2: " << endl;
    message2.print();
     
    cout << endl << endl;
     
	cout << "<-----------------MorseCodeMessage Class parametric constructor:----->" << endl << endl;
	 
    cout << "Please input a string for initialization: ";
    getline(cin,morsmess);   
    cout << endl << endl;
    MorseCodeMessage mors1(morsmess);

	cout << "<-----------------Morse Code Translation and Print:------------------>" << endl << endl;
   
    mors1.translate();
    mors1.print();
	 
	cout << endl << endl;
	cout << "<-----------------MessageStack Initialization:----------------------->" << endl << endl;
	 
	cout << "Please input a string for initialization: ";
    getline(cin,stackable1); 
	Message stacking1(stackable1);
	MessageStack stack(stacking1);
	 
	cout << "Please input a string for initialization: ";
    getline(cin,stackable2); 
	Message stacking2(stackable2);
	stack.push(stacking2);
	 
	cout << "Please input a string for initialization: ";
    getline(cin,stackable3); 
	Message stacking3(stackable3);
	stack.push(stacking3);
	 
	cout << "Please input a string for initialization: ";
    getline(cin,stackable4); 
	Message stacking4(stackable4);
	stack.push(stacking4);
	 
	cout << "<-----------------MessageStack Print:-------------------------------->" << endl << endl;
	 
	stack.printStack();
	 
	cout << "<-----------------MessageStack Deleting Two Elements:---------------->" << endl << endl;
	 
	stack.pop();
	stack.pop();
	 
	cout << "<-----------------MessageStack Print:-------------------------------->" << endl << endl;
	 
	stack.printStack();
            
    return 0;     
}