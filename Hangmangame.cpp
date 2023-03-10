#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_TRIES=5;
int letterFill (char, string, string&);

int main ()
{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"orange",
		"watermelon",
		"papaya",
		"grapes",
		"fig",
		"cherrie",
		"berries",
		"apple",
		"pear",
		"mango",
		"banana",
		"pinapple",
		"sopata"
	};

	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];
    
	string unknown(word.length(),'*');

	cout << "\n\nWelcome to hangman...Guess a fruit  Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
	
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
			if (num_of_wrong_guesses == 1)
           cout<<("   _____ \n"
                  "  |     | \n"
                  "  |      \n"
                  "  |      \n"
                  "  |      \n"
                  "  |      \n"
                  "  |      \n"
                  "__|__\n");
 
        else if (num_of_wrong_guesses == 2)
           cout<<("   _____ \n"
                  "  |     | \n"
                  "  |     |\n"
                  "  |      \n"
                  "  |      \n"
                  "  |      \n"
                  "  |      \n"
                  "__|__\n");
 
        else if (num_of_wrong_guesses == 3)
          cout<<("   _____ \n"
                 "  |     | \n"
                 "  |     |\n"
                 "  |     | \n"
                 "  |     O \n"
                 "  |      \n"
                 "  |      \n"
                 "__|__\n");
 
        else if (num_of_wrong_guesses == 4)
           cout<<("   _____ \n"
                  "  |     | \n"
                  "  |     |\n"
                  "  |     | \n"
                  "  |     O \n"
                  "  |    /|] \n"
                  "  |      \n"
                  "__|__\n");
 
        else if (num_of_wrong_guesses == 5)
           cout<<("   _____ \n"
                  "  |     | \n"
                  "  |     |\n"
                  "  |     | \n"
                  "  |     O \n"
                  "  |    /|] \n"
                  "  |    / | \n"
                  "__|__\n");
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}

		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;

		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	}
	cout<<"\nby:chandana mn "<<endl;
    cout<<"20030141cse060"<<endl;
    cout<<"sec:B";

	cin.ignore();
	cin.get();
	return 0;
}


int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		if (guess == guessword[i])
			return 0;
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
