.class public main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	goto FUNC_main
FUNC_main:
	ldc 10.500000
	fstore 0
	fload 0
	ldc 11.400000
	fcmpl
	ifgt ELSE_0_0
	ldc 1
	istore 1
	fload 0
	iload 1
	i2f
	fadd
	fstore 0
	goto EXIT_0_0
ELSE_0_0:
	fload 0
	ldc 10
	i2f
	fcmpl
	ifne ELSE_0_1
	ldc 1
	istore 1
	fload 0
	iload 1
	i2f
	fsub
	fstore 0
	goto EXIT_0_0
ELSE_0_1:
	fload 0
	ldc 9
	i2f
	fcmpl
	ifne ELSE_0_2
	ldc 20
	i2f
	fstore 0
	goto EXIT_0_0
ELSE_0_2:
	ldc 0
	i2f
	fstore 0
EXIT_0_0:
EXIT_0_1:
EXIT_0_2:
	fload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	ldc 3.300000
	ldc 3
	i2f
	fcmpl
	ifle BOOL_F_0_0
	ldc "True"
	goto BOOL_T_0_0
BOOL_F_0_0:
	ldc "False"
BOOL_T_0_0:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method
