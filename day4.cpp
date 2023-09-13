#include <iostream>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>

bool can_be_in_range(std::string &ranges)
{

    std::istringstream ss(ranges);

    std::vector<int> numbers;
    std::string segment;

    // Parse out numbers separated by comma
    while (std::getline(ss, segment, ','))
    {
        // Parse out two numbers separated by hyphen from the segment
        std::istringstream segmentStream(segment);
        int a, b;
        char hyphen;

        if (segmentStream >> a >> hyphen >> b && hyphen == '-')
        {
            numbers.push_back(a);
            numbers.push_back(b);
        }
    }

    return (numbers[0] <= numbers[2] && numbers[3] <= numbers[1]) || (numbers[0] >= numbers[2] && numbers[3] >= numbers[1]);
}


bool overlap(std::string &ranges)
{

    std::istringstream ss(ranges);

    std::vector<int> numbers;
    std::string segment;

    // Parse out numbers separated by comma
    while (std::getline(ss, segment, ','))
    {
        // Parse out two numbers separated by hyphen from the segment
        std::istringstream segmentStream(segment);
        int a, b;
        char hyphen;

        if (segmentStream >> a >> hyphen >> b && hyphen == '-')
        {
            numbers.push_back(a);
            numbers.push_back(b);
        }
    }

    return (numbers[0] <= numbers[3] && numbers[2] <= numbers[1]);
}



int part_one(){ 
    std::ifstream inputFile("day4.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int overlapping_pairs = 0;
    while (std::getline(inputFile, line))
    {
        if (can_be_in_range(line)) { 
            ++overlapping_pairs;
        }
    }

    inputFile.close();
    return overlapping_pairs;
}

int part_two(){ 
    std::ifstream inputFile("day4.txt");
    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int overlapping_pairs = 0;
    while (std::getline(inputFile, line))
    {
        if (overlap(line)) { 
            ++overlapping_pairs;
        }
    }

    inputFile.close();
    return overlapping_pairs;
}



int main()
{   
    std::cout << part_one() << std::endl;
    std::cout << part_two() << std::endl;
}