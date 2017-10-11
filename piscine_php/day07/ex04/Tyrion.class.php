<?php
class Tyrion
{

	public function sleepWith( $x )
	{
		if ( $x instanceof Jaime )
			print( "Not even if I'm drunk !" . PHP_EOL );
		if ( $x instanceof Sansa )
			print( "Let's do this." . PHP_EOL );
		if ( $x instanceof Cersei )
			print( "Not even if I'm drunk !" . PHP_EOL );
	}

}
?>