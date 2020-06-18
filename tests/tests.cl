/ Include the standard library
|C:\Users\thoma\desktop\cmdlang\tests\standard.cl|



/ Program Start

=0 ( + >
	/ Operation flag
	++++ ++++ ++++ +

	/ Numbers to use
	> ++
	> ++++

	{Multiply } <: { and } >: {
} <<
	
	@std_math;
)


/ Multiply results
{Result: } >: {

} <<


=1 ( + >
	/ Reset cells
	[-] > [-] <

	/ Operation flag
	++++ ++++ ++++ +

	/ Numbers to use
	> ++++
	> +++++++++

	{Multiply } <: { and } >: {
} <<

	@std_math;
)