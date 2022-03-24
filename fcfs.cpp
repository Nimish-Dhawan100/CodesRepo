#include <bits/stdc++.h>
using namespace std;
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};
bool compareArrival(process p1, process p2)
{
    return p1.arrival_time < p2.arrival_time;
}

bool compareID(process p1, process p2)
{
    return p1.pid < p2.pid;
}
int main()
{
    int n;
    cout << "Enter The Number of Processes" << endl;
    cin >> n;
    struct process p[n];
    float avg_turnaround_time;
    float avg_waiting_time;
    float avg_response_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    cout << "Enter Arrival Time for The Processes" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].arrival_time;
        p[i].pid = i + 1;
    }
    cout << "Enter Burst Time for The Processes" << endl;
    for (int i = 0; i < n; i++)
        cin >> p[i].burst_time;
    sort(p, p + n, compareArrival);
    for (int i = 0; i < n; i++)
    {
        p[i].start_time = (i == 0) ? p[i].arrival_time : max(p[i - 1].completion_time, p[i].arrival_time);
        p[i].completion_time = p[i].start_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;
    }
    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;
    sort(p, p + n, compareID);
    cout << endl;
    cout<<"First Come First Served Scheduling Policy is Implemented as follows:"<<endl;
    cout <<endl<< left << setw(9) << "Process" << left << setw(14) << "Arrival Time" << left << setw(12) << "Burst Time" << left << setw(17) << "Completion Time" << left << setw(17) <<"Turnaround Time"<<left<<setw(14)<<"Waiting Time"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(9) << p[i].pid << left << setw(14) << p[i].arrival_time<< left << setw(12) << p[i].burst_time << left << setw(17) << p[i].completion_time<< left << setw(17) << p[i].turnaround_time<<left<<setw(14)<<p[i].waiting_time<<endl;
    }
    cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
    cout << "Average Waiting Time = " << avg_waiting_time << endl;
}
