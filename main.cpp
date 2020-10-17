#include <iostream>
#include <fstream>
#include <vector>

//#include "Vocabulary.h" //this is if we are calling a function from another file

using namespace std;

void vocabulary()
{
    cout << "howdy" << endl;
    ifstream question_file; // read mode
    question_file.open("questions.txt");
    ifstream answer_file; // read mode
    answer_file.open("answers.txt");

    vector<string> questions;
    vector<string> answers;

    string line;
    while (getline(question_file, line))
    {
        questions.push_back(line);
    }
    while (getline(answer_file, line))
    {
        answers.push_back(line);
    }

    for (unsigned int i = 0; i < questions.size(); i++)
    {
        cout << questions.at(i) << endl;
        cout << i << endl;
    }
    question_file.close();
    answer_file.close();
}

void selection(){
    int x = 0;
    string option;
    char input;
    while (x == 0)
    {
        cout << "         (1) Vocabulary" << endl;
        cout << "         (2) History" << endl;
        cout << "         (3) Influencers" << endl;
        cout << "         (4) Blah" << endl;
        cout << "         (5) BlahBlah\n"<< endl;

        cin >> option;
        input = option.at(0);
        cout << "You picked " << option << "!" << endl;

        switch (input)
        {
        case 'V':
        case 'v':
            x = 1;
            //cout<<"Case1"<<endl;
            vocabulary();
            break;
        case 'H':
        case 'h':
            x = 1;
            //cout<<"Case2"<<endl;
            void History();
            break;
        case 'I':
        case 'i':
            x = 1;
            //cout<<"Case3"<<endl;
            void Influencers();
            break;
        default:
            cout << "Invalid Option! Try Again\n"
                 << endl;
        }
    }

}

void play(){
int x=0;
string playAgain;
    char again;
    while(x==0){
    cout<<"Would you like to choose another category?"<<endl;
    cin>>playAgain;
    again = playAgain.at(0);
    switch(again){
        case 'Y':
        case 'y':
            //start the main again
            cout<<"Thank you for playing again! Pick another category!"<<endl;

            selection();
            break;
        
        case 'N':
        case 'n':
        x=1;
            cout<<"Thanks for playing!"<<endl;
            break;
    }
    }
}

int main(int argc, char **argv)
{
    int points;
    int result;
    cout << "Welcome! Pick a category to start the game:\n"<< endl;
    selection();
    play();
    return (0);
}
