#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

struct Task
{
    std::string description;
    std::string dueDate;
    bool isCompleted;
    Task(std::string desc, std::string due) : description(desc), dueDate(due), isCompleted(false) {}
};

void clearWindow();
void showTasks(std::vector<Task> &tasks);

void showMenu()
{
    std::cout << "1. 添加任务" << std::endl;
    std::cout << "2. 查看任务" << std::endl;
    std::cout << "3. 删除任务" << std::endl;
    std::cout << "4. 完成任务" << std::endl;
    std::cout << "q. 退出" << std::endl;
}

void addTask(std::vector<Task> &tasks, std::string desc, std::string due)
{
    tasks.push_back(Task(desc, due));
}
void deleteTask(std::vector<Task> &tasks, int index)
{
    if (index > 0 && index <= tasks.size())
    {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "任务已删除" << std::endl;
    }
    else
    {
        std::cout << "无效的编号" << std::endl;
    }
}

void completeTask(std::vector<Task> &tasks, int index)
{
    if (index > 0 && index <= tasks.size())
    {
        if (tasks[index - 1].isCompleted)
        {
            std::cout << "当前任务是已完成的" << std::endl;
        }
        else
        {
            tasks[index - 1].isCompleted = true;
            std::cout << "任务已完成" << std::endl;
        }
    }
    else
    {
        std::cout << "无效的编号" << std::endl;
    }
}
void handleChoice(std::vector<Task> &tasks, char &choice, std::string type)
{
    clearWindow();
    showTasks(tasks);
    std::cout << "请输入要" << (type == "delete" ? "删除" : "完成") << "的任务编号: ";
    int index;
    std::cin >> index;
    if (type == "delete")
    {
        deleteTask(tasks, index);
    }
    if (type == "complete")
    {
        completeTask(tasks, index);
    }
    std::cout << "输入r返回主菜单" << std::endl;
    std::cin >> choice;
    if (choice == 'r')
    {
        clearWindow();
    }
}
void clearWindow()
{
    std::cout << "\033[2J\033[1;1H";
}
void showTasks(std::vector<Task> &tasks)
{
    for (int i = 0; i < tasks.size(); i++)
    {
        std::cout << i + 1 << '.' << tasks[i].description << '(' << tasks[i].dueDate << ')' << (tasks[i].isCompleted ? "[已完成]" : "[未完成]") << std::endl;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    std::vector<Task> tasks;
    tasks.push_back(Task("学习C++", "2025-01-17"));
    tasks.push_back(Task("学习Python", "2025-01-18"));
    char choice;

    while (choice != 'q')
    {
        showMenu();
        std::cin >> choice;
        switch (choice)
        {
        case '1':
        {
            clearWindow();
            std::string desc, due;
            std::cout << "请输入任务描述: ";
            std::cin.ignore();
            std::getline(std::cin, desc);
            std::cout << "请输入任务截止日期: ";
            std::getline(std::cin, due);
            addTask(tasks, desc, due);
            clearWindow();
            break;
        }
        case '2':
        {

            clearWindow();
            showTasks(tasks);
            std::cout << "输入r返回主菜单" << std::endl;
            std::cin >> choice;
            if (choice == 'r')
            {
                clearWindow();
            }
            break;
        }
        case '3':
        {
            handleChoice(tasks, choice, "delete");
            break;
        }
        case '4':
        {
            handleChoice(tasks, choice, "complete");
            break;
        }
        case 'q':
        {
            std::cout << "退出程序" << std::endl;
            break;
        }
        default:
        {
            std::cout << "无效的输入" << std::endl;
            break;
        }
        }
    }

    return 0;
}