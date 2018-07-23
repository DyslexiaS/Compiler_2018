.class public main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	goto FUNC_main
FUNC_add:
	astore 10
	istore 12
	istore 11
	iload 11
	iload 12
	iadd
	ret 10
FUNC_main:
	ldc 0
	istore 0
	ldc 1
	ldc 2
	jsr FUNC_add
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
