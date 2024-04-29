class Solution {
public:
    string reverseVowels(string s) {
        	int left = 0;
	int right = s.size()-1;
	
	unordered_map<char,bool> mp;
	mp.insert({'a',true});
	mp.insert({'e',true});
	mp.insert({'i',true});
	mp.insert({'o',true});
	mp.insert({'u',true});

    mp.insert({'A',true});
	mp.insert({'E',true});
	mp.insert({'I',true});
	mp.insert({'O',true});
	mp.insert({'U',true});
	
	
	while(left < right){
		while(left < right && mp[s[left]]==false){
			left++;
		}
		
		while(right>left && mp[s[right]]==false){
			right--;
		}
		
		char c = s[left];
		s[left] = s[right];
		s[right] = c;
		
		left++;
		right--;
		
		
	}

    return s;
    }
};