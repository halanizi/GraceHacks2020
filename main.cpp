#include <iostream>
#include <fstream>
#include <vector>

//#include "Vocabulary.h" //this is if we are calling a function from another file

using namespace std;
int points;

void vocabulary();
void history();
void influencers();
void q_and_a(vector<string>, vector<string>);
void selection();
void play();
bool checkString(string);

int main(int argc, char **argv)
{
    //int points=0;
    cout << "Welcome! Pick a category to start the game:\n"<< endl;
    selection();
    play();
    return (0);
}

void vocabulary() {
//    cout << "howdy" << endl;
    ifstream question_file; // read mode
    question_file.open("definitions.txt");
    ifstream answer_file; // read mode
    answer_file.open("vocab.txt");

    vector<string> questions;
    vector<string> answers;

    string line;
    while (getline(question_file, line)) {
        questions.push_back(line);
    }
    while (getline(answer_file, line)) {
        answers.push_back(line);
    }

    question_file.close();
    answer_file.close();

    q_and_a(questions, answers);
}

void history() {
    ifstream question_file; // read mode
    question_file.open("inventions.txt");
    ifstream answer_file; // read mode
    answer_file.open("inventors.txt");

    vector<string> questions;
    vector<string> answers;

    string line;
    while (getline(question_file, line)) {
        questions.push_back(line);
    }
    while (getline(answer_file, line)) {
        answers.push_back(line);
    }

    question_file.close();
    answer_file.close();
    q_and_a(questions, answers);

}

void influencers() {
    ifstream question_file; // read mode
    question_file.open("quotes.txt");
    ifstream answer_file; // read mode
    answer_file.open("speakers.txt");

    vector<string> questions;
    vector<string> answers;

    string line;
    while (getline(question_file, line)) {
        questions.push_back(line);
    }
    while (getline(answer_file, line)) {
        answers.push_back(line);
    }

    question_file.close();
    answer_file.close();
    q_and_a(questions, answers);
}

void q_and_a(vector<string> q, vector<string> a) {
    unsigned int i = 0;
    string response;

//    cout <<"Num elements in vector is: " << q.size() << endl;
//    cout <<"num elements in vector a: " << a.size() << endl;

    while(i < q.size()) {
        cout << q[i] << endl;

        //char response[100];
        string response;
        //cin.ignore();
        if(i==0) getline(cin, response);
        getline(cin, response);
        //cin.getline(response, 100);

 //       cout << "Response was: " << response << endl;
 //       cout << "A[i] is: " << a[i] << endl;

        if (a[i].compare(response) == 0) {
            i++;
            cout << "Correct!" << endl;
            points++;
            cout << "Yay!" << endl;
            ifstream correct_art;
            correct_art.open("goodjob.txt");
            cout << correct_art.rdbuf();
            correct_art.close();
            //continue;

        } else {
            cout << "I'm sorry, that's not the right answer" << endl;
            ifstream not_correct_art; // read mode
            not_correct_art.open("wrong.txt");
            cout << not_correct_art.rdbuf();
            not_correct_art.close();
        }
        if(i==q.size()){
            break;
        }
    }
    cout <<"You finished the category!" << endl;
}

void selection(){
    points = 0;
    int x = 0;
    string option;
    char input;
    while (x == 0)
    {
        cout << "          * Vocabulary" << endl;
        cout << "          * History" << endl;
        cout << "          * Influencers" << endl;
        //cout << "         (4) Blah" << endl;
        //cout << "         (5) BlahBlah\n"<< endl;
        
        
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
                history();
                break;
            case 'I':
            case 'i':
                x = 1;
                //cout<<"Case3"<<endl;
                influencers();
                break;
            default:
                cout << "Invalid Option! Try Again\n" << endl;
        }
        
    }

}

void play(){
    //int points;
    //int result;
    int x=0;
    string playAgain;
    char again;
    while(x==0){
        cout<<"You scored "<<points<<"points!\n"<<endl;
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