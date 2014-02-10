#
# Problem 54 - Poker hands
#
import time

class Hands():
    HighCard      = 0
    OnePair       = 1
    TwoPair       = 2
    ThreeOfAKind  = 3
    Straight      = 4
    Flush         = 5
    FullHouse     = 6
    FourOfAKind   = 7
    StraightFlush = 8
    RoyalFlush    = 9

card_num = {
'2':0, '3':4, '4':8, '5':12, '6':16, '7':20,
'8':24, '9':28, 'T':32, 'J':36, 'Q':40, 'K':44, 'A':48,
'C':0, 'D':1, 'H':2, 'S':3 }

def card_to_num(card):
    return card_num[card[0]] + card_num[card[1]]

def card_way(cards):
    sorted_cards = sorted(cards)

    ranks = [x // 4 for x in cards]
    ranks.sort()
    # print(ranks)

    straight = False
    flush = False

    set_size = len(set(ranks))

    if set_size == 5: # High Card or Straight or ...
        if ranks[0] + 4 == ranks[4]:
            straight = True


    elif set_size == 4: # One Pair

        for i in range(0,4):
            if ranks[i] == ranks[i+1]:
                s = ranks[i]
                break
        r = [x for x in cards if x in range(s * 4, s * 4 + 4)]
        return ["OP", Hands.OnePair, max(r)]

    # Two Pairs or Three of a Kind
    #
    # [A A B B C] # Return 'Two Pairs' / B with suit
    # [A A B C C] # Return 'Two Pairs' / C with suit
    # [A B B C C] # Return 'Two Pairs' / C with suit
    # [A A A B C] # Return 'Three of a Kind' / A
    # [A B B B C] # Return 'Three of a Kind' / B
    # [A B C C C] # Return 'Three of a Kind' / C
    elif set_size == 3:
        if ((ranks[0] == ranks[1] and ranks[1] == ranks[2]) or
            (ranks[1] == ranks[2] and ranks[2] == ranks[3]) or
            (ranks[2] == ranks[3] and ranks[3] == ranks[4])):
            return ["TK", Hands.ThreeOfAKind, sorted_cards[2]]
        else:

            return ["TP", Hands.TwoPair, sorted_cards[3]]

    # Full House or Four of a Kind
    #
    #      | -------> Rank
    # [A A A B B]  # Full House / A
    # [A A B B B]  # Full House / B
    # [A A A A B]  # Return 'Four of a Kind' / A
    # [A B B B B]  # Return 'Four of a Kind' / B
    #    ^   ^ -----> Full House or Four of a Kind
    #
    elif set_size == 2:
        if ranks[1] == ranks[3]:
            return ["FK", Hands.FourOfAKind, sorted_cards[2]]
        else:
            return ["FH", Hands.FullHouse, sorted_cards[2]]


    if len(set([x % 4 for x in cards])) == 1:
        flush = True

    # Straight Flush or Royal Flush
    if straight and flush:
        return ["SF", Hands.StraightFlush, sorted_cards[4]]

    # Flush
    if flush:
        return ["FL", Hands.Flush, sorted_cards[4]]

    if straight:
        return ["ST", Hands.Straight, sorted_cards[4]]

    # High Card
    return ["HC", Hands.HighCard, sorted_cards[4]]


def main():

    f = open("poker.txt", "r")
    i = 0
    win = 0
    for line in f:
        line = line[:-1]
        # print("-- %s" %(line))
        cards = [card_to_num(x) for x in line.split(' ')]

        player1 = card_way(cards[0:5])
        player2 = card_way(cards[5:10])

        if (player1[1] > player2[1] or
            player1[1] == player2[1] and player1[2] > player2[2]):
            win += 1

    f.close()
    print(win)



if __name__ == '__main__':
    t_start = time.time()
    main()
    t_stop = time.time()
    print(t_stop-t_start)
