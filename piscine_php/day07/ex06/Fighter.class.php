<?php
class Fighter
{

	private $name;

	public function __construct( $nom )
	{
		$this->name = $nom;
	}

	public function getName()
	{
		return $this->name;
	}

}
?>