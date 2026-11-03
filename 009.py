def naive_string_matching(text, pattern):
    n = len(text)
    m = len(pattern)
    positions = []
    
    # Check pattern at every possible position
    for i in range(n - m + 1):
        j = 0
        # Compare pattern with text
        while j < m and text[i + j] == pattern[j]:
            j += 1
            
        # If all characters matched
        if j == m:
            positions.append(i)
            
    return positions

# Input
text = input("Enter the text: ")
pattern = input("Enter the pattern: ")

# Find pattern
result = naive_string_matching(text, pattern)

# Output
if result:
    print("Pattern found at positions:", result)
else:
    print("Pattern not found")
