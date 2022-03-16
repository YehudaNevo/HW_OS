#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include "string"

class Process {

private:

    int pid;
    int arrival_time;
    int burst_time;
    int priority = 0;

public:
    Process(int pid_, int arrivaltime, int bursttime) {
        this->pid = pid_;
        this->arrival_time = arrivaltime;
        this->burst_time = bursttime;
    }

    int getPid() const {
        return pid;
    }

    int getArrivalTime() const {
        return arrival_time;
    }

    int getBurstTime() const {
        return burst_time;
    }

    int getPriority() const {
        return priority;
    }
};


void FCFS();

void getDataFcfs(vector<Process>);


int main() {

//    FCFS();



    return 0;
}


void FCFS() {


    vector<Process> my_process;
    getDataFcfs(my_process);

    // getting the data from the user  into the my_process queue...

    unsigned long size = my_process.size();
    int time = 0;
    int total_waiting_time = 0;

    for (int i = 0; i < size; i++) {
        int b_time = my_process.front().getBurstTime();
        int a_time = my_process.front().getArrivalTime();

        cout << i + 1 << "# : " << "[" << time << "]-[" << time + b_time << "] ";
        int w_time = time - a_time;
        time += b_time;
        total_waiting_time += w_time;
        cout << "waiting time = " << w_time << endl;
        my_process.pop_back();
    }
    cout << "average time = " << float(total_waiting_time) / size << endl;

}


void getDataFcfs(vector <Process> lst) {

    int pid;
    int arrival_time;
    int burst_time;


    char ans = ' ';
    cout << "for random data enter r , for user data enter  u" << endl;
    cin >> ans;


    if (ans == 'u') {
        char c = 'a';
        while (c != 'q') {
            cout << "please enter pid arrival timme and burst time..." << endl;
            cin >> pid;
            cin >> arrival_time;
            cin >> burst_time;

            auto *temp = new Process(pid, arrival_time, burst_time);
            lst.push_back(*temp);

            cout << "if you end enter q else enter  y" << endl;
            cin >> c;
        }
    } else {
        for (int i = 0; i < 10; i++) {
            int r = rand() % 20;
            pid = i;
            burst_time =r;
            arrival_time = (i)

        }
    }

}

