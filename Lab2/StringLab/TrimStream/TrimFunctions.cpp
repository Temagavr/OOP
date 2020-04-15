#include "TrimFunctions.h"

void TrimStream(istream& input, ostream& output)
{
    string inString;
    while (getline(input, inString)) {
        string trimedStr = TrimBlanks(inString);
        output << trimedStr << endl;
    }
}

string TrimBlanks(string const& str) {
    bool letterFlag = false, endFl = false;
    int start = -1, end;
    string trimedString = str;
    if (str != "") {
        for (int i = 0; i < str.length();++i) {
            if ((str[i] == ' ' || str[i] == '\t') && !letterFlag) {
                if (i == str.length() - 1) {
                    trimedString = "";
                    break;
                }
            }
            else if (!letterFlag) {
                letterFlag = true;
                start = i;
            }
            if ((str[str.length() - i - 1] == ' ' || str[str.length() - i - 1] == '\t') && !endFl) {
                continue;
            }
            else if (!endFl) {
                endFl = true;
                end = str.length() - i;
            }
        }
    }
    if (trimedString != "") {
        if (end != str.length() - 1) {
            trimedString.erase(end, trimedString.length() - 1);
        }
        if (start != -1) {
            trimedString.erase(0, start);
        }
    }
    return trimedString;
}