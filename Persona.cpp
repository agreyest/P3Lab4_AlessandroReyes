#include<iostream>
#include<iomanip> 
#include<vector>
#include<bits/stdc++.h>
#include<string.h> 

#ifndef PERSONA_CPP
#define PERSONA_CPP

using namespace std;


class Persona{
	
      private:
      	
              int key;
              string name, lastName, password;
              vector<string> messages;
              vector<string> senders;
              
      public:
      	
            Persona(){}
             
			Persona(int key){
				this->key=key;
			}
            Persona(int key, string name, string lastName, string password){	
              this->key=key;
              this->name.assign(name);
              this->lastName.assign(lastName);
              this->password.assign(password);
            }
             
            void setKey(int key){
                this->key = key;
            }
            int getKey(){
                return this->key;
            }
             
            void setName(string name){
                this->name.assign(name);
            }
            string getName(){
                return this->name;
            }
             
            void setLastName(string lastName){
                this->lastName.assign(lastName);
            }
            string getLastName(){
                return this->lastName;
            }  
			
			void setPassword(string password){
                this->password.assign(password);
            }
            string getPassword(){
                return this->password;
            }  
			
			vector<string> getMessages() {//Get varios mensanjes
        		return messages;
    		}
			void setMessage(string message) {//Set un mensaje
        		this->messages.push_back(message);
			}
			
			vector<string> getSenders() {//Get varios senders
        		return senders;
    		}
			void setSender(string sender) {//Set un sender
        		this->senders.push_back(sender);
			}
			
			~Persona(){}	     
};
#endif
