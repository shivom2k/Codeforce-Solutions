class Solution {
    private:
    
    void removeDupWord(string str) 
    { 
       string word = ""; 
       for (auto x : str) 
       { 
           if (x == ' ') 
           { 
               v.push_back(word);
               word = ""; 
           } 
           else
           { 
               word = word + x; 
           } 
       }  
       v.push_back(word); 
    } 
public:
    vector<string> v;
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=searchWord.length();
        removeDupWord(sentence);
        int idx=-1;
        for(int i=0;i<v.size();i++)
        {
            string ab=v[i];
            bool flag=true;
            int m=ab.length();
            if(m<n)
                continue;
            for(int j=0;j<n;j++)
            {
                if(ab[j]!=searchWord[j])
                    flag=false;
            }
            if(flag==true)
            {
                idx=i+1;
                break;
            }
        }
        return idx;
            
        }
    };
    

