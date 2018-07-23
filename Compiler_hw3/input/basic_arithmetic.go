var x int
var a int = 2
var y float32 = 1.3

// pure int operation
x = a + 5 * 2
println(x)
// hybrid operation
y = x + 3.2 * (a - 2.3)
println(y)
/*
 * Mod operation need to consider type checking.
 * If float involve into mod operation, we expext to see the error message.
 */
x = (x - 1) % 2
println(x)
//x = y % 2

// All operator
x = x + 1
println(x)
x = x - 1
println(x)
x = x * 1
println(x)
x = x / 1
println(x)
x = x % 1
println(x)
x += 1
println(x)
x -= 1
println(x)
x *= 1
println(x)
x /= 1
println(x)
x %= 1
println(x)
x++
println(x)
x--
println(x)
