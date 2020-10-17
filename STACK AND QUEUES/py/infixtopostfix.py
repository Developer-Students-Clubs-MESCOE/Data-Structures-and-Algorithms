from stack import Stack

def InfixToPostfix(expression):
    '''infix to postfix conversion'''

    # Precedence
    prec = {}
    prec["*"] = 3
    prec["/"] = 3
    prec["+"] = 2
    prec["-"] = 2
    prec["("] = 1
    
    # Create an empty stack called data_stack for keeping operators. Create an empty list for output.
    data_stack = Stack()
    postfix_exp = []
    tokens = expression.split()

    for token in tokens:
		# If the token is an operand, append it to the end of the output list.
        if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
            postfix_exp.append(token)
        
        # If the token is a left parenthesis, push it on the data_stack.    
        elif token == '(':
            data_stack.push(token)
        
        #If the token is a right parenthesis, pop the data_stack until the corresponding left parenthesis is removed. 
        elif token == ')':
            top_token = data_stack.pop()
            while top_token != '(':
				# Append each operator to the end of the output list.
                postfix_exp.append(top_token)
                top_token = data_stack.pop()
        else:
			
			# first remove any operators already on the data_stack that have higher or equal precedence and append them to the output list.
            while (not data_stack.is_empty()) and (prec[data_stack.peek()] >= prec[token]):
                  postfix_exp.append(data_stack.pop())
            data_stack.push(token)
    
    # Any operators still on the stack can be removed and appended to the end of the output list.
    while not data_stack.is_empty():
        postfix_exp.append(data_stack.pop())
    
    return " ".join(postfix_exp)

# Testing
print(InfixToPostfix("A * B + C * D"))
print(InfixToPostfix("( A + B ) * C - ( D - E ) * ( F + G )"))