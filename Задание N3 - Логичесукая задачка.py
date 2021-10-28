for A in range(2):
    for B in range(2):
        for C in range(2):
            print("Значения A, B, C -", A, B, C)
            print("1)", bool((not A) or B and C))
            print("2)", bool((A == C)))
            print("3)", bool(((not C) or B)))
            print()
