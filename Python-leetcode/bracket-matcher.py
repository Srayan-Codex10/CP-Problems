def matchBrackets(symbols: str) -> bool:
    symbol_stack = []
    for bracket in symbols:
        if bracket in symbol_stack:
            symbol_stack.pop()
        elif len(symbol_stack) == 0:
            symbol_stack.append(bracket)
        else:
            symbol_stack.append(bracket)
    
    if(len(symbol_stack) != 0):
        return False
    else:
        return True


if __name__ == "__main__":
    input_symbols = str(input())
    print(matchBrackets(input_symbols))