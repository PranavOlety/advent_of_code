#include <iostream>
#include <stdexcept>
#include <fstream>
#include <queue>
#include <algorithm>
#include <string>


// strategies for part_one
const std::unordered_map<std::string, int> outcomes = {
    {"A X", 4},
    {"A Y", 8},
    {"A Z", 3},
    {"B X", 1},
    {"B Y", 5},
    {"B Z", 9},
    {"C X", 7},
    {"C Y", 2},
    {"C Z", 6}};

//strategies for part_two
const std::unordered_map<std::string, int> strategy_outcomes = {
    {"A X", 3},
    {"A Y", 4},
    {"A Z", 8},
    {"B X", 1},
    {"B Y", 5},
    {"B Z", 9},
    {"C X", 2},
    {"C Y", 6},
    {"C Z", 7}};


// abstracted function for different rule_sets
int rock_papers_scissors(const std::unordered_map<std::string, int> &rules) { 
    std::ifstream inputFile("day2.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int score = 0;
    while (std::getline(inputFile, line))
    {
        if (!line.empty())
        {
            score += rules.at(line);
        }
    }

    inputFile.close();

    return score;
}


int part_one()
{
    return rock_papers_scissors(outcomes);
}

int part_two()
{
    return rock_papers_scissors(strategy_outcomes);
}
int main()
{
    std::cout << part_one() << std::endl;
    std::cout << part_two() << std::endl;
}