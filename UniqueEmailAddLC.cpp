class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if(emails.size()==0)
            return 0;
        if(emails.size()==1)
            return 1;
        //2 Parts are there
        //1 is LN, 2nd is DN
        int ans=0;
        set<string> s;
        for(int i=0;i<emails.size();i++)
        {
            string str=emails[i];
            string ln="",dn="";
            int j=0;
            for(;j<str.length();j++)
            {
                if(str[j]=='@')
                    break;
                ln+=str[j];
            }
            j++;
            for(;j<str.length();j++)
            {
                dn+=str[j];
            }
            // cout<<ln<<endl<<dn<<endl;
            ln=formatting(ln);
            // dn=formatting(dn);
            // cout<<ln<<endl<<dn<<endl;
            string outp=ln+"@"+dn;
            s.insert(outp);
        }
        return s.size();
    }
    private:
        string formatting(string s)
        {
            string out;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='.')
                {
                    //I will have to do nothing Just Skip It
                    i++;
                }
                if(s[i]=='+')
                {
                    return out;
                }
                else
                    out+=s[i];
            }
            return out;
        }
};
