/*
 Developed by Samuael Ketema  
 lijsamuael@gmail.com          

*/
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cctype>
using namespace std;
void insertMany();
void display();
void insertAtBeginning();
void insertAtEnd();
void insertAtMiddleRight();
void deleteAtBegening();
void deleteAtEnd();
void deleteAtMiddle();
void deletAtnth();
void search();
void maximum();
void minimum();
void update();
void sort();
void countOccurence();
void chooseAction();
void askingToContinue();
void deleteMaximumeAge();
void deleteMinimumeAge();
double avarage();
void wellcome();
void top();
int key;
// Definition of the structure.
struct Player{
  char name[15];
  char lastName[15];
  int age;
  char club[20]; // This is the club from where they selected for national team.
  int salary;
  int goalScored;
  int shirtNumber; // This is a promary key for our players.It is unique.
  int redCard;
  int yellowCard;
  Player *next;
};
Player *start = NULL;
// A MAIN FUNCTION STARTS AFTER HERE
int main(){
        wellcome();
        chooseAction();
return 0;
}
void askingToContinue(){
    cout<<"\n\tPRESS  ( 1 ) To Go To ...MENU...  Or Any Else To Exit the program : ";
    int ask;
    cin>>ask;
    if(ask == 1){
        system("cls");
        chooseAction();
    }
    else{
        cout<<"\n\tTHANK YOU FOR USING OUR SERVICE.\n"<<endl;
        exit(0);
    }
}
// The definition of the function that inserts the Player at the end.
void insertMany(){
     cout<<"\nFor how many players do you want to insert data : ";
    int key;
    manyin:
    cin>>key;
    if ((key < 0) || cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\nWarrning!!! please enter numbers only : ";
		goto manyin;
	}
    for(int i = 0; i < key; i++){
        Player *temp = new Player;
        // Prompting the user to insert the players information.
        cout<<"\nEnter the informaion of the "<<i+1<<"th student.\n";
        cout<<"__________________________________________________\n";
        cout<<"\nEnter the name of the player : ";
        cin>>temp->name;
        cout<<"\nEnter the last name of the player : ";
        cin>>temp->lastName;
        cout<<"\nEnter the age of the player : ";
        agein:
        cin>>temp->age;
	if ((temp->age < 0) || (temp->age > 130)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\nWarrning!!! the age of the player should be a number less than 150."<<endl;
        cout<<"Please insert again : ";
		goto agein;
	}
        cout<<"\nEnter the Club of the player : ";
        cin>>temp->club;
        cout<<"\nEnter the Salary of the player : ";
        salaryin:
        cin>>temp->salary;
        if ((temp->salary < 0) || (temp->salary > 50,000)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\nWarrning!!! the salary of Ethiopian national team players is lessthan 50000" << endl;
        cout<<"Please insert a corrected value :";
		goto salaryin;
	}
        cout<<"\nEnter the goal that the player had scored this season: ";
        goalin:
        cin>>temp->goalScored;
        if ((temp->goalScored < 0) || (temp->goalScored > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "please enter the real goal of not more than 50" << endl;
		goto goalin;
	}
        cout<<"\nEnter the unique shirt number  of the player : ";
        int snum;
        shirtin000:
        cin>>snum;
        for(Player *temp = start; temp != NULL; temp = temp->next){
            if(temp->shirtNumber == snum){
            cout<<"\nWARRNING!!! You are not allowed  to enter a duplicated shirt number.\nPlease make it unique and TRY AGAIN :";
            goto shirtin000;
            }
        }
         if ((snum < 0) || (snum > 999)|| cin.fail())
            {
                cin.clear();
                cin.ignore(256,'\n');
                cout << "please enter the real shirt number of not more than 999" << endl;
                goto shirtin000;
            }
        temp->shirtNumber = snum;
        cout<<"\nEnter the number of red cards that the player get: ";
        redin:
        cin>>temp->redCard;
         if ((temp->redCard < 0) || (temp->redCard > 10)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
		goto redin;
	}
        cout<<"\nEnter the number of yellow cards that the player get: ";
        yellowin:
        cin>>temp->yellowCard;
         if ((temp->yellowCard < 0) || (temp->yellowCard > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real yellow cards of the player more than 20" << endl;
		goto yellowin;
	}
        temp->next = NULL;
        // Setting the inserted values to the linked list.
        if(start == NULL)
            start = temp;
        else
        {   Player *temp2 = start;
            while(temp2->next != NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    }
    askingToContinue();
}
// The definition of the function that displays all the nodes in the forward direction.
void display(){
    if(start == NULL)
        cout<<"There is no data to be displayed."<<endl;
    else{
        system("cls");
        Player *temp = start;
        cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
        do
        {
            if(temp == NULL)
                cout<<"\nEnd of the list.\n";
            else
            {
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                temp = temp->next;
            }
        }while(temp != NULL);
    }
    askingToContinue();
}
// Definition of the function insert at the beginning.
void insertAtBeginning(){
        Player *temp = new Player;
         // Prompting the user to insert the players information.
        cout<<"\nEnter the name of the player : ";
        cin>>temp->name;
        cout<<"\nEnter the last name of the player : ";
        cin>>temp->lastName;
        cout<<"\nEnter the age of the player : ";
        agein1:
        cin>>temp->age;
        if ((temp->age < 0) || (temp->age > 130)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real age of the person" << endl;
		goto agein1;
	}
       cout<<"\nEnter the Club of the player : ";
       cin>>temp->club;
        cout<<"\nEnter the Salary of the player : ";
        salaryin1:
        cin>>temp->salary;
        if ((temp->salary < 0) || (temp->salary > 50,000)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real salary of Ethiopian players which is less than 50000" << endl;
		goto salaryin1;
	}
        cout<<"\nEnter the goal that the player had scored this season: ";
        goalin1:
        cin>>temp->goalScored;
        if ((temp->goalScored < 0) || (temp->goalScored > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real goal of not more than 50" << endl;
		goto goalin1;
    }
        cout<<"\nEnter the unique shirt number  of the player : ";
        int snum;
        shirtin1:
        cin>>snum;
        for(Player *temp = start; temp != NULL; temp = temp->next){
            if(temp->shirtNumber == snum){
            cout<<"\nWARRNING!!! You are not allowed  to enter a duplicated shirt number.\nPlease make it unique and TRY AGAIN :";
            goto shirtin1;
         }
        }
        if ((snum < 0) || (snum > 999)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real shirt number of not more than 999" << endl;
		goto shirtin1;
	}
        temp->shirtNumber = snum;
        cout<<"\nEnter the number of red cards that the player get: ";
        redin1:
        cin>>temp->redCard;
         if ((temp->redCard < 0) || (temp->redCard > 10)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
		goto redin1;
	}
        cout<<"\nEnter the number of yellow cards that the player get: ";
        yellowin1:
        cin>>temp->yellowCard;
         if ((temp->yellowCard < 0) || (temp->yellowCard > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real yellow cards of the player more than 20" << endl;
		goto yellowin1;
	}
        temp->next = NULL;
        if(start == NULL)
        {     
        start = temp;
        }
        else
            {
            temp->next = start; 
            start = temp; 
            }
            askingToContinue(); 
}
void insertAtEnd(){
    Player *temp = new Player;
        // Prompting the user to insert the players information.
        cout<<"\nEnter the name of the player : ";
        cin>>temp->name;
        cout<<"\nEnter the last name of the player : ";
        cin>>temp->lastName;
        cout<<"\nEnter the age of the player : ";
        agein2:
        cin>>temp->age;
        if ((temp->age < 0) || (temp->age > 130)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real age of the person" << endl;
		goto agein2;
	}
       cout<<"\nEnter the Club of the player : ";
        cin>>temp->club;
        cout<<"\nEnter the Salary of the player : ";
        salaryin2:
        cin>>temp->salary;
        if ((temp->salary < 0) || (temp->salary > 50,000)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real salary of Ethiopian players which is less than 50000" << endl;
		goto salaryin2;
	}
        cout<<"\nEnter the goal that the player had scored this season: ";
        goalin2:
        cin>>temp->goalScored;
        if ((temp->goalScored < 0) || (temp->goalScored > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real goal of not more than 50" << endl;
		goto goalin2;
	}
        cout<<"\nEnter the unique shirt number  of the player : ";
        int snum;
        shirtin2:
        cin>>snum;
        for(Player *temp = start; temp != NULL; temp = temp->next){
            if(temp->shirtNumber == snum){
            cout<<"\nWARRNING!!! You are not allowed  to enter a duplicated shirt number.\nPlease make it unique and TRY AGAIN :";
            goto shirtin2;
        }
        }
        if ((temp->shirtNumber < 0) || (temp->shirtNumber > 999)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real shirt number of not more than 999" << endl;
		goto shirtin2;
	}
        cout<<"\nEnter the number of red cards that the player get: ";
        redin2:
        cin>>temp->redCard;
        if ((temp->redCard < 0) || (temp->redCard > 10)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
		goto redin2;
	}
        cout<<"\nEnter the number of yellow cards that the player get: ";
        yellowin2:
        cin>>temp->yellowCard;
        if ((temp->yellowCard < 0) || (temp->yellowCard > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real yellow cards of the player more than 20" << endl;
		goto yellowin2;
	}
        temp->next = NULL;
        // Setting the inserted values to the linked list.
        if(start == NULL)
            start = temp;
        else
        {   Player *temp2 = start;
            while(temp2->next != NULL){
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
    askingToContinue();
}
void insertAtMiddleRight(){
    Player *temp = new Player;
    if(start == NULL)
        cout<<"\nThere is no data in the list so that you can not add after nobody.";
    else{
        cout<<"\nafter who do you want to insert the player : ";
        char Name[15];
        cin>>Name;
        temp->next = NULL;
        Player *temp2 = start;
        while(strcmp( temp2->name , Name) != 0 ){
            temp2 = temp2->next;
           if(temp->next == NULL)
             cout<<"You can not insert!!!.....Because the Player with that do not exist in the system."<<endl;
        }
        temp->next = temp2->next;
        temp2->next = temp;
        cout<<"\nEnter the name of the player : ";
        cin>>temp->name;
        cout<<"\nEnter the last name of the player : ";
        cin>>temp->lastName;
       cout<<"\nEnter the age of the player : ";
        agein1:
        cin>>temp->age;
        if ((temp->age < 0) || (temp->age > 130)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real age of the person" << endl;
		goto agein1;
	}
       cout<<"\nEnter the Club of the player : ";
       cin>>temp->club;
        cout<<"\nEnter the Salary of the player : ";
        salaryin1:
        cin>>temp->salary;
        if ((temp->salary < 0) || (temp->salary > 50,000)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real salary of Ethiopian players which is less than 50000" << endl;
		goto salaryin1;
	}
        cout<<"\nEnter the goal that the player had scored this season: ";
        goalin1:
        cin>>temp->goalScored;
        if ((temp->goalScored < 0) || (temp->goalScored > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real goal of not more than 50" << endl;
		goto goalin1;
    }
        cout<<"\nEnter the unique shirt number  of the player : ";
        shirtin77:
        int sh;
        cin>>sh;
        for(Player *temp = start; temp != NULL; temp = temp->next){
            if(temp->shirtNumber == sh){
            cout<<"\nWARRNING!!! You are not allowed  to enter a duplicated shirt number.\nPlease make it unique and TRY AGAIN :";
            goto shirtin77;
            }
        }
        temp->shirtNumber = sh;
        if ((sh < 0) || (sh > 999)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real shirt number of not more than 999" << endl;
		goto shirtin77;
	}
        temp->shirtNumber = sh;
        cout<<"\nEnter the number of red cards that the player get: ";
        redin1:
        cin>>temp->redCard;
         if ((temp->redCard < 0) || (temp->redCard > 10)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
		goto redin1;
	}
        cout<<"\nEnter the number of yellow cards that the player get: ";
        yellowin1:
        cin>>temp->yellowCard;
         if ((temp->yellowCard < 0) || (temp->yellowCard > 50)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the real yellow cards of the player more than 20" << endl;
		goto yellowin1;
	}
    }
  askingToContinue();  
}
double avarage(){
    Player *temp;
    int sum = 0;
    int count = 0;
    int key;
    double avg;
    if(start == 0)
      cout<<"\nThere is no data. so we cant calculate the avarage.";
    else {
         cout<<"What variables avarage do you want to calculate :  ";       
        cout<<"\n\tPress 1  to search by age."<<endl;
        cout<<"\tPress 2  to search by salary."<<endl;
        cout<<"\tPress 3  to search by goal."<<endl;
        cout<<"\tPress 4  to search by number of red card."<<endl;
        cout<<"\tPress 5  to search by number of yellow card."<<endl;
        cout<<"Please select the appropraite number to search by specific attribute : ";
        select:
        cin>>key;
         if ((key < 1) || (key > 5)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the among the specified numbers only." << endl;
		goto select;
	}
        switch(key){
            case 1:
                temp = start;
                while(temp != NULL){
                    count++;
                    sum += temp->age;
                    temp = temp->next;
                }
                avg = (double)sum/count;
                cout<<avg;
            break;
            case 2:
                 temp = start;
                while(temp != NULL){
                    count++;
                    sum += temp->salary;
                    temp = temp->next;
                }
                avg = (double)sum/count;
                cout<<avg;
            break;
            case 3:
                temp = start;
                while(temp != NULL){
                    count++;
                    sum += temp->goalScored;
                    temp = temp->next;
                }
                 avg = (double)sum/count;
                cout<<avg; 
            break;
            case 4:
                 temp = start;
                while(temp != NULL){
                    count++;
                    sum += temp->redCard;
                    temp = temp->next;
                }
                 avg = (double)sum/count;
                cout<<avg;
            break;
            case 5:
                 temp = start;
                while(temp != NULL){
                    count++;
                    sum += temp->yellowCard;
                    temp = temp->next;
                }
                 avg = (double)sum/count;
                cout<<avg;
            break;
    }
    }
    askingToContinue();
    return 0;
}
void deleteAtBegening(){
    Player *temp;
    if(start == NULL)
       cout<<"\nYou have no data to delete.";
    else{
        temp = start;
        start = temp->next;
        delete temp;
    }
    askingToContinue();
}
void deleteAtEnd(){
    Player *temp;
    if(start == NULL)
       cout<<"\nYou have no data to delete.";
    else{
         Player *temp2;
         temp = start;
         if(temp->next == NULL){
             delete temp;
             start = NULL;
         }
         else{
         while(temp->next != NULL){
             temp2 = temp;
             temp = temp->next;
         }
         temp2->next = NULL;
         delete temp;
         }
    }
    askingToContinue();
}
void deleteAtMiddle(){
    Player *temp;
    Player *temp2;
    int found = 0;
    if(start == NULL)
       cout<<"\nYou have no data to delete.";
    else {
        cout<<"By which attribute do you want to delete \n: ";
        cout<<"\tPress 1  to delete by name."<<endl;
        cout<<"\tPress 2  to delete by last name."<<endl;
        cout<<"\tPress 3  to delete by age."<<endl;
        cout<<"\tPress 4  to delete by club."<<endl;
        cout<<"\tPress 5  to delete by salary."<<endl;
        cout<<"\tPress 6  to delete by goal."<<endl;
        cout<<"\tPress 7  to delete by shirtnumber."<<endl;
        cout<<"\tPress 8  to delete by number of red card."<<endl;
        cout<<"\tPress 9  to delete by number of yellow card."<<endl;
        cout<<"Please select the appropraite number to search by specific attribute : ";
        select1:
        cin>>key;
            if ((key < 1) || (key > 9)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the among the specified numbers only." << endl;
		goto select1;
	}
        switch(key){
            case 1:
                cout<<"\nEnter the name of the player you want to delete : ";
                char Name[15];
                cin>>Name;
                temp = start;
                if(strcmp(temp->name, Name) == 0){
                    found++;
                    start = temp->next;
                    delete temp;
                }
                else{
                while(strcmp( temp->name , Name) != 0 ){
                    found++;
                    temp2 = temp;
                    temp = temp->next;
                    //jhjhgyuyutyythg
                }
                temp2->next = temp->next;
                delete temp;
                }
                if(found == 0)
                    cout<<"The value you entered do not exist in our data."<<endl;
            break;
            case 2:
                 cout<<"\nEnter the last name of the player you want to delete : ";
                char LName[15];
                cin>>LName;
                temp = start;
                if(strcmp(temp->lastName, LName) == 0){
                    start = temp->next;
                    delete temp;
                }
                else{
                while(strcmp( temp->lastName , LName) != 0 ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;
                }
            break;
            case 3:
                 cout<<"\nEnter the age of the player you want to delete : ";
                int Age;
                agein3:
                cin>>Age;
                if ((Age < 0) || (Age > 150)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "Please enter the real age of the person which is less than 150." << endl;
                    goto agein3;
                }
                temp = start;
                if(temp->age == Age ){
                    found ++;
                    start = temp->next;
                    delete temp;
                }
                else{
                while(temp->age  != Age ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;
                }  
            break;
            case 4:
                 cout<<"\nEnter the club of the player you want to delete : ";
                char Club[15];
                cin>>Club;
                temp = start;
                if(strcmp(temp->club, Club) == 0){
                    start = temp->next;
                    delete temp;
                }
                else{
                while(strcmp( temp->club , Club) != 0 ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;
                }
            break;
            case 5:
                 cout<<"\nEnter the salary of the player you want to delete : ";
                int Salary;
                salaryin3:
                cin>>Salary;
                if ((Salary < 0) || (Salary > 50,000)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real salary of Ethiopian players which is less than 50000" << endl;
                    goto salaryin3;
                }
                temp = start;
                if(temp->salary == Salary ){
                    start = temp->next;
                    delete temp;
                }
                else{
                while(temp->salary  != Salary ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;
                }
            break;
            case 6:
              cout<<"\nEnter the goal that the playered scored  to delete : ";
                int Goal;
                goalin3:
                cin>>Goal;
                if ((Goal < 0) || (Goal > 50)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real goal of not more than 50" << endl;
                    goto goalin3;
                }
                temp = start;
                if(temp->goalScored == Goal ){
                    start = temp->next;
                    delete temp;
                }
                else{
                while(temp->goalScored  != Goal ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;
                }   
            break;
            case 7:
                 cout<<"\nEnter the number on the shirt of the player you want to delete : ";
                int ShirtNumber;
                shirtin3:
                cin>>ShirtNumber;
                if ((ShirtNumber < 0) || (ShirtNumber > 999)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real shirt number of not more than 999" << endl;
                    goto shirtin3;
                }
                temp = start;
                if(temp->shirtNumber == ShirtNumber ){
                    start = temp->next;
                    delete temp;
                }
                else{
                while(temp->shirtNumber  != ShirtNumber ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;
                }
            break;
            case 8:
               cout<<"\nEnter the number red cards of the player you want to delete : ";
                int RedCard;
                redin3:
                cin>>RedCard;
                if ((RedCard < 0) || (RedCard > 10)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
                    goto redin3;
                }
                temp = start;
                if(temp->redCard == RedCard ){
                    start = temp->next;
                    delete temp;
                }
                else{
                while(temp->redCard  != RedCard ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp; 
                } 
            break;
            case 9:
                cout<<"\nEnter the number Yellow cards of the player you want to delete : ";
                int YellowCard;
                yellowin3:
                cin>>YellowCard;
                if ((YellowCard < 0) || (YellowCard > 50)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real yellow cards of the player more than 20" << endl;
                    goto yellowin3;
                }
                temp = start;
                if(temp->yellowCard == YellowCard ){
                    start = temp->next;
                    delete temp;
                }
                else{
                while(temp->yellowCard  != YellowCard ){
                    temp2 = temp;
                    temp = temp->next;
                }
                temp2->next = temp->next;
                delete temp;  
                }
            break;
    }
    }
    askingToContinue();
}
void deletAtnth(){
    cout<<"\nwhat nth value you want to delete : ";
    int key;
    cin>>key;
    Player *temp;
    Player *temp2;
    if(start == NULL)
        cout<<"There is no data inserted.";
    else{
        temp = start;
        if(temp->next == NULL){
            delete temp;
            start = NULL;
        }
        else{
            for(int i = 1; i <= key; i++){
                if(i == key){
                break;
            }
            temp2 = temp;
            temp = temp->next;
            }
            temp2->next = temp->next;
            delete temp;
        }
    }
    askingToContinue();
}
void search(){
    cout<<"By which attribute do you want to search \n: ";
    cout<<"\tPress 1  to search by name."<<endl;
    cout<<"\tPress 2  to search by last name."<<endl;
    cout<<"\tPress 3  to search by age."<<endl;
    cout<<"\tPress 4  to search by club."<<endl;
    cout<<"\tPress 5  to search by salary."<<endl;
    cout<<"\tPress 6  to search by goal."<<endl;
    cout<<"\tPress 7  to search by shirtnumber."<<endl;
    cout<<"\tPress 8  to search by number of red card."<<endl;
    cout<<"\tPress 9  to search by number of yellow card."<<endl;
    cout<<"Please select the appropraite number to search by specific attribute : ";
    select3:
    cin>>key;
      if ((key < 1) || (key > 9)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "\tplease enter the among the specified numbers only." << endl;
		goto select3;
	}
    Player *temp;
    int i;
    if(start == NULL)
       cout<<"\nYou have no data to be searched.";
    else {
        switch(key){
            case 1:
                cout<<"\nenter the name of the player you want to search : ";
                char  Name[15];
                cin>>Name;
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                  //  temp->name = toupper(temp->name);
                    if(strcmp(temp->name, Name) == 0){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                            i++;
                    }
                } 
                if(i == 1)
                  cout<<"\nthere is no data matching your item";
            break;
            case 2:
                cout<<"\nenter the last name of the player you want to search : ";
                char  last[15];
                cin>>last;
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                //  temp->name = toupper(temp->name);
                    if(strcmp(temp->lastName, last) == 0){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                }
            }
            if(i == 1)
                  cout<<"\nthere is no data matching your item";
            break;
            case 3:
                cout<<"\nEnter the age of the player you want to search : ";
                int Age;
                agein4:
                cin>>Age;
                if ((Age < 0) || (Age > 130)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real age of the person" << endl;
                    goto agein4;
                }
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                    if(temp->age == Age){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                    }
                }
                if(i == 1)
                  cout<<"\nthere is no data matching your item";     
            break;
            case 4:
                  cout<<"\nEnter the club of the player you want to search : ";
                char Club[15];
                cin>>Club;
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                    if(temp->club == Club){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                    }
                }
                if(i == 1)
                  cout<<"\nthere is no data matching your item";
            break;
            case 5:
                  cout<<"\nEnter the salary of the player you want to search : ";
                int Salary;
                salaryin4:
                cin>>Salary;
                if ((Salary < 0) || (Salary > 50,000)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real salary of Ethiopian players which is less than 50000" << endl;
                    goto salaryin4;
                }
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                    if(temp->salary == Salary){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                    }
                }
                if(i == 1)
                  cout<<"\nthere is no data matching your item";
            break;
            case 6:
               cout<<"\nEnter the goal of the player you want to search : ";
                int Goal;
                goalin4:
                cin>>Goal;
                if ((Goal < 0) || (Goal > 50)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real goal of not more than 50" << endl;
                    goto goalin4;
                }
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                    if(temp->goalScored == Goal){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                    }
                }  
                if(i == 1)
                  cout<<"\nthere is no data matching your item";
            break;
            case 7:
                 cout<<"\nEnter the shirt number of the player you want to search : ";
                int Shirt;
                shirtin4:
                cin>>Shirt;
                if ((Shirt < 0) || (Shirt > 999)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real shirt number of not more than 999" << endl;
                    goto shirtin4;
                }
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                    if(temp->shirtNumber == Shirt){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                    }
                }
                if(i == 1)
                  cout<<"\nthere is no data matching your item";
            break;
            case 8:
                cout<<"\nEnter the numeber red cards  of the player you want to search : ";
                int Red;
                redin4:
                cin>>Red;
                if ((Red < 0) || (Red > 10)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
                    goto redin4;
                }
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                    if(temp->redCard == Red){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                    }
                }
                if(i == 1)
                  cout<<"\nthere is no data matching your item";
            break;
            case 9:
                cout<<"\nEnter the munber of yellow cards of the player you want to search : ";
                int Yellow;
                yellowin4:
                cin>>Yellow;
                if ((Yellow < 0) || (Yellow > 50)|| cin.fail())
                {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real yellow cards of the player more than 20" << endl;
                    goto yellowin4;
                }
                i = 1;
               cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
                for(Player *temp = start; temp != NULL; temp = temp->next){
                    if(temp->yellowCard == Yellow){
                        cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                        i++;
                    }
                }
                if(i == 1){
                  system("cls");
                  cout<<"\nthere is no data matching your item";
                }
            break;
    }
    }
    askingToContinue();
  }
void sort(){
     Player *temp;
     Player *temp1;
     int key;
     if(start == NULL)
       cout<<"\nthere is no data.";
    else{
        cout<<"By which attribute do you want to sort \n: ";
        cout<<"\tPress 1  to sort by name."<<endl;
        cout<<"\tPress 2  to sort by last name."<<endl;
        cout<<"\tPress 3  to sort by age."<<endl;
        cout<<"\tPress 4  to sort by salary."<<endl;
        cout<<"\tPress 5  to sort by goal."<<endl;
        cout<<"\tPress 6  to sort by shirtnumber."<<endl;
        cout<<"\tPress 7  to sort by number of red card."<<endl;
        cout<<"\tPress 8  to sort by number of yellow card."<<endl;
        cout<<"Please select the appropraite number to search by specific attribute : ";
    ask5:
    cin>>key;
    if ((key < 1) || (key > 9)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "please enter the among the specified numbers only." << endl;
		goto ask5;
	}
        switch(key){
            case 1:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(strcmp(temp->name, temp1->name) == 1){
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard);
                        }
                    }
                }
                display();
            break;
            case 2:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(strcmp(temp->lastName, temp1->lastName) == 1){
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard);
                        }
                    }
                }
                display();
            break;
            case 3:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(temp->age > temp1->age){
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard);
                        }
                    }
                }
                display();
            break;
            case 4:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(temp->salary > temp1->salary){
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard); 
                        }
                    }
                }
                display();
            break;
            case 5:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(temp->goalScored > temp1->goalScored){   
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard);
                        }       
                    }   
                }
                display();
            break;
            case 6:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(temp->shirtNumber > temp1->shirtNumber){   
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard);
                        }       
                    }     
                }
                display();
            break;
            case 7:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(temp->redCard > temp1->redCard){                          
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard);
                        }        
                    }    
                }
                display();
            break;
            case 8:
                for(temp = start; temp->next != NULL; temp = temp->next){
                    for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                        if(temp->yellowCard > temp1->yellowCard){   
                            swap(temp->name, temp1->name);
                            swap(temp->age, temp1->age);
                            swap(temp->lastName, temp1->lastName);
                            swap(temp->club, temp1->club);
                            swap(temp->salary, temp1->salary);
                            swap(temp->goalScored, temp1->goalScored);
                            swap(temp->shirtNumber, temp1->shirtNumber);
                            swap(temp->redCard, temp1->redCard);
                            swap(temp->yellowCard, temp1->yellowCard);   
                        }       
                    }   
                }
                display();
            break;
        }
    }
    askingToContinue();
 }
 void update(){
    if(start == NULL)
       cout<<"\nYou have no data to be updated.";
    else {  
    cout<<"By which attribute do you want to Update \n: ";
    cout<<"\tPress 1  to Update by name."<<endl;
    cout<<"\tPress 2  to Update by last name."<<endl;
    cout<<"\tPress 3  to Update by age."<<endl;
    cout<<"\tPress 4  to Update by club."<<endl;
    cout<<"\tPress 5  to Update by salary."<<endl;
    cout<<"\tPress 6  to Update by goal."<<endl;
    cout<<"\tPress 7  to Update by shirtnumber."<<endl;
    cout<<"\tPress 8  to Update by number of red card."<<endl;
    cout<<"\tPress 9  to Update by number of yellow card."<<endl;
    cout<<"Please select the appropraite number to search by specific attribute : ";
    Player *temp;
    int i; 
    ask6:
    cin>>key;
    if ((key < 1) || (key > 9)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "please enter the among the specified numbers only." << endl;
		goto ask6;
	}
        switch(key){
            case 1:
                cout<<"\nEnter the name of the player that you want to update: ";
                char Name[15];
                cin>>Name;
                temp = start;
                while(temp != NULL){
                    if(strcmp(temp->name, Name) == 0){
                        cout<<"\nEnter the new name of the player : ";
                        cin>>temp->name;   
                    }
                    temp = temp->next;       
            } 
            break;
             case 2:
              cout<<"\nEnter the last name of the player that you want to update it's data : ";
                char Last[15];
                cin>>Last;
                temp = start;
                while(temp != NULL){
                    if(strcmp(temp->lastName, Last) == 0){
                        cout<<"\nEnter the new last name of the player : ";
                        cin>>temp->lastName;    
                    }
                    temp = temp->next;
            }
            break;
            case 3:
                cout<<"\nEnter the age of the player that you want to update it's data : ";
                int Age;
                cin>>Age;
                temp = start;
                while(temp != NULL){                  
                    if(temp->age == Age){   
                        cout<<"\nEnter the new age of the player : ";
                        agein22:
                        cin>>temp->age;
                        if ((temp->age < 0) || (temp->age > 130)|| cin.fail())
                        {
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout << "\tplease enter the real age of the person" << endl;
                            goto agein22;
                        }
                    }
                    temp = temp->next;
            }       
            break;
            case 4:
                cout<<"\nEnter the club of the player that you want to update it's data : ";
                char Club[15];
                cin>>Club;
                temp = start;
                while(temp != NULL){
                    if(strcmp(temp->club, Club) == 0){
                        cout<<"\nEnter new the club of the player : ";
                        cin>>temp->club;  
                    }
                    temp = temp->next;
            }
            break;
            case 5:
                cout<<"\nEnter the Salary of the player that you want to update it's data : ";
                int sal;
                cin>>sal;
                temp = start;
                while(temp != NULL){    
                    if(temp->salary == sal){ 
                        cout<<"\nEnter the new salary of the player : ";
                        salaryin44:
                        cin>>temp->salary;
                        if ((temp->salary < 0) || (temp->salary > 50,000)|| cin.fail())
                        {
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout << "\tplease enter the real salary of Ethiopian players which is less than 50000" << endl;
                            goto salaryin44;
                        }
                    }
                    temp = temp->next;
            }
            break;
            case 6:
              cout<<"\nEnter the goal of the player that you want to update it's data : ";
                int goal;
                cin>>goal;
                temp = start;
                while(temp != NULL){
                    if(temp->goalScored == goal){
                        cout<<"\nEnter the new number of goals of the player : ";
                        goalin55:
                        cin>>temp->goalScored;
                        if ((temp->goalScored < 0) || (temp->goalScored > 50)|| cin.fail())
                        {
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout << "\tplease enter the real goal of not more than 50" << endl;
                            goto goalin55;
                        }
                    }
                    temp = temp->next;
            }
            break;
            case 7:
                 cout<<"\nEnter the shirt number of the player that you want to update it's data : ";
                int shrt;
                cin>>shrt;
                temp = start;
                while(temp != NULL){
                    if(temp->shirtNumber == shrt){
                        cout<<"\nEnter the new shirt number of the player : ";
                        shirtin66:
                        int snum;
                        cin>>snum;
                    for(Player *temp = start; temp != NULL; temp = temp->next){
                        if(temp->shirtNumber == snum){
                        cout<<"\nWARRNING!!! You are not allowed  to enter a duplicated shirt number.\nPlease make it unique and TRY AGAIN :";
                        goto shirtin66;
                         }
                    }
                        if ((temp->shirtNumber < 0) || (temp->shirtNumber > 999)|| cin.fail())
                        {
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout << "\tplease enter the real shirt number of not more than 999" << endl;
                            goto shirtin66;
                        }    
                    }
                    temp = temp->next;
            }
            break;
            case 8:
                cout<<"\nEnter the number of red cards of the player that you want to update it's data : ";
                int red;
                cin>>red;
                temp = start;
                while(temp != NULL){
                    if(temp->redCard == red){
                        cout<<"\nEnter the new number of red cards of the player : ";
                        redin0:
                        cin>>temp->redCard;
                        if ((temp->redCard < 0) || (temp->redCard > 10)|| cin.fail())
                        {
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
                            goto redin0;
                        }
                    }
                    temp = temp->next;
            }
            break;
            case 9:cout<<"\nEnter the number of yellow cards of the player that you want to update it's data : ";
                int yellow;
                cin>>yellow;
                temp = start;
                while(temp != NULL){
                    if(temp->yellowCard == yellow){
                        cout<<"\nEnter the new number of yellow cards of the player : ";
                        yellowin88:
                        cin>>temp->yellowCard;
                         if ((temp->yellowCard < 0) || (temp->yellowCard > 50)|| cin.fail())
                        {
                            cin.clear();
                            cin.ignore(256,'\n');
                            cout << "\tplease enter the real yellow cards of the player more than 20" << endl;
                            goto yellowin88;
                        }
                    }
                    temp = temp->next;
            }
            break;
    }
    }
    askingToContinue();
 }
 void maximum(){
     if(start == NULL)
       cout<<"\nthere is no data.";
    else{
         Player *temp;
        int max = start->age;
        int key;
        int i;
        cout<<"Which attribute's maximum do you want to get \n: ";
        cout<<"\tPress 1  to find maximum values of ages."<<endl;
        cout<<"\tPress 2  to find maximum values of salary."<<endl;
        cout<<"\tPress 3  to find maximum values of goal."<<endl;
        cout<<"\tPress 4  to find maximum values of red cards."<<endl;
        cout<<"\tPress 5  to find maximum values of yellow cards."<<endl;
        cout<<"Please select the appropraite number to search by specific attribute : ";
    ask7:
    cin>>key;
    if ((key < 1) || (key > 9)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "please enter the among the specified numbers only." << endl;
		goto ask7;
	}
        cout<<"\nHere are the information of a student that has a maximum value of the selected attribute "<<endl;
        cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
    switch(key){
        case 1:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max < temp->age){
                    max = temp->age;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
                if(temp->age == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
             cout<<"\n\tSO THAT...In Ethipopian national team  the MAXIMUME Age is "<<max<<"."<<endl;
        break;
        case 2:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max < temp->salary){
                    max = temp->salary;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
                if(temp->salary == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MAXIMUME Salary is "<<max<<"."<<endl;
        break;
        case 3:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max < temp->goalScored){
                    max = temp->goalScored;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
                if(temp->goalScored == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MAXIMUME Goal Scored is "<<max<<"."<<endl;
        break;
        case 4:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max < temp->redCard){
                    max = temp->redCard;
                }
            } 
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
            //  temp->name = toupper(temp->name);
                if(temp->redCard == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MAXIMUME number of Red cards is "<<max<<"."<<endl;
        break;
        case 5:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max < temp->yellowCard){
                    max = temp->yellowCard;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
            //  temp->name = toupper(temp->name);
                if(temp->yellowCard == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MAXIMUME number of Yellow cards is "<<max<<"."<<endl;
        break;
        }
    }
    askingToContinue();
 }
 void minimum(){ 
     if(start == NULL)
       cout<<"\nthere is no data.";
    else{
        Player *temp;
        int max = start->age;
        int key;
        int i; 
        cout<<"Which attribute's minimum do you want to get \n: ";
        cout<<"\tPress 1  to find minimum values of ages."<<endl;
        cout<<"\tPress 2  to find minimum values of salary."<<endl;
        cout<<"\tPress 3  to find minimum values of goal."<<endl;
        cout<<"\tPress 4  to find minimum values of red cards."<<endl;
        cout<<"\tPress 5  to find minimum values of yellow cards."<<endl;
        cout<<"Please select the appropraite number to search by specific attribute : ";
    ask8:
    cin>>key;
    if ((key < 1) || (key > 9)|| cin.fail())
	{
		cin.clear();
		cin.ignore(256,'\n');
		cout << "please enter the among the specified numbers only." << endl;
		goto ask8;
	}
        cout<<"\nHere are the information of a student that has a MINIMUMe value of the selected attribute "<<endl;
        cout<<"--------------------------------------------------------------------------------------------\n";
        cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
    switch(key){
        case 1:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max > temp->age){
                    max = temp->age;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
            //  temp->name = toupper(temp->name);
                if(temp->age == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MINIMUME Age is "<<max<<"."<<endl;
        break;
        case 2:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max > temp->salary){
                    max = temp->salary;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
            //  temp->name = toupper(temp->name);
                if(temp->salary == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MINIMUME Salary is "<<max<<"."<<endl;
        break;
        case 3:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max > temp->goalScored){
                    max = temp->goalScored;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
            //  temp->name = toupper(temp->name);
                if(temp->goalScored == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MINIMUME Goal Scored is "<<max<<"."<<endl;
        break;
        case 4:
            for(temp = start; temp != NULL; temp = temp->next){
                if(max > temp->redCard){
                    max = temp->redCard;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
                if(temp->redCard == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MINIMUME number of red cards is "<<max<<"."<<endl;
        break;
        case 5:
            for(temp = start; temp->next != NULL; temp = temp->next){
                if(max > temp->yellowCard){
                    max = temp->yellowCard;
                }
            }
             i = 1;
            for(Player *temp = start; temp != NULL; temp = temp->next){
            //  temp->name = toupper(temp->name);
                if(temp->yellowCard == max){
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                    i++;
                }
                    }
                cout<<"\n\tSO THAT...In Ethipopian national team  the MINIMUME number of Yellow cards is "<<max<<"."<<endl;
        break;
        }
    }
    askingToContinue();
 }
void chooseAction()
{
	int fir, sec;
    cout<<"\nHERE ARE THE ACTIVITIES THAT YOU CAN DO ON THE ETHIOPIAN NATIONAL TEAM FOOTBALL PLAYERS.\n ";
	cout << "\twhat do you want to do?" << endl;
	cout << "\t\t1. Insert Data\n" << "\t\t2. Delete Data\n" << "\t\t3. Update Data\n" << "\t\t4. Search Data\n" << "\t\t5. Sort list\n" << "\t\t6. Display Data\n"<< "\t\t7. Find Maximum Data\n"<< "\t\t8. Find Minimum Data\n"<< "\t\t9. For Counting Occurance\n"<< "\t\t10. For Finding Top n Values\n"<< "\t\t11. For Finding Avarage.";
     reenter:
     cin >> fir;
	if ((fir < 1) || (fir > 11) || cin.fail())
	{
		cout << "please input a choice from the list" << endl;
		cin.clear();
		cin.ignore(256,'\n');
		goto reenter;
	}
	switch (fir)
	{
	case 1:
	{
	cout << "\t1. Insert Data at the beginning\n" << "\t2. Insert Data at the end\n" << "\t3. Insert Data after a data\n" << "\t4. Insert many players at once\n"<<endl;
	reenter2
    :cin >> sec;
		if ((sec < 1) || (sec > 4) || cin.fail())
		{
			cout << "please input a choice from the list" << endl;
			cin.clear();
			cin.ignore(256,'\n');
			goto reenter2;
		}
		switch (sec)
		{
		case 1:
			insertAtBeginning(); break;
		case 2:
			insertAtEnd(); break;
		case 3:
			insertAtMiddleRight(); break;
		case 4:
			insertMany(); break;
		}
	}
	break;
	case 2:
	{
	cout << "\t1. Delete the first Data\n" << "\t2. Delete Data at the end\n" << "\t3. Delete a specific Data \n" << "\t4. Delete the nth data \n"<< "\t5. Delete A Player with MAXIMUME Age \n"<< "\t4. Delete A Player with a MINIMUME AGE \n";
	reenter3
    :cin >> sec;
		if ((sec < 1) || (sec > 6) || cin.fail())
		{
			cout << "please input a choice from the list" << endl;
			cin.clear();
			cin.ignore(256,'\n');
			goto reenter3;
		}
		switch (sec)
		{
		case 1:
			deleteAtBegening(); break;
		case 2:
			deleteAtEnd(); break;
		case 3:
			deleteAtMiddle(); break;
        case 4: 
             deletAtnth(); break;
        case 5:
             deleteMaximumeAge(); break;
        case 6:
             deleteMinimumeAge(); break;
		}
	}
	break;
	case 3:{
		update();
    }
	break;
	case 4:
	{
	search();
    }
	break;
	case 5:
	{
		sort();
	}
	break;
	case 6:{
		display();
    }
    break;
    case 7:{
        maximum();
    }
    break;	
    case 8:{
         minimum();
    }
    break;
    case 9:{
        countOccurence();
    }
    case 10:{
        top();
    }
    break;
    case 11:{
        avarage();
    }
    break;
 }
}
void countOccurence(){
	if(start == NULL)
        cout<<"There is no any information about the players."<<endl;
    else{
        cout<<"\nEnter your choice  :"<<endl;
        cout<<"to count number of occurence by name press 1 :"<<endl;
        cout<<"to count number of occurence by age  press 2 :"<<endl;
        cout<<"to count number of occurence by club press 3 :"<<endl;
        cout<<"to count number of occurence by red card press 4 :"<<endl;
        cout<<"to count number of occurence by yellow card press 5 :"<<endl;
        int key;
        inask80:
        cin>>key;
        if (cin.fail())
		{
			cin.clear();
			cin.ignore(256,'\n');
			cout << "/nplease enter amonng the specified numbers only. : ";
			goto inask80;
		}
        int count=0;
        Player *temp,*temp1;
        switch(key){
            case 1:
                cout<<"enter the name which you want to count the number of occurence "<<endl;
                char Name[15];
                cin>>Name;
                temp=start;
                for(temp=start;temp->next!=NULL;temp=temp->next){
                    if(strcmp(temp->name,Name)==0)
                    count++;
                }
                if(temp->next==NULL)
                if(strcmp(temp->name,Name)==0)
                    count++;
                    cout<<endl<<"the number of occurence of "<<Name<<" is "<<count<<endl;
            break;
                case 2:
                cout<<"enter the Age of the players which you want to count the number of occurence "<<endl;
                int Age;
                inask84:
                cin>>Age;
                if ((Age < 0) || (Age > 150)|| cin.fail())
                 {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "please enter the real age of the person which is less than 150." << endl;
                    goto inask84;
                }
                temp=start;
                for(temp=start;temp->next!=NULL;temp=temp->next){
                    if(temp->age==Age)
                    count++;
                }
                if(temp->next==NULL)
                if(temp->age==Age)
                    count++;
                    cout<<endl<<"the number of occurence of "<<Age<<" is "<<count<<endl;
            break;
                case 3:
                cout<<"enter the name of club which you want to count the number of occurence "<<endl;
                char Club[20];
                cin>>Club;
                temp=start;
                for(temp=start;temp->next!=NULL;temp=temp->next){
                    if(strcmp(temp->club,Club)==0)
                    count++;
                }
                if(temp->next==NULL)
                if(strcmp(temp->club,Club)==0)
                    count++;
                    cout<<endl<<"the number of occurence of "<<Club<<" is "<<count<<endl;
            break;
                case 4:
                cout<<"enter the number of the red cards which you want to count the number of occurence "<<endl;
                int rc;
                inask82:
                cin>>rc;
                if ((rc < 0) || (rc > 10)|| cin.fail())
                        {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real red cards of  the player not more than 10" << endl;
                    goto inask82;
                }
                temp=start;
                for(temp=start;temp->next!=NULL;temp=temp->next){
                    if(temp->redCard==rc)
                    count++;
                }
                if(temp->next==NULL)
                if(temp->redCard==rc)
                    count++;
                    cout<<endl<<"the number of occurence of "<<rc<<" is "<<count<<endl;
            break;
                case 5:
                cout<<"enter the number of yellow card  which you want to count the number of occurence "<<endl;
                int yc;
                inask81:
                cin>>yc;
                 if ((yc < 0) || (yc > 50)|| cin.fail())
                        {
                    cin.clear();
                    cin.ignore(256,'\n');
                    cout << "\tplease enter the real yellow cards of the player more than 50" << endl;
                    goto inask81;
                }
                temp=start;
                for(temp=start;temp->next!=NULL;temp=temp->next){
                    if(temp->yellowCard==yc)
                    count++;
                }
                if(temp->next==NULL)
                if(temp->yellowCard==yc)
                    count++;
                    cout<<endl<<"the number of occurence of "<<yc<<" is "<<count<<endl;
            break;
            default :
            cout<<"invalid input"<<endl;
        }
    }
    askingToContinue();
}
void deleteMinimumeAge(){
	     Player *temp;
		 Player *temp1;
     int min = start->age; 
     for(temp = start; temp->next != NULL; temp = temp->next){
         if(min > temp->age){
             min = temp->age;
         }
         temp1=temp;
     }
        if(temp->next==NULL)
        {
        	if(min > temp->age)
        	 min = temp->age;
		}    
     temp1->next=temp->next;
     delete temp;
    cout<<"\nYou have successfully deleted the players with a minimume age.\n";
	askingToContinue();
}
void deleteMaximumeAge(){
	     Player *temp;
		 Player *temp1;
     int max = start->age; 
     for(temp = start; temp->next != NULL; temp = temp->next){
         if(max < temp->age){
             max = temp->age;
         }
         temp1=temp;
     }
        if(temp->next==NULL)
        {
        	if(max < temp->age)
        	 max = temp->age;
		}    
     temp1->next=temp->next;
     delete temp;	
     cout<<"\nYou have successfully deleted the players with a maximume age.\n";
     askingToContinue();
}
void top(){
    if(start == NULL)
    cout<<"\nThere is no data."<<endl;
        else{
        cout<<"\nenter your choice to calculate :"<<endl;
        cout<<"\tPress 1 : For top ten by name"<<endl;
        cout<<"\tPress 2 : For top seven by age."<<endl;
        cout<<"\tPress 3 : For top fifteen by salary."<<endl;
        cout<<"\tPress 4 : For top tewenty by shirt number."<<endl;
        int key;
        cin>>key;
        Player *temp,*temp1;
        switch(key){
            case 1:
                cout<<"The first 10 players when they are oredered alphabetically"<<endl;
                cout<<"--------------------------------------------------------------------------------------------------"<<endl;
                for(temp = start; temp->next != NULL; temp = temp->next){
                        for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                            if(strcmp(temp->name, temp1->name) == 1){
                                
                                swap(temp->name, temp1->name);
                                swap(temp->age, temp1->age);
                                swap(temp->lastName, temp1->lastName);
                                swap(temp->club, temp1->club);
                                swap(temp->salary, temp1->salary);
                                swap(temp->goalScored, temp1->goalScored);
                                swap(temp->shirtNumber, temp1->shirtNumber);
                                swap(temp->redCard, temp1->redCard);
                                swap(temp->yellowCard, temp1->yellowCard);
                                
                            }
                            
                                
                        }                   
                    }
        cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
        temp=start;
            for(int i=0;i<10 && temp != NULL;i++){			   
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                temp = temp->next;
            }
            break;   
                case 2:
                    cout<<"Top 20 youngest players in your data"<<endl;
                    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
                for(temp = start; temp->next != NULL; temp = temp->next){
                        for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                            if(temp->age > temp1->age){                           
                                swap(temp->name, temp1->name);
                                swap(temp->age, temp1->age);
                                swap(temp->lastName, temp1->lastName);
                                swap(temp->club, temp1->club);
                                swap(temp->salary, temp1->salary);
                                swap(temp->goalScored, temp1->goalScored);
                                swap(temp->shirtNumber, temp1->shirtNumber);
                                swap(temp->redCard, temp1->redCard);
                                swap(temp->yellowCard, temp1->yellowCard);                            
                            }                                                    
                        }                   
                    }
        cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
        temp=start;
            for(int i=0;i<20 && temp != NULL; i++){			   
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                temp = temp->next;
  
            }
            break;
                case 3:
                    cout<<"Fifteen highly paid players"<<endl;
                   cout<<"--------------------------------------------------------------------------------------------------"<<endl;
                for(temp = start; temp->next != NULL; temp = temp->next){
                        for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                            if(temp->salary > temp1->salary){                           
                                swap(temp->name, temp1->name);
                                swap(temp->age, temp1->age);
                                swap(temp->salary, temp1->salary);
                                swap(temp->lastName, temp1->lastName);
                                swap(temp->club, temp1->club);
                                swap(temp->goalScored, temp1->goalScored);
                                swap(temp->shirtNumber, temp1->shirtNumber);
                                swap(temp->redCard, temp1->redCard);
                                swap(temp->yellowCard, temp1->yellowCard);                           
                            }                                                   
                        }                
                    }
        cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
        temp=start;
            for(int i=0;i<15 && temp != NULL; i++){
                
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                temp = temp->next;
            }
            break;
                    case 4:
                        cout<<"Top 7 goal scorers"<<endl;
                        cout<<"--------------------------------------------------------------------------------------------------"<<endl;
                for(temp = start; temp->next != NULL; temp = temp->next){
                        for(temp1 = temp->next; temp1 != NULL ; temp1 = temp1->next){
                            if(temp->goalScored > temp1->goalScored){                      
                                swap(temp->name, temp1->name);
                                swap(temp->age, temp1->age);
                                swap(temp->salary, temp1->salary);
                                swap(temp->goalScored, temp1->goalScored);
                                swap(temp->lastName, temp1->lastName);
                                swap(temp->club, temp1->club);
                                swap(temp->shirtNumber, temp1->shirtNumber);
                                swap(temp->redCard, temp1->redCard);
                                swap(temp->yellowCard, temp1->yellowCard);                        
                            }                                            
                        }  
                    }
        cout<<setw(10)<<"Name"<<setw(16)<<"Last Name"<<setw(8)<<"Age"<<setw(15)<<"Club"<<setw(15)<<"Salary"<<setw(8)<<"Goal"<<setw(20)<<"Shirt Number"<<setw(20)<<"Red Card"<<setw(20)<<"Yellow Card"<<endl;
        temp=start;
            for(int i=0;i<7&& temp != NULL; i++){			   
                cout<<setw(10)<<temp->name<<setw(16)<<temp->lastName<<setw(8)<<temp->age<<setw(15)<<temp->club<<setw(15)<<temp->salary<<setw(8)<<temp->goalScored<<setw(20)<<temp->shirtNumber<<setw(20)<<temp->redCard<<setw(20)<<temp->yellowCard<<endl;
                temp = temp->next;
            }
            break; 
        }	
    }
            askingToContinue();	
}
void wellcome(){
	
	  cout<<"\n\t\t                                        ";
	  cout<<"\n\t\t              L      C                  ";
	  cout<<"\n\t\t         L                O             ";
	  cout<<"\n\t\t      E         TO           M          ";
	  cout<<"\n\t\t   W   ETHIPIAN NATIONAL TEAM!   E  \n\n";
	  system("pause");
	  }

