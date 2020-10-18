class store:
 pro_code=[]
 name=[]
 price=[]
 
 
 def input_data(self):
  for i in range(5):
   self.pro_code.append(int(input("Enter the code:")))
   self.name.append(input("Enter name:"))
   self.price.append(int(input("Enter price:")))
   

 def display_data(self):
   print("pro_code \tname \t     price")
   for i in range(5):
    print (self.pro_code[i],"\t\t",self.name[i],"\t\t",self.price[i])
    

 def calculate_bill(self,qty):
   total=0
   for i in range(5):
    total=total+self.price[i]*qty[i]
   print("*****BILL*****")
   print("code\tname\tprice\tqty\tsubtotal")
   for i in range(5):
    print (self.pro_code[i],"\t",self.name[i],"\t",self.price[i],"\t",qty[i],"\t",qty[i]*self.price[i])
    print ("Total:",total)
    

s=store()
s.input_data()
s.display_data()
q=[]
print("Enter quantity:")
for i in range(5):
 q.append(int(input()))
s.calculate_bill(q)
