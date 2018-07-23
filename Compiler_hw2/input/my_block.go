var x int = 12
{
	print(x)
	var x float32 = 2.4
	print(x)
}
print(x)
{
	x++
	print(x)
	{
		x++
		print(x)
		var x int = 300
		x++
		print(x)
	}
}
