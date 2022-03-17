#include <vector>
#include "HW_1.h"
#include "cstdlib"

using namespace std;

// helper function (implement below ..)
void getData(vector<Process> &my_process, bool userInput);

void HW_1::FCFS(bool userInput) {

//  [ process1 , process2 .... process100 ... ] process = [pid,arrival time , burst time , priority = 0 ]
    vector<Process> my_process;
    getData(my_process, userInput);


    // wll sort the processes by their arrival time ...
    sort(my_process.begin(), my_process.end(), [](const Process &a, const Process &b) ->
            bool { return a.getArrivalTime() < b.getArrivalTime(); });


    unsigned long size = my_process.size();
    int time = my_process[0].getArrivalTime();
    int total_waiting_time = 0;

    for (auto &it: my_process) {

        int pid = it.getPid();
        int b_time = it.getBurstTime();
        int a_time = it.getArrivalTime();
        cout << " [  pid " << pid << " arrival time = " << a_time << ", burst time = " << b_time << " ]" << endl;

        cout << pid << "# : " << "[" << time << "]-[" << time + b_time << "] ";
        int w_time = max(0, time - a_time);
        cout << "waiting time = " << w_time << endl;
        time += b_time;
        total_waiting_time += w_time;
        cout << endl;
    }
    cout << "average time = " << float(total_waiting_time) / size << endl;
}

void HW_1::SJF(bool userInput) {

    vector<Process> my_processes;
    getData(my_processes, userInput);
    int time = 0;
    int total_waiting_time = 0;
    int temp_w_time = 0;

    // wll sort the processes by their burst time ...
    sort(my_processes.begin(), my_processes.end(), [](const Process &a, const Process &b) ->
            bool { return a.getBurstTime() < b.getBurstTime(); });


    // after
    int count = 0;
    while (!my_processes.empty()) {
        auto it = my_processes.begin();
        for (; it != my_processes.end(); it++) {
            if (it->getArrivalTime() <= time) {
                temp_w_time = time - it->getArrivalTime();
                time += it->getBurstTime();
                total_waiting_time += temp_w_time;
                my_processes.erase(--it);
                cout << count++ <<" [ pid " << it->getPid() << " arrival time " << it->getArrivalTime() << " burst time = "
                     << it->getBurstTime() << " ] " << endl;
                cout << "[" << time - it->getBurstTime() << "] - [" << time << "]" << " waiting time = " << temp_w_time
                     << endl << endl;
            }
        }
    }


}

// getting tha data for fcfs and sjf
void getData(vector<Process> &my_process, bool userInput) {
    int pid;
    int arrival_time;
    int burst_time;


    // the  user insert the data... 3 processes
    if (userInput) {
        cout << "please insert 3 processes .. process = [ pid , arrival time , burst time ]   " << endl;
        cin >> pid >> arrival_time >> burst_time;
        auto *temp = new Process(pid, arrival_time, burst_time);
        my_process.push_back(*temp);

        // random 10 processes
    } else {
        for (int i = 0; i < 10; i++) {
            int r = rand();
            pid = r;
            burst_time = r % 100;
            arrival_time = r % 5;
            auto *temp = new Process(pid, arrival_time, burst_time);
            my_process.push_back(*temp);
        }
    }

}




