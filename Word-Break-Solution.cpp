#################################################################################  Question  #################################################################################################################################################



Given a string s and a dictionary of n words dictionary, find out if a s can be segmented into a space-separated sequence of dictionary words. Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

Note: From the dictionary dictionary each word can be taken any number of times and in any order.

Example 1:

Input:
n = 6
s = "ilike"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:
1
Explanation:
The string can be segmented as "i like".
Example 2:

Input:
n = 6
s = "ilikesamsung"
dictionary = { "i", "like", "sam", "sung", "samsung", "mobile"}
Output:
1
Explanation:
The string can be segmented as 
"i like samsung" or "i like sam sung".
Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

Expected Time Complexity: O(len(s)2)
Expected Space Complexity: O(len(s))

Constraints:
1 ≤ n ≤ 12
1 ≤ len(s) ≤ 1100





##################################################################################  Solution  ################################################################################################################################################

  //{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    map<string,int> mp;
    bool solve(int n, string s, vector<string> &dictionary, string temp)
    {
        if(temp.size() > s.size())
            return false;
        if(s == temp)
            return true;
        if(s.find(temp) == string::npos)
            return false;
        if(mp[temp] == 1)
            return true;
        for(int i = 0; i < n; i++)
        {
            bool ret = solve(n,s,dictionary,temp+dictionary[i]);
            if(ret)
            {   mp[temp+dictionary[i]]=1;  
                return true;
            }
        }
        return false;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) 
    {
        mp.clear();
        for(int i = 0; i < n; i++)
        {
            string temp = dictionary[i];
            if(temp[0] == s[0])
            {
                bool ans = solve(n,s,dictionary,dictionary[i]);
                if(ans)
                    return ans;
            }
            
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends
