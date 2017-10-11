<?php
class UnholyFactory
{

	private $absorbed = array();

	public function absorb( $fighter )
	{
		if ( get_parent_class( $fighter ) === "Fighter" )
		{
			if ( isset( $this->absorbed[ $fighter->getName() ] ) )
				printf( "(Factory already absorbed a fighter of type %s)", $fighter->getName() );
			else
			{
				printf( "(Factory absorbed a fighter of type %s)", $fighter->getName() );
				$this->absorbed[ $fighter->getName() ] = $fighter;
			}
		}
		else
			print("(Factory can't absorb this, it's not a fighter)");
		print(PHP_EOL);
	}

	public function fabricate( $type )
	{
		if ( isset( $this->absorbed[ $type ] ) )
		{
			echo "(Factory fabricates a fighter of type " . $type . ")" . PHP_EOL;
			return clone $this->absorbed[ $type ];
		}
		else
			echo "(Factory hasn't absorbed any fighter of type " . $type . ")" . PHP_EOL;
		return Null;
	}

}
?>