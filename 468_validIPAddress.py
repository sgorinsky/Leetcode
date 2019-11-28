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
