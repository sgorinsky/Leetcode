class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        self.domain_visits = {}
        
        for domain in cpdomains:
            [num, domain] = domain.split(' ')
            num = int(num)
            subdomains = domain.split('.')
            
            for i in range(len(subdomains)):
                curr_str = '.'.join(subdomains[i:])
                self.domain_visits[curr_str] = num if curr_str not in self.domain_visits else self.domain_visits[curr_str] + num
                
        
        return [ f'{v} {k}' for k, v in self.domain_visits.items() ]
