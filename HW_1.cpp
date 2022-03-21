#include <vector>
#include "HW_1.h"
#include "cstdlib"

using namespace std;

// helper function (implement below ..)
void getData(vector<Process> &my_process, bool userInput);

void HW_1::FCFS(bool userInput) {

    cout << "------------FCFS------------------\n" << endl;

//  [ process1 , process2 .... process100 ... ] process = [pid, arrival time , burst time , priority = 0 ]

    vector<Process> my_process;
    getData(my_process, userInput);


    // wll sort the processes by their arrival time ...
    sort(my_process.begin(), my_process.end(), [](const Process &a, const Process &b) ->
            bool { return a.getArrivalTime() < b.getArrivalTime(); });


    unsigned long size = my_process.size();
    int time = my_process[0].getArrivalTime();
    int total_waiting_time = 0;
    int count = 0;

    for (auto &it: my_process) {

        int pid = it.getPid();
        int b_time = it.getBurstTime();
        int a_time = it.getArrivalTime();
        cout << " [  pid " << pid << " arrival time = " << a_time << ", burst time = " << b_time << " ]" << endl;

        cout << count++ << "# : " << "[" << time << "]-[" << time + b_time << "] ";
        int w_time = max(0, time - a_time);
        cout << "waiting time = " << w_time << endl;
        time += b_time;
        total_waiting_time += w_time;
        cout << endl;
    }
    cout << "---------average time FCFS = " << float(total_waiting_time) / size << "----------\n" << endl;
}

void HW_1::SJF(bool userInput) {
    cout << "------------Sjf------------------\n" << endl;

    vector<Process> ready_list;
    getData(ready_list, userInput);
    int size = ready_list.size();
    int time = 0;
    int total_waiting_time = 0;
    int temp_w_time = 0;

    // wll sort the processes by their burst time ...
    sort(ready_list.begin(), ready_list.end(), [](const Process &a, const Process &b) ->
            bool { return a.getBurstTime() < b.getBurstTime(); });


    // after we sort by the burst time , every iteration wll find the shortest one that can be executed , exe it and
    // erase from ready list and start from the start again ...
    int count = 0;
    while (!ready_list.empty()) {
        auto it = ready_list.begin();
        for (; it != ready_list.end(); it++) {
            if (it->getArrivalTime() <= time) {
                temp_w_time = time - it->getArrivalTime();
                time += it->getBurstTime();
                total_waiting_time += temp_w_time;
                ready_list.erase(--it);
                cout << count++ << " [ pid " << it->getPid() << " arrival time " << it->getArrivalTime()
                     << " burst time = "
                     << it->getBurstTime() << " ] " << endl;
                cout << "[" << time - it->getBurstTime() << "] - [" << time << "]" << " waiting time = " << temp_w_time
                     << endl << endl;
                break;
            }
        }
    }
    cout << "-------average waiting time SJF  = " << float(total_waiting_time) / size << "-----\n" << endl << endl;


}

void HW_1::SRTF(bool userInput) {

    cout << "--------------SRTF------------------------\n" << endl;
// more aficiant to implement with heap ..
    vector<Process> ready_lst;
    getData(ready_lst, userInput);


    while (!ready_lst.empty()) {

        sort(ready_lst.begin(), ready_lst.end(), [](const Process &a, const Process &b) ->
                bool { return a.getBurstTime() < b.getBurstTime(); });
        auto job = ready_lst.begin();

        cout <<" [ pid " << job->getPid() << " arrival time " << job->getArrivalTime()
             << " burst time = "<< job->getBurstTime() << " ] \n" << endl;
        job->setBurstTime(1);
        if (job->getBurstTime() == 0)
            ready_lst.erase(job);
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
            arrival_time = r % 10;
            auto *temp = new Process(pid, arrival_time, burst_time);
            my_process.push_back(*temp);
        }
    }

}





