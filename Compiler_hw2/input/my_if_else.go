/*
 * Your parser just need to match the if... else if ... grammar.
 * Don't need to operate the correct result after parsing.
 * In the other hand, we don't consider the "x" value in this input case.
 */
var x int = 10

if (x < 10) {
    print(x+1) 
}

if (x < 10) {
    print(x-1) 
} else {
    print(x*1) 
}

if (x < 10) {
    print(x/1) 
} else if(x == 10) {
    print(x+1) 
}

if (x < 10) {
    print(x-1) 
} else if(x == 10) {
    print(x*1) 
} else if(x == 9) {
    print(x/1) 
} else {
    print(x+1) 
}
