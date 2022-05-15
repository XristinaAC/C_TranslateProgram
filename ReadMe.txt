The program reads text characters from the standard output( which is supposed to be text written with greek characters iso8859-7), and writes the same text, translated using a certain set of rules, to the standard output. 

Basically, the program translates greek text to a Greeklish text using Latin characters from the iso8859-1 character set and Greek characters from the iso8859-7 character set. The file format should be ANSI.

The program can run through the command prompt using the following lines:
     $ gcc –Wall –ansi –pedantic –o translate translate.c

     $ translate < test1.txt > test.txt

,where "test1.txt" is the imput file and "test.txt" is the ouput file. 

Two files are provided for testing the program( test1.7 and test2.7).



