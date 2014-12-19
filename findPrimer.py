class Sloution(object):
    
    def __init__(self):
        self.primes = [2,3,5,7] 
    def getNum(self):
        num = 10
        
        while True:
            notFound = 0
            for x in xrange(4):
                result = self.getFactorNo(num+x)
                if result != 4:
                    notFound = 1
                    num += x
                    break
            if notFound == 0:
                return num
            num += 1

    def getFactorNo(self, num):
        nCnt = 0
        for x in self.primes:
            if num % x == 0:
                nCnt += 1
        if nCnt == 0:
            self.primes.append(num)
            nCnt += 1
        return nCnt
    def factorization(self, num):
        factors = []
        for x in self.primes:
            while num % x == 0:
                factors.append(x)
                num /= x
                if num == 1:
                    return factors
def main():
    s =Sloution()
    num = s.getNum()

    for x in xrange(4):
        result = s.factorization(num+x)
        print str(num+x) + ":"
        print result

if __name__ == '__main__':
    main()
