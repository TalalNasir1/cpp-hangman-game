#include<iostream>
#include<fstream>
#include<ctime> //Used for getting random word from the file.
#include<cstdlib>
#include<string>
using namespace std;

void GetWord(string &word)
{
	fstream myfile;//file Handling

	string wordlist[100]; //Word array
	int random;

	myfile.open("Word List.txt");

	for(int i=0;i<100;i++){
		myfile >> wordlist[i];
	}

	srand(time(0)); //Takes computers clock time and proforms an alorithm to get a random num.
	random=rand()%100;
	word=wordlist[random];

	myfile.close();
}
int main()
{

	cout<<"\t */*/*/*/*/*/*/*/*/*/*HANGMAN*/*/*/*/*/*/*/*/*/*/*\n";
	cout<<"\t ___________________________________________________\n\n";

	char start{};

	cout <<"\n\n Press any key and Enter to Begin !";
	cin >> start;

	int lives=6,x;
	string word;

	char guess;
	char guessed[7]; //for displaying wrong guesses.
	guessed[0]='\0'; //to prevent garbage value

	for(int i=1;i<6;i++)
    {
		guessed[i]='-';
	}
	guessed[6]='\0';

    GetWord(word);
    //cout << word<<endl; //can be used for checking/cheating.
    x=word.length();
    string unknown(x,'*');

	while(lives>=0)
        {
		bool correct=false;
		cout << "\n Your word is: "<< unknown << endl;
		cout << "\n Which contains " << x<<" letters.\n";
		cout << "\n Your lives left to keep playing are: " << lives<< endl;
		if(guessed[0]!='\0'){
			cout <<"\n Already Guessed Letters are: "<< guessed <<endl;
		}
		cout << "\n TAKE A GUESS: ";
		cin >> guess;

		for(int i=0;i<x;i++)
		{
			if(word[i]==guess){
				unknown[i]= guess;
				correct=true;
			}
		}
		if(correct==true)
		{
				cout <<"You guessed letter '" << guess << "' correctly,CONGRATS. \n";
			}
			else{
				cout <<"You guessed letter '" << guess << "' incorrectly. \n";
				lives--;
			}
		if(word==unknown)
		{
			cout<<"\n\n\n\n ^^^^^YOU WON THE GAME^^^^^\n\n\n";
			break;
		}
        if (lives == 0)
        {

        cout<<endl;
        cout << "The word was: " << word << endl;
        }

		switch(lives)
		{
			case 6:{
				cout<<" \n_________________\n";
                cout<<"     |/      !\n";
                cout<<"     |         \n";
                cout<<"     |         \n";
                cout<<"     |         \n";
                cout<<"     |           \n";
                cout<<"     |\n";
                cout<<"  ___|___\n\n\n";
				break;
			}
			case 5:
			    {
				cout<<"\n _________________\n";
                cout<<"     |/      !\n";
                cout<<"     |      (_)\n";
                cout<<"     |          \n";
                cout<<"     |         \n";
                cout<<"     |           \n";
                cout<<"     |\n";
                cout<<"  ___|___\n\n\n";
                if(correct==false){
                	guessed[0]=guess;
				}
				break;
			}
			case 4:
			    {
				cout<<" \n_________________\n";
                cout<<"     |/      !\n";
                cout<<"     |      (_)\n";
                cout<<"     |       |  \n";
                cout<<"     |       | \n";
                cout<<"     |           \n";
                cout<<"     |\n";
                cout<<"  ___|___\n\n\n";
                if(correct==false){
                	guessed[1]=guess;
				}
				break;
			}
			case 3:
			    {
				cout<<" \n_________________\n";
                cout<<"     |/      !\n";
                cout<<"     |      (_)\n";
                cout<<"     |      \\| \n";
                cout<<"     |       | \n";
                cout<<"     |           \n";
                cout<<"     |\n";
                cout<<"  ___|___\n\n\n";
                if(correct==false){
                	guessed[2]=guess;
				}
				break;
			}
			case 2:
			    {
				cout<<" \n_________________\n";
                cout<<"     |/      !\n";
                cout<<"     |      (_)\n";
                cout<<"     |      \\|/\n";
                cout<<"     |       | \n";
                cout<<"     |           \n";
                cout<<"     |\n";
                cout<<"  ___|___\n\n\n";
                if(correct==false){
                	guessed[3]=guess;
				}
				break;
			}
			case 1:
			    {
				cout<<" \n_________________\n";
                cout<<"     |/      !\n";
                cout<<"     |      (_)\n";
                cout<<"     |      \\|/\n";
                cout<<"     |       | \n";
                cout<<"     |      /    \n";
                cout<<"     |\n";
                cout<<"  ___|___\n\n\n";
                if(correct==false){
                	guessed[4]=guess;
				}
				break;
			}
			case 0:
			    {
				cout<<" \n_________________\n";
                cout<<"     |/      !\n";
                cout<<"     |      .@.\n";
                cout<<"     |      /|\\\n";
                cout<<"     |       | \n";
                cout<<"     |      | |\\ \n";
                cout<<"     |\n";
                cout<<"  ___|___\n\n\n";
                cout<<"\n\n!!!!!GAME OVER!!!!!\n";
				lives=-1;
				break;
			}
		}
	}

	return 0;
}
