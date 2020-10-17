# Python program to print the first non-repeating character 

def getcount(string): 
	count = [0] * 256 
	for i in string: 
		count[ord(i)]+= 1
	return count 

def firstNonRepeating(string): 
	count = getcount(string) 
	index = -1
	k = 0

	for i in string: 
		if count[ord(i)] == 1: 
			index = k 
			break
		k += 1

	return index 

string = "helloWorld"
index = firstNonRepeating(string) 
if index == 1: 
	print "Either all characters are repeating or string is empty"
else: 
	print "First non-repeating character is " + string[index] 

