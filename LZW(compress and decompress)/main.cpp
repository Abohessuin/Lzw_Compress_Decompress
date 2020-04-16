/*                 _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         ????       ??BUG
*/



#include<bits/stdc++.h>
using namespace std;
/// all functions(prototype) used during  implementation and two main functions of program(Lzw_compress and Lzw_decompress)....
void Lzw_Compress(string );  //compress...
void Lzw_decompress(int);    //decompress...
void printvector(vector<int>); //print vector value...
void iterator_through_map(map<string,int>,vector<int>,string); //check about exist of any value in dictionary....




/// the main program(compress and decompress)....


int main()
{
    cout<<setw(80)<<"welcome to LZW compress and decompress"<<endl<<endl<<endl;

    cout<<"Overview about LZW:"<<endl;

    cout<<"If you were to take a look at almost any data file on a computer, character by character, you would notice that there are many recurring patterns."
    <<" LZW is a data compression method that takes advantage of this repetition. The original version of the method was created by Lempel and Ziv in 1978 (LZ78) and was further refined by Welch "
    <<"in 1984, hence the LZW acronym. Like any adaptive/dynamic compression method, the idea is to (1) start with an initial model, (2) read data piece by piece, (3) and update the model and encode the data as you go along."
    <<"LZW is a dictionary-based compression algorithm. This means that instead of tabulating character counts and building trees (as for Huffman encoding),"
    <<"LZW encodes data by referencing a dictionary. Thus, to encode a substring, only a single code number, corresponding to that substring's index in the dictionary, needs to be written to the output file."
    << "Although LZW is often explained in the context of compressing text files, it can be used on any type of file. However, it generally performs best on files with repeated substrings, such as text files. ";



    cout<<endl<<endl<<endl;;

    char char_;
    string compress_;
    int key_num;

    /// THE CHOICSES OF THE PROGRAMMER.....
    while(char_!='E')
    {
        cout<<"To  Compress switch C"<<endl;
        cout<<"To  Decompress switch D"<<endl;
        cout<<"to exit switch E"<<endl;
        cin>>char_;
        switch(char_)
        {
            case 'C':
            {
                cout<<"Welcome to Lzw Compress"<<endl;
                cout<<"Enter text or string needed to be compressed"<<endl;
                cin.ignore();
                getline(cin,compress_);
                Lzw_Compress(compress_);
                cout<<endl<<endl;
                break;

            }

            case 'D':
                {
                    cout<<"Welcome to Lzw Decompress"<<endl;
                    cout<<"Enter number of keys you need to decompress it into string or text"<<endl;
                    cin>>key_num;
                    Lzw_decompress(key_num);
                    cout<<endl<<endl;;
                    break;
                }
        }

    }

    cout<<endl<<endl;;
    cout<<setw(80)<<"Thanks for using LZW COMPRESS and DECOMPRESS"<<endl;
    cout<<setw(67)<<"Eng.Mohamed Hessuin";




return 0;
}




/* lzw_compress:It is necessary for the codes to be longer in bits than the characters (12 vs. 8 bits),
but since many frequently occuring substrings will be replaced by a single code,
in the long haul, compression is achieved.
*/


/// *** first compress.....

void Lzw_Compress(string str1)
{
    /// *** Data used in Compressing.....

    string ascii;                             // ascii code char.....
    string last_char="";                     // last char in str1....
    string sum="";                          // sum of two strings(current_char and alternative1_string)....
    string alternative1_string="";         // using to take value of current char after each loop....
    string z="";                          // to add in it last char(convert it into string)....
    string last_str=sum;                 // to save in it last char or string  to encoded as sum always cleared(in my logic) to take new values after each loop....
    vector<int>encoded_output;          // hold results of compressing string(key of sum of current_char and alternative1_string in lzw_dictionary)....
    map<string,int>lzw_dictionary;     // hold all possible ascii Characters(dictionary of 256 characters (in the case of 8 bits) and uses those as the "standard" character set)....
    z+=str1[str1.size()-1];           //save last char as string.....
    bool flag=0;                     // used to check sum of current_char and alternative1_string are exist in lzw_dictionary....
    char current_char;              // char for reading current character in str1....

    /// *** filling lzw_dictionary with all possible ascii Characters....

    for(int i=0;i<256;++i)
    {
        ascii=i;
        lzw_dictionary.insert(pair<string,int>(ascii,i));
    }

    /// *** 1st loop for looping over  string for compressing it....

    for(int i=0;i<str1.size();++i)
    {
      flag=0;                // to make flag false for every new loop(if it change to true)
      current_char=str1[i]; // reading a character
      sum=alternative1_string+current_char;
      last_str=sum;

      /// *** 2nd loop for making iterator over components of lzw_dictionary....

      for(pair<string,int>itera:lzw_dictionary)
      {


        /// *** check for existing of sum of current_char and alternative1_string....
        if(itera.first==sum)
        {
           flag=1;    // if sum exist flag will be equel True..
           break;
        }
        else
          {
            continue;  /* if not.. it  will loop over lZW_dictionary for searching for it is exist
                          and if not the flag will be False */
          }
      }

        /// *** the flag=1 >> sum is exist(so nothing will happen)..the flag=0(put in dic,encode alternative1_string, alternative1_string=current_char,clear sum)....

        if(flag==1)
        {
          alternative1_string=sum;
          sum.clear();            // clear sum from any previous value for new loop....
        }
        else    /// sum not exist  >>>
        {
            ///* return new string in lZW_dictionary with key number

            lzw_dictionary.insert(pair<string,int>(sum,lzw_dictionary.size()+1)); //* return new string in


            /// *** get key number of current alternative1_string from lZW_dictionary and save it in vector( encoded_output)


            for(pair<string,int>it:lzw_dictionary)
            {
               if(it.first==alternative1_string)
             {
                encoded_output.push_back(it.second);
                break;
             }
            }


            /// preparing data for next new loop....

            alternative1_string.clear(); // clear it from previos value for new value
            alternative1_string=current_char; // make alternative =current and current will be new value bec counter will increment as the idea of this (x[i],x[i+1)...
            sum.clear();

         }

    }




   /// *** save last value of sum in last_str before clear it and put it back in vector and save it in lzw_dictionary
   /// compress exception (i don t know why ??this happen)
   if(last_str.size()>2)
    {
         lzw_dictionary.insert(pair<string,int>(last_str,lzw_dictionary.size()+1));   // if last string more than 2  will push it to dictionary in two condition...
         encoded_output.push_back(lzw_dictionary[last_str]);                         // push key of last string in the output...as example(ababababababab)
    }
    else
    {
          lzw_dictionary.insert(pair<string,int>(last_str,lzw_dictionary.size()+1));  // we will push same string all to dictionary
          encoded_output.push_back(lzw_dictionary[z]);                                //push key of the last char to output code......
    }






    /// *** last step return result of compressing string ..........
    cout<<"the number of compressed keys is:"<<endl;
    cout<<encoded_output.size()<<endl;;
    cout<<"the text compressed result is:"<<endl;
    for(int num:encoded_output)
    {
       cout<<num<<" ";

    }
    cout<<endl;
    cout<<"the new stored value in Lzw_dictionary";
    cout<<endl;
    for (auto const&x:lzw_dictionary){

       if(x.second>256)
        {
            cout << x.first << ":" << x.second << endl;
        }


    }
}


/// *** pseudocode of LZW Compress.....
/*
summary.............
 * string s;
 * char ch;
 * s = empty string;
 * while (there is still data to be read)
 {
 *   ch = read a character;
 *   if (dictionary contains s+ch)
 *   {
 *	s = s+ch;
 *   }
 *   else
 *   {
 *	encode s to output file;
 *	add s+ch to dictionary;
 *	s = ch;
 *   }
}
* encode s to output file;
*/


/// *** second decompress....

void Lzw_decompress(int num)
{

    ///  Data used in decompressed...

    bool flag=0;                                  // int num: number of int  keys  needed to be decompressed...
    string ascii;                                // take int value and  change it into ascii key....
    int user_need_decompress;                   // take compress results(int keys)from user to decompress it...
    vector<int>compress_index;                 // to save keys taken from it it...
    vector<string>decompress_str;             // save result of decompress process(string that compressed before)...
    map<int,string>lzw_dictionary;           // hold all possible ascii Characters(dictionary of 256 characters (in the case of 8 bits) and uses those as the "standard" character set)....
    int alternat_int=0,current_int;         // current_int hold current compress key value and give  it is value after each loop to alternate_int
    string alternat_str="",current_str=""; // after initialize current and alternate int with number keys of compress after that iterate over dictionary to get string value of each key in lzw_dictionaryr

   /// *** Data used to add new strings to dictionary...

    string alternate_char="",current_char="";   // alternate_char value equal to alternat_str and current_char equel to current_str
    string sum="";                             // hold string from summation of alternat_str and current_char and then add sum to lzw_dictionary...


  /// *** Take number of int  keys  needed to be decompressed from user...



  /// *** Take the keys value that wiil decompressed and save it in  vector...

  cout<<"Enter the keys value";
  cout<<endl;
   for(int j=0;j<num;++j)
    {
        cin>>user_need_decompress;                        // taking keys value...
        compress_index.push_back(user_need_decompress);  // save keys value in  compress_index...
    }


  /// *** filling lzw_dictionary with all possible ascii Characters....


    for(int i=0;i<256;++i)
    {
        ascii=i;                                            // get assci that it is value is int i...
        lzw_dictionary.insert(pair<int,string>(i,ascii));  // save all assci characters in lzw_dictionary(i >> it is number in dic,ascii >> it is value)
    }


  /// *** 1st loop to print value of the first int key value(compress_index[0]...

   for(auto const &x:lzw_dictionary)
        {
            current_int=compress_index[0];                    // current_int  equal to first number(key) in compress_index)...
            if(x.first==current_int)                         // to search about it in dictionary...
            {
                current_str=x.second;                      // current_str will hold string value of first number...
                decompress_str.push_back(current_str);    // the decompress happen as print string value of current_str...
                current_str.clear();
                alternat_int=0;                         //  alternate_int sure to be equal to zero to take new value(not very important but for ensure)...
                alternat_int=current_int;              //  alternate_int will take value of current_int...
                break;                                // because if key in begging not continue loop(for time execution)...

             }
       }



    /// *** 2nd loop to iterate over keys to be compressed and print it is compress value(except first number)...


    for(int i=1;i<compress_index.size();++i)   // make value of counter i equal to one to begin from second key as first key decompressed before....
    {
        current_int=compress_index[i];        // current_int will take the value of  current key and  alternate_int will be the previous value  of current_int as they alternate value with current_int after each end of loop...


       /// *** 3rd loop to get string value of the key stored in  alternate key and put it in alternate_str...

        for(auto const &x:lzw_dictionary)
        {
            if(x.first==alternat_int)
            {
                alternat_str=x.second;    // alternate_str equal string value of key...
                break;                   //  because if key in begging not continue loop(for time execution)...

            }

        }


       /// *** 4rd loop to get string value of the key stored in  current key and put it in current_str...


                /// uncompress-ion ERRORS(SPECIAL CASE OF DECOMPRESS)....
               /// SO WHAT IS THE ERROR? ....
              ///  WILL ANSWER THIS FROM TOPIC THAT AN UNVERISTY MADE IT OF HEADING LZW Data Compression(THE ExAMPLE IS abababab)
             /*

              As you can see, the decoder comes across an index of 4 while the entry that belongs
              there is currently being processed. To understand why this happens, take a look at the encoding table
              Immediately after "ABA" (with an index of 4) is entered into the dictionary,
              he next substring that is encoded is an "ABA" (IE. the very next code written to the encoded output file is a 4). Thus, the
              only case in which this special case can occur is if the substring begins and ends with the same character
               ("ABA" is of the form <char><string><char>). So, to deal with this exception, you simply
               take the substring you have so far, "ab", and concatenate its first character to itself, "ab"+"a" = "ABA",
                instead of following the procedure as normal. Therefore the pseudo code provided above must be altered a bit in order to handle all cases.
            */

               /// the aim to check about exist of current key in lzw_dictionary....


            for (auto const&x:lzw_dictionary)
            {
                                                                   //check tool equal false...
                if(x.first==current_int)                          //if yes
                {
                    flag=1;                                      //flag=true
                    break;                                      // exist of loop...
                }
                else
                {
                    flag=0;                }
            }

        if(flag==1)                                           // if key exist in dictionary...
        {
          for (auto const&x:lzw_dictionary)
            {
                if(x.first==current_int)                     //get key to get it is key string value....
                {
                   current_str=x.second;
                   decompress_str.push_back(current_str);  // put   key string value in output code
                   alternat_int=0;                        // check that alternate_int is free
                   alternat_int=current_int;             // make current int ==alternate int
                   break;                               // exist
                }
            }
        }

           /// if the key is not found in dictionary and this the exception event in LZW_decompress
           else
           {

               for (auto const&x:lzw_dictionary)
              {
                current_str=alternat_str+alternat_str[0];  /// make last alternate string value equal to current string value but add the first character of alternate string ...
                decompress_str.push_back(current_str);     //return it to decompress string (out put code)....
                alternat_int=0;                           // check that alternate_int is free
                alternat_int=current_int;                // make current int ==alternate int
                break;                                  // exist

              }
           }

       /// *** Adding new string to dictionary

          /// the properties of string that add to dictionary must be: the value of alternate_str all (char or string) but current_str must be char only if it string will take only first index [0]...

       if(current_str.size()<2) // check about size and it must be less 2 to satisfy adding to dictionary properties
        {                        // if YES::


          alternate_char+=alternat_str;                                            // alternate_char will take the value of alternat_str...
          current_char+=current_str;                                              //  current_char will take the value of current_str...
          sum=alternate_char+current_char;                                       //   merge alternate_char and current_char with each other ...
          lzw_dictionary.insert(pair<int,string>(lzw_dictionary.size()+1,sum)); // save new value in the dictionary with new int key...


           /// clear all strings data for new iteration as it will take new values....

            alternate_char.clear();
            current_char.clear();
            sum.clear();
            current_str.clear();
            alternat_str.clear();

        }
      else
        {
            // if no:

            alternate_char+=alternat_str;                                            // alternate_char will take the value of alternate_str...
            current_char+=current_str[0];                                           // current_char equal to first char in current_str  ...
            sum= alternate_char+current_char;                                      //   merge alternate_char and current_char with each other ...
            lzw_dictionary.insert(pair<int,string>(lzw_dictionary.size()+1,sum)); // save new value in the dictionary with new int key...


            /// clear all strings data for new iteration as it will take new values....

            alternate_char.clear();
            current_char.clear();
            current_str.clear();
            alternat_str.clear();

        }

    }


  /// *** the last step return user decompress results which is some string and dictionary value if needed....

    cout<<"the keys decompressed result is:"<<endl;
    for(string c:decompress_str)
    {
       cout<<c<<"";        // print decompress_str values
    }
    cout<<endl;
    cout<<"the number of keys decompressed:"<<endl;
    cout<<decompress_str.size()<<endl;

    cout<<"the new stored value in Lzw_dictionary"<<endl;
    for(auto const &x:lzw_dictionary)
           if(x.first>256)
        {
            cout << x.first << ":" << x.second << endl;
        }

}





  /// *** pseudocode of LZW decompressing  .....


/*
 summery of decompressing
 string entry;
 char ch;
 int prevcode, currcode;
 ...

 prevcode = read in a code;
 decode/output prevcode;
 while (there is still data to read)
 {
    currcode = read in a code;
    entry = translation of currcode from dictionary;
    output entry;
    ch = first char of entry;
    add ((translation of prevcode)+ch) to dictionary;
     prevcode = currcode;
 }
*/




  /// *** function for print vector...


void printvector(vector<int>myvector)
{
    for(int v:myvector)
   {
       cout<<v;

   }


  /// *** function to check exist of element in  any dictionary...



}
void iterator_through_map(map<string,int>mystring,vector<int>p,string g)
{
    for(pair<string,int>iter:mystring)
    {
        if(iter.first==g)
        {
            p.push_back(iter.second);
        }
    }
}

/*
                             UM.
                            J@B@1                                                                    iO@1
                           Y@@@B@BB.                                                              7B@B@B@
                          :@B@i,B@B@O                                                          ,Z@B@B@B@Br
                          @B@q   i@B@BS                                                      7@B@@@O5vMB@q
                         8@@B      LB@B@i                                                  FB@@@BNjYjLE@B@
                        ,B@B:        0@@@Z                                               P@B@BM1JJ125JPB@B
                        B@BB          :@B@B                                            XB@B@Z2LuU52F2u2@B@.
                       :@B@             @@@B:                                        v@B@B8uJj51F1525uUB@B7
                       @B@O              0@@B.               ..::ir7vvYUuU777r::.   B@B@OULU2F2F151F11Y@B@S
                       B@B,               8B@B  :ruXMB@B@B@B@B@B@B@B@B@B@@@B@B@B@B@B@B@5Jj1211F1F1F2FUJO@BB
                      U@B@                 @B@B@B@B@B@@@B@B@B@MMqPS5JuYL7rq@B@OBB@B@B8Yu211F1515251515YGB@@
                      @B@u                 v@@@@MSur:.                    LB@MvvjJuU5YU252F1F1F25251F2uX@@@
                      @@@.                                                N@BML2U2UUU12F15252525251515Jk@@B
                     r@B@                                                 YB@Bju52121252515252F15251F2u5@B@
                     PB@B                                                  @@@PYUF151F25151F152F2F1F15jF@@B
                     @@BS                                                  N@@@UJ2F25252F251525151F1F1u5@B@
                     @@@7                                                   B@B@5Yj12F152F1F1F25252515jFB@B
                     B@Bi                                                    M@B@O2Luu52525212F151121UY1@B@7
                    O@B@:                                                     v@B@BMSuYJJuuUu2u2uujjYJJXB@B@M
                  7B@B@,                                                        1B@@@B@GPF1uujuu21PNMB@B@B@B@@
                 qB@B2                                                            i8B@B@B@B@B@@@@@B@B@B@q: @@@B
                MB@B:                                                                 7SBB@B@B@B@B@Zu:      @B@B
               ZB@B.                                              ,v.                                        @B@L
              LB@B,                         Y7                    @B@Bu                                      7@B@
   :B@B@@B2:  @@B7                         @B@Z                   r@B@B@BP:                                   B@BE
    BB@@@B@B@B@BE                        r@B@B                       7@B@B@B@Ou:                              iB@B
         :uM@@B@@2.           :7::::ivk@B@B@0                           :5B@B@B@B@B@B@G.                       @B@i
            BB@@@B@@         :@B@B@@@B@B@@1                                 .i5M@B@B@@@5                       M@@2
            B@B ,@B1          L0EZZG0F7:                                            .:,                        uB@MrP@M7
           2@B@                                                                                               ,O@B@B@B@B
           @B@1                                                     :@B@@@r                                :@@@@B@BL:,,
           B@Bi                         :2ZS;                      :@B@B@B@r                               L@B@B@BU
           @B@.                        @@@B@B@                     vB@B@B@B5                                   @B@i
           B@B                        7B@B@B@BM                     OB@B@B@                                   ,B@B
           @B@                         @B@B@@@i                       rL7.                                    B@BM
           B@B7.:                       NB@@M.                                                               .@B@.
  .;JEB@@ @B@B@B@B@.                                                                                       .  @B@u
@@@B@B@B@B@@@B@18U                                                                                      :B@B@B@BU,
7@BOui.    ,@@B                                                                                          SP@B@B@B@B@Or
            @@@U                                                                                           B@BJ.YO@B@B@i
            r@B@                                                                                         :B@Bk     .k@B@
             B@B@                                                                                       LB@@k         2i
              B@BM                                      .7jXEGqF7:                                     OB@@L
              .B@BM                                   .B@B@B@B@B@B@.                                 :@B@B:
               .B@B@                                   @@MYr::ivG@B                                .M@B@G
                 B@@@S                                                                           ,MB@B@,
                  v@@@BF                                                                      .1B@B@Br
                    2@@B@BL                                                                ,FB@@@B8,
                      r@B@B@BF,                                                        :YBB@B@B@B
                         L@B@B@B@P7,                                           .ivXB@B@B@B@B@M@B@
                            ,1B@B@B@B@@@BOP2L7i:,.              ..,:i7LSNB@@B@B@@@B@B@B@Z5v;.LB@@
                              @B@OEB@B@@@B@B@B@B@B@B@B@B@@@B@B@B@B@B@@@B@B@B@B@BM0SJ7i::::i:,u@B@
                              B@Bu ::i;7vu2XNGOMB@B@BMB@B@B@B@B@B@@@B1UFuj77ii:::::::iir;r;i.YB@B
                              @B@L.:i:i:i::::::::::..Y@B@BMYi:i;SB@B@N:.::i:iirir;r;rii::::ivO@B@
                              B@@X::,::::iirir;riri:E@B@1         ,@B@Br:;;r;rii:i::::i7JEB@@@@@B
                              @@@B@BBq5v7ii:::::::.2@@@i  ..,..     @B@@,,:::::irv2XMB@B@B@B@2@B@:
                             .B@BBB@@@B@B@B@BMNP5u7@B@1 .,,:,,  :.   @B@P50MB@B@B@B@B@@@BS:   @@B1
                             E@B@   ijGB@B@B@B@B@B@B@Bi .,:,,..@@B@7 B@B@B@B@B@B@BM57.        kB@B
                            .@B@:          .,ivu5Nq@B@u  ..,.. SB@B@@@B@PL7i,                 ,@B@
                            @@@8                   i@B@:    .     :B@B@@                       B@@2
                          i@@@@                     0@B@u          B@@B.                       vB@B
                         ,@B@G                       L@B@BOv:.:iFB@B@M                          @B@Bi
                          vNi                          S@@B@B@B@B@BM:                            MB@N
                                                          758BMqJ,

    s
                          .ll                                           rB.                     :
*/





