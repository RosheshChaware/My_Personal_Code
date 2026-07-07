class Solution {
public:
    long long sumAndMultiply(int n) {

        string s = to_string(n);
        string temp = "";
        int sum = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '0')
                continue;

            temp += s[i];
            sum += s[i] - '0';
        }

        if(temp.empty())
            return 0;

        long long x = stoll(temp);

        return x * sum;
    }
};