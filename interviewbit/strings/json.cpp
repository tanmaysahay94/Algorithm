vector<string> Solution::prettyJSON(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> ans;
    string json = A;
    if (json.length() == 0) {
        return ans;
    }
    json.erase(remove(json.begin(), json.end(), ' '), json.end());
    string indent = "";
    string current = "";
    int i = 0, len = json.length();
    while (i < len) {
        current.push_back(json[i]);
        switch(json[i]) {
            case ',':
                ans.push_back(current);
                current = indent;
                i++;
                break;
            case ':':
                i++;
                if (json[i] == '{' or json[i] == '[') {
                    ans.push_back(current);
                    current = indent;
                }
                break;
            case '{':
            case '[':
                i++;
                ans.push_back(current);
                if (i < len and (json[i] != '}' or json[i] != ']')) {
                    indent.push_back('\t');
                }
                current = indent;
                break;
            case '}':
            case ']':
                i++;
                if (i < len and json[i] == ',')
                    break;
                ans.push_back(current);
                if (i < len and (json[i] == '}' or json[i] == ']')) {
                    if (not indent.empty()) {
                        indent.pop_back();
                    }
                }
                current = indent;
                break;
            default:
                i++;
                if (i < len and (json[i] == '}' or json[i] == ']')) {
                    ans.push_back(current);
                    if (not indent.empty())
                        indent.pop_back();
                    current = indent;
                }
        }
    }
    return ans;
}
