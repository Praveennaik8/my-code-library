# Python program for insert and search 
# operation in a Trie
import datetime
from os import system
from time import sleep

def clear_scr():
    print("\nPlease press enter to continue ")
    # sleep(2)
    input()
    system("cls")

# This TRIE code [only creation and insertion] is referenced from geeksforgeeks.com
# contributed by Atul Kumar (www.facebook.com/atul.kr.007)
class TrieNode: 
      
    # Trie node class 
    def __init__(self): 
        self.children = [None]*26
  
        # isEndOfWord is True if node represent the end of the word 
        self.isEndOfWord = 'z'
  
class Trie: 
      
    # Trie data structure class 
    def __init__(self): 
        self.root = self.getNode() 
  
    def getNode(self): 
      
        # Returns new trie node (initialized to NULLs) 
        return TrieNode() 
  
    def _charToIndex(self,ch): 
          
        # private helper function 
        # Converts key current character into index 
        # use only 'a' through 'z' and lower case 
          
        return ord(ch)-ord('a') 
  
  
    def insert(self,key,val): 
          
        # If not present, inserts key into trie 
        # If the key is prefix of trie node,  
        # just marks leaf node 
        pCrawl = self.root 
        length = len(key) 
        for level in range(length): 
            index = self._charToIndex(key[level]) 
        
            # if current character is not present 
            if not pCrawl.children[index]: 
                pCrawl.children[index] = self.getNode() 
            pCrawl = pCrawl.children[index] 
  
        # mark last node as leaf 
        pCrawl.isEndOfWord = val
  
    def search(self, key): 
          
        # Search key in the trie 
        # Returns true if key presents  
        # in trie, else false 
        if len(key) <5:
            flag = False
        else:
            flag = True

        pCrawl = self.root 
        length = len(key) 
        for level in range(length): 
            index = self._charToIndex(key[level]) 
            if not pCrawl.children[index]: 
                return 'z'
            pCrawl = pCrawl.children[index] 

        #This is improvisation part[Predicting next best word]
        if pCrawl.isEndOfWord == 'z' and flag:
            while pCrawl.isEndOfWord == 'z':
                try:
                    for i in range(0,26):
                        # print(i)
                        if pCrawl.children[i]:
                            pCrawl = pCrawl.children[i] 
                            break
                    if i > 26:
                        return 'z'
                except:
                    print("fail")
                    break

        
        return  pCrawl.isEndOfWord 

#f1 here is a global variable
f1='null'
myTree = 'null'
action = {}#'101':['hbjh','h k']}#dummy initialisation

def create_log():
    # global variables are used with the keyword 'global' when
    # they are used inside functions
    global f1
    f1 = open("log-file.txt", "a")
    f1.write("\n------------------------------------------------------\n")
    f1.write("Session started @ "+str(datetime.datetime.now()) + "\n")

def close_log():
    global f1
    f1.close()

def write_log(s):
    global f1
    f1.write(s+"\n")


def load_from_file(s):
    try:
        fp = open(s,"r")
        l = fp.readline()
        fp.close()
        write_log("The file "+s+" readed successfully")
    except:
        write_log("***Failure in reading file "+s+"***")
        l = []
    return l 

def add_to_file(file_name,s,val):
    try:
        write_log("Opening file "+file_name)
        fp = open(file_name,"a")
        fp.write(","+s+" "+val)
        write_log(s+" added successfully with catagory "+val)
        fp.close()
        return True
    except:
        print("file opening error")
        write_log("***"+file_name+" crashed while appending "+ s+" "+val+"***")
        return False
        


def test(s):
    for i in s:
        if i>'z' or i< 'a': 
            return False
    return True


# To calculate percentage of negativity of the sentence
def calc_perc(p,c,z,v,a,d):
   
    v = v*20
    d = d*10
    a = a*5
    c = c*8
    p = p*15
    ans = v+d+a+c-p
    calc = v+d+a+c+p
    if ans <0 :
        ans = 0
    if calc == 0:
        return 0
    return ans/calc * 100

def menu():
    print("\n1.Process a sentence \n2.Add new word\n3.Check for possible actions I can take\n10.exit")

def catagory():
    print("Choose catagory :\n1 : positive word\n2 : Curse word\n3 : Neautral\n4 : Vulgur word\n5 : anger\n6 : disgust")

def show_details():
    clear_scr()
    print("What did you face ?")
    print("1.Getting vulgur messages")
    print("2.Someone is stalking on social media")
    print("3.Getting negative comments")
    print("4.Someone is blackmailing me")
    print("5.Someone is misusing my identity")
    print("6.Posting my pics/video with bad intentions")
    print("7.Sharing inappropriate posts")
    print("8.Provoking to suicide")
    print("9.Triggering religious, racial, ethnic or political hate online by posting hate comments or videos ")
    print("10.Spreading rumors or gossip about me online.")
    print("11.Making fun of me repeatedly in an online chat that includes multiple people")
    print("12.Cheating through computer resource")
    print("13.Someone accessed my private information")
    print("14.Getting threatening messages")
    print("15.Recieving abusing messaging through mail")
    print("16.Forcing me to do criminal offence\n\n")
    ch = input()
    write_log("In 3 , option "+ch+" is selected ")
    try:
        i = action[ch]
        print("Laws supporting you OR Action You can take : \n")
        cnt = 1
        for x in i:
            print(str(cnt)+".",x+"\n")
            cnt+=1
    except:
        print("Invalid Input")
        write_log("Invalid Input")
        

def second_part():
    clear_scr()
    print('1.It happened through samrtphone/laptop/ or any other electronic gadgets')
    print("2.It didn't happen through electronic gadgets" )
    # print("3.I am Not Sure.")
    try:
        ch = int(input())
    except:
        ch =101
        print("Invalid Entry")
    
    if ch == 1:
        show_details()
    elif ch == 2:
        print("Contact Nearest police station for help")
    
        
def load_action(s):
    try:
        write_log("openning file "+s)
        fp = open(s,"r")
        l = fp.readline()
        fp.close()
        write_log("The file "+s+" readed successfully")
    except:
        write_log("***Failure in reading file "+s+"***")
        l = []
    return l 

def initialize():
    # Input keys (use only 'a' through 'z' and lower case) 
    create_log()
    write_log("Opening file"+"total_words_update.txt")

    l=load_from_file("total_words_update.txt")

    # print(l)
    l = str(l)
    # print(l)

    # print(len(l))
    # for i in l:
    #     print(i)
    # Trie object 
    write_log("Creating TRIE.....")
    global myTree
    myTree = Trie() 
    keys = l.split(",")
    # Construct trie 
    for key in keys: 
        try:
            word,val = key.split(" ")
            if(test(word)):
                # print(word," -->",val)
                myTree.insert(word,val) 
        except:
            print("Fail for key = ",key)
            write_log("***key = "+key+" is not inserted ")
    write_log("TRIE created successfully.....")
    
    # Search for different keys 
    write_log("Creating Dictionary.....")
    output ={'p':'positive word','c':'Curse word',
             'z': 'Neautral','v':'Vulgur word',
             'a':'anger','d':'disgust'}

    catag_number = ['p','c','z','v','a','d']
    write_log("Dictionary created!!")
    # print(output[myTree.search("pus")]) 
    # print(output[myTree.search("kill")]) 
    # print(output[myTree.search("die")]) 
    # print(output[myTree.search("happy")])
    global action
    for i in range(1,17):
        action[str(i)] = []

    temp = str(load_action("actions.txt"))
    temp = temp.split("$")
    for line in temp:
        try:
            key,value = line.split("%")
            key = key.split(",")
            for j in key:
                if j != '':
                    x = action[j]
                    x.append(value)
                    action[i] = x
        except:
            write_log("Failed for key :"+str(j))
    write_log("Dictionary of actions created!!!! ") 
    
    return output,catag_number

# driver function 
def main(): 
  
    output,catag_number = initialize()
    
    while True:
        clear_scr()
        menu()
        try:
            choice = int(input())
            write_log("choice "+str(choice)+" is selected")
        except:
            print("Invalid option")
            choice = 101
        if choice == 1:
           
            sentence = input()
            res={'p':0,'c':0,'v':0,'z':0,'d':0,'a':0}
            sentence = sentence.split(" ")
            for word in sentence:
                try:
                    word = word.lower()
                    x = myTree.search(word)
                    print(word,x)
                    res[x]+=1
                except:
                    print(word+" is not a string ")

            print(output['p']," --> ",res['p'])
            print(output['c']," --> ",res['c'])
            print(output['v']," --> ",res['v'])
            print(output['z']," --> ",res['z'])
            print(output['a']," --> ",res['a'])
            print(output['d']," --> ",res['d'])
            print(calc_perc(res['p'],res['c'],res['z'],res['v'],res['a'],res['d']))
            
        elif choice == 2:
            
            word = input("Enter the word\n")
            try:
                word = word.lower()
                if test(word):
                    catagory()
                    ch = int(input())

                    if ch < 1 or ch > 6 :
                        print("invalid input")
                        write_log("***input"+ch+" is not valid***")
                    else:
                        myTree.insert(word,catag_number[ch-1])
                        write_log(word+" inserted successfully with val "+str(catag_number[ch-1]))

                        if add_to_file("total_words_update.txt",word,catag_number[ch-1]) :
                            print("Added successfully")
                else:
                    write_log("***"+word+" is not valid***")
                    print(word+" is not valid")
            except:
                write_log("***"+word+" is not valid***")
                print(word+" is not valid")
        elif choice == 3:
            second_part()

        elif choice == 10:
    
            write_log("Session terminating @"+str(datetime.datetime.now()))
            close_log()
            print("\nProgram Terminating................!!!\n\n")
            clear_scr()
            
            return
        write_log("Task "+str(choice)+" is Finished")
                

if __name__ == '__main__': 
    main() 
