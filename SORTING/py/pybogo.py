import random
from random import randit, shuffle  
    def bosort(a):
        iter=0
        while not is_sorted(a):
            shuffle(a)
            iter=iter+1
        return iter,a    
    def sorted(a):
        for i in xrange (1, len(a)):
            if a[i]<a[i-1]:
                return False
            return True            
    def create_array()
        return[randit(0,max) for _ in range(size)]
    a=create_array(6,6) 
    print "Before Sort:",a
    iter, a= bogo_sort(a)
    print "After Sort:",s
    print "Number of iteration:%d", iter   

        