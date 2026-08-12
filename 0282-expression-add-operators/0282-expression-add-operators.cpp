class Solution {
public:
    vector<string>ans;

    void helper(int i,string num, int target, string str,  long long eval,  long long prev){
        if(i==num.size()){
            if(eval==target){
                ans.push_back(str);
            }
            return ;
        }

        for(int j=i;j<num.size();j++){
            if(j>i && num[i]=='0') break;
            string currStr=num.substr(i,j-i+1);
            long long currNumVal=stoll(currStr);
            if(i==0){
                helper(j+1,num,target,currStr,currNumVal,currNumVal);
            }
            else{
            //Add
            helper(j+1,num,target,str+"+"+currStr,eval+currNumVal,currNumVal);

            //Substract
            helper(j+1,num,target,str+"-"+currStr,eval-currNumVal,-currNumVal);

            //Multiply
            helper(j+1,num,target,str+"*"+currStr,eval-prev+(prev*currNumVal),prev*currNumVal);
            }

           
        }
    }

    vector<string> addOperators(string num, int target) {
        helper(0,num,target,"",0,0);
        return ans;
    }
};