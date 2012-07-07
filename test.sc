int add( int v1, int v2 );

int main()
{
	int val;
	int test;

	string a;

	a = "s";

//	print( a );

	a = "s" + a + "tt";
	
	print( a );

	val = 20;
	test = 40;

	val = add( 25, 35 ) + 50;

	//val += 20;

//	val = test;

//	print( str(val) );

	return val;
}

int add( int v1, int v2 )
{
	return v1 - v2;
}
