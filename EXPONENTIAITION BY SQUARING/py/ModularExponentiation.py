def power(a, b, mod):
    res = 1 
    while (b > 0):
        if b%2: # if it is not divisible by 2
            res = ((res%mod)*(a%mod))%mod
        b = int(b/2)
        a = ((a%mod)*(a%mod))%mod
    return res
    
assert (power(5,2,1000000007) == 25)
assert (power(3,7,1000000007) == 2187)
