#include <iostream>
#include <stdexcept>
#include <fstream>
#include <queue>
#include <algorithm>
#include <string>
#include <set>

int convert_char_to_int(char &c)
{
    int value = c;

    if (97 <= value && value <= 122)
    {
        return value - 96;
    }

    else
    {
        return value - 38;
    }
}

int part_one()
{
    std::ifstream inputFile("day3.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int priority_sum = 0;
    while (std::getline(inputFile, line))
    {
        int size = line.size();

        std::set<char> first_half;
        std::set<char> second_half;

        int counter = 0;
        for (char c : line)
        {
            if (counter < size / 2)
            {
                first_half.insert(c);
            }
            else
            {
                second_half.insert(c);
            }
            ++counter;
        }

        std::vector<char> inserter;
        std::set_intersection(first_half.begin(), first_half.end(), second_half.begin(), second_half.end(), std::back_inserter(inserter));

        priority_sum += convert_char_to_int(inserter[0]);
    }

    return priority_sum;
}

int part_two()
{
    std::ifstream inputFile("day3.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int priority_sum = 0;

    std::vector<std::string> elves;
    while (std::getline(inputFile, line))
    {
        elves.push_back(line);
        if (elves.size() == 3)
        {
            std::set<char> elf_a(elves[0].begin(), elves[0].end());
            std::set<char> elf_b(elves[1].begin(), elves[1].end());
            std::set<char> elf_c(elves[2].begin(), elves[2].end());


            std::vector<char> one_two;
            std::set_intersection(elf_a.begin(), elf_a.end(), elf_b.begin(), elf_b.end(), std::back_inserter(one_two));

            std::vector<char> result; 
            std::set_intersection(one_two.begin(), one_two.end(), elf_c.begin(), elf_c.end(), std::back_inserter(result));


            priority_sum += convert_char_to_int(result[0]);
            elves.clear();
        }
    }

    return priority_sum;
}

int main()
{
    std::cout << part_one() << std::endl;
    std::cout << part_two() << std::endl;
}