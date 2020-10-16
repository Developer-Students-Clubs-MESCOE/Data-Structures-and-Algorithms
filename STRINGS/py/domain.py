#Code to extract domain name from email id

Mail=input("Enter your Email Address:")


#getting index position of '@' in the entered string

at_index=Mail.find('@')


#extracting domain name from the email id using string slicing

print(Mail[at_index+1:])