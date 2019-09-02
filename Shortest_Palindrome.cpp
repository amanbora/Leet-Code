class Solution {
public:
    bool checkPalin(string s, int str,int end){
        for(int i=str; i<=end;i++){
            if(s[i] != s[end-i])return false;
        }
        return true;
    }
    string shortestPalindrome(string s) {
        string ans1="",ans2="";
        set<char> ch;

        for(int i=0;i<s.length();i++){
            ch.insert(s[i]);
        }
        cout<<ch.size()<<endl;
        if(ch.size()==1){
            if(s.length()%2==1)return s;
            else return s+s[0];
        }

        if(checkPalin(s,0,s.length()-1))return s;

        int flag1=0,flag2=0;

        for(int i=2;i<=s.length()-1;i++){
            if( checkPalin(s,0,s.length()-i) ){
                flag1=1;ans1=s;
                for(int j=s.length()-i+1; j<s.length();j++)
                    ans1 = s[j] + ans1 ;

                break;
            }

        }

        for(int i=1;i<=s.length()-2;i++){
            if( checkPalin(s,i,s.length()-1) ){
                flag2=1;ans2=s;
                for(int j=i-1;j>=0;j--)
                    ans2 = ans2 + s[j] ;

                break;
            }
        }

        if(flag1 && flag2){
            if(ans1.length()>ans2.length()){
                if(checkPalin(ans2,0,ans2.length()-1))
                    return ans2;
                return ans1;
            }
            if(checkPalin(ans1,0,ans1.length()-1))
                 return ans1;
            return ans2;
        }

        else if(flag1)return ans1;
        else if(flag2)return ans2;
        else {
            ans1=s;
            for(int i=1;i<s.length();i++)
                ans1 = s[i]+ans1;
            return ans1;
        }





    }
};
