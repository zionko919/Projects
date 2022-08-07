 *  Synthesizing a Plucked String Sound:

 It is a program to simulate a guitar string using the Karplus-Strong 
 algorithm.
 
 The program plays guitar like sound on 37 keys on the keyboard. 
 I have divided my programs into two so you can test out my guitar and
 my extra credit instrument sound.
 
 I modified the algorithm in my StringSound
 .cpp file to make some different sound other than a guitar. It sounds
 like a bell or a harp. However, I am not really sure what instrument
 it really is. All I can tell is that it is different from the guitar
 I did it by using a decay factor of negative number in tic() function.
 I also played around with the frequency to change the sound.

 Basically, The program needs two components, the ring buffer feedback mechanism
 and the averaging operation. So, we create an empty ring buffer, with
 given max capacity. Then, return number of items currently in the 
 buffer. And in a while, we could check if the buffer is full or empty.
 Then add item to the end. Then delete and return item from the front 
 or return but do not delete item from the front. So, it is to increase
 the end when entering, and increase the front when leaving. Then when
 the end or the front is equal to capacity, it goes back to 0.
