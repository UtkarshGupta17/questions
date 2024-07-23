class Solution {
public:
    string processEmail(const string& email) {
        string local;
        string domain;
        bool atSymbolReached = false;
        bool plusSymbolReached = false;

        for (char ch : email) {
            if (ch == '@') {
                atSymbolReached = true;
            }

            if (atSymbolReached) {
                domain += ch;
            } else {
                if (ch == '+') {
                    plusSymbolReached = true;
                }
                if (!plusSymbolReached && ch != '.') {
                    local += ch;
                }
            }
        }

        return local + domain;
    }

    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmails;
        for (const string& email : emails) {
            string processedEmail = processEmail(email);
            uniqueEmails.insert(processedEmail);
        }
        return uniqueEmails.size();
    }
};

