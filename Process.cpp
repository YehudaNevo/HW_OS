#include "Process.h"

Process::Process(int pid_, int arrivaltime, int bursttime) {
    this->pid = pid_;
    this->arrival_time = arrivaltime;
    this->burst_time = bursttime;

}

int Process::getPid() const {
    return pid;
}

int Process::getArrivalTime() const {
    return arrival_time;
}

int Process::getBurstTime() const {
    return burst_time;
}

int Process::getPriority() const {
    return priority;
}
