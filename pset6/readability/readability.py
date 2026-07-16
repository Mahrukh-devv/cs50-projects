from cs50 import get_string
import re

text = get_string("Text: ")

letters = len(re.findall(r'[a-zA-Z]', text))
words = len(text.split())
sentences = len(re.findall(r'[.!?]', text))

L = (letters / words) * 100
S = (sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
