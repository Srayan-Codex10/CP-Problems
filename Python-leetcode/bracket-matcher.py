def matchBrackets(symbols: str) -> bool:
    pair_brackets = {'(':')', '{':'}', '[':']'}
    symbol_pair_stack = list()

    for bracket in symbols:
        if bracket in pair_brackets.keys():
            symbol_pair_stack.append(bracket)
        elif bracket in pair_brackets.values():
            if len(symbol_pair_stack) == 0:
                return False
            else:
                if(pair_brackets[symbol_pair_stack.pop()] != bracket):
                    return False
    if(len(symbol_pair_stack) == 0):
        return True
    else:
        return False


if __name__ == "__main__":
    input_symbols = str(input().strip())
    print(matchBrackets(input_symbols))
