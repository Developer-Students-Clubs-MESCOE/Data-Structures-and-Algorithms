# Python Program to convert Upper-case to Lower-case and vice versa.
# Written by Lisha Ray

# Function to convert Upper-case to Lower-case and vice versa. 
def change_case(sentence): 
    new_sentence=""
    for i in range (len(sentence)):
        if sentence[i] == " ":
            new_sentence+=(sentence[i])
        if sentence[i].islower() == 1:
            new_sentence+=sentence[i].upper()
        elif sentence[i].isupper() == 1:
            new_sentence+=sentence[i].lower()
        else :  
            new_sentence+=(sentence[i])
    return new_sentence

sentence= str(input("Enter a sentence = "))
print(" Result = ",change_case(sentence)) 

#Output:  
#Enter a sentence = Lily is a flower                                                                                           
#Result =  lILY  IS  A  FLOWER 