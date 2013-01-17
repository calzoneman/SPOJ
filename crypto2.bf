# Input 3 digits & increment last one

,>,>,+

# Use the cell to the right of the last one as a buffer
# Assign 58 to it (ASCII 0 plus 10)

>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

# Subtract 1 from the last digit and the buffer cell until the last
# digit is 0 (buffer now holds the difference)

<[->-<]

# Set the last digit to 58 (ASCII 0 plus 10)

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

# If the buffer cell is 0 decrement the last digit 10 times
# This produces a last digit of ASCII 0
# Then increment the middle digit
# If the buffer cell is not 0 subtract the difference from 58 to
# Obtain the original digit ASCII value
# Brainfuck doesn't have else conditionals so do the reverse of the 0 case
# so that the 0 case doesn't change anything

>[[<->-]<<->++++++++++>]<----------<+

# Repeat the above steps but for the middle digit
# The only change is the number of shifts required to jump between
# the middle digit and the buffer cell

>>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
<<[->>-<<]
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
>>[[<<->>-]<<<->++++++++++>>]<<----------<+

# Print answer

.>.>.
