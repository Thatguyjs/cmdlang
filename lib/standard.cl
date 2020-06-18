/ Copyright (c) 2020 Thatguyjs All Rights Reserved.

/ This is the standard library, still largely in development.
/ Feel free to contribute and discuss ideas about this project.



/ Logic
!std_logic;


/ Convert to boolean
=1 ( >
	=0 (< @std_end;)
	[-] +
< )


/ Convert to inverse boolean (NOT gate)
=2 ( >
	=0 (+ < @std_end;)
	[-]
< )


/ AND gate
=3 ( >
	>> [-] <<

	[
		>> +
		<< -
	] +

	>> =0 (<< [-] >>) [-]
	< =0 (< [-] >) [-] <
< )


/ OR gate
=4 ( >
	>> [-] <<

	[
		>> +
		<< -
	]

	>> [<< + >> [-]]
	< [< [-] + > [-]] <
< )



/ Math
!std_math;


/ Add
=11 ( >>
	[
		< +
		> -
	]
<< )


/ Subtract
=12 ( >>
	[
		< -
		> -
	]
<< )


/ Multiply
=13 ( >
	>> [-] > [-] > [-] <<<<

	[
		>> + > +
		<<< -
	]

	>

	!_mul_;
	[
		> [
			<< +
			>> -
		] <

		-

		>> =0 ( >
			[
				< + < +
				>> -
			]

			<<< @_mul_;
		)

		[
			-
			> + << +
			>
		]

		<<
	]

	> [-] >> [-] <<<
<< )


/ Divide
=14 ( >
	>> [-] > [-] <<<

	[
		>>> +
		<<< -
	]

	>>>

	[
		<< [
			>>

			=0 (
				< [-] < [-] <<
				@std_end;
			)

			-

			< + < -
		] >>

		<<< + >>>

		< [
			> -

			=0 (
				< [-] < [-] <<
				@std_end;
			)

			<< + > -
		] >

		<<< + >>>
	]
< )



/ Memory
!std_memory;


/ Clear a cell range, including parameters
=21 ( >
	=0 (@std_end;)

	> [-] > [-] <<

	[
		> + > +
		<< -
	]
	
	> -- >

	[
		<< +
		>> -
	]
	
	< [
		> [-] <

		[
			> +
			< -
		]

		< [
			> +
			< -
		] >>

		-
	]

	< [
		> +
		< -
	] > -

	[
		[
			< +
			> -
		] <

		-
	]
<<< )



/ End of library
!std_end;