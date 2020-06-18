/ Include the standard library
|lib/standard.cl|



/ Program Start

=0 ( + >
	/ Operation flag
	++++ ++++ ++++ +

	/ Parameters
	> ++
	> ++++

	{Multiply } <: { and } >: {
} <<
	
	@std_math;
)


/ Expression results
{Result: } >: {

} <<


=1 ( + >
	/ Reset cells
	[-] > [-] <

	/ Operation flag
	++++ ++++ +++

	/ Parameters
	> ++++
	> +++++++++

	{Add } <: { and } >: {
} <<

	@std_math;
)


=2 ( + >
	/ Reset cells
	[-] > [-] <

	/ Operation flag
	++++ ++++ ++++

	/ Parameters
	> +++++++
	> +++

	{Subtract } : { from } <: {
} <

	@std_math;
)