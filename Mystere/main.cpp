#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

/* swapLetters return false if the word is shorter than a 2 letters word
otherwise swapLetters takes a string and permute randomly the elements in that string. */
string swapLetters (string word)
{
    int randomNumber(0), wordLength(word.size());
    char charStorage;
    {
        for (int k(wordLength-1); k>0; k--)
        {
            randomNumber = rand() % k;
            charStorage=word[k];
            word[k]=word[randomNumber];
            word[randomNumber]=charStorage;
        }
        return word;
    }
}

string anotherRound(string& keepPlaying)
{
    cout << "Do you want to play another round? Please enter 'yes' or 'no': " << endl;
    cin >> keepPlaying;
    while (keepPlaying.compare("yes")!=0&&keepPlaying.compare("no")!=0)
    {
        cout << "Please follow the instructions and enter 'yes or 'no': " << endl;
        cin >> keepPlaying;
    }
    return keepPlaying;
}

int main()
{
    string keepPlaying("yes");
    do
    {

        srand(time(0));
        string word;
        cout << "Please enter the word you want people to guess: " << endl;
        cin >> word;

        int wordLength(word.size());
        while(wordLength<2)
        {
            cout << "The suggested word is too short, please re-enter your word: " << endl;
            cin >> word;
            wordLength=word.size();
        }

        string wordAfterSwap = swapLetters(word);

        string playerGuess;
        int numberGuess(5);
        cout << "What is this word? Remember, you only have "<< numberGuess << " attempts: " << wordAfterSwap << endl;
        --numberGuess;
        cin >> playerGuess;

        while (playerGuess.compare(word)!=0&&numberGuess>0)
        {
            cout << "Oh no, you got the wrong word! Please guess again." << endl;
            cout << "What is this word?( "<< numberGuess << " attempts left ): " << wordAfterSwap << endl;
            cin >> playerGuess;
            --numberGuess;
        }

        if(playerGuess.compare(word)==0)
        {
            cout << "Bingo, you win!" << endl;
            anotherRound(keepPlaying);
        }
        else
        {
            cout <<"Game over! You were so close!" << endl;
            anotherRound(keepPlaying);
        }


    }
    while (keepPlaying.compare("yes")==0);
    return 0;


}


