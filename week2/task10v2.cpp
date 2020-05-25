#include <string>
#include <iostream>
#include <vector>
using namespace std;

void display_tasks(int day, const vector<vector<string>>& tasks) {
    
    cout << tasks[day - 1].size();

    for (const auto& task : tasks[day - 1]){
        cout << " " << task;
    }
    cout << endl;
}

void to_next_month(int& num_of_month, const vector<int>& diy, vector<vector<string>>& tasks) {
    num_of_month++;

    if (num_of_month > 11) {
        num_of_month = 0;
    }

    vector<vector<string>> NewMonth = tasks;

    int old_vector_size = tasks.size();
    int new_vector_size = diy[num_of_month];

    tasks.resize(new_vector_size);
    const int temp_const = new_vector_size - 1;
    if (old_vector_size > new_vector_size) {
        for (new_vector_size; old_vector_size > new_vector_size; new_vector_size++) {
            tasks[temp_const].insert(end(tasks[temp_const]), begin(NewMonth[new_vector_size]), end(NewMonth[new_vector_size]));
        }
    }
    NewMonth.clear();
}

int main()
{
    vector<int> days_in_year = { 31,28,31,30,31,30,31,31,30,31,30,31};
    vector<vector<string>> task_for_day;
    int index_of_month = 0;
    task_for_day.resize(days_in_year[index_of_month]);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int current_day;
        string task_to_do;
        
        string command;
        cin >> command;
        if (command == "ADD") {
            cin >> current_day >> task_to_do;
            task_for_day[current_day - 1].push_back(task_to_do);
        }
        else if (command == "DUMP") {
            cin >> current_day;
            display_tasks(current_day,task_for_day);
        }
        else if (command == "NEXT") {
            to_next_month(index_of_month, days_in_year, task_for_day);
        }
    }
    return 0;
}