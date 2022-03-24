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
    int response_time;
};
int main()
{
    int n;
    cout << "Enter The Number of Processes" << endl;
    cin >> n;
    struct process p[n];
    float avg_turnaround_time;
    float avg_waiting_time;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));
    cout << setprecision(2) << fixed;
    cout << "Enter Arrival Time for The Processes" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].arrival_time;
        p[i].pid = i + 1;
    }
    cout << "Enter Burst Time for The Processes" << endl;
    for (int i = 0; i < n; i++)
        cin >> p[i].burst_time;
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while (completed != n)
    {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].burst_time < mn)
                {
                    mn = p[i].burst_time;
                    idx = i;
                }
                if (p[i].burst_time == mn)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        mn = p[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            total_turnaround_time += p[idx].turnaround_time;
            total_waiting_time += p[idx].waiting_time;
            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }

    int min_arrival_time = 10000000;
    int max_completion_time = -1;
    for (int i = 0; i < n; i++)
    {
        min_arrival_time = min(min_arrival_time, p[i].arrival_time);
        max_completion_time = max(max_completion_time, p[i].completion_time);
    }

    avg_turnaround_time = (float)total_turnaround_time / n;
    avg_waiting_time = (float)total_waiting_time / n;

    cout << endl;
    cout << "Shortest Job First Served Scheduling Policy is Implemented as follows:" << endl;
    cout << endl
         << left << setw(9) << "Process" << left << setw(14) << "Arrival Time" << left << setw(12) << "Burst Time" << left << setw(17) << "Completion Time" << left << setw(17) << "Turnaround Time" << left << setw(14) << "Waiting Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << left << setw(9) << p[i].pid << left << setw(14) << p[i].arrival_time << left << setw(12) << p[i].burst_time << left << setw(17) << p[i].completion_time << left << setw(17) << p[i].turnaround_time << left << setw(14) << p[i].waiting_time << endl;
    }
    cout << "Average Turnaround Time = " << avg_turnaround_time << endl;
    cout << "Average Waiting Time = " << avg_waiting_time << endl;
}