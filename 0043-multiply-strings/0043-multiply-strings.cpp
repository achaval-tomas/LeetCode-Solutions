class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int carry = 0;
        vector<string> submults;
        for (int i = num1.length() - 1; i >= 0;  --i){
            string mul = "";
            for (int j = num2.length() - 1; j >= 0; --j){
                int diff = carry + (num1[i] - 48) * (num2[j] - 48);
                int rem = diff % 10;
                carry = (diff - rem) / 10;
                mul = (char)(48 + rem) + mul;
            }
            if (carry != 0){
                mul = (char)(48 + carry) + mul;
                carry = 0;
            }
            mul += string(num1.length() - 1 - i, '0');
            submults.push_back(mul);
        }
        
        string biggest = "";
        for (string s : submults){
            if (s.length() > biggest.length())
                biggest = s;
        }
        
        string mult = "";
        carry = 0;
        int len = submults.size();

        for (int digit = 0; digit < biggest.length(); ++digit){
            int sum = 0;
            for (int j = 0; j < len; ++j){
                int k = submults[j].length() - 1 - digit; 
                int val = k < submults[j].length() ? (submults[j][k] - 48) : 0;
                sum += val;
            }
            sum += carry;
            mult = (char)(48 + sum % 10) + mult;
            carry = (sum / 10);
        }
        if (carry != 0){
            mult = (char)(48 + carry) + mult;
        }

        return mult;
    }
};