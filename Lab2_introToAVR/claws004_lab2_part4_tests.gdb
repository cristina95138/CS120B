# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Add tests below

test “PINA: 20, PINB: 20, PINC: 20  => PORTB: 60”
setPINA 0x20
setPINB 0x20
setPINC 0x20
continue 5
expectPORTD 0x60
checkResult

test “PINA: 50, PINB: 00, PINC: 00  => PORTB: 62”
setPINA 0x60
setPINB 0x00
setPINC 0x00
continue 5
expectPORTD 0x62
checkResult

test "PINA: 50, PINB: 50, PINC: 00 => PORTD = B3"
setPINA 0x60
setPINB 0x50
setPINC 0x00
continue 5
expectPORTD 0xB3
checkResult

test "PINA: 40, PINB: 40, PINC: 40 => PORTD = C1"
setPINA 0x40
setPINB 0x40
setPINC 0x40
continue 5
expectPORTD 0xC1
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
