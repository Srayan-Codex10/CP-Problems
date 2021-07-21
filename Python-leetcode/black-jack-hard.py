def balance_points(points_hand:list, constant_points:dict):
    if(sum(points_hand) > 21):
        temp = points_hand.copy()
        if(max(constant_points['A']) in temp):
                temp[temp.index(max(constant_points['A']))] = min(constant_points['A'])
                if(sum(temp) <= 21):
                    points_hand = temp.copy()
    return points_hand

def calculate_points(hand):
    constant_points = {'J':10,'Q':10,'K':10,'A':(1,11)}
    points_hand = []
    for index,value in enumerate(hand):
        if value not in constant_points:
            points_hand.append(int(value))
            if(index == len(hand)-1):
                points_hand = balance_points(points_hand, constant_points)
        elif ((value in constant_points) and (value != 'A')):
            points_hand.append(constant_points[value])
        else:
            curnt_sum = sum(points_hand)
            max_sum = curnt_sum + max(constant_points[value])
            min_sum = curnt_sum + min(constant_points[value])
            if(curnt_sum <= 21):
                if(max_sum < 21):
                    points_hand.append(max(constant_points[value]))
                elif(min_sum < 21):
                    points_hand.append(min(constant_points[value])) 
                else:
                    points_hand.append(min(constant_points[value])) 
        
    return points_hand


def blackjack_hand_greater_than(hand_1, hand_2):
    points_hand_1 = calculate_points(hand_1)
    points_hand_2 = calculate_points(hand_2)
    if (sum(points_hand_1) > 21):
        return False
    else:
        if(sum(points_hand_2) > 21):
            return True
        elif(sum(points_hand_1) > sum(points_hand_2)):
            return True
        else:
            return False

blackjack_hand_greater_than(['3', '9', '6', '3', 'A'], ['6'])
"""
    Return True if hand_1 beats hand_2, and False otherwise.
    
    In order for hand_1 to beat hand_2 the following must be true:
    - The total of hand_1 must not exceed 21
    - The total of hand_1 must exceed the total of hand_2 OR hand_2's total must exceed 21
    
    Hands are represented as a list of cards. Each card is represented by a string.
    
    When adding up a hand's total, cards with numbers count for that many points. Face
    cards ('J', 'Q', and 'K') are worth 10 points. 'A' can count for 1 or 11.
    
    When determining a hand's total, you should try to count aces in the way that 
    maximizes the hand's total without going over 21. e.g. the total of ['A', 'A', '9'] is 21,
    the total of ['A', 'A', '9', '3'] is 14.
    
    Examples:
    >>> blackjack_hand_greater_than(['K'], ['3', '4'])
    True
    >>> blackjack_hand_greater_than(['K'], ['10'])
    False
    >>> blackjack_hand_greater_than(['K', 'K', '2'], ['3'])
    False
"""