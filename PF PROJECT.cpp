#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void loggedinmenu(){
	
    cout<<" "<<endl;
    cout<<"select 3 to deposit money  "<<endl;
    cout<<" "<<endl;
    cout<<"select 4 to check your balance "<<endl;
    cout<<" "<<endl;
    cout << "select 5 to transfer funds " << endl;
    cout << " " << endl;
    cout << "select 6 to withdraw money  " << endl;
        cout << "                " << endl;

        cout << "select 7 to see transaction history  " << endl;

    cout << "                " << endl;
     cout << "select 8 for loan request  " << endl;

    cout << "                " << endl;
     cout << "select 9 for currency calculator  " << endl;

    cout << "                " << endl;
    cout<<"select 10 for payments"<<endl;
    cout<<"                    "<<endl;
    cout<<"select 11 to buy cryptocurrancy"<<endl;
    cout<<"                    "<<endl;
     cout<<"select 12 to view your crypto wallet"<<endl;
    cout<<"                    "<<endl;
    cout<<"select -1 to Exit"<<endl;
    cout<<"                    "<<endl;
    
};
void notloggedinmenu(){
 
	    cout<<"select 1 to Sign Up"<<endl;
    cout<<" "<<endl;
    cout<<"select 2 to Log in"<<endl;
    cout<<" "<<endl;
    cout<<"select -1 to close the app"<<endl;
    cout<<" "<<endl;
};
void Signup(){
string username;
string pin;
    
 int balance;
       cout<<"Enter User Name:"<<endl;
    cin>>username;
     cout<<"Enter PIN: "<<endl;
    cin>>pin;

	cout<<"enter your initial deposit Mr."<<username<<endl;
	cin>>balance;
	    fstream my_balance_file("balance.txt",ios::app);
	        my_balance_file<<balance<<endl;
	        my_balance_file.close();

    fstream my_username_file("username.txt",ios::app);
    fstream my_pin_file("pin.txt",ios::app);

    my_username_file<<username<<endl;
	my_pin_file<<pin<<endl;
    my_username_file.close();
    my_pin_file.close();

}



bool login(int &index, string &username, string &pin)
{
  bool loggedin=false;

	   
	    cout<<"Enter UserName: ";
    cin>>username;
    cout<<" "<<endl;
    cout<<"Enter 4 digit PIN: ";
    cin>>pin;
   

	
    string array[100];
    string array2[100];


  

   fstream my_username_file("username.txt",ios::in);
    fstream my_pin_file("pin.txt",ios::in);

    
    int lines = 0;
    while (lines < 100 && getline(my_username_file, array[lines])) {
        lines++;
    }
   int lines1 = 0;
    while (lines1 < 100 && getline(my_pin_file, array2[lines1])) {
        lines1++;
    }
  
  my_username_file.close();
        my_pin_file.close();
bool user=false;
bool pn=false;

 for (int i = 0; i < lines; ++i) {
        if (array[i] == username) {
            user = true;
         index=i;
            break;
        }
	else{
		user=false;
	}
	

}

for(int j=0;j<=lines;j++){

		if(array2[j]==pin){
		pn=true;
		break;
	}
	else{
		pn =false;
	}
	

}
if( user&&pn == true){

loggedin=true;
	

}
else{
loggedin=false;
	cout<<" "<<endl;
	cout<<"incorrect username or PIN, please try again."<<endl;
	cout<<" "<<endl;
}

 return loggedin;
   loggedin = (user && pn);
    return index;
}

void balance(string username,int index){
	
	
	
int balance;
	cout<<"enter the amount you want to deposit Mr."<<username<<endl;
	cin>>balance;
	 fstream my_balance_file("balance.txt",ios::in);
    string array[100];
    int lines = 0;
    while (lines < 100 && getline(my_balance_file, array[lines])) {
        lines++;
    }
    int old_balance=stoi(array[index]);
    int new_balance=balance+old_balance;
	 array[index]=to_string(new_balance);
 my_balance_file.close();


remove("balance.txt");

 fstream my_balance2_file("balance.txt",ios::app);
	       
	      



for (int i=0;i<lines;i++){
 my_balance2_file<<array[i]<<endl;

}
	   	ofstream outFile(username + ".txt", ios::app);
	  outFile<<username<<" "<<balance<<"+ is added to your account "<<endl;
	   outFile.close(); 


}
void print_balance(int index){
		
		
		
    string array[100];
  
   fstream my_balance_file("balance.txt",ios::in);
   
    int lines = 0;
    while (lines < 100 && getline(my_balance_file, array[lines])) {
        lines++;
    }
 
  my_balance_file.close();
       cout<<""<<endl;
       cout<<"Your current balance: "<<array[index]<<endl;
       cout<<""<<endl;
}
  //---------------------------------------------------------------------//

void transfer_funds(int index, string username){
	
	
	
	
	string transfer_name;
	string amount;
	cout<<"name of person you want to transfer money: "<<endl;
	cin>> transfer_name;
	cout<<"amount you want to transfer: "<<endl;
	cin>>amount;
	
	  string array[100];
	  	  string array1[100];

   fstream my_balance_file("balance.txt",ios::in);
    fstream my_username_file("username.txt",ios::in);
    
    int lines = 0;
    while (lines < 100 && getline(my_balance_file, array[lines])) {
        lines++;
    }
  lines = 0;
    while (lines < 100 && getline(my_username_file, array1[lines])) {
        lines++;
    }
   	int new_amount_add;
   	int n;
  my_balance_file.close();
    my_username_file.close();
  for(int i=0;i<lines;i++){
  	if(array1[i]==transfer_name){
  		int n1=stoi(array[i]);
  		int n2=stoi(amount);
  		 new_amount_add=n1+n2;
  		 system("cls");
  		 cout<<" "<<endl;
  		
  	array[i]=to_string(new_amount_add);
  		
	  }
	  
  }
int num1=stoi(array[index]);
int num2=stoi(amount);
int my_balance=num1-num2;
cout<<" "<<endl;
cout<<amount<<"- from your account"<<endl;
cout<<" "<<endl;
cout<<"your new balance is: "<<my_balance<<endl;
cout<<" "<<endl;

 array[index]=to_string(my_balance);
 


remove("balance.txt");

 fstream my_balance2_file("balance.txt",ios::app);
	       
	      



for (int i=0;i<lines;i++){
 my_balance2_file<<array[i]<<endl;

}

my_balance2_file.close();
	ofstream outFile(username + ".txt", ios::app);
	  outFile<<username<<" transfer of  -"<<amount<<" to "<<transfer_name<<endl;
	   outFile.close(); 
}
  //---------------------------------------------------------------------//

void money_withdrawal(int index, string username, string pin ,int &withdrawal)
{

	int pin2;
	cout<<"enter the amount you want to withdraw: ";
	cin>>withdrawal;
	cout<<" "<<endl;
		cout<<"enter your PIN: ";
		cin>>pin2;
	int pin3=stoi(pin);
	if(pin2==pin3){
		string array[100];
		  fstream my_balance_file("balance.txt",ios::in);
    
    int lines = 0;
    while (lines < 100 && getline(my_balance_file, array[lines])) {
        lines++;
    }
    int current_balance=stoi(array[index]);
    int new_balance=current_balance-withdrawal;
    cout<<" "<<endl;
    cout<<withdrawal<<"- from your account"<<endl;
    cout<<" "<<endl;
    cout<<"your new balance is: "<<new_balance<<endl;
    cout<<" "<<endl;
    	 array[index]=to_string(new_balance);
 my_balance_file.close();


remove("balance.txt");

 fstream my_balance2_file("balance.txt",ios::app);
	       
	      



for (int i=0;i<lines;i++){
 my_balance2_file<<array[i]<<endl;

}
	}
	else{
		cout<<" "<<endl;
		cout<<"incorrect PIN. Try again please "<<endl;
		cout<<" "<<endl;
	}
	ofstream outFile(username + ".txt", ios::app);
	  outFile<<username<<" withdrawal of  -"<<withdrawal<<endl;
	   outFile.close(); 

}
  //---------------------------------------------------------------------//

void transaction_history(string username, int &p){
		ifstream inFile(username + ".txt", ios::in);
	 string line;
	 cout<<" "<<endl;
	 cout<<username<<"'s transaction history: "<<endl;
	 cout<<" "<<endl;
	 p=0;
        while (getline(inFile, line)) {
            cout << line << endl;
			p++; 
        }

        	 

        inFile.close();
}

void loan_calculator(int p , string username){
		int amount;
		int age;
		int installments;
	cout<<"Mr."<<username<<" your credit score is: "<<p<<endl;
	cout<<" "<<endl;
	if(p<=0){
	
		cout<<"you don't have any transactions, so you are not eligible for any loan"<<endl;
	}
		if(p>0&&p<5){
		cout<<"your credit score is low, so you are not eligible for any loan"<<endl;
	}
		if(p>5){
		cout<<"you are eligible for a loan, kindly give your details. "<<endl;
		cout<<" "<<endl;
		cout<<"the amount you want for loan: ";
		cin>>amount;
			cout<<" "<<endl;
		cout<<"your current age: ";
		cin>>age;
			cout<<" "<<endl;
		cout<<"number of installments you want: ";
		cin>>installments;
					cout<<" "<<endl;
			cout<<"your loan request has been forwarded, kindly visit the bank for further details. "<<endl;

	}
	
}
  //---------------------------------------------------------------------//


  //---------------------------------------------------------------------//
  
  
  currency_calculator(int index){
 	 string array[100];
  
   fstream my_balance_file("balance.txt",ios::in);
   
    int lines = 0;
    while (lines < 100 && getline(my_balance_file, array[lines])) {
        lines++;
    }
 
  my_balance_file.close();
  int currency= stoi(array[index]);	
  int choice;
  int out;
  int value;
  if(currency>0){
  	        cout<<"click 1 to convert in USD"<<endl;
        	cout<<" "<<endl;
  		    cout<<"click 2 to convert in pounds"<<endl;
  		  	cout<<" "<<endl;
  			cout<<"click 3 to convert in dirhams"<<endl;
  			cout<<" "<<endl;
  			cout<<"click 4 to convert in riyal"<<endl;
  	cin>>choice;
  	cout<<" "<<endl;
  	cout<<"Enter the value of your desired choice"<<choice<<endl;
  	cin>>value;

  	
  	 switch(choice){

            case 1:
                
                out=currency/value;
                cout<<"your balance in USD is: $"<<out<<endl;
                break;
                 case 2:
                
                out=currency/value;
                cout<<"your balance in pounds is: GBP "<<out<<endl;
                break;
                 case 3:
                
                out=currency/value;
                cout<<"your balance in dirhams is: AED "<<out<<endl;
                break;
                 case 4:
                
                out=currency/value;
                cout<<"your balance in riyal is: SAR "<<out<<endl;
                break;
                
                
                break;
                 default:
                cout<<"You have Entered Wrong Value! Try Again"<<endl;
}
}
            	cout<<" "<<endl;
}
  
  
  //---------------------------------------------------------------------//
  
 void payments(int index, string username, string pin ,int &withdrawal)
{
int choice;
cout<<"press 1 for bill payment"<<endl;
cout<<"press 2 for donations"<<endl;
cin>>choice;
	int pin2;
	if(choice==1){
	
	cout<<"enter the amount you want to pay: ";}
	else{
			cout<<"enter the amount you want to donate:   (for various reasons state bank will reciprocate rs 2.86 on your donations)" ;
	}
	cin>>withdrawal-2;
	cout<<" "<<endl;
		cout<<"enter your PIN: ";
		cin>>pin2;
	int pin3=stoi(pin);
	if(pin2==pin3){
		string array[100];
		  fstream my_balance_file("balance.txt",ios::in);
    
    int lines = 0;
    while (lines < 100 && getline(my_balance_file, array[lines])) {
        lines++;
    }
    int current_balance=stoi(array[index]);
    int new_balance=current_balance-withdrawal;
     	 system("cls");

    cout<<" "<<endl;
    if(choice==1){
    	cout<<"BILL PAID!"<<endl;
    			cout<<" "<<endl;
	}
	else{
		cout<<"MONEY DONATED!"<<endl;
		cout<<" "<<endl;
	}
    cout<<withdrawal<<"- from your account"<<endl;
    cout<<" "<<endl;
    cout<<"your new balance is: "<<new_balance<<endl;
    cout<<" "<<endl;
    	 array[index]=to_string(new_balance);
 my_balance_file.close();


remove("balance.txt");

 fstream my_balance2_file("balance.txt",ios::app);
	       
	      



for (int i=0;i<lines;i++){
 my_balance2_file<<array[i]<<endl;

}
	}
	else{
		cout<<" "<<endl;
		cout<<"incorrect PIN. Try again please "<<endl;
		cout<<" "<<endl;
	}
	ofstream outFile(username + ".txt", ios::app);
	if(choice==1){
		outFile<<username<<" paid utility bill worth -"<<withdrawal<<endl;
	}
	else{

	  outFile<<username<<" donated -"<<withdrawal<<endl;
	  	}
	   outFile.close(); 

}




void crypto_buying(int index, string username, string pin){
		int money;
		int pin2;
	int choice;
	cout<<"click 1 to buy BITCOIN"<<endl;
	cout<<" "<<endl;
	cout<<"click 2 to buy Ethereum (ETH)"<<endl;
	cout<<" "<<endl;
	cout<<"click 3 to buy Binance Coin (BNB)"<<endl;
	cout<<" "<<endl;
	cout<<"click 4 to buy Cardano (ADA)"<<endl;
	cout<<" "<<endl;
	cout<<"click 5 to buy XRP (Ripple)"<<endl;
	cout<<" "<<endl;
cin>>choice;

		if(choice==1){
		
	cout<<"enter the amount of BITCOIN you want to buy: ";
		}
	else	if  (choice==2){
		
	cout<<"enter the amount of Ethereum (ETH) you want to buy: ";
		}
else	if	 (choice==3){
		
	cout<<"enter the amount of Binance Coin (BNB) you want to buy: ";
		}
else	if	 (choice==4){
		
	cout<<"enter the amount of Cardano (ADA) you want to buy: ";
		}
else	if	 (choice==5){
		
	cout<<"enter the amount of XRP (Ripple) you want to buy: ";
		}
	
	cin>>money;
	cout<<" "<<endl;
		cout<<"enter your PIN: ";
		cin>>pin2;
	int pin3=stoi(pin);
	if(pin2==pin3){
		string array[100];
		  fstream my_balance_file("balance.txt",ios::in);
    
    int lines = 0;
    while (lines < 100 && getline(my_balance_file, array[lines])) {
        lines++;
    }
    int current_balance=stoi(array[index]);
    
    int new_balance=current_balance-money;
    cout<<" "<<endl;
    cout<<money<<"- from your account"<<endl;
    cout<<" "<<endl;
    cout<<"your new balance is: "<<new_balance<<endl;
    cout<<" "<<endl;
    	 array[index]=to_string(new_balance);
 my_balance_file.close();


remove("balance.txt");

 fstream my_balance2_file("balance.txt",ios::app);
	       
	      



for (int i=0;i<lines;i++){
 my_balance2_file<<array[i]<<endl;

}
	ofstream outfile(username + "cryptowallet.txt", ios::app);
float crypto;
if (choice==1){
	crypto=money/1000.09;
	outfile<<"Bitcoin (BTC):"<<crypto<<endl;
	cout<<"now you have: "<<crypto<<" Bitcoin (BTC)"<<endl;
}

if(choice==2){
		crypto=money/500.9;
			outfile<<"Ethereum (ETH):"<<crypto<<endl;
			cout<<" "<<endl;
			cout<<"now you have: "<<crypto<<" Ethereum (ETH)"<<endl;

}

if(choice==3){
	crypto=money/250.2;
		outfile<<"Binance coin (BNB):"<<crypto<<endl;
		cout<<" "<<endl;
		cout<<"now you have: "<<crypto<<" Binance coin (BNB)"<<endl;

}

if(choice==4){
	crypto=money/123.3;
		outfile<<"Cardano (ADA):"<<crypto<<endl;
		cout<<" "<<endl;
		cout<<"now you have: "<<crypto<<" Cardano (ADA)"<<endl;

}

if(choice==5){
	crypto=money/64;
		outfile<<"XRP (Ripple):"<<crypto<<endl;
		cout<<" "<<endl;
		cout<<"now you have: "<<crypto<<" XRP (Ripple)"<<endl;

}


 outfile.close(); 

	}
	else{
		cout<<" "<<endl;
		cout<<"incorrect PIN. Try again please "<<endl;
		cout<<" "<<endl;
	}

	
	
	
	
	
	ofstream outFile(username + ".txt", ios::app);
	if(choice==1){

	  outFile<<username<<" bought BITCOIN worth (BTC) of "<<money<<endl;	}
else	if(choice==2){

	  outFile<<username<<" bought Ethereum (ETH) worth of "<<money<<endl;	}
	else  	if(choice==3){

	  outFile<<username<<" bought Binance coin (BNB) worth of"<<money<<endl;	}
	  	else if(choice==4){

	  outFile<<username<<" bought Cardano (ADA) worth of   "<<money<<endl;	}
	 else 	if(choice==5){

	  outFile<<username<<"  bought XRP (Ripple) worth of  "<<money<<endl;	}
	  
	   outFile.close(); 
}
void crypto_wallet(string username){
		ifstream inFile(username + "cryptowallet.txt", ios::in);
	 string line;
	 cout<<" "<<endl;
	 cout<<username<<"'s crypto wallet : "<<endl;
	 cout<<" "<<endl;
        while (getline(inFile, line)) {
            cout << line << endl;
		
        }        	 

        inFile.close();
}



int main(){
int option;
string username;
string pin;
int index;
int p;
int withdrawal;
bool loggedin=false;
do{
	
	   if(loggedin==false){
          notloggedinmenu();
        }else{
              loggedinmenu();
        }
        cout<<"Welcome to C.A.D.E bank ltd."<<endl;
        cout<<"    Enter your choice: "<<endl;
        cin>>option;
        
           switch(option){

            case 1:
                Signup();
                
                break;
	
	case 2: 
	 
	    loggedin=login (index, username, pin);
                if(loggedin){
                	 system("cls"); 
                    cout<<"Hi Mr."<< username<<"! "<<"You are logged in"<<endl;
                    cout<<"---------------------------------"<<endl;
                     break;
                     
                      case 3:
                balance(username, index);
                 system("cls");
                break;
					     case 4:
                print_balance(index);
              ;
                break;
    	     case 5:
                transfer_funds(index,username);
                break;
                  case 6:
               money_withdrawal(index,username,pin,withdrawal);
                break;
 case 7:
 	 system("cls");
              	transaction_history( username, p);
            
                break;
 case 8:
 	 system("cls");
              loan_calculator(p,username);
            
                break;
case 9:
 	 system("cls");
              currency_calculator(index);
            
                break;
                case 10:
 	 system("cls");
            
             payments(index,username,pin,withdrawal);
                break;
                 case 11:
 	 system("cls");
            
 crypto_buying( index,  username,  pin);
                break;
                 case 12:
 	 system("cls");
            
 crypto_wallet(username);
                break;
}
                
                break;
                 default:
                cout<<"You have Entered Wrong Value! Try Again"<<endl;

}
}while(option!=-1);

	return 0;
}

