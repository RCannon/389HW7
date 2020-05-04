author: Reilly Cannon (reicannon@reed.edu)

# Things I Tried

I first wrote the fucntion super_naive_convert, which was going to be my baseline implementation, until I discovered that it was slower than atoi. When writing this function, I first thought of making and int array that was padded with zeros except for the interger 1 at index 49, 2 at index 50, and so on, the indices corresponding to the ascii value of the numeric characters. I soon realized that I could do this so much easier with just 10 switch cases. 

The baseline naive_convert and optimized advanced_convert functions came to be pretty much simultaneously. The other thing I remembered when I initially started implementing int array method above was that ascii characters were just 8-bit strings that I could just as easily treat as a number. I could then just subtract the ascii representation for '0' from the representation for any number to get an integer form of that number. With that in mind, I developed these two methods, the naive_convert function really only uses that trick, as I wanted something faster than atoi that approximated Eitan's naive runtime of 0.006s, but that also didn't use any language optimaization techniques (i.e. those in the lecture notes) so that I could actually see what difference the language optimizations made.

I suspect that, if there is a faster solution, it is done by making fewer accesses to each variable, as the pointer to the char array is accessed twice per loop, as is the val variable. I would have liked to find a way to get at least one of these down to 1 access per loop. Alternatively, there might bbe some sneaky bbitwise operations that could be done to speed things up, but I didn't look to deep into that and figured the compiler could do that better than I could. 

I did try some other things. One thing I played aroud with a lot was to sort of "pack" the loop condition check step and try to get as much computation to be done at that step as possible (sort of like what I did in the advanced_convert function where by checking that the next element is not null it is also incrementing the pointer). This pretty much just overcomplicated things and didn't improve performance.

# Results

To compare the implementations, I tested each function three times on 10,000 lines of qutoes, and report the minimum run time of the three tests here. The full results can be seen in results.csv.

 Conversion Algorithm | MacOS Run Time (seconds) | VM Run Time (seconds)
----------------------|--------------------------|----------------------
atoi | 0.053345 | 0.034703
Super Naive Covert | 0.090251 | 0.094023
Naive Convert (baseline) | 0.010236 | 0.010308
Optimized Convert | 0.005331 | 0.004514

From these results, we conclude the optimized implementation performs 48% percent better on macOS than the baseline naive implementation, and 56% better than the baseline on the virtual machine. 
