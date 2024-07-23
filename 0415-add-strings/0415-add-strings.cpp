class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string result;
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int n1 = 0;
            if (i >= 0) {
                n1 = num1[i] - '0';
                i--;
            }
            
            int n2 = 0;
            if (j >= 0) {
                n2 = num2[j] - '0';
                j--;
            }
            
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
