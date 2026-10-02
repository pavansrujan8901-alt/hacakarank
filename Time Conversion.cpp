#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string timeConversion(string s) {
    // Extract indicator ("AM" or "PM")
    string period = s.substr(8, 2);
    
    // Parse the hour as an integer
    int hour = stoi(s.substr(0, 2));
    string minutes_seconds = s.substr(2, 6); // ":MM:SS"

    if (period == "AM") {
        if (hour == 12) {
            hour = 0;
        }
    } else { // "PM"
        if (hour != 12) {
            hour += 12;
        }
    }

    // Format hour back to 2-digit string with leading zeros
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%02d", hour);
    
    return string(buffer) + minutes_seconds;
}

int main() {
    string s;
    cin >> s;
    cout << timeConversion(s) << endl;
    return 0;
}