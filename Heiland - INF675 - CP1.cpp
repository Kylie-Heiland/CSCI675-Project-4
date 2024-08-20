class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int count = 0; //Will keep track of the number of words in words that are greater in frequency than the queries.
        vector<int> answer; //Each element in answer refers to the count of words that are greater in frequency than the corresponding element from queries.
        vector<string>::iterator W = words.begin(); //Sets iterator to beginning of words.
        vector<int> answersF; //Will contain frequencies of each of the words.
        vector<string>::iterator iter = queries.begin(); //Sets iterator to beginning of queries.
        vector<int> answersQ; //Will contain frequencies of each query.
        //cout << "The size of answer: " << answer.size() << " The size of queries: " << queries.size() << endl;

        for(unsigned int i = 0; i < words.size(); i++){ //Loops through each of the words in words.
            answersF.push_back(f(words[i])); //Adds the frequency of each W.
            //cout << f(*W) << endl;
        }

        for(unsigned int i = 0; i < queries.size(); i++){ //Loops through each of the words in queries.
            //cout << *iter << " ";
            answersQ.push_back(f(queries[i])); //Adds the frequency of each query.
            //cout << f(*iter) << endl;
        }

        for(int x : answersQ){ //Loops through each of the queries.
            for(int y : answersF){ //Loops through each of the words
                if(x < y)
                    count++;
            }
            answer.push_back(count); //Sets the answer vector the count to keep track of the number of words that have a higher frequency for each of the queries.
            count = 0; //Resets count to 0.
        }
        //answersQ
        return answer;
    }

    int f(string s){ //Returns the frequency of the smallest character in a string.
        int frequency = 1; //Keeps track of the frequency of the smallest character.
        char smallestChar = s[0]; //Is the current smallestChar.
        //cout << smallestChar;

        for(int i = 1; i < s.length(); i++){//Loops through each character in the string.
            if(smallestChar > s[i]){ //If the character is smaller than the character in smallestChar:
                smallestChar = s[i]; //Sets smallestChar to the smaller character.
                frequency = 1; //Sets the frequency of this smaller character to 1.
            } else if(smallestChar == s[i]){ //If the character matches the character already set to smallestChar:
                frequency++; //Increment frequency
            }
        }

        //cout << "The smallest char in the string is " << smallestChar << " with a frequency of " << frequency << endl;
        return frequency; 
    }
};