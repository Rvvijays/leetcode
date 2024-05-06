class Solution {
    
    string cleanString(string email){
        string uniqueEmail = "";
            int index = 0;
            while(index < email.length()){
                
                if(email[index] == '@'){
                    uniqueEmail += email.substr(index,email.length());
                    break;
                }
                
                if(email[index] == '.'){
                    index++;
                    
                    continue;
                }
                
                if(email[index] == '+'){
                    index++;
                    while(email[index]!='@'){
                        index++;
                    }
                    continue;
                }
                
                uniqueEmail += email[index];
                index++;
            }
        
        return uniqueEmail;
    }
public:

    int brute(vector<string>& emails) {
set<string> uniqueEmails;
        for(int i=0; i<emails.size(); i++){
            string email = emails[i];
                        
            uniqueEmails.insert(cleanString(email));
        }
      
        
        return uniqueEmails.size();
    }
    int numUniqueEmails(vector<string>& emails) {
        
        return brute(emails);
    }
};