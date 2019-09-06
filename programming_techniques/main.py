#!/usr/bin/python3

from random import shuffle;
    
def scrambleWord(str):
	chars = list(str);
	shuffle(chars);
	return ''.join(chars);

def joinAll(word):
	if len(word) <= 2: return word; # no shuffle needed
	firstLetter, midLetters, lastLetter = word[0], word[1:-1], word[-1]
	return firstLetter + scrambleWord(midLetters) + lastLetter;

if __name__ == "__main__":
    sentence = str(input("Informe o texto: "));
    sentence = sentence.split(' ');
    result = ' '.join(map(joinAll, sentence));
    print(result);

