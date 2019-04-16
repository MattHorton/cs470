#include<iostream>
#include<string>
#include<fstream>
#include<queue>

using namespace std;

int main(int argc, char** argv) {
    queue <int> pid[150];

    printf("\n%s\n\n", argv[1]); //double check input file string
    ifstream inputFile(argv[1]); //open input file

    int tpid; //temp pid
    int tpage;//temp page request

    //get page requests for each process
    while(inputFile >> tpid >> tpage) {
        pid[tpid].push(tpage);
    }
    //iterate through processes and print their page request queues
    for(int i = 0; i < 150; i++) {
        cout << '[' << i << "]: ";
        while(!pid[i].empty()) {
            cout << pid[i].front() << ' ';
            pid[i].pop();
        }
        cout << endl;
    }

    return 0;
}