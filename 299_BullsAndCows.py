class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls, cows = 0, 0
        bull_indices, secret_dict = set(), {}
        for l in secret: secret_dict[l] = secret_dict[l] + 1 if l in secret_dict else 1
        
        # bulls
        for i in range(len(guess)):
            if guess[i] == secret[i]: 
                bulls += 1
                secret_dict[guess[i]] -= 1
                bull_indices.add(i)
                
        #cows
        for i in range(len(guess)):
            if guess[i] in secret_dict and secret_dict[guess[i]] > 0 and i not in bull_indices: 
                cows += 1
                secret_dict[guess[i]] -= 1
        
        return f'{bulls}A{cows}B'
