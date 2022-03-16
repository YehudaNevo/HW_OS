#include <vector>
#include "HW_1.h"
#include "cstdlib"

using namespace std;

void HW_1::FCFS(bool userInput) {

//  [ process1 , process2 .... process100 ... ] process = [pid,arrival time , burst time , priority = 0 ]
    vector<Process> my_process;

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
            pid = i;
            burst_time = r % 20;
            arrival_time = r % 30;
            auto *temp = new Process(pid, arrival_time, burst_time);
            my_process.push_back(*temp);
        }
    }
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
