import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit(1)

    people = []
    with open(sys.argv[1]) as f:
        reader = csv.DictReader(f)
        strs = reader.fieldnames[1:]
        for row in reader:
            people.append(row)

    with open(sys.argv[2]) as f:
        sequence = f.read()

    counts = {}
    for s in strs:
        counts[s] = longest_run(sequence, s)

    for person in people:
        match = True
        for s in strs:
            if int(person[s]) != counts[s]:
                match = False
                break
        if match:
            print(person["name"])
            return

    print("No match")


def longest_run(sequence, s):
    max_count = 0
    i = 0
    while i < len(sequence):
        count = 0
        while sequence[i:i + len(s)] == s:
            count += 1
            i += len(s)
        max_count = max(max_count, count)
        i += 1
    return max_count


main()

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
