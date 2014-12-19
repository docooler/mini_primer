class Sloution(object):
    
    def __init__(self):
        self.length = 1000000
        self.data=[ 0 for i in range(self.length)] 

    def factorization(self, num):
        factor = []
        x = 2

        while num != 1:
            if self.data[x]==0:
                while num %x == 0:
                    factor.append(x)
                    num /=x
            x += 1

        return (factor)
    def initPrimes(self):
        for x in xrange(2,self.length):
            if self.data[x] == 0:
                mutil = 2
                while x*mutil<self.length:
                    self.data[x*mutil] += 1
                    mutil += 1
    def getStartNum(self):
        x = 2
        while x+3 < self.length:
            if self.data[x] == 4     \
            and self.data[x+1] == 4  \
            and self.data[x+2] == 4  \
            and self.data[x+3] == 4:
                return x
            x += 1
        print "length too low Not found"
        return 1

def main():
    s =Sloution()
    s.initPrimes()
    num = s.getStartNum()

    for x in xrange(4):
        result = s.factorization(num+x)
        print str(num+x) + ":"
        print result

if __name__ == '__main__':
    main()
