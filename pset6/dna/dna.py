def sumOfTheSeries(n): 
  
    sum = 0
    for i in range(0, n + 1): 
        # first term of each i-th 
        # term 
        k = 2
        for j in range(1, i + 1): 
            sum = sum + k; 
  
            # next term 
            k = k + 2
      
    # required sum 
    return sum; 
  
# Driver program to test above 
n = 5
ans = sumOfTheSeries(n); 
print (ans) 
        
        
        
