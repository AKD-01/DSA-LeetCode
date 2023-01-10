class Solution {
public:
    string spaceJustifier(string str, int maxWidth, int isLast){
    //condition if line length is equal to maxWidth so return line as it is.
    if(str.length() == maxWidth)
        return str;
    
    int spacesInString = 0; //count total spaces in the line 
    for(int i = 0; i<str.length(); i++){
        if(str[i] == ' ')
            spacesInString++;
    }
    int spacesToBeInserted = maxWidth - str.length(); //spaces to be inserted will be maxWidth - line length
    //Left Justifier 
    //if line has only 1 word(number of spaces in one word is 0 ex "hi") || it's last line then left justify the line
    if(spacesInString == 0 || isLast == 1){ 
        str.insert(str.length(), spacesToBeInserted,' '); //insert required spaces in right of line ex "do                  "
        return str;
    }
    int eachSlot = spacesToBeInserted / spacesInString; 
    int leftOverSpace = spacesToBeInserted % spacesInString; 
    //EXPLANATION FOR EACH SLOT
    //(spacesToBeInserted / spacesInString) will tell us how much space should we insert at eachSlot
    //ex - (spacesToBeInserted = 6)/(spaces in string = 2) then each slot will get 3 extra spaces ex - "hi_hi" => "hi_ _ _ _hi_ _ _ _" will be output
    
    //EXPLANATION FOR LEFT OVER SPACE
    //when the spacesToBeInserted is not divisibe by spacesInString 
    //EX if we spacesToBeInserted = 5 and spaces in string = 2.
    //since 5/2 is not fully Divisble we will find remainder 5%2 to get left overspace.
    
    
    //EX - so_fine_That_all_the. and maxWidth is 25
    //      in above case spacesToBeInserted = 5 and spaces in stirng = 4.
    //      eachSlot will be 5/4 is 1. ie increase spaces by 1 
    
    //output will be -> so_ _fine_ _That_ _all_ _the
    
    //      since 5/4 is not fully divisible. we will find leftOverSpaces = 5%4 = 1;
    //      this leftOverSpace will be distributed from left to right ie each slot will get 1,1,1 from left to right
    
    //output will be -> so_ _ _fine_ _That_ _all_ _the
    //                        ↑
    //                    leftOverSpace added 
    
    //if we had more leftoverspaces then it will be added to next slot.
    
    for(int i = 0; i<str.length(); i++){
        if(str[i] == ' ' && (eachSlot > 0 || leftOverSpace >0 )){ //we add spaces till (eachSlot > 0 || leftOverSpace >0)
            //required noOfSpaces = eachSlot + (leftOverSpace-- > 0 ? 1:0)
            //((leftOverSpace--) > 0 ? 1:0) will return 1 if leftoverspace>0.
            //(leftOverSpace--) post decrement
            int noOfSpaces = eachSlot + ((leftOverSpace--) > 0 ? 1:0);
            str.insert(i, noOfSpaces , ' '); //inserting spaces
            i+=noOfSpaces;   //increament count with no of spaces inserted each time 
        }
        
    }
    return str;
}

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
         vector<string> result; //result vector which will store each line
        string output = words[0]; //add first word to output string
        for (int i = 1; i<words.size(); i++){
            if(output.length() + words[i].length() + 1 <= maxWidth) //+1 for space 
			
					output += " "+words[i]; //add space before adding word
            
            else{ 
			   //this else will be executed when current line can't add current words 
                output = spaceJustifier(output, maxWidth, 0); //formatting space before adding it to result 
                result.push_back(output);
                //now we added output to result vector now we can start a new line 
                output = words[i]; //add current word to output(start of new line)
            }
        }
        //the above loop will not add last line to result because last line to will always satify (output.length()+words[i].length()+1<=maxWidth) condition
        output = spaceJustifier(output, maxWidth, 1); //justifying spaces in last line
        result.push_back(output); //adding last line to result array
        return result;
    }
};