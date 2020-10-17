#include<iostream>
#include<fstream>
#include<vector>

//#include "Vocabulary.h" //this is if we are calling a function from another file

using namespace std;

void vocabulary () {
    cout << "howdy" << endl;
    ifstream question_file; // read mode
    question_file.open("questions.txt");
    ifstream answer_file; // read mode
    answer_file.open("answers.txt");

    vector<string> questions;
    vector<string> answers;

    string line;
    while (getline(question_file, line)) {
        questions.push_back(line);
    }
    while (getline(answer_file, line)) {
        answers.push_back(line);
    }

    for (unsigned int i = 0; i < questions.size(); i++) {
        cout << questions.at(i) << endl;
        cout << i << endl;
    }
    question_file.close();
    answer_file.close();

}

int main(int argc, char** argv) {
    string option;
    char input;
    //int lengthOfOption;

    cout<<"Welcome! Pick a category to start the game:\n"<<endl;
    cout<<"         (1) Vocabulary"<<endl;
    cout<<"         (2) History"<<endl;
    cout<<"         (3) Influencers"<<endl;
    cout<<"         (4) Blah"<<endl;
    cout<<"         (5) BlahBlah\n"<<endl;

    cin>>option;
    input=option.at(0);
    cout<<"You picked "<<option<<"!"<<endl;

    switch(input){
        case 'V': 
        case 'v':
            cout<<"Case1"<<endl;
            vocabulary();
            break;
        case 'H':
        case 'h':
            cout<<"Case2"<<endl;
            void History();
            break;
        case 'I':
        case 'i':
            cout<<"Case3"<<endl;
            void Influencers();
            break;
    }
    return(0);
}
