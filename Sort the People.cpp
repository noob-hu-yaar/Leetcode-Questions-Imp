class Solution {
public:
    vector<string> sortPeople(vector<string>& n, vector<int>& h) 
    {
        vector<pair<int, string>> a;
        for(int i=0;i<n.size();i++)
        {
            a.push_back({h[i], n[i]});
        }
        
        sort(a.rbegin(), a.rend());
        
        vector<string> ans;
        for(auto i : a)
            ans.push_back(i.second);
        return ans;
    }
};