/ Copyright (c) 2020 Thatguyjs All Rights Reserved.

/ This is the standard library, still largely in development.
/ Feel free to contribute and discuss ideas about this project.



/ Start of the library
!std_top;



/ Convert two numbers (section, command) to a section + command number
[ <
	[
		< ++++ ++++ ++
		> -
	]

	< [
		> ++++ ++++ ++
		< -
	] >
	
	[
		> +
		< -
	]
> @std_commands;]



/ Commands section of the library
!std_commands;



/ Logic
!std_logic;


/ Convert to boolean
=101 ( >
	=0 (< @std_end;)
	[-] +
< )


/ Convert to inverse boolean (NOT gate)
=102 ( >
	=0 (+ < @std_end;)
	[-]
< )


/ AND gate
=103 ( >
	>> [-] <<

	[
		>> +
		<< -
	] +

	>> =0 (<< [-] >>) [-]
	< =0 (< [-] >) [-] <
< )


/ OR gate
=104 ( >
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
=201 ( >>
	[
		< +
		> -
	]
<< )


/ Subtract
=202 ( >>
	[
		< -
		> -
	]
<< )


/ Multiply
=203 ( >
	>> [-] > [-] > [-] <<<<

	[
		>> + > +
		<<< -
	]

	>

	!_std_mul_;
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

			<<< @_std_mul_;
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
=204 ( >
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

			- < + < -
		] >>
		
		<<< + >>>

		=0 (
			< [-] < [-] <<
			@std_end;
		)

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
=301 ( >
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