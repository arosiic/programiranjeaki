def misere_move(piles):
    bigger = sum(1 for x in piles if x > 1)

    if bigger == 0:
        cnt = sum(piles)
        for i in range(len(piles)):
            if piles[i]:
                piles[i] -= 1
                return

    xor_sum = 0
    for x in piles:
        xor_sum ^= x

    if bigger == 1:
        idx = next(i for i,x in enumerate(piles) if x > 1)
        ones = sum(1 for x in piles if x == 1)

        if ones % 2 == 0:
            piles[idx] = 1
        else:
            piles[idx] = 0
        return

    for i in range(len(piles)):
        target = piles[i] ^ xor_sum
        if target < piles[i]:
            piles[i] = target
            return