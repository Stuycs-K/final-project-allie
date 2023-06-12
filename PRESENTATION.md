# THE BIFID CIPHER

## HISTORY

The bifid cipher was invented in 1895 by Felix-Marie Delastelle, a French cryptographer.
Delastelle was born in 1840 and died at 64 years old in 1902
Other notable accomplishments of Delastelle are inventing the trifid cipher and four-square cipher.

The bifid cipher was first published in a French journal named "Revue de Genie Civil" which translates to the "Journal of Civil Engineering".
Delastelle also wrote a book in cryptography shortly before his death in 1901.

<img class="img-fluid" src="https://miro.medium.com/v2/resize:fit:254/1*sZamlaesGrM5m4Arr7_FNw.jpeg" alt="Delastelle" height="300px">

The bifid cipher uses a transposed Polybius square and fractionation to encrypt messages.

## ENCRYPTING  MESSAGES

There are a couple of steps in order to encrypt a message using the bifid cipher.

1. Generating the 25-letter Polybius square
2. Encrypt message using the Polybius square to return coordinate values
3. Fractionate coordinate values by writing them in a single row
4. Decrypt fractionated coordinates to reveal cipher text

### STEP 1: GENERATING POLYBIUS SQUARE

What is a polybius square? Great question!
A polybius square is a representation of the alphabet sorted in a 5X5 grid.
An example is shown below:

<img class="img-fluid" src="https://media.geeksforgeeks.org/wp-content/uploads/polybius-square.png" alt="POLYBIUS" height="300px">

You may notice that there are only 25 spaces, however there are 26 letters of the alphabet.
This problem is solved by omitting/replacing a letter in the polybius square.
Usually the letter 'J' is ignored and replaced by the letter 'I' in the message or key.

However, we don't just use a normal polybius square.
We have to use a key in order to alter the position of the letters in a square.
> KEY: CRYBABY

Given the key above we can properly alter the polybius square.

```
  1 2 3 4 5
1 C R Y B A
2 D E F G H
3 I K L M N
4 O P Q S T
5 U V W X Z
```

The key is written in the square starting at the position (1, 1).
Every other letter of the alphabet is shifted after the key in the polybius sqaure.
Once a letter in the word is written it cannot be used in the grid again.
If the key contains multiple instances of the same letter, that letter is skipped the second time.

### GET CORDS

Now we have to start encrypting a message.
Lets use the previously mentioned key and following message as an example:
> CYBER

Now we have to match each letter of the message to its coordinates on the polybius sqaure.
For example, a 'C' would be [1, 1]. This is done in order of row, column.
Spaces and punctuation are ignored. After doing this for the whole message, this is what you get:

```
C Y B E R
1 1 1 2 1
1 3 4 2 2
```

### FRACTIONATE/WRITE IN A SINGLE LINE

Now we have reorganize these coordinates.
We do this by writing out the row coordinates and then appending the column coordinates to this line.
After doing this process, we get this result:

**1** 1 1 2 1 **1** 3 4 2 2

For longer messages, this process can be broken up into blocks by doing this process on only 10 coordinates at a time for example.

### DECRYPT REWRITTEN COORDINATES

Now the last step is pretty simple, we just have to use the polybius table in order to decrypt the coordinates above.
For reference, here is the polybius table we made before:

```
  1 2 3 4 5
1 C R Y B A
2 D E F G H
3 I K L M N
4 O P Q S T
5 U V W X Z
```

The first decrypted letter is 'C', and the second is 'R' as those are the letters that the coordinates correspond to.
If we repeat this process, we get the following cypher text:
> CRCME

## DECRYPTING MESSAGES

To decrypt messages, we just have to reverse this process.
Knowing the key, we can make the same polybius square we made above.
We can then take the cipher text "CRCME" and translate it into coordinates.

After getting:
> 1 1 1 2 1 1 3 4 2 2

We can break the numbers into two lines in order to get the actual coordinates back.
Using the actual coordinates, we can properly decrypt this message.

```
1 1 1 2 1
1 3 4 2 2
C Y B E R
```

## OVERVIEW

There was no solution I found to decrypt this message without the key.
Frequency analysis is not possible because the transposition and fractionalization spreads out the letter frequency.
