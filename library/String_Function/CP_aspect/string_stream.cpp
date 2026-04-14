#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> split_string(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream token_stream(s);
    
    while (getline(token_stream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string join_strings(const vector<string>& tokens, const string& delimiter) {
    if (tokens.empty()) return "";
    
    ostringstream result;
    result << tokens[0];
    
    for (size_t i = 1; i < tokens.size(); i++) {
        result << delimiter << tokens[i];
    }
    
    return result.str();
}

// Number to string and vice versa
string number_to_string(int num) {
    return to_string(num);
}

int string_to_number(const string& s) {
    return stoi(s);
}

// Efficient number conversion for CP
int fast_string_to_int(const string& s) {
    int result = 0;
    for (char c : s) {
        result = result * 10 + (c - '0');
    }
    return result;
}

string fast_int_to_string(int num) {
    if (num == 0) return "0";
    
    char buffer[20];
    int i = 0;
    bool negative = num < 0;
    
    if (negative) num = -num;
    
    while (num > 0) {
        buffer[i++] = '0' + (num % 10);
        num /= 10;
    }
    
    if (negative) buffer[i++] = '-';
    buffer[i] = '\0';
    
    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        swap(buffer[j], buffer[i - j - 1]);
    }
    
    return string(buffer);
}