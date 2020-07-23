#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW,          // новая
    IN_PROGRESS,  // в разработке
    TESTING,      // на тестировании
    DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = std::map<TaskStatus, int>;

class TeamTasks {
public:
    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const std::string& person) const {
        int _new, _in_progress, _testing, _done = 0;
        for (const auto& item : person_tasks) {
            if (person == item.first) {
                for (const auto& k : item.second) {
                    if (k.first == TaskStatus::NEW) {
                        _new = k.second;
                    } else if (k.first == TaskStatus::IN_PROGRESS) {
                        _in_progress = k.second;
                    } else if (k.first == TaskStatus::TESTING) {
                        _testing = k.second;
                    } else if (k.first == TaskStatus::DONE) {
                        _done = k.second;
                    }
                }
            }
        }
        TasksInfo temp = {{TaskStatus::NEW, _new}, {TaskStatus::IN_PROGRESS, _in_progress}, {TaskStatus::TESTING, _testing}, {TaskStatus::DONE, _done}};
        
        return temp;
    }
  
    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const std::string& person) {
        person_tasks[person][TaskStatus::NEW]++;
    }
  
    // Обновить статусы по данному количеству задач конкретного разработчика
    std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, int task_count) {
    TasksInfo updated_tasks, untouched_tasks(person_tasks[person]);
    int max = task_count;
    for (int i = 0; i < max; max--) {
        person_tasks[person][TaskStatus::NEW]--;
        person_tasks[person][TaskStatus::IN_PROGRESS]++;
    }
    for (int i = 0; i < max; max--) {
        person_tasks[person][TaskStatus::IN_PROGRESS]--;
        person_tasks[person][TaskStatus::TESTING]++;
    }
    for (int i = 0; i < max; max--) {
        person_tasks[person][TaskStatus::TESTING]--;
        person_tasks[person][TaskStatus::DONE]++;
    }
    return std::make_tuple(updated_tasks, untouched_tasks);
    }

private:
    // база данных <имя разработчика> - <мапа задач>
    std::map<std::string, TasksInfo> person_tasks;
};