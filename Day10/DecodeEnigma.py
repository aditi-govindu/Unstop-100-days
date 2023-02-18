# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: You own an enigma machine that can interpret a string command. The command consists of an alphabet of "S", "[]" and/or "[sps]" in some order. The enigma will interpret "S" as the string "send", "[]" as the string "the", and "[sps]" as the string “ships". You are assigned with the task of parsing this information and getting the allies and advantage in the war. Each word is separated by a space “ ”.

Given the string command, return the enigma’s interpretation of the command.
'''

mapping = { 'S':'send', '[]':'the', '[sps]':'ships' }

string = input()
idx = 0
n = len(string)
curr = ''

for letter in string:
    # Store combination of letters seen so far
    curr += letter
    if curr in mapping.keys():
        # If match found in mapping, display enigma decoding and reset combination
        print(mapping[curr], end =' ')
        curr = ''