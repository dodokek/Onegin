# Onegin
String sorting algorithm
## Overview
This programm is capable of:
- Efficiently reading the file
- Trimming unneeded symbols
- Sorting strings according to many params
## Installation
All installation is made by makefiles:
~~~
git clone https://github.com/dodokek/Onegin.git
cd src
make
~~~
## Options
This programm allows you efficiently read the text files and then sort the lines in it.
### Forward sorting
Strings are being sorted by their beginnings, empty lines are ignored automaticly.
~~~
main.exe -f
~~~
### Backward sorting
Strings are being sorted by their end, excluding symbols such as '!', ';', etc.
~~~
main.exe -b
~~~
### Logging 
Programm starts to write logs and make the function-call tree.
~~~
main.exe -l
~~~

### Choosing input file 
You can choose the name and the path to the file you want to be read.
~~~
main.exe -l
~~~


### Choosing output file 
You can choose the name and the path to the file you want your output to be stored.
~~~
main.exe -l
~~~

### Choosing the sorting algorithm 
You can choose the sorting algorithm.
By default the QuickSort is used, but 
~~~
main.exe -l -1 #BubbleSort
main.exe -l -2 #QuickSort
~~~

## Conclusion
Very soon this programm will be able to sort lines according to their and, moreover it will be a generator of true poems(Bredogenerator).
