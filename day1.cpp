#include <iostream>
#include <stdexcept>
#include <fstream>
#include <queue>
#include <algorithm>

int part_one()
{
    std::ifstream inputFile("day1.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int max_calories = 0;
    int cal_count = 0;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
        {
            if (cal_count > max_calories)
            {
                max_calories = cal_count;
            }
            cal_count = 0;
        }
        else
        {
            cal_count += std::stoi(line);
        }
    }

    inputFile.close();

    if (cal_count > max_calories)
    {
        max_calories = cal_count;
    }
    return max_calories;
}

int part_two()
{
    std::ifstream inputFile("day1.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::priority_queue<int> pq; 


    std::string line;
    int cal_count = 0;
    while (std::getline(inputFile, line))
    {
        if (line.empty())
        {
            pq.push(cal_count * -1);       
            cal_count = 0;

            if(pq.size() > 3) { 
                pq.pop();
            }
        }
        else
        {
            cal_count += std::stoi(line);
        }
    }

    int sum = 0;

    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum * - 1;
}

int main()
{
    std::cout << part_one() << std::endl;
    std::cout << part_two() << std::endl;
}