import numpy as np

class Add():
    
    def split(self,a):

		'''given int a 
		   return the numpy array 
		'''
		a = str(a)
		a = [int(cha) for cha in a]
		return np.array(a)
    
    def unsplit(self,a):

        '''opposite of split'''
        
        val = 0
        for i in range(a.shape[0]):
            val = val*10+a[i]
        
        return int(val)


    
    def adder(self,a,b):
        '''
           a and b are two np arrays
           returns: the sum of the two
        '''
        a = self.split(a)
        b = self.split(b)
        sum = np.zeros((max(a.size,b.size)))

        carry = 0

        ra = np.flip(a)
        rb = np.flip(b)
        
        idx = max(ra.size,rb.size)

        i = 0

        while i<idx:

            x=0
            y=0

            if i<ra.size:
                x = ra[i]
            
            if i<rb.size:
                y= rb[i]
            
            sum[i] = int((x+y+carry)%10)
            carry = int((x+y+carry)//10)
            
            i += 1
        
        if carry == 1:
           sum = np.hstack((sum,[carry]))
        
        return self.unsplit(np.flip(sum))
    

if __name__ == '__main__':

    add = Add()
    value = add.adder(999,1)
    # value = add.split(50)
    print(value)

