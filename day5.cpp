#include <iostream>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <stack>

std::unordered_map<int, std::stack<char>> stack_map = {};
std::vector<std::tuple<int, int, int>> moves = {};

void initialize_map()
{
    for (int i = 1; i <= 9; ++i)
    {
        stack_map.emplace(i, std::stack<char>());
    }
}

void parse_file()
{
    std::ifstream inputFile("day5.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
    }

    std::string line;
    int first = 0;
    int second = 0;
    int third = 0;
    while (std::getline(inputFile, line))
    {
        if (!line.empty() && line.at(0) != 'm')
        {

            int counter = 0;
            for (char &c : line)
            {
                int k = c;
                if (k <= 90 && k >= 65)
                {
                    auto current_stack = &stack_map[(counter - 1) / 4 + 1];
                    current_stack->push(c);
                }
                ++counter;
            }
        }
        else if(!line.empty())
        {

            int counter = 0;
            for (char &c : line)
            {
                int k = c;
                if (k >= 48 && k <= 57)
                {
                    switch (counter)
                    {
                    case 0:
                        first = k - 48;
                        break;
                    case 1:
                        second = k - 48;
                        break;
                    case 2:
                        third = k - 48;
                        break;
                    }
                    ++counter;
                }
                if (counter == 3)
                {
                    moves.push_back(std::tuple<int, int, int>(first, second, third));
                }
            }
        }
    }

    for (int i = 1; i <= 9; ++i)
    {
        std::stack<char> temp;
        auto &current_stack = stack_map[i];
        while (!current_stack.empty())
        {
            temp.push(current_stack.top());
            current_stack.pop();
        }
        stack_map[i] = temp;
    }
}

 std::string part_one()
{   

    initialize_map();
    parse_file();
    std::string message = "";
    for (int i = 0; i < moves.size(); ++i)
    {
        auto current_move = moves.at(i);

        int to_move = std::get<0>(current_move);

        auto &from_stack = stack_map[std::get<1>(current_move)];

        auto &to_stack = stack_map[std::get<2>(current_move)];

        for (int j = 0; j < to_move; ++j)
        {   
            if(!from_stack.empty() && !to_stack.empty()) {
                to_stack.push(from_stack.top());
                from_stack.pop();
            }
        }
    }


    

    for(int i = 1; i <= 9; ++i) {
        if (!stack_map[i].empty()) {
            message += stack_map[i].top();
        }
    }

    return message;
}

int main()
{
    std::cout << part_one() << std::endl;
}