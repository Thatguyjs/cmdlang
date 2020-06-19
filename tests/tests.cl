/ Include the standard library
|lib/standard.cl|



[
	/ Log results
	{Result: } >:< {

} <<<

	/ Reset cells
	> [-] > [-] > [-] > [-] > [-] <<<<<

	@program;
]

!program;



/ Logic


/ Convert to boolean
=0 ( + >>
	/ Section & command numbers (1:1)
	+ > +

	/ Parameters
	> ++++
	
	{Converting } : { to a boolean
} <

	@std_top;
)

=1 ( + >>
	/ Section & command numbers (1:1)
	+ > +

	/ Parameters
	>

	{Converting } : { to a boolean
} <

	@std_top;
)


/ NOT gate
=2 ( + >>
	/ Section & command numbers (1:2)
	+ > ++

	/ Parameters
	> ++++

	{NOT gate } : {
} <

	@std_top;
)

=3 ( + >>
	/ Section & command numbers (1:2)
	+ > ++

	/ Parameters
	>

	{NOT gate } : {
} <

	@std_top;
)


/ AND gate
=4 ( + >>
	/ Section & command numbers (1:3)
	+ > +++

	/ Parameters
	> + > ++

	{AND gate } <: {, } >: {
} <<

	@std_top;
)

=5 ( + >>
	/ Section & command numbers (1:3)
	+ > +++

	/ Parameters
	> + >

	{AND gate } <: {, } >: {
} <<

	@std_top;
)

=6 ( + >>
	/ Section & command numbers (1:3)
	+ > +++

	/ Parameters
	> > +

	{AND gate } <: {, } >: {
} <<

	@std_top;
)

=7 ( + >>
	/ Section & command numbers (1:3)
	+ > +++

	/ Parameters
	> >

	{AND gate } <: {, } >: {
} <<

	@std_top;
)


/ OR gate
=8 ( + >>
	/ Section & command numbers (1:4)
	+ > ++++

	/ Parameters
	> + > ++

	{OR gate } <: {, } >: {
} <<

	@std_top;
)

=9 ( + >>
	/ Section & command numbers (1:4)
	+ > ++++

	/ Parameters
	> + >

	{OR gate } <: {, } >: {
} <<

	@std_top;
)

=10 ( + >>
	/ Section & command numbers (1:4)
	+ > ++++

	/ Parameters
	> > +

	{OR gate } <: {, } >: {
} <<

	@std_top;
)

=11 ( + >>
	/ Section & command numbers (1:4)
	+ > ++++

	/ Parameters
	> >

	{OR gate } <: {, } >: {
} <<

	@std_top;
)


/ More than
=12 ( + >>
	/ Section & command numbers (1:5)
	+ > ++++ +

	/ Parameters
	> +++ > ++

	{Check if } <: { > } >: {
} <<

	@std_top;
)

=13 ( + >>
	/ Section & command numbers (1:5)
	+ > ++++ +

	/ Parameters
	> ++ > +++

	{Check if } <: { > } >: {
} <<

	@std_top;
)


/ Less than
=14 ( + >>
	/ Section & command numbers (1:6)
	+ > ++++ ++

	/ Parameters
	> ++ > +++

	{Check if } <: { < } >: {
} <<

	@std_top;
)

=15 ( + >>
	/ Section & command numbers (1:6)
	+ > ++++ ++

	/ Parameters
	> +++ > ++

	{Check if } <: { < } >: {
} <<

	@std_top;
)



/ Math


/ Addition
=16 ( + >>
	/ Section & command numbers (2:1)
	++ > +

	/ Parameters
	> + > ++

	{Add } <: { + } >: {
} <<

	@std_top;
)


/ Subtraction
=17 ( + >>
	/ Section & command numbers (2:2)
	++ > ++

	/ Parameters
	> ++++ ++ > ++

	{Subtract } <: { - } >: {
} <<

	@std_top;
)


/ Multiplication
=18 ( + >>
	/ Section & command numbers (2:3)
	++ > +++

	/ Parameters
	> ++++ + > +++

	{Multiply } <: { * } >: {
} <<

	@std_top;
)


/ Division
=19 ( + >>
	/ Section & command numbers (2:4)
	++ > ++++

	/ Parameters
	> ++++ ++++ ++++ > +++

	{Divide } <: { by } >: {
} <<

	@std_top;
)