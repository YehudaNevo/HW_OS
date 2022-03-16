#ifndef HW_OS_PROCESS_H
#define HW_OS_PROCESS_H


class Process {


private:

    int pid{};
    int arrival_time{};
    int burst_time{};
    int priority = 0;

public:

    Process(int pid_, int arrivaltime, int bursttime);

    int getPid() const;

    int getArrivalTime() const;

    int getBurstTime() const;

    int getPriority() const;

};


#endif //HW_OS_PROCESS_H
