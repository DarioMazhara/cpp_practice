int romanToInt(string s) {
        map<string, int> mp;
        bool timesfive = true;
        int value = 1;
        mp["I"]=1;
        mp["V"]=5;
        mp["X"]=10;
        mp["L"]=50;
        mp["C"]=100;
        mp["D"]=500;
        mp["M"]=1000;
        
        vector<char> vec (s.begin(), s.end());
        vector<int> nums;
        string symbol;
        stringstream ss;
        for (const char &c : vec) {
            ss << c;
            ss >> symbol;
            ss.clear();
            nums.push_back(mp[symbol]);
        }
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << endl;
            if (i != nums.size()-1)
                if (nums[i] < nums[i+1]) {
                    cout << nums[i] << " < " << nums[i+1];
                    nums[i] = nums[i+1]-nums[i];
                    nums.erase(nums.begin()+(i+1));
                }
       //     cout << nums[i] << " "; 
            result+=nums[i];
        }
        return result;
    }
    //much faster solution
    int superFastRomanToInt(string s) {
       int ans = 0, num = 0;
        for(int i = s.size()-1; ~i; i--) {
            switch(s[i]) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            if (4 * num < ans) ans-=num;
            else ans+=num;
        }
        return ans;
    }
};