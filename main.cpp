#include <iostream>
#include <fstream>
#include <vector>

//#include "Vocabulary.h" //this is if we are calling a function from another file

using namespace std;
int points;

void vocabulary();
void history();
void influencers();
void q_and_a(vector<string>, vector<string>, vector<string>);
void selection();
void play();

int main(int argc, char **argv)
{
    //int points=0;
    cout << "Welcome! Pick a category to start the game:\n"<< endl;
    selection();
    play();
    return (0);
}

void vocabulary() {
    ifstream question_file; // read mode
    question_file.open("definitions.txt");
    ifstream answer_file; // read mode
    answer_file.open("vocab.txt");
    ifstream links_file; // read mode
    links_file.open("vocablinks.txt");

    vector<string> questions;
    vector<string> answers;
    vector<string> links;

    string line;
    string prompt = "Match this definition to a vocabulary term:";
    while (getline(question_file, line)) {
        questions.push_back(line);
    }
    questions.push_back(prompt);
    while (getline(answer_file, line)) {
        answers.push_back(line);
    }
    while (getline(links_file, line)) {
        links.push_back(line);
    }

    question_file.close();
    answer_file.close();
    links_file.close();

    q_and_a(questions, answers, links);
}

void history() {
    ifstream question_file; // read mode
    question_file.open("inventions.txt");
    ifstream answer_file; // read mode
    answer_file.open("inventors.txt");
    ifstream links_file; // read mode
    links_file.open("inventorlinks.txt");

    vector<string> questions;
    vector<string> answers;
    vector<string> links;

    string line;
    string prompt = "Match this invention to a female inventor:";
    while (getline(question_file, line)) {
        questions.push_back(line);
    }
    questions.push_back(prompt);
    while (getline(answer_file, line)) {
        answers.push_back(line);
    }
    while (getline(links_file, line)) {
        links.push_back(line);
    }

    question_file.close();
    answer_file.close();
    links_file.close();

    q_and_a(questions, answers, links);

}

void influencers() {
    ifstream question_file; // read mode
    question_file.open("quotes.txt");
    ifstream answer_file; // read mode
    answer_file.open("speakers.txt");
    ifstream links_file; // read mode
    links_file.open("speakerlinks.txt");

    vector<string> questions;
    vector<string> answers;
    vector<string> links;

    string line;
    string prompt = "Match this quote to a female speaker:";
    while (getline(question_file, line)) {
        questions.push_back(line);
    }
    questions.push_back(prompt);
    while (getline(answer_file, line)) {
        answers.push_back(line);
    }
    while (getline(links_file, line)) {
        links.push_back(line);
    }

    question_file.close();
    answer_file.close();
    links_file.close();

    q_and_a(questions, answers, links);
}

void q_and_a(vector<string> q, vector<string> a, vector<string> l) {
    unsigned int i = 0;
    string response;
    string prompt;


    while(i < 10) { //element q[10] is the prompt
        cout << "" << endl;
        cout << q[10] << endl;
        cout << "" << endl;
        cout << q[i] << endl;
        cout << "" << endl;

        if (i == 0) {
            getline(cin, response);
        }
        getline(cin, response);

        string solution = a[i];
        
        for (unsigned int j = 0; j < response.size(); j++) {
            response[j] = tolower(response[j]);
        }
        for (unsigned int k = 0; k < solution.size(); k++) {
            solution[k] = tolower(solution[k]);
        }

        if (solution.compare(response) == 0) {
            cout << "Correct! If you'd like to learn more about this term, navigate to this link :" << endl;
            cout << l[i] << endl;
            i++;
            points++;
 //         cout << "Yay!" << endl;
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
            history();
            break;
        case 'I':
        case 'i':
            x = 1;
            //cout<<"Case3"<<endl;
            influencers();
            break;
        default:
            cout << "Invalid Option! Try Again\n"
                 << endl;
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
                ifstream lady_art;
            lady_art.open("lady.txt");
            cout << lady_art.rdbuf();
            lady_art.close();
                break;
        }
    }
}

