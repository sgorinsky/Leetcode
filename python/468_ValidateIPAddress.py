class Solution:
    def validIPAddress(self, IP: str) -> str:
        ip_array_v4 = IP.split('.')
        
        if len(ip_array_v4) == 4:
            for entry in ip_array_v4:
                if self.isInt(entry):
                    n = int(entry)
                else:
                    return 'Neither'
                
                if not entry or entry[0] == '-' or (entry[0] == '0' and len(entry) > 1) or not 0 <= n <= 255:
                    return 'Neither'
            return 'IPv4'
        
        ip_array_v6 = IP.split(':')
        if len(ip_array_v6) == 8:
            limit = 2**16
            for entry in ip_array_v6:
                try:
                    if not entry or len(entry) > 4 or entry[0] == '-' or int(entry, 16) > limit or int(entry, 16) < 0:
                        return 'Neither'
                except:
                    return 'Neither'
            return 'IPv6'
        
        return 'Neither'
    
    def isInt(self, s):
        try:
            n = int(s)
            return True
        except:
            return False

def validIPAddress(IP: str) -> str:
    ipv4 = IP.split('.')
    if len(ipv4) == 4:
        for i in ipv4:
            if i.isdigit():
                n = int(i)
                if (i[0] == '0' and len(i) > 1) or n > 255 or n < 0:
                    return 'Neither'
            else:
                return 'Neither'
        return 'IPv4'

    ipv6 = IP.split(':')
    if len(ipv6) == 8:
        limit = 2**16
        for i in ipv6:
            if len(i) > 4 or i =='' or i[0] == '-':
                return 'Neither'
            try:
                if int(i, 16) > limit or int(i, 16) < 0:
                    return 'Neither'
            except:
                return 'Neither'

        return 'IPv6'
    return 'Neither'
