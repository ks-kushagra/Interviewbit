Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
For the last line of text, it should be left justified and no extra space is inserted between words.

Your program should return a list of strings, where each string represents a single line.

Example:

words: ["This", "is", "an", "example", "of", "text", "justification."]

L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

    Note: Each word is guaranteed not 


_______________________________________________________________________________________________________________________________________________________________________
void add(string &t,int k)
{
    while(k--) t.append(" "); 
}


vector<string> Solution::fullJustify(vector<string> &A, int B) 
{
    vector<string>ans;
    int i=0,j=0;
    while(j<A.size())
    {
        int blank=0,words=0;
        while(blank-1+words<=B && j<A.size())
        {
            if(words+A[j].size()+blank<=B) {words+=A[j].size();blank++;j++;}
            else break;
        }
        int total_blank=(B-words);
        blank--;
        j--;
        //cout<<i<<" "<<j<<" "<<words<<endl;
        int k=i;
        string t;
        if(j<A.size()-1)
        {
            while(k<=j)
            {
              t+=A[k];
              int space;
              if(blank==0) space=(B-t.size());
              else if(total_blank%blank==0) {space=total_blank/blank;}
              else {space=total_blank/blank+1;}
              total_blank-=space;
              blank--;k++;
              add(t,space);
            }
        }
        else
        {
            while(k<=j && k<A.size())
            {
                t+=A[k];
                if(k<A.size()-1) add(t,1);
                else {add(t,B-t.size());}
                k++;
            }
        }
        ans.push_back(t);
        i=j+1;
        j=i;
    }
    return ans;
}

