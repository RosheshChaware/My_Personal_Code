#include <bits/stdc++.h>
using namespace std;

class Solution {
    using Arr = array<int, 4>; 
    const Arr digitFactor[10] = {
        Arr{0, 0, 0, 0}, 
        Arr{0, 0, 0, 0}, 
        Arr{1, 0, 0, 0}, 
        Arr{0, 1, 0, 0}, 
        Arr{2, 0, 0, 0}, 
        Arr{0, 0, 1, 0}, 
        Arr{1, 1, 0, 0}, 
        Arr{0, 0, 0, 1}, 
        Arr{3, 0, 0, 0}, 
        Arr{0, 2, 0, 0}  
    };

    Arr factorize(long long t, bool &valid) {
        Arr cnt{0, 0, 0, 0};
        long long primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; ++i) {
            while (t % primes[i] == 0) {
                ++cnt[i];
                t /= primes[i];
            }
        }

        valid = (t == 1);
        return cnt;
    }

    Arr getFactors(const Arr &need) {
        Arr result{0, 0, 0, 0};

        int count8 = need[0] / 3;
        int remaining2 = need[0] % 3;

        int count9 = need[1] / 2;
        int count3 = need[1] % 2;

        int count4 = remaining2 / 2;
        int count2 = remaining2 % 2;

        int count6 = 0;

        if (count2 == 1 && count3 == 1) {
            count2 = 0;
            count3 = 0;
            count6 = 1;
        }

        if (count3 == 1 && count4 == 1) {
            count2 = 1;
            count3 = 0;
            count4 = 0;
            count6 = 1;
        }

        result[0] = count2; 
        result[1] = count3; 
        result[2] = count4; 
        result[3] = need[2]; 

        return result;
    }

    array<int, 10> buildDigitCounts(const Arr &need) {
        array<int, 10> cnt{};
        cnt.fill(0);

        int count8 = need[0] / 3;
        int rem2 = need[0] % 3;

        int count9 = need[1] / 2;
        int count3 = need[1] % 2;

        int count4 = rem2 / 2;
        int count2 = rem2 % 2;

        int count6 = 0;

        if (count2 == 1 && count3 == 1) {
            count2 = 0;
            count3 = 0;
            count6 = 1;
        }

        if (count3 == 1 && count4 == 1) {
            count2 = 1;
            count3 = 0;
            count4 = 0;
            count6 = 1;
        }

        cnt[2] = count2;
        cnt[3] = count3;
        cnt[4] = count4;
        cnt[5] = need[2];
        cnt[6] = count6;
        cnt[7] = need[3];
        cnt[8] = count8;
        cnt[9] = count9;

        return cnt;
    }

    int countDigits(const array<int, 10> &cnt) {
        int total = 0;
        for (int d = 2; d <= 9; ++d) {
            total += cnt[d];
        }
        return total;
    }

    string construct(const Arr &need) {
        auto cnt = buildDigitCounts(need);

        string result;
        for (int d = 2; d <= 9; ++d) {
            result.append(cnt[d], char('0' + d));
        }
        return result;
    }

    Arr subtractFactors(Arr a, const Arr &b) {
        for (int i = 0; i < 4; ++i) {
            a[i] = max(0, a[i] - b[i]);
        }
        return a;
    }

    bool satisfies(const Arr &have, const Arr &need) {
        for (int i = 0; i < 4; ++i) {
            if (have[i] < need[i]) return false;
        }
        return true;
    }

public:
    string smallestNumber(string num, long long t) {
        bool valid;
        Arr target = factorize(t, valid);

        if (!valid) return "-1";

        int n = num.size();

        Arr total{0, 0, 0, 0};
        for (char ch : num) {
            int d = ch - '0';
            for (int i = 0; i < 4; ++i) {
                total[i] += digitFactor[d][i];
            }
        }
        auto requiredDigits = buildDigitCounts(target);
        int minLength = countDigits(requiredDigits);

        if (minLength > n) {
            return construct(target);
        }

        int firstZero = n;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
        }

        if (firstZero == n && satisfies(total, target)) {
            return num;
        }
        Arr remaining = total;

        for (int i = n - 1; i >= 0; --i) {
            int currentDigit = num[i] - '0';

            for (int k = 0; k < 4; ++k) {
                remaining[k] = max(0, remaining[k] - digitFactor[currentDigit][k]);
            }
            if (i > firstZero) continue;

            for (int biggerDigit = currentDigit + 1;
                 biggerDigit <= 9;
                 ++biggerDigit) {

                if (biggerDigit == 0) continue;

                Arr need = target;
                need = subtractFactors(need, remaining);
                need = subtractFactors(need, digitFactor[biggerDigit]);
                auto factorDigits = buildDigitCounts(need);
                int suffixRequired = countDigits(factorDigits);
                int suffixLength = n - i - 1;
                if (suffixRequired <= suffixLength) {
                    string answer = num.substr(0, i);
                    answer.push_back(char('0' + biggerDigit));

                    answer.append(
                        suffixLength - suffixRequired,
                        '1'
                    );

                    answer += construct(need);
                    return answer;
                }
            }
        }
        auto factors = buildDigitCounts(target);
        int neededLength = countDigits(factors);
        int answerLength = max(n + 1, neededLength);

        string answer;
        answer.append(answerLength - neededLength, '1');
        answer += construct(target);
        return answer;
    }
};