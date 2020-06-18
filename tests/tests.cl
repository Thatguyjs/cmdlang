/ Include the standard library
|lib/standard.cl|



/ Multiplication
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


/ Division
=1 ( + >
	/ Reset cells
	[-] > [-] <

	/ Operation flag
	++++ ++++ ++++ ++

	/ Parameters
	> ++++ ++++ +++
	> ++

	{Divide } <: { by } >: {
} <<

	@std_math;
)


/ Addition
=2 ( + >
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


/ Subtraction
=3 ( + >
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