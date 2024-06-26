/*
bai
*/
// "написано" под музыку https://suno.com/song/ff9f268f-e5cd-47df-9c1b-330e857b2ce4

#include <windows.h>


#include <iostream>
#include <list>
#include <unordered_set>

#include <iostream>
#include <fstream>
#include <list>
#include <string>

#define u64 unsigned long long

void read1(const char* filename,std::list<std::string> &lines);
void compareStrings(const std::list<std::string>& list1, const std::list<std::string>& list2);


    u64 cntf=0;
int main(int argc, char *argv[]) {

SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);

    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <filename1> <filename2>" << std::endl;
        return 1;
    }
    std::list<std::string> list1;
    std::list<std::string> list2;

        cntf=0;
    read1(argv[1],list1 );
        cntf=0;
    read1(argv[2],list2 );

    compareStrings(list1, list2);
    
    return 0;
}


void compareStrings(const std::list<std::string>& list1, const std::list<std::string>& list2) {
    std::unordered_set<std::string> set1(list1.begin(), list1.end());
    std::unordered_set<std::string> set2(list2.begin(), list2.end());
    
    std::list<std::string> uniqueStrings1;
    std::list<std::string> uniqueStrings2;
    
    u64 cnt1=0;
    u64 cnt2=0;
    // Find unique strings in list1
    for (const std::string& str : list1) {
        if (set2.find(str) == set2.end()) {
            uniqueStrings1.push_back(str);
            cnt1++;
        }
    }
    
    // Find unique strings in list2
    for (const std::string& str : list2) {
        if (set1.find(str) == set1.end()) {
            uniqueStrings2.push_back(str);
            cnt2++;
        }
    }

    // Output the unique strings1
    for (const std::string& str : uniqueStrings1) {
        std::cout << "-" << str << std::endl;
    }
    // Output the unique strings2
    for (const std::string& str : uniqueStrings2) {
        std::cout << "+" << str << std::endl;
    }


}

void read1(const char* filename,std::list<std::string> &lines)
{
//   const char* filename = argv[1];
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        exit(1);
    }

//    std::list<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
        cntf++;
    }

    file.close();
}

