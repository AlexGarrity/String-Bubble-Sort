#include <string>
#include <iostream>

struct SearchString{
    SearchString(const char *text) {
        str = text;
    }
    SearchString(std::string &string) {
        str = string;
    }
    SearchString() {
        str = "";
    }

    bool operator> (SearchString &other) {
        if (other.str.size() < str.size()) {
            for (unsigned int i = 0; i < other.str.size(); i++) {
                if (str.data()[i] > other.str.data()[i]) {
                    return true;
                }
            }
        }
        else {
            for (unsigned int i = 0; i < str.size(); i++) {
                if (str.data()[i] > other.str.data()[i]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator< (SearchString &other) {
        if (other.str.size() < str.size()) {
            for (unsigned int i = 0; i < other.str.size(); i++) {
                if (str.data()[i] < other.str.data()[i]) {
                    return true;
                }
            }
        }
        else {
            for (unsigned int i = 0; i < str.size(); i++) {
                if (str.data()[i] < other.str.data()[i]) {
                    return true;
                }
            }
        }
        return false;
    }

    void operator= (SearchString &other) {
        str = other.str;
    }

    std::string str;
};



// Example use
#include <vector>

void OutputVector(std::vector<SearchString> &in)
{
    for (SearchString s : in)
    {
        std::cout << s.str << std::endl;
    }
}

void BubbleSort (std::vector<SearchString> &in)
{
    SearchString temp;
    for (unsigned int i = in.size(); i > 0; i--) {
        for (unsigned int j = 0; j < i - 1; j++) {
            if (in[j] > in[j+1]) {
                temp = in[j+1];
                in[j+1] = in[j];
                in[j] = temp;
            }
        }
    }
}

int main(int argc, char **argv)
{
    std::vector<SearchString> searchStrings;
    for (unsigned int i = 1; i < argc; i++) {
        searchStrings.push_back(argv[i]);
    }

    std::cout << "Input was: " << std::endl;
    OutputVector(searchStrings);

    std::cout << "Sorting with bubble sort (asc order)." << std::endl;
    BubbleSort(searchStrings);
    std::cout << "Sorted." << std::endl;

    OutputVector(searchStrings);
    return 0;
    
}