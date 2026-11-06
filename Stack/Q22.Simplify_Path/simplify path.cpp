#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

string simplifyPath(string path) {
    stack<string> s;
    string curr = "";

    for(int i = 0; i < path.length(); i++) {

        if(path[i] == '/') {

            if(curr == "..") {
                if(!s.empty()) {
                    s.pop();
                }
            }
            else if(curr == "." || curr == "") {
                // Ignore
            }
            else {
                s.push(curr);
            }

            curr = "";
        }
        else {
            curr += path[i];
        }
    }

    // Process remaining directory
    if(!curr.empty()) {
        if(curr == "..") {
            if(!s.empty()) {
                s.pop();
            }
        }
        else if(curr != ".") {
            s.push(curr);
        }
    }

    // Build final path
    vector<string> v;

    while(!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }

    string ans = "";

    for(int i = v.size() - 1; i >= 0; i--) {
        ans += "/" + v[i];
    }

    if(ans == "") {
        return "/";
    }

    return ans;
}

int main() {
    string path;

    cout << "Enter path: ";
    getline(cin, path);

    cout << "Simplified Path: " << simplifyPath(path) << endl;

    return 0;
}