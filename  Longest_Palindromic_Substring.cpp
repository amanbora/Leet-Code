class Solution {
public:
    string longestPalindrome(string str) {
        int maxlength = 1;
        string ss="";
        int n = str.length();
        if(!n)return "";
        int ans[n][n];
        memset(ans,0,sizeof(ans));

        for(int i=0;i<n;i++){
            ans[i][i]=true;

        }
        int start=0;

        for(int i=0;i<n-1;i++){
            if(str[i]==str[i+1]){
                ans[i][i+1]=true;
                maxlength = 2;
                start = i;
            }


        }

        for(int k=3;k<=n;k++){


            for(int i=0;i<n-k+1;i++){
                int j = i+k-1;


                if(ans[i+1][j-1] && str[i]==str[j]){

                    ans[i][j]=true;

                    if (k > maxlength)
                    {

                        start = i;
                        maxlength = k;
                    }

                }

            }
        }


        if(maxlength == n)return str;
        for(int i=start;i<start+maxlength;i++){
            ss += str[i];
        }
        return ss;

    }

};
