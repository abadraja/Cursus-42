<?php
class NightsWatch implements IFighter
{

	private $man = array();

	public function recruit( $x )
	{
		if ( method_exists( get_class( $x ), 'fight' ) )
			$this->man[] = $x;
	}

	public function fight()
	{
		foreach ($this->man as $rec)
			$rec->fight();
	}

}
?>