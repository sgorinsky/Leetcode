class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        split_emails = [e.split('@') if e else ['', ''] for e in emails]
        email_set = set()
        count = 0
        
        for split_email in split_emails:
            [first, second] = split_email
            first = first.replace('.', '')
            for i, l in enumerate(first):
                if l == '+':
                    first = first[:i]
                    break
            entire_email = first + '@' + second
            if entire_email not in email_set:
                email_set.add(entire_email)
                count += 1
        return count
        
