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

void showMenu()
{
    std::cout << "1. 添加任务" << std::endl;
    std::cout << "2. 查看任务" << std::endl;
    std::cout << "q. 退出" << std::endl;
}

void addTask(std::vector<Task> &tasks, std::string desc, std::string due)
{
    tasks.push_back(Task(desc, due));
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
        if (choice == '1')
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
            
        }
        if (choice == '2')
        {
            clearWindow();
            showTasks(tasks);
            std::cout<<"输入r返回主菜单"<<std::endl;
            std::cin>>choice;
            if(choice=='r')
            {
                clearWindow();
            }
        }
    }

    return 0;
}